#include "ray.h"



ray::ray(dot _B, dot _E) {
	B = _B;
	E = _E;
	M = _B.X;
	K = _E.X;
	for (int i = 0; i < K.size(); i++) {
		K[i] -= M[i];
	}
}

ray::ray(std::vector<double> _B, std::vector<double> _E) {
	B.X = _B;
	E.X = _E;
	M = _B;
	K = _E;
	for (int i = 0; i < K.size(); i++) {
		K[i] -= M[i];
		if (K[i] == 0) K[i] = 0.000000001;
	}
}

ray::ray()
{
}


ray::~ray()
{
}
