#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "funkcije.h"
#include "algoritmi.h"
#include "mt64.h"

void set_function(int funkcija, int* dim, double* f_best, double* border_l, double* border_h, double* greska);

int main(int argc, char* argv[])
{
		
	//variables from argument
	int funkcija = atoi(argv[1]);
	int br_iter = atoi(argv[2]);
	int br_pon = atoi(argv[3]);
	int n = atoi(argv[4]);
	double omega = atof(argv[5]);
	double ro_p = atof(argv[6]);
	double ro_g = atof(argv[7]);
	int m = atoi(argv[8]);
	int e = atoi(argv[9]);
	//variables for function
	int dim;
	double f_best, greska, border_l, border_h;
	
	//output variables
	int tren_iter_pso, tren_iter_abc, tren_iter_opso;
	double g_best_pso, g_best_abc, g_best_opso;
	double cpu_time_used;
	FILE *pso, *abc, *opso;
	//help variables	
	int i;
	clock_t start, end, start_time, end_time;
	
	set_function(funkcija, &dim, &f_best, &border_l, &border_h, &greska);
	pso = fopen("results/pso.txt", "w");
	abc = fopen("results/abc.txt", "w");
	opso = fopen("results/opso.txt", "w");
	
	//agorithm call
	for( i = 0 ; i < br_pon ; i++ )
	{
		tren_iter_pso = tren_iter_abc = tren_iter_opso = 0;
		
		//printf("%d\n", i);
		
		start_time = time(NULL);
		start = clock();
		PSO(funkcija, br_iter, n, dim, f_best, greska, border_l, border_h, &tren_iter_pso, &g_best_pso, omega, ro_p, ro_g);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		//printf("PSO: %12.10f\t%d\t%lf\t%lf\n", g_best_pso, tren_iter_pso, cpu_time_used);
		fprintf(pso, "%lf\t%d\t%lf\t%lf\n", g_best_pso, tren_iter_pso, cpu_time_used, f_best-g_best_pso);
		
		start = clock();
		ABC(funkcija, br_iter, n, dim, f_best, greska, border_l, border_h, &tren_iter_abc, &g_best_abc, m, e);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		//printf("ABC: %lf\t%d\t%lf\n", g_best_abc, tren_iter_abc, cpu_time_used);
		fprintf(abc, "%lf\t%d\t%lf\t%lf\n", g_best_abc, tren_iter_abc, cpu_time_used, f_best-g_best_abc);
		
		start = clock();
		OPSO(funkcija, br_iter, n, dim, f_best, greska, border_l, border_h, &tren_iter_opso, &g_best_opso, omega, ro_p, ro_g, e);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	      //printf("OPSO: %lf\t%d\t%lf\n", g_best_opso, tren_iter_opso, cpu_time_used);
		fprintf(opso, "%lf\t%d\t%lf\t%lf\n", g_best_opso, tren_iter_opso, cpu_time_used, f_best-g_best_opso);
		
		//change MT seed
		end_time = time(NULL);
		cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
		if(cpu_time_used < 1)
			sleep(1);
	}
	fclose(pso);
	fclose(abc);
	fclose(opso);
	printf("1"); //da shell_exec zna da je gotovo
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
