#pragma once
#include<vector>
#include"dot.h"
#include<windows.h>
class poly
{
public:
	std::vector<double> K1;
	std::vector<double> K2;
	std::vector<double> M;
	COLORREF color = RGB(255, 255, 255);
	int obj;
	dot A;
	dot B;
	dot C;
	poly(dot _A, dot _B, dot _C);
	poly(std::vector<double> _A, std::vector<double> _B, std::vector<double> _C, COLORREF _color);
	poly();
	~poly();
};

