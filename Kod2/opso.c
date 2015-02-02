#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "funkcije.h"
#include "algoritmi.h"
#include "mt64.h"

void OPSO(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_opso, double* g_best_opso, double omega, double ro_p, double ro_g, int e)
{
	//counters
	int i, j, k; 
	//other var
	double border_tmp = border_h - border_l;
	int sort_bool;
	//MT init
	clock_t now;
	now = time(NULL);
	init_genrand64(now);
	FILE *test;
	test=fopen("results/test.txt", "w");
	
	//alg param	
	double r_p, r_g, g_best_tmp, g_best_tmp1, okolina_h, okolina_l, epsilon = 1;
	double **cestica, **cestica_best, *cestica_g_best, **brzina, *cestica_val, **loc_sea;
	int  *sort_pos;
		
	/*init param:
	 * cestica
	 * brzina
	 * cestica_best
	 * cestica_g_best
	 * g_best_opso 
	 * loc_sea
	 * sort_pos*/
	cestica_g_best = (double*)malloc(sizeof(double*)*dim);
	cestica = (double **) malloc(sizeof(double*)*n); 
	cestica_best = (double **) malloc(sizeof(double*)*n);
	brzina = (double **) malloc(sizeof(double*)*n);
	loc_sea = (double **) malloc(sizeof(double*)*(e*dim));
	sort_pos = malloc(n*sizeof(int));
	cestica_val = (double*)malloc(sizeof(double*)*n);
	
	for( i = 0 ; i < n ; i++ )
	{
		cestica[i] = (double *) malloc(sizeof(double*)*dim);
		cestica_best[i] = (double *) malloc(sizeof(double*)*dim);
		brzina[i] = (double *) malloc(sizeof(double*)*dim);
		sort_pos[i] = i;
	}
	
	for( i = 0 ; i < e*dim ; i++ )
		loc_sea[i] = (double *) malloc(sizeof(double*)*dim);

	if(border_tmp < 0)
		border_tmp = border_tmp * -1;
	
	for( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < dim ; j++ )
		{
			cestica[i][j] = border_l + genrand64_real1() * (border_h - border_l);
			brzina[i][j] = border_l + genrand64_real1() * (border_h - border_l);
			cestica_best[i][j] = cestica[i][j];
		}
		ispitaj_vrijednost(&cestica_val[i], funkcija, dim, cestica[i]);
	}

	do
	{
		r_p = genrand64_real1();
		r_g = genrand64_real1();
		sort_bool = 1;
		
		//bubble sort to find e best
		while (sort_bool > 0)
		{
			sort_bool = 0;
			for( i = 0 ; i < (n-1) ; i++ )
			{
				if(cestica_val[i] > cestica_val[i+1])
				{
					g_best_tmp = cestica_val[i+1]; //g_best_tmp used as normal tmp var
					sort_bool = sort_pos[i+1]; //sort_bool used as normal tmp var
					cestica_val[i+1] = cestica_val[i];
					sort_pos[i+1] = sort_pos[i];
					cestica_val[i] = g_best_tmp;
					sort_pos[i] = sort_bool;
				}
			}
		}
		
		for(i=0; i<n;i++)
		{
			for(j=0; j<dim; j++)
			{
				fprintf(test, "%lf ", cestica[i][j]);
			}
			fprintf(test, "\n");
		}
		fprintf(test, "\n");
		for(j=0; j<n; j++)
		{
			fprintf(test, "%lf ", cestica_val[j]);
		}
		fprintf(test, "\n");
		for(j=0; j<n; j++)
		{
			fprintf(test, "%d ", sort_pos[j]);
		}
		
		
		*g_best_opso = cestica_val[0]; 	
		for( i = 0 ; i < dim ; i++ )
			cestica_g_best[i] = cestica[sort_pos[0]][i];
		
		//orbital search for e best cestica
		for( i = 0 ; i < e ; i++ )
		{
			for(j = 0 ; j < dim ; j++ )
			{
				for( k = 0 ; k < dim ; k++ )
				{
					if( j == k )
						loc_sea[(i*dim)+j][k] = cestica[sort_pos[i]][k];
					else
					{
						okolina_h = cestica[sort_pos[i]][k] + epsilon;
						okolina_l = cestica[sort_pos[i]][k] - epsilon;
						loc_sea[(i*dim)+j][k] = okolina_l + genrand64_real1()*(okolina_h - okolina_l);
					}
				}
								
				//refresh cestica, cestica_best
				ispitaj_vrijednost(&g_best_tmp, funkcija, dim, loc_sea[(i*dim)+j]);
				
				if ( g_best_tmp < cestica_val[i] )
				{
					for (k = 0 ; k < dim ; k++ )
					{
						cestica[sort_pos[i]][k] = loc_sea[(i*dim)+j][k];
					} 
					
					ispitaj_vrijednost(&g_best_tmp1, funkcija, dim, cestica_best[sort_pos[i]]);
					
					if( g_best_tmp1 < g_best_tmp )
						for ( k = 0 ; k < dim ; k++ )
							cestica_best[sort_pos[i]][k] = loc_sea[(i*dim)+j][k];
				}
				
				//refresh g_best_opso, cestica_g_best
				if( g_best_tmp < *g_best_opso )
				{
					*g_best_opso = g_best_tmp;
					
					for ( k = 0 ; k < dim ; k++ )
						cestica_g_best[k] = loc_sea[(i*dim)+j][k];
				}
			}
		}
		
		//update velocity and new particle position
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ;j < dim ; j++ )
			{
				brzina[i][j] = omega*brzina[i][j] + ro_p*r_p*(cestica_best[i][j]-cestica[i][j]) + ro_g*r_g*(cestica_g_best[j]-cestica[i][j]); 
				
				if(cestica[i][j] + brzina[i][j] > border_l && cestica[i][j] + brzina[i][j] < border_h)
					cestica[i][j] = cestica[i][j] + brzina[i][j];
				else
				{
					cestica[i][j] = border_l + genrand64_real1() * (border_h - border_l);
					brzina[i][j] = border_l + genrand64_real1() * (border_h - border_l);
				}
			}
			
			ispitaj_vrijednost(&cestica_val[i], funkcija, dim, cestica[i]);
						
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
			if(g_best_tmp1 < *g_best_opso)
			{
				*g_best_opso = g_best_tmp1;
			
				for( k = 0 ; k < dim ; k++ )
					cestica_g_best[k] = cestica[i][k];
			}
			
			sort_pos[i] = i;
		}
		fprintf(test, "\n");
		for(i=0; i<e*dim;i++)
		{
			for(j=0; j<dim; j++)
			{
				fprintf(test, "%lf ", loc_sea[i][j]);
			}
			fprintf(test, "\n");
		}
		fprintf(test, "\n----------------------------------\n");
				
		*tren_iter_opso = *tren_iter_opso + 1;	
	}while(*tren_iter_opso < br_iter && (*g_best_opso >= f_best+greska || *g_best_opso <= f_best-greska));
	
	
	//free malloc memory
	for( i = 0 ; i < n ; i++)
	{
		free(cestica[i]);
		free(cestica_best[i]);
		free(brzina[i]);
	}
	
	for( i = 0; i < e*dim ; i++)
		free(loc_sea[i]);
	
	free(cestica);
	free(cestica_best);
	free(brzina);
	free(cestica_g_best);
	free(loc_sea);
	free(sort_pos);
	fclose(test);
}
