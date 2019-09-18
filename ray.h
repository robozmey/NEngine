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
	ray(std::vector<double> _B, std::vector<double> _E);
	ray();
	~ray();
};

