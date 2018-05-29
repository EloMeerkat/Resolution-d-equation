#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fonctions.h"

double f(double x){
	return (1.85/sqrt(x) - 3.4 - 1.2*x*x*x);
}

double g1(double x){
	return (1.85/(3.4+1.2*x*x*x)) * (1.85/(3.4+1.2*x*x*x));
}

double f_prim(double x){
	return (-0.925/pow(x,3/2) - 3.6*x*x);
}
