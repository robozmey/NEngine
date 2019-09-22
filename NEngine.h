#pragma once
#include"dot.h"
#include"ray.h"
#include"poly.h"
#include"screen.h"
#include<set>
#include"SDL.h"




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

	double distance;
	int trace(ray Ray, poly Poly);
	double cross(ray Ray, poly Poly);

	int height;
	int width;

	void draw();

	int dims;

	NEngine(int _dims);
	~NEngine();
};

