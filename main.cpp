#include<iostream>
#include"NEngine.h"
#pragma optimize( "", on)
int main(int arg, char** args) {
	vector <int> a[5];
	a[0] = { 0, 0, 0, 0, 0 };
	a[1] = { 0, 0, 0, 0, 0 };
	a[2] = { 1, 0, 1, 1, 1 };
	a[3] = { 1, 0, 1, 1, 1 };
	a[4] = { 0, 0, 0, 0, 0 };
	
	//cin.ignore();
	NEngine nengine(3);
	//std::vector<double> x(3), y(3), z(3);
	int sz = 2;
	int t = 0;
	int h = 4;
	//nengine.Polys.push_back(poly({ -1, 1, 2 }, { 1, 1, 2 }, { 1, 1,-2 }, RGB(0, 255, 0)));
	for (double i = t; i <= h; i++) {
		for (double j = -sz; j <= sz; j++) {
			if ((i == 0 && j == 0) || !a[int(i)][int(j) + sz]) {
				//i += 1;
				i *= -2;
				j *= -2;
				nengine.Polys.push_back(poly({ i - 1, j + 1, 1 }, { i + 1, j - 1, 1 }, { i + 1, j + 1, 1 }, RGB(0, 0, 255)));
				nengine.Polys.push_back(poly({ i - 1, j - 1, 1 }, { i + 1, j - 1, 1 }, { i - 1, j + 1, 1 }, RGB(0, 128, 255)));
				nengine.Polys.push_back(poly({ i - 1, j + 1, -1 }, { i + 1, j - 1, -1 }, { i + 1, j + 1, -1 }, RGB(0, 0, 255)));
				nengine.Polys.push_back(poly({ i - 1, j - 1, -1 }, { i + 1, j - 1, -1 }, { i - 1, j + 1, -1 }, RGB(0, 128, 255)));
				//nengine.Polys.push_back(poly({ i - 1, j - 1, -2 }, { i + 1, j - 1, -2 }, { i - 1, j + 1, -2 }, RGB(0, 128, 255)));
				i /= -2;
				j /= -2;
				//i -= 1;
			}
			else {
				i *= -2;
				j *= -2;
				nengine.Polys.push_back(poly({ i - 1.00001, j + 1.00002, 1.00003 }, { i - 1, j + 1, -2 }, { i - 1.00007, j - 1.00008, -1.00009 }, RGB(0, 128, 0)));
				nengine.Polys.push_back(poly({ i - 1.00001, j + 1.00002, 1.00003 }, { i - 1, j - 1,  2 }, { i - 1.00007, j - 1.00008, -1.00009 }, RGB(0, 255, 0)));

				i /= -2;
				j /= -2;
			
			}
		}
	}
	while (true) {
		nengine.draw();
	}
}