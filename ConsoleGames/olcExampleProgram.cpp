/*

	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018-2020 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Relevant Video: https://www.youtube.com/watch?v=8JJ-4JgR7Dg

	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
				https://www.youtube.com/javidx9extra
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Patreon:	https://www.patreon.com/javidx9
	Homepage:	https://www.onelonecoder.com

	Community Blog: https://community.onelonecoder.com

	Author
	~~~~~~
	David Barr, aka javidx9, �OneLoneCoder 2018, 2019, 2020
*/

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <algorithm>
#include <functional>
#include <cmath>
struct rect
{
	olc::vf2d pos;
	olc::vf2d size;
	olc::vf2d velocity;
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

	float speed = 0.0f;
	float max_speed = 3.0f;
	float acceleration = 0.2f;
	float friction = 0.05f;
	float angle = 0.0f;

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
		}
		if (speed < 0.0f)
		{
			speed += friction;
		}
		if (abs(speed) < friction)
		{
			speed = 0;
		}

		if (speed != 0)
		{
			float flip = speed > 0.0f ? 1.0f : -1.0f;

			//std::cout << angle << "   " << speed << "  " << flip << std::endl;

			if (GetKey(olc::Key::A).bHeld)
			{
				angle += 0.03f * flip;
			}
			if (GetKey(olc::Key::D).bHeld)
			{
				angle -= 0.03f * flip;
			}
		}

		
		//createRandomTraffic(fElapsedTime);

		// Update the player rectangles position, with its modified velocity
		vRects[0].pos.x -= sin(angle) * speed ;
		vRects[0].pos.y -= cos(angle) * speed ;

		std::cout << sinf(angle) * speed << "  #############  " << cosf(angle) * speed  << std::endl;

		// Draw all rectangles
		for (const auto &r : vRects)
			DrawRect(r.pos, r.size, olc::WHITE);


		vRects[3].pos.y += speed * fElapsedTime;

		return true;
	}
};

int main()
{
	RectangleCollisions demo;
	if (demo.Construct(256, 240, 4, 4, false, false))
		demo.Start();
	return 0;
}