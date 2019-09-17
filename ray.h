#pragma once
#include<vector>
#include"dot.h"
class ray
{
public:
	std::vector<double> K;
	std::vector<double> M;
	dot B;
	dot E;
	std::vector<double> W;
	ray(dot _B, dot _E);
	ray();
	~ray();
};

