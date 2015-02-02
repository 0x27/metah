#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "funkcije.h"
#include "algoritmi.h"
#include "mt64.h"

void PSO(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_pso, double* g_best_pso, double omega, double ro_p, double ro_g)
{
	//counters
	int i, j, k; 
	//other var
	double border_tmp = border_h - border_l;
	//MT init
	clock_t now;
	now = time(NULL);
	init_genrand64(now);
		
	//alg param	
	double r_p, r_g, g_best_tmp, g_best_tmp1;
	double **cestica, **cestica_best, *cestica_g_best, **brzina;
	
	/*init param:
	 * cestica
	 * brzina
	 * cestica_best
	 * cestica_g_best
	 * g_best_pso */
	
	cestica_g_best = (double*)malloc(sizeof(double*)*dim);
	cestica = (double **) malloc(sizeof(double*)*n); 
	cestica_best = (double **) malloc(sizeof(double*)*n);
	brzina = (double **) malloc(sizeof(double*)*n);
	
	for( i = 0 ; i < n ; i++ )
	{
		cestica[i] = (double *) malloc(sizeof(double*)*dim);
		cestica_best[i] = (double *) malloc(sizeof(double*)*dim);
		brzina[i] = (double *) malloc(sizeof(double*)*dim);
	}

	if(border_tmp < 0)
		border_tmp = border_tmp * -1;
	
	for( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < dim ; j++ )
		{
			cestica[i][j] = border_l + genrand64_real1() * (border_h - border_l);
			brzina[i][j] = -1 * border_tmp + genrand64_real1() * border_tmp;
			cestica_best[i][j] = cestica[i][j];
		}
	}
	
	for ( j = 0 ; j < dim ; j++ )
		cestica_g_best[j] = cestica[0][j];

	ispitaj_vrijednost(g_best_pso, funkcija, dim, cestica_g_best);
	
	for( i = 1 ; i < n ; i++ )
	{
		ispitaj_vrijednost(&g_best_tmp, funkcija, dim, cestica[i]);
		if (*g_best_pso > g_best_tmp)
		{
			*g_best_pso = g_best_tmp;
			
			for( k = 0 ; k < dim ; k++ )
				cestica_g_best[k] = cestica[i][k];
		}
	}
	
	//main algorithm
	do
	{
		r_p = genrand64_real1();
		r_g = genrand64_real1();
		
		//update velocity and new particle position
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ;j < dim ; j++ )
			{
				brzina[i][j] = omega*brzina[i][j] + ro_p*r_p*(cestica_best[i][j]-cestica[i][j]) + ro_g*r_g*(cestica_g_best[j]-cestica[i][j]);
				//get particle back in domain borders
				if(cestica[i][j] + brzina[i][j] > border_l && cestica[i][j] + brzina[i][j] < border_h)
					cestica[i][j] = cestica[i][j] + brzina[i][j];
				else
				{
					if(cestica[i][j] < border_l)
					{	
						g_best_tmp = border_l - cestica[i][j]; //user as normal tmp var
						if(g_best_tmp > 1)
							g_best_tmp *= (-1);
						cestica[i][j] = border_l - g_best_tmp;
					}
					if(cestica[i][j] > border_h)
					{
						g_best_tmp = border_h - cestica[i][j]; //user as normal tmp var
						if(g_best_tmp < 1)
							g_best_tmp *= (-1);
						cestica[i][j] = border_h - g_best_tmp;
					}
					brzina[i][j] = -1 * border_tmp + genrand64_real1() * border_tmp;
				}
			}
			
			//check for new best
			ispitaj_vrijednost(&g_best_tmp, funkcija, dim, cestica_best[i]);
			ispitaj_vrijednost(&g_best_tmp1, funkcija, dim, cestica[i]);
			//new best particle position
			if(g_best_tmp1 < g_best_tmp)
			{
				for ( j = 0; j < dim ; j++ )
				{
					cestica_best[i][j] = cestica[i][j];
				} 
			}
			//new best global value
			if(g_best_tmp1 < *g_best_pso)
			{
				*g_best_pso = g_best_tmp;
			
				for( k = 0 ; k < dim ; k++ )
					cestica_g_best[k] = cestica[i][k];
			}
		}
		
		*tren_iter_pso = *tren_iter_pso + 1;
	}while(*tren_iter_pso < br_iter && (*g_best_pso >= f_best+greska || *g_best_pso <= f_best-greska));
	
	//free malloc memory
	for( i = 0 ; i < n ; i++)
	{
		free(cestica[i]);
		free(cestica_best[i]);
		free(brzina[i]);
	}
	
	free(cestica);
	free(cestica_best);
	free(brzina);
	free(cestica_g_best);
	
}
