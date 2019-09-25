#include "poly.h"


poly::poly(dot _A, dot _B, dot _C) {
	A = _A;
	B = _B;
	C = _C;
	M = A.X;
	K1 = B.X;
	K2 = C.X;
	for (int i = 0; i < M.size(); i++) {
		K1[i] -= M[i];
		K2[i] -= M[i];
	}
}

poly::poly(std::vector<double> _A, std::vector<double> _B, std::vector<double> _C, SDL_Color _color) {
	color = _color;
	A.X = _A;
	B.X = _B;
	C.X = _C;
	M = A.X;
	K1 = B.X;
	K2 = C.X;
	for (int i = 0; i < M.size(); i++) {
		K1[i] -= M[i];
		K2[i] -= M[i];
		if (K1[i] == 0) K1[i] = 0.0000000002;
		if (K2[i] == 0) K2[i] = -0.0000000002;
	}
}

poly::poly()
{
}


poly::~poly()
{
}
