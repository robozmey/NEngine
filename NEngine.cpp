#include "NEngine.h"
#pragma optimize( "", on)

int NEngine::trace(ray Ray, poly Poly) {
	double a, b, c, d, e, f, g, h, i, l, o, p, q, la_1, la_2, la;

	int x = 0;
	while (Poly.K1[x % 3] == 0) x++;
	a = Ray.K[x % 3] / Poly.K1[x%3];
	b = -Poly.K2[x % 3] / Poly.K1[x % 3];
	c = (Ray.M[x % 3] + Poly.M[x % 3]) / Poly.K1[x % 3];
	d = b * Poly.K1[(x + 1) % 3] + Poly.K2[(x+1) % 3];
	e = Ray.K[(x + 1) % 3] - a * Poly.K1[(x + 1) % 3];
	f = Ray.M[(x + 1) % 3] - Poly.M[(x + 1) % 3] - Poly.K1[(x + 1) % 3] * c;
	g = a + b * e / d;
	h = b * f / d + c;
	i = Poly.K1[(x + 2) % 3] * g / Ray.K[(x + 2) % 3];
	l = Poly.K1[(x + 2) % 3] * h / Ray.K[(x + 2) % 3];
	o = Poly.K2[(x + 2) % 3] * e / Ray.K[(x + 2) % 3] / d;
	p = Poly.K2[(x + 2) % 3] * f / Ray.K[(x + 2) % 3] / d;
	q = (Poly.M[(x + 2) % 3] - Ray.M[(x + 2) % 3]) / Ray.K[(x + 2) % 3];

	la = (l + p + q) / (1 - i - o);
	la_2 = e / d * la + f / d;
	la_1 = g * la + h;

	if (la_1 >= 0 && la_2 >= 0 && la_2 <= 1 - la_1) {
		return Poly.color;
	}
	else {
		return 0;
	}
}
double NEngine::cross(ray Ray, poly Poly) {
	double a, b, c, d, e, f, g, h, i, l, o, p, q, la_1, la_2, la;

	int x = 0;
	while (Poly.K1[x % 3] == 0) x++;
	a = Ray.K[x % 3] / Poly.K1[x % 3];
	b = -Poly.K2[x % 3] / Poly.K1[x % 3];
	c = (Ray.M[x % 3] + Poly.M[x % 3]) / Poly.K1[x % 3];
	d = b * Poly.K1[(x + 1) % 3] + Poly.K2[(x + 1) % 3];
	e = Ray.K[(x + 1) % 3] - a * Poly.K1[(x + 1) % 3];
	f = Ray.M[(x + 1) % 3] - Poly.M[(x + 1) % 3] - Poly.K1[(x + 1) % 3] * c;
	g = a + b * e / d;
	h = b * f / d + c;
	i = Poly.K1[(x + 2) % 3] * g / Ray.K[(x + 2) % 3];
	l = Poly.K1[(x + 2) % 3] * h / Ray.K[(x + 2) % 3];
	o = Poly.K2[(x + 2) % 3] * e / Ray.K[(x + 2) % 3] / d;
	p = Poly.K2[(x + 2) % 3] * f / Ray.K[(x + 2) % 3] / d;
	q = (Poly.M[(x + 2) % 3] - Ray.M[(x + 2) % 3]) / Ray.K[(x + 2) % 3];

	la =  (l + p + q) / (1 - i - o);
	la_2 = (d == 0 ? 0 : e / d) * la + (d == 0 ? 0 : f / d);
	la_1 = g * la + h;

	if (la_1 >= 0 && la_2 >= 0 && la_2 <= 1 - la_1) {
		return la;
	}
	else {
		return -1;
	}

}

void NEngine::draw() {
	myconsole = GetConsoleWindow();

	mydc = GetDC(myconsole);

	for (double i = 0.5; i < height+0.5; i++) {
		for (double j = 0.5; j < width+0.5; j++) {
			ray nRay = ray({ 0, 0, 0 }, { distance, double(j) - width / 2, double(i) - height / 2 });
			COLORREF color = RGB(128,10,10);
			double mn = 1000;
			for (auto pl : Polys) {
				COLORREF c_color = trace(nRay, pl);
				double r = cross(nRay, pl);
				if (r > 0 && r < mn) {
					mn = r;
					color = c_color;
				}
			}
			int bl = 3;
			for (int i1 = 0; i1 < bl; i1++) {
				for (int j1 = 0; j1 < bl; j1++) {
					SetPixel(mydc, j * bl + j1, (height + 0.5) * bl - i * bl - i1, color);
				}
			}

			//ReleaseDC(myconsole, mydc);
			//nengine.Screen.setpixel(i, j, color);
			//cout << color;
		}
	}
	//ReleaseDC(myconsole, mydc);
}

NEngine::NEngine(int _dims)
{
	dims = _dims;
	width = 80;
	height = 60;
	distance = width/2;
}


NEngine::~NEngine()
{
}
