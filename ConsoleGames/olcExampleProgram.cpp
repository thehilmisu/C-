#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"



struct Rectangle{
	olc::vf2d starting_coordinates;
	olc::vf2d ending_coordinates;
	int width = 0;
	int height = 0;

	olc::vi2d getSize()
	{
		width = ending_coordinates.x - starting_coordinates.x;
		height = ending_coordinates.y - starting_coordinates.y;
		return { width, height};
	}

};

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

	olc::vf2d mouse_position;
	olc::vf2d mouse_position1;
	olc::vf2d mouse_position2;
	std::vector<Rectangle> rectangles;
	bool isStarted = false;


public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool CheckIfIsInside(int x1, int y1, int x2,
               int y2, int x, int y)
	{
		if (x > x1 and x < x2 and y > y1 and y < y2)
			return true;
	
		return false;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		// for (int x = 0; x < ScreenWidth(); x++)
		// 	for (int y = 0; y < ScreenHeight(); y++)
		// 		Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));	

		Clear(olc::VERY_DARK_BLUE);
		olc::vf2d start_txt_point = {125, 200};
		DrawRect(start_txt_point, {50, 35}, olc::WHITE);
		DrawString({132,215},"Start",olc::WHITE);

		if(GetMouse(0).bPressed)
		{
			mouse_position1 = {float(GetMouseX()), float(GetMouseY())};
		}

		if(GetMouse(0).bReleased)
		{
			mouse_position2 = {float(GetMouseX()), float(GetMouseY())};
			if(CheckIfIsInside(start_txt_point.x,start_txt_point.y,
							   start_txt_point.x+50,start_txt_point.y+35,mouse_position1.x,
							   mouse_position1.y))
			{
				std::cout << "Start Pressed" << std::endl;
				isStarted = true;
			}
			else{
				if(!isStarted)
				{
					Rectangle temp;
					temp.starting_coordinates = mouse_position1;
					temp.ending_coordinates = mouse_position2;
					rectangles.push_back(temp);
				}
					
			}
			
		}

		if(GetMouse(0).bHeld)
		{
			mouse_position2 = {float(GetMouseX()), float(GetMouseY())}; 
			int width = mouse_position2.x - mouse_position1.x;
			int height = mouse_position2.y - mouse_position1.y;
			if(!isStarted)
				DrawRect(mouse_position1,{(width), (height)},olc::WHITE);
		}

		for(int i=0; i < rectangles.size(); i++)
		{
			DrawRect(rectangles.at(i).starting_coordinates,rectangles.at(i).getSize(),olc::WHITE);
		}
			

		return true;
	}
};


int main()
{
	Example demo;
	std::cout << "started" << std::endl;
	if (demo.Construct(300, 240, 4, 4))
		demo.Start();

	return 0;
}
