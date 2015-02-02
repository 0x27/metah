#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "funkcije.h"
#include "algoritmi.h"
#include "mt64.h"

void set_function(int funkcija, int* dim, double* f_best, double* border_l, double* border_h, double* greska);

int main()
{
	int funkcija, br_iter = 5000, br_pon = 2, n = 10,e=10;
	double omega = 0.7, ro_p =1.4, ro_g =1.4;
	int dim, i;
	double f_best, greska, border_l, border_h;
	int tren_iter_pso;
	double g_best_pso;
	double cpu_time_used;
	clock_t start, end;
	FILE *test;
	test = fopen("results/test.txt", "w");
	
	for( funkcija = 1 ; funkcija <= 10 ; funkcija= funkcija + 1 )
	{
		set_function(funkcija, &dim, &f_best, &border_l, &border_h, &greska);
		fprintf(test, "%d\n", funkcija);
		for( n = 100 ; n < 160 ; n = n + 10 )
		{
			fprintf(test, "\t%d\t%d\t%lf\t%lf\t%lf\t%d\n", funkcija, n, omega, ro_p, ro_g,e);
						for( i = 0 ; i < br_pon ; i++ )
						{
							tren_iter_pso = 0;
							start = clock();
							OPSO(funkcija, br_iter, n, dim, f_best, greska, border_l, border_h, &tren_iter_pso, &g_best_pso, omega, ro_p, ro_g,e);
							end = clock();
							cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
							
							fprintf(test, "\t\t%12.10f\t%lf\t%d\t%lf\n", g_best_pso, f_best, tren_iter_pso, cpu_time_used);
						}
					
		}
	}
	
	fclose(test);
	
	return 0;
}

//set function variables
void set_function(int funkcija, int* dim, double* f_best, double* border_l, double* border_h, double* greska)
{
	switch (funkcija)
	{
		case 1 :
			*dim = sphere_set(0);
			*f_best = sphere_set(1);
			*border_l = sphere_set(2);
			*border_h = sphere_set(3);
			*greska = sphere_set(4);
			break;
		case 2 :
			*dim = rosenbrock_set(0);
			*f_best = rosenbrock_set(1);
			*border_l = rosenbrock_set(2);
			*border_h = rosenbrock_set(3);
			*greska = rosenbrock_set(4);
			break;
		case 3 :
			*dim = step_set(0);
			*f_best = step_set(1);
			*border_l = step_set(2);
			*border_h = step_set(3);
			*greska = step_set(4);
			break;
		case 4 :
			*dim = quartic_set(0);
			*f_best = quartic_set(1);
			*border_l = quartic_set(2);
			*border_h = quartic_set(3);
			*greska = quartic_set(4);
			break;
		case 5 :
			*dim = shekel_set(0);
			*f_best = shekel_set(1);
			*border_l = shekel_set(2);
			*border_h = shekel_set(3);
			*greska = shekel_set(4);
			break;
		case 6 :
			*dim = schaffer_set(0);
			*f_best = schaffer_set(1);
			*border_l = schaffer_set(2);
			*border_h = schaffer_set(3);
			*greska = schaffer_set(4);
			break;
		case 7 :
			*dim = rastrigin_set(0);
			*f_best = rastrigin_set(1);
			*border_l = rastrigin_set(2);
			*border_h = rastrigin_set(3);
			*greska = rastrigin_set(4);
			break;
		case 8 :
			*dim = griewank_set(0);
			*f_best = griewank_set(1);
			*border_l = griewank_set(2);
			*border_h = griewank_set(3);
			*greska = griewank_set(4);
			break;
		case 9 :
			*dim = hypell_set(0);
			*f_best = hypell_set(1);
			*border_l = hypell_set(2);
			*border_h = hypell_set(3);
			*greska = hypell_set(4);
			break;
		case 10 :
			*dim = ackley_set(0);
			*f_best = ackley_set(1);
			*border_l = ackley_set(2);
			*border_h = ackley_set(3);
			*greska = ackley_set(4);
			break;
		default:
			printf("ERROR function set main!\n");
	}
};
