#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "methodes.h"
#include "fonctions.h"

void dicotomie(double epsilon, unsigned int Nmax, double x1, double x2, double* t){
	unsigned int N = 0;

	if(x1 < pow(10, -14)){
		x1 = epsilon;
	}
	if(x2 < pow(10, -14)){
		x2 = epsilon;
	}

	double xm = (x1+x2)/2;

	for(int i =0; i<4; i++){
		t[i] = 0;
	}

	while(fabs(x2-x1)/(2*fabs(xm)) > epsilon){
		if(fabs(x1) < pow(10, -14) || fabs(x2) < pow(10, -14)){
			t[3] = 20;
			return;
		}
		else if(x1 < pow(10, -14) || x2 < pow(10, -14)){
			t[3] = 30;
			return;
		}

		xm = (x1+x2)/2;

		if(f(x1)*f(xm) < 0){
			x2 = xm;
		}
		else if(f(xm)*f(x2) < 0){
			x1 = xm;
		}
		else{
			t[3] = 40;
			return;
		}
		N ++;

		if(N > Nmax){
			t[3] = 10;
			return;
		}
	}
	t[0] = xm;
	t[1] = N;
	t[2] = fabs(x2-x1)/(2*fabs(xm));

}

void point_fixe(double epsilon, unsigned int Nmax, double x0, double* t){
	unsigned int N =0;
	double xn, xn_pls1;

	for(int i =0; i<3; i++){
		t[i] = 0;
	}

	xn = x0;
	xn_pls1 = g1(xn);

	while(fabs(xn_pls1 - xn)/fabs(xn) > epsilon){
		
		xn = xn_pls1;
		xn_pls1 = g1(xn);

		N++;
		if(N > Nmax){
			t[2] = 10;
			return;
		}
	}

	t[0] = xn_pls1;
	t[1] = N;
	t[2] = fabs(xn_pls1 - xn)/fabs(xn);
}

void Newton_Raphson(double epsilon, unsigned int Nmax, double x0, double* t){
	unsigned int N=0;
	double xn, xn_pls1;
	
	for(int i =0; i<3; i++){
		t[i] = 0;
	}

	xn = x0 - (f(x0)/f_prim(x0));
	xn_pls1 = xn - (f(xn)/f_prim(xn));

	while(fabs(xn_pls1 - xn)/fabs(xn) > epsilon){

		xn = xn_pls1;
		xn_pls1 = xn - (f(xn)/f_prim(xn));
		//printf("%lf %lf\n",xn, fabs(xn_pls1 - xn)/fabs(xn));

		N++;
		if(N > Nmax){
			t[2] = 10;
			return;
		}
	}

	t[0] = xn_pls1;
	t[1] = N;
	t[2] = fabs(xn_pls1 - xn)/fabs(xn);
}
