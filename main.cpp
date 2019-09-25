#include<iostream>
#include"NEngine.h"
#include"models.h"
#include<ctime>
#pragma optimize( "", on)
int main(int arg, char** args) {

	
	//cin.ignore();
	NEngine nengine(3);
    
    models _models;
    
    nengine.Polys = _models.lab();
	//std::vector<double> x(3), y(3), z(3);
	//nengine.Polys.push_back(poly({ -1, 1, 2 }, { 1, 1, 2 }, { 1, 1,-2 }, RGB(0, 255, 0)));
	
    
    clock_t t_prv = clock(), t_cur;
    double phi = 0.0, dt;
	while (true) {
        t_cur = clock();
        phi += (double)(t_cur-t_prv)/CLOCKS_PER_SEC*0.2;
        t_prv = t_cur;
        nengine.draw();
        nengine.cam_az = phi;
        SDL_Delay(50);
	//return 0;
	}
    return 0;
}
