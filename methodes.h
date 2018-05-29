#ifndef _METHODES_
#define _METHODES_

void dicotomie(double epsilon, unsigned int Nmax, double x1, double x2, double* t);

void point_fixe(double epsilon, unsigned int Nmax, double x0, double* t);

void Newton_Raphson(double epsilon, unsigned int Nmax, double x0, double* t);

#endif