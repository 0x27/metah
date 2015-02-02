#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "funkcije.h"
#include "algoritmi.h"
#include "mt64.h"

void ABC(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_abc, double* g_best_abc, int m, int e)
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
	FILE *test_abc;
	test_abc=fopen("results/test_abc.txt", "w");

	/*alg param:
	 * cestica: matrix of worker bees [n x dim]
	 * cestica_g_best: possition of best global value [dim]
	 * cestica_val: function values in current iter [n]
	 * sort_pos: keeps track of permutations after sorting cestica_val [n]
	 * loc_sea: matrix of particles in local search [(e*nep+m*nmp)  x dim] 
	 */
	double **cestica, *cestica_g_best, *cestica_val, **loc_sea;
	int  *sort_pos, nep, nmp;
	double g_best_tmp, epsilon, okolina_h, okolina_l;
	nep = 5;
	nmp = 3;
	epsilon = 1;
	
	//init param
	cestica = (double **) malloc(sizeof(double*)*n); 
	loc_sea = (double **) malloc(sizeof(double*)*(e*nep+(m-e)*nmp)); 
	cestica_g_best = (double*)malloc(sizeof(double*)*dim);
	cestica_val = (double*)malloc(sizeof(double*)*n);
	sort_pos = malloc(n*sizeof(int));
	
	for( i = 0 ; i < n ; i++ )
		cestica[i] = (double *) malloc(sizeof(double*)*dim);
	
	for( i = 0 ; i < (e*nep+(m-e)*nmp) ; i++ )
		loc_sea[i] = (double *) malloc(sizeof(double*)*dim);
	
	
		
	if(border_tmp < 0)
		border_tmp = border_tmp * -1;
	
	//set reference g_best_abc and cestica_g_best
	for( j = 0 ; j < dim ; j++ )
	{
		cestica[0][j] = border_l + genrand64_real1() * (border_h - border_l);
		cestica_g_best[j] = cestica[0][j];
	}
	
	ispitaj_vrijednost(g_best_abc, funkcija, dim, cestica_g_best);
	
	//start alogorithm
	do
	{
		sort_bool = 1;
		//set worker bees location
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < dim ; j++ )
			{
				cestica[i][j] = border_l + genrand64_real1() * (border_h - border_l);
			}
			
			ispitaj_vrijednost(&cestica_val[i], funkcija, dim, cestica[i]);
			sort_pos[i] = i;
		}
		
		//bubble sort to find m best locations & refresh g_best_abc and cestica_g_best
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
				fprintf(test_abc, "%lf ", cestica[i][j]);
			}
			fprintf(test_abc, "\n");
		}
		fprintf(test_abc, "\n");
		for(j=0; j<n; j++)
		{
			fprintf(test_abc, "%lf ", cestica_val[j]);
		}
		fprintf(test_abc, "\n");
		for(j=0; j<n; j++)
		{
			fprintf(test_abc, "%d ", sort_pos[j]);
		}
		
		if( *g_best_abc > cestica_val[0] )
		{
			*g_best_abc = cestica_val[0];
			for( i = 0 ; i < dim ; i++ )
				cestica_g_best[i] = cestica[sort_pos[0]][i];
		}
		
		//local search
		for( i = 0 ; i < e ; i++)
		{
			for( j = 0 ; j < nep ; j++)
			{
				for( k = 0 ; k < dim ; k++ )
				{
					okolina_h = cestica[sort_pos[i]][k] + epsilon;
					okolina_l = cestica[sort_pos[i]][k] - epsilon;
					loc_sea[i*nep+j][k] = okolina_l + genrand64_real1()*(okolina_h - okolina_l);
				}
			}
		}
		
		for( i = e; i < m ; i++ )
		{
			
			for( j = 0 ; j < nmp ; j++)
			{	
				for( k = 0 ; k < dim ; k++ )
				{
					okolina_h = cestica[sort_pos[i]][k] + epsilon;
					okolina_l = cestica[sort_pos[i]][k] - epsilon;
					loc_sea[e*nep+(i-e)*nmp+j][k] = okolina_l + genrand64_real1()*okolina_h;
					
				}
			}
		}

		//refreh g_best_abc and cestica_g_best
		for( i = 0 ; i < (e*nep+(m-e)*nmp) ; i++ )
		{
			ispitaj_vrijednost(&g_best_tmp, funkcija, dim, loc_sea[i]);
			if(g_best_tmp < *g_best_abc)
			{
				*g_best_abc = g_best_tmp;
				for( j = 0 ; j < dim ; j++)
					cestica_g_best[j] = loc_sea[i][j];
			}
		}
		
		fprintf(test_abc, "\n");
		for(i=0; i<e*nep+(m-e)*nmp;i++)
		{
			for(j=0; j<dim; j++)
			{
				fprintf(test_abc, "%lf ", loc_sea[i][j]);
			}
			fprintf(test_abc, "\n");
		}
		fprintf(test_abc, "\n g_best: %lf", *g_best_abc);
		
		fprintf(test_abc, "\n----------------------------------\n");
		
		*tren_iter_abc = *tren_iter_abc + 1;
	}while(*tren_iter_abc < br_iter && (*g_best_abc >= f_best+greska || *g_best_abc <= f_best-greska));
	
		//free malloc memory
	for( i = 0 ; i < n ; i++)
		free(cestica[i]);
	for( i = 0 ; i < (e*nep+(m-e)*nmp) ; i++ )
		free(loc_sea[i]);
	free(cestica);
	free(loc_sea);
	free(cestica_g_best);
	free(cestica_val);
	free(sort_pos);
	fclose(test_abc);

}
