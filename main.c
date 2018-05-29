#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "methodes.h"

int main(int argc, char **argv){
	printf("Debut de l'algorithme\n");
	printf("*********************\n");
	printf("Lecture des donnees\n");

	FILE *in = fopen("texte.txt", "rt");
	FILE *out = fopen("reponse.txt", "wt");

	char ligne[255];
	fgets(ligne, 255, in);
	double epsilon;
	sscanf(ligne, "%lf", &epsilon);

	fgets(ligne, 255, in);
	unsigned int Nmax;
	sscanf(ligne, "%d", &Nmax);

	fgets(ligne, 255, in);
	double x1;
	sscanf(ligne, "%lf", &x1);

	fgets(ligne, 255, in);
	double x2;
	sscanf(ligne, "%lf", &x2);

	fgets(ligne, 255, in);
	double x0;
	sscanf(ligne, "%lf", &x0);
	printf("%lf\n%d\n%lf\n%lf\n",epsilon,Nmax,x1,x2);

	double *t = (double*)malloc((4)*sizeof(double));
	fclose(in);

	printf("*********************\n");
	printf("Code erreur\n 0 : aucune erreur\n 10 : divergence de la methode\n 20 : division par 0\n 30 : racine d'un nombre negatif\n\n");
	fprintf(out, "Code erreur\n 0 : aucune erreur\n 10 : divergence de la methode\n 20 : division par 0\n 30 : racine d'un nombre negatif\n\n");

	dicotomie(epsilon, Nmax, x1, x2, t);
	printf("Resultat de la dichotomie :\n Racine : %lf\n Nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);
	fprintf(out, "Resultat de la dichotomie :\n racine : %lf\n nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);

	point_fixe(epsilon, Nmax, x0, t);
	printf("Resultat du point fixe :\n Racine : %lf\n Nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);
	fprintf(out, "Resultat du point fixe 1 :\n racine : %lf\n nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);

	Newton_Raphson(epsilon, Nmax, x0, t);
	printf("Resultat de Newton-Raphson :\n Racine : %lf\n Nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);
	fprintf(out, "Resultat de Newton-Raphson :\n racine : %lf\n nombre d'iterations : %d\n Erreur : %lf\n Code erreur : %d\n\n", t[0], (unsigned int)t[1], t[2], (int)t[3]);

	fclose(out);
	free(t);
	printf("Fin\nAppuyer sur entrer pour quitter.\n");
	getchar();

	return 0;
}
