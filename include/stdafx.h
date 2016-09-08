#ifndef _STDAFX_H_
#define _STDAFX_H_

#include <iostream>

#define SIMULATION_2D 1
//#define CONNECTED 1
//#define OBSTACLE 1
//#define OUTPUT 1
#define GAUSS_SEIDEL 1

#ifdef SIMULATION_2D
	#define _W 100
	#define _H 100
	#define _L 1.0
	//#define VISBLEW 1200
	#define GRIDSIZE 6
	#define DIFFUSION 0.001
	#define VISCOSITY 0.001
	#define TIMESTEP 0.01
	#define ITERATION 30
	#define FRAMERATE 32
	#define DRAGSCALE 100
	#define FLOWTIME 1000//1
	#define DENSITY 300
	#define SPEED 4000
	#define OBSTACLEX 30
	#define LICL 30
	//The viscosity matters a lot, when you decrease visc, you should also decrease speed

#ifdef CONNECTED
	#define IX(x, y) ( (x) == 0? _W + (y) * (_W+2) : ((x) == _W+1? 1 + (y) * (_W+2) : (x) + (y) * (_W+2)) )
#else	
	#define IX(x, y) ( (x) + (y) * (_W+2) )
#endif
	#define IX2(x, y) ( (x) + (y) * (_W*GRIDSIZE+2) )
	#define BOUNDED(x, y) ( ((x) < 1 || (x) > _W+1 || (y) < 1 || (y) > _H+1)? false : true)
	
	//int IX(float x, float y);
#else
	#define _N 40
	#define GRIDSIZE 20
	#define DIFFUSION 0.0001
	#define VISCOSITY 0.0001
	#define TIMESTEP 0.01
	#define ITERATION 10
	#define FRAMERATE 32

	#define IX(x, y, z) ((x) + (y)*(_N+2) + (z)*(_N+2)*(_N+2) )
#endif

#define PI 3.14159265
#define LENGTH _N*GRIDSIZE
//#define eps 1e-10
#define SWAP(x0, x) {float *tmp = x0; x0 = x; x = tmp;}

//system output defines
#define REPORT(X) std::cout << #X << ": " << X << std::endl
#define PRINT(X) std::cout << X << std::endl
#define PRINT_ONELINE(X) std::cout << X

#endif

//Best for vortex street connected
/*
	#define _W 600
	#define _H 100
	#define _L 1.0
	#define VISBLEW 1200
	#define GRIDSIZE 3
	#define DIFFUSION 0.01
	#define VISCOSITY 0.01
	#define TIMESTEP 0.01
	#define ITERATION 30
	#define FRAMERATE 32
	#define DRAGSCALE 100
	#define FLOWTIME 10
	#define DENSITY 100
	#define SPEED 20000
	#define OBSTACLEX 30
	#define LICL 30
*/

//Best for vortex street not connected
/*
	#define _W 150
	#define VISBLEW 1500
	#define _H 30
	#define GRIDSIZE 10
	#define DIFFUSION 0.01
	#define VISCOSITY 0.01
	#define TIMESTEP 0.01
	#define ITERATION 10
	#define FRAMERATE 32
	#define DRAGSCALE 100
	#define FLOWTIME 20
	#define DENSITY 100
	#define SPEED 200
*/

//Best for gas
/*
	#define _W 200
	#define _H 200
	#define _L 1.0
	//#define VISBLEW 1200
	#define GRIDSIZE 3
	#define DIFFUSION 0.001
	#define VISCOSITY 0.001
	#define TIMESTEP 0.01
	#define ITERATION 30
	#define FRAMERATE 32
	#define DRAGSCALE 100
	#define FLOWTIME 1
	#define DENSITY 300
	#define SPEED 4000
	#define OBSTACLEX 30
	#define LICL 30
*/