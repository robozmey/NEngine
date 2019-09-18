#include<iostream>
#include"NEngine.h"

int main() {
	vector <int> a[5];
	a[0] = { 0, 1, 0, 0, 0 };
	a[1] = { 1, 1, 1, 1, 1 };
	a[2] = { 0, 1, 0, 0, 0 };
	a[3] = { 1, 1, 1, 1, 1 };
	a[4] = { 0, 1, 0, 0, 0 };
	
	//cin.ignore();
	NEngine nengine(3);
	//std::vector<double> x(3), y(3), z(3);
	int sz = 2;
	int t = 0;
	int h = 4;
	for (double i = t; i <= h; i++) {
		for (double j = -sz; j <= sz; j++) {
			if ((i == 0 && j == 0) || !a[int(i)][int(j) + sz]) {
				nengine.Polys.push_back(poly({ i + 1, j + 1, 2 }, { i + 1, j - 1, 2 }, { i - 1, j + 1, 2 }, RGB(0, 0, 255)));
				nengine.Polys.push_back(poly({ i - 1, j - 1, 2 }, { i + 1, j - 1, 2 }, { i - 1, j + 1, 2 }, RGB(0, 128, 255)));
				nengine.Polys.push_back(poly({ i + 1, j + 1, -2 }, { i + 1, j - 1, -2 }, { i - 1, j + 1, -2 }, RGB(0, 0, 255)));
				nengine.Polys.push_back(poly({ i - 1, j - 1, -2 }, { i + 1, j - 1, -2 }, { i - 1, j + 1, -2 }, RGB(0, 128, 255)));
			}
			else {
				nengine.Polys.push_back(poly({ i + 1, j + 1, 2 }, { i + 1, j - 1, 2 }, { i + 1, j + 1,-2 }, RGB(0, 255, 0)));
				nengine.Polys.push_back(poly({ i + 1, j + 1, 2 }, { i + 1, j - 1,-2 }, { i + 1, j + 1,-2 }, RGB(0, 255, 0)));
				
				nengine.Polys.push_back(poly({ i - 1, j + 1, 2 }, { i - 1, j - 1, 2 }, { i - 1, j + 1,-2 }, RGB(0, 255, 0)));
				nengine.Polys.push_back(poly({ i - 1, j + 1, 2 }, { i - 1, j - 1,-2 }, { i - 1, j + 1,-2 }, RGB(0, 255, 0)));
				///////////////////////
				nengine.Polys.push_back(poly({ i + 1, j + 1, 2 }, { i - 1, j + 1, 2 }, { i + 1, j + 1,-2 }, RGB(255, 0, 0)));
				nengine.Polys.push_back(poly({ i + 1, j + 1, 2 }, { i - 1, j + 1,-2 }, { i + 1, j + 1,-2 }, RGB(255, 0, 0)));

				nengine.Polys.push_back(poly({ i + 1, j - 1, 2 }, { i - 1, j - 1, 2 }, { i + 1, j - 1,-2 }, RGB(255, 0, 0)));
				nengine.Polys.push_back(poly({ i + 1, j - 1, 2 }, { i - 1, j - 1,-2 }, { i + 1, j - 1,-2 }, RGB(255, 0, 0)));
			}
		}
	}
	while (true) {
		nengine.draw();
	}
}