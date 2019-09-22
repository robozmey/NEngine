#include "NEngine.h"
#include<algorithm>

#pragma optimize( "", on)

int NEngine::trace(ray Ray, poly Poly) {
	double a, b, c, d, e, f, g, h, i, l, o, p, q, la_1, la_2, la;

	vector <int> x = { 0, 1, 2};
	while (true) {
		//next_permutation(x.begin(), x.end());
		//if (Poly.K1[x[0]] == 0) cout << x[0];
		//if (Poly.K1[x[0]] == 0) continue;

		a = Ray.K[x[0]] / Poly.K1[x[0]];
		b = -Poly.K2[x[0]] / Poly.K1[x[0]];
		c = (Ray.M[x[0]] + Poly.M[x[0]]) / Poly.K1[x[0]];
		d = b * Poly.K1[x[1]] + Poly.K2[x[1]];
		e = Ray.K[x[1]] - a * Poly.K1[x[1]];
		f = Ray.M[x[1]] - Poly.M[x[1]] - Poly.K1[x[1]] * c;
		//if (d == 0) continue;
		g = a + b * e / d;
		h = b * f / d + c;
		//if (Ray.K[x[2]] == 0) cout << "g";
		//if (Ray.K[x[2]] == 0) continue;
		i = Poly.K1[x[2]] * g / Ray.K[x[2]];
		l = Poly.K1[x[2]] * h / Ray.K[x[2]];
		o = Poly.K2[x[2]] * e / Ray.K[x[2]] / d;
		p = Poly.K2[x[2]] * f / Ray.K[x[2]] / d;
		q = (Poly.M[x[2]] - Ray.M[x[2]]) / Ray.K[x[2]];
		//if ((1 - i - o) == 0) cout << "L";
		//if ((1 - i - o) == 0) continue;
		la = (l + p + q) / (1 - i - o);
		break;
	}
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
	//myconsole = GetConsoleWindow();

//	mydc = GetDC(myconsole);
	//SDL_Init(SDL_INIT_EVERYTHING);
	//window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	//renderer = SDL_CreateRenderer(window, -1, 0);
	for (double i = 0.0001; i < height; i++) {
		for (double j = 0.0001; j < width; j++) {
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
			int bl = 1;
			for (int i1 = 0; i1 < bl; i1++) {
				for (int j1 = 0; j1 < bl; j1++) {
					//SDL_SetRenderDrawColor(renderer, GetRValue(color), GetGValue(color), GetBValue(color), 255);

					//SDL_RenderClear(renderer);
					//SDL_RenderDrawPoint(renderer, i, i);
					SDL_RenderDrawPoint(renderer, int(j * bl + j1), int((height)* bl - i * bl - i1));
					//SDL_RenderPresent(renderer);
					//SetPixel(mydc, j * bl + j1, (height) * bl - i * bl - i1, color);
					cout << (i <1  && j <1 ? "s" : "");
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
	width = 320;
	height = 160;
	distance = width/2;


	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderDrawPoint(renderer,100, 100);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);

	//SDL_Delay(3000);

}


NEngine::~NEngine()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
