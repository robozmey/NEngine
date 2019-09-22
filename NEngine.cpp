#include "NEngine.h"
#include<algorithm>


#pragma optimize( "", on)

double a, b, c, d, e, f, g, h, i, l, o, p, q, la_1, la_2, la;

vector <int> x = { 0, 1, 2 };

COLORREF color = RGB(128, 10, 10);
COLORREF c_color;
double r;
double mn = 1000;
bool is_found;
SDL_Rect rect;

void NEngine::trace(const ray &Ray,const poly &Poly, COLORREF &c_color, double &r) {
	//while (true) {
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
	//	break;
	//}
	la_2 = e / d * la + f / d;
	la_1 = g * la + h;

	if (la_1 >= 0 && la_2 >= 0 && la_2 <= 1 - la_1) {
		c_color = Poly.color;
		r = la;
	}
	else {
		c_color = 0;
		r = -1;
	}
}


void NEngine::draw() {
	double i, j;
	ray nRay;
	while (true) {
		
		for (i = 0.0001; i < height; i++) {
			for (j = 0.0001; j < width; j++) {
				nRay = ray({ cam_x, cam_y, 0 }, { cam_x + distance * cos(cam_az) + (j - width / 2) * sin(cam_az),
													  cam_y + distance * sin(cam_az) + (j - width / 2) * cos(cam_az), 
													  cam_z + i - height / 2 });
				mn = 1000;
				is_found = 0;
				for (auto &pl : Polys) {
					
					
					trace(nRay, pl, c_color, r);
					//double r =
					if (r > 0 && r < mn) {
						mn = r;
						color = c_color;
						is_found = 1;
					}
				}
				//cout << (i < 1 && j < 1 ? "s" : "");
			//	int bl = 1;

				if (is_found) {
					//for (int i1 = 0; i1 < h_x; i1++) {
					//	for (int j1 = 0; j1 < w_x; j1++) {
					SDL_SetRenderDrawColor(renderer, GetRValue(color), GetGValue(color), GetBValue(color), 255);

					//SDL_RenderClear(renderer);
					//SDL_RenderDrawPoint(renderer, i, i);

					
					rect.x = j * w_x;
					rect.y = height * h_x - i * h_x - h_x + 1;
					rect.w = w_x;
					rect.h = h_x;

					SDL_RenderFillRect(renderer, &rect);

					//SDL_RenderDrawPoint(renderer, int(j * w_x + j1), int((height)* h_x - i * h_x - i1));
					SDL_RenderPresent(renderer);
					//SetPixel(mydc, j * bl + j1, (height) * bl - i * bl - i1, color);


				}

				//ReleaseDC(myconsole, mydc);
				//nengine.Screen.setpixel(i, j, color);
				//cout << color;
			}
		}
	}
	//ReleaseDC(myconsole, mydc);
}

NEngine::NEngine(int _dims)
{
	
	dims = _dims;

	distance = width/2 / atan(fov);


	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * w_x, height * h_x, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_RenderDrawPoint(renderer,100, 100);
	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

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
