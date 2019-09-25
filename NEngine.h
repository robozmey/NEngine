#pragma once
#include"dot.h"
#include"ray.h"
#include"poly.h"
#include"screen.h"
#include<set>
#include<SDL2/SDL.h>

class NEngine
{
public:
	std::vector<poly> Polys;
	std::set<int> Objs;
	screen Screen;

	//HWND myconsole;

	//HDC mydc;

	SDL_Window* window;
	SDL_Renderer* renderer;

	int k_obj=0;

	float distance;
	float fov = M_PI * 2 / 3;
	void trace(const ray &Ray, const poly &Poly, SDL_Color& c_color, double& r);
	//double cross(ray Ray, poly Poly);

	int height = 64;
	int width  = 128;

	int h_x = 10;
	int w_x = 10;

	double cam_x = 1;
	double cam_y = 0;
	double cam_z = 0;
	double cam_az = -0*M_PI;

	void draw();

	int dims;

	NEngine(int _dims);
	~NEngine();
};

