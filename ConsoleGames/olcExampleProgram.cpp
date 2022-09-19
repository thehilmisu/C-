
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <algorithm>
#include <functional>
#include <cmath>
struct rect
{
	olc::vf2d pos;
	olc::vf2d size;
};
class RectangleCollisions : public olc::PixelGameEngine
{
public:
	RectangleCollisions()
	{
		sAppName = "Rectangles!";
	}

	std::vector<rect> vRects;

public:

	bool checkcollisiononeway(rect rect1, rect rect2)
	{
		if (rect1.pos.x < rect2.pos.x + rect2.size.x &&
			rect1.pos.x + rect1.size.x > rect2.pos.x &&
			rect1.pos.y < rect2.pos.y + rect2.size.y &&
			rect1.size.y + rect1.pos.y > rect2.pos.y)
		{
			return true;
		}
		return false;
	}

	bool checkcollisionbothways(rect rectA, rect rectB)
	{
		return checkcollisiononeway(rectA, rectB) || checkcollisiononeway(rectB, rectA);
	}

	float rand_FloatRange(float a, float b)
	{
		return ((b - a) * ((float)rand() / RAND_MAX)) + a;
	}

	void createRandomTraffic(float fElapsedTime)
	{
		float x_value = rand_FloatRange(50.0f, 160.0f);
		// std::cout << vRects.size() << std::endl;
		// to do
		if (vRects.size() > 3)
		{
			if (vRects[3].pos.y > 240)
				vRects.pop_back();
		}
		else
			vRects.push_back({{x_value, -50.0f}, {10.0f, 40.0f}});
	}

	olc::vf2d DrawRotatedRectangle(const olc::vf2d& pos, rect rectangle, const float fAngle)
	{
		float x1 = cos(fAngle) * pos.x - sin(fAngle) * pos.y;
		float y1 = sin(fAngle) * pos.x + cos(fAngle) * pos.y;

		return {x1,y1};

	}
	olc::vf2d rotate_point(float cx,float cy,float angle)
	{
		olc::vf2d p;
		float s = sin(angle);
		float c = cos(angle);

		// translate point back to origin:
		p.x -= cx;
		p.y -= cy;

		// rotate point
		float xnew = p.x * c - p.y * s;
		float ynew = p.x * s + p.y * c;

		// translate point back:
		p.x = xnew + cx;
		p.y = ynew + cy;
		return p;
	}
	olc::vf2d rotate_point_new(float cx, float cy, float angle, olc::vf2d p){
	  olc::vf2d ret(cos(angle) * (p.x - cx) - sin(angle) * (p.y - cy) + cx,
                  sin(angle) * (p.x - cx) + cos(angle) * (p.y - cy) + cy);
     return ret;
	}

	float speed = 0.0f;
	float max_speed = 3.0f;
	float acceleration = 0.2f;
	float friction = 0.05f;
	float angle = 0.0f;
	float m_angle = 0.0f;

	bool OnUserCreate() override
	{
		vRects.push_back({{120.0f, 160.0f}, {10.0f, 40.0f}}); // car rectangle
		vRects.push_back({{50.0f, 0.0f}, {1.0f, 1000.0f}});	  // left wall
		vRects.push_back({{200.0f, 0.0f}, {1.0f, 1000.0f}});  // right wall
		// vRects.push_back({ {170.0f, 50.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {190.0f, 50.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {110.0f, 50.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {50.0f, 130.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {50.0f, 150.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {50.0f, 170.0f}, {20.0f, 20.0f} });
		// vRects.push_back({ {150.0f, 100.0f}, {10.0f, 1.0f} });
		// vRects.push_back({ {200.0f, 100.0f}, {20.0f, 60.0f} });

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);

		if (GetKey(olc::Key::W).bHeld)
			speed += acceleration;
		if (GetKey(olc::Key::S).bHeld)
			speed -= acceleration;

		if (speed > max_speed)
		{
			speed = max_speed;
		}
		if (speed < -max_speed / 2)
		{
			speed = -max_speed / 2;
		}

		if (speed > 0.0f)
		{
			speed -= friction;
			if (GetKey(olc::Key::A).bHeld || GetKey(olc::Key::D).bHeld)
			   angle -= friction;
		}
		else if (speed < 0.0f)
		{
			speed += friction;
			if (GetKey(olc::Key::A).bHeld || GetKey(olc::Key::D).bHeld)
				angle += friction;
		}
		if (abs(speed) < friction)
		{
			speed = 0;
			angle = 0;
		}

		if (speed != 0.0f)
		{
			float flip = speed > 0.0f ? 1.0f : -1.0f;

			//std::cout << fElapsedTime << "   " << speed << "  " << flip << std::endl;
			

			if (GetKey(olc::Key::A).bHeld)
			{
				angle = 45 * flip;
			}
			if (GetKey(olc::Key::D).bHeld)
			{
				angle = -45 * flip;
			}

		}
		else if(speed == 0.0f)
		{
			
			
			if((GetKey(olc::Key::A).bHeld) || (GetKey(olc::Key::D).bHeld))
			{
				if (GetKey(olc::Key::A).bHeld)
				{
					m_angle += 0.03f;
				}
				if (GetKey(olc::Key::D).bHeld)
				{
					m_angle += -0.03f;
				}
				float cx = vRects[0].pos.x + vRects[0].size.x / 2;

				float cy = vRects[0].pos.y + vRects[0].size.y / 2;

				olc::vf2d newCoordinates =  rotate_point_new(cx,cy,m_angle,vRects[0].pos);

				//vRects[0].pos.x = newCoordinates.x;
				//vRects[0].pos.y = newCoordinates.y;

				DrawLine(vRects[0].pos,newCoordinates);
				//DrawLine(x1,y1,x2,y2)
				// DrawLine(x, y, x+w, y);
				// DrawLine(x+w, y, x+w, y+h);
				// DrawLine(x+w, y+h, x, y+h);
				// DrawLine(x, y+h, x, y);

				//DrawRect(newCoordinates,vRects[0].size);


				//std::cout << "###########" << newCoordinates.x << newCoordinates.y << m_angle << std::endl;
			}
		}

		createRandomTraffic(fElapsedTime);

		// Update the player rectangles position, with its modified velocity
		//vRects[0].pos.x -= sinf(angle) * speed ;
		//vRects[0].pos.y -= cosf(angle) * speed ;

		//std::cout << checkcollisionbothways(vRects[0],vRects[1]) << std::endl;

		//vRects[0].pos -= {(sin(angle)) * speed, (cos(angle)) * speed};

		//std::cout << sinf(angle) * speed << "  #############  " << cosf(angle) * speed  << std::endl;

		// Draw all rectangles
		for (const auto &r : vRects)
			DrawRect(r.pos, r.size, olc::WHITE);


		vRects[3].pos.y += max_speed * fElapsedTime * 5;


		return true;
	}
};



//   void DrawRotatedRectangle(const olc::vf2d& pos, rect* rectangle, const float fAngle, const olc::vf2d& center, const olc::vf2d& scale)
//   {
//     rect r;
//     r = rectangle;
//     r.pos[0] = (olc::vf2d(0.0f, 0.0f) - center) * scale;
//     r.pos[1] = (olc::vf2d(0.0f, float(r.size.y) - center) * scale;
//     r.pos[2] = (olc::vf2d(float(r.size.x), float(r.size.y)) - center) * scale;
//     r.pos[3] = (olc::vf2d(float(r.size.x), 0.0f) - center) * scale;
//     float c = cos(fAngle), s = sin(fAngle);
//     for (int i = 0; i < 4; i++)
//     {
//       r.pos[i] = pos + olc::vf2d(r.pos[i].x * c - r.pos[i].y * s, r.pos[i].x * s + r.pos[i].y * c);
//       r.pos[i] = r.pos[i] * 240 * 2.0f - olc::vf2d(1.0f, 1.0f);
//       r.pos[i].y *= -1.0f;
//     }
//   }

int main()
{
	RectangleCollisions demo;
	if (demo.Construct(256, 240, 4, 4, false, false))
		demo.Start();
	return 0;
}