#pragma once
#include<vector>
#include<windows.h>
#include<iostream>
#include <cmath>

using namespace std;

#define PI 3.14
class screen
{
public:
	std::vector< std::vector<int> > pixels;
	int width;
	int height;
	HWND myconsole;
	HDC mydc;
	void setpixel(int x, int y, int c);
	screen(int w, int h);
	screen();
	~screen();
};

