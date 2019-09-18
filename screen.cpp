#include "screen.h"

void screen::setpixel(int x, int y, int c) {
	SetPixel(mydc, x, y, RGB(c, c, c));
}

screen::screen(int w, int h)
{
	width = w;
	height = h;
	pixels.resize(h);
	for (int i = 0; i < h; i++) {
		pixels[i].resize(w);
	}

	myconsole = GetConsoleWindow();
	//Get a handle to device context
	mydc = GetDC(myconsole);

	int pixel = 0;

	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);

	//Draw pixels
	setpixel(50, 100, 255);
	setpixel(50, 100, 255);

}

screen::screen()
{
}

screen::~screen()
{
	ReleaseDC(myconsole, mydc);
	//cin.ignore();
}
