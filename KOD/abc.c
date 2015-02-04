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

	/*alg param:
	 * cestica: matrix of worker bees [n x dim]
	 * cestica_g_best: possition of best global value [dim]
	 * cestica_val: function values in current iter [n]
	 * sort_pos: keeps track of permutations after sorting cestica_val [n]
	 * loc_sea: matrix of particles in local search [(e*nep+m*nmp)  x dim] 
	 */
	double **cestica, *cestica_g_best, *cestica_val, **loc_sea;
	int  *sort_pos, nep, nmp;
	double g_best_tmp, okolina_h, okolina_l;
	nep = 10;
	nmp = 5;
	//double epsilon = 1;
double *epsilon;
epsilon=(double*)malloc(sizeof(double)*m);
int *promjena_wd;
promjena_wd=malloc(sizeof(int)*m);
int promjena_tmp;
	
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
		
			if(i<m)
			{
			promjena_wd[i]=0;
			epsilon[i]=(border_h-border_l)/n;
			}
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
		
		if( *g_best_abc > cestica_val[0] )
		{
			*g_best_abc = cestica_val[0];
			for( i = 0 ; i < dim ; i++ )
				cestica_g_best[i] = cestica[sort_pos[0]][i];
		}
		
		//local search
		for(int wdn=0;wdn<100;wdn++)		
		{
			for( i = 0 ; i < e ; i++)
			{
				for( j = 0 ; j < nep ; j++)
				{
					for( k = 0 ; k < dim ; k++ )
					{
						okolina_h = cestica[sort_pos[i]][k] + epsilon[i];
						okolina_l = cestica[sort_pos[i]][k] - epsilon[i];
						loc_sea[i*nep+j][k] = okolina_l + genrand64_real1()*(okolina_h - okolina_l);
						
						//get particle back in domain borders
						if(loc_sea[j][k] < border_l)
						{	
							g_best_tmp = border_l - loc_sea[j][k]; //user as normal tmp var
							if(g_best_tmp > 1)
								g_best_tmp *= (-1);
							loc_sea[j][k] = border_l - g_best_tmp;
						}
						if(loc_sea[j][k] > border_h)
						{
							g_best_tmp = border_h - loc_sea[j][k]; //user as normal tmp var
							if(g_best_tmp < 1)
								g_best_tmp *= (-1);
							loc_sea[j][k] = border_h - g_best_tmp;
						}
					}

					ispitaj_vrijednost(&g_best_tmp, funkcija, dim, loc_sea[j]);
					
					if(g_best_tmp<cestica_val[i])
					{
						cestica_val[i]=g_best_tmp;
						for( k = 0 ; k < dim ; k++ )
						cestica[sort_pos[i]][k] = loc_sea[j][k];
						epsilon[i]*=0.8;
					}
					else
						promjena_wd[i]++;
				}
			}
		
			for( i = e; i < m ; i++ )
			{
				for( j = 0 ; j < nmp ; j++)
				{	
					for( k = 0 ; k < dim ; k++ )
					{
						okolina_h = cestica[sort_pos[i]][k] + epsilon[i];
						okolina_l = cestica[sort_pos[i]][k] - epsilon[i];
						loc_sea[e*nep+(i-e)*nmp+j][k] = okolina_l + genrand64_real1()*okolina_h;
						
						//get particle back in domain borders
						if(loc_sea[j][k] < border_l)
						{	
							g_best_tmp = border_l - loc_sea[j][k]; //user as normal tmp var
							if(g_best_tmp > 1)
								g_best_tmp *= (-1);
							loc_sea[j][k] = border_l - g_best_tmp;
						}
						if(loc_sea[j][k] > border_h)
						{
							g_best_tmp = border_h - loc_sea[j][k]; //user as normal tmp var
							if(g_best_tmp < 1)
								g_best_tmp *= (-1);
							loc_sea[j][k] = border_h - g_best_tmp;
						}
					}
					
					ispitaj_vrijednost(&g_best_tmp, funkcija, dim, loc_sea[j]);

					if(g_best_tmp<cestica_val[i])
					{
						cestica_val[i]=g_best_tmp;
	
						for( k = 0 ; k < dim ; k++ )
							cestica[sort_pos[i]][k] = loc_sea[j][k];
						
						epsilon[i]*=0.8;
					}
					else
						promjena_wd[i]++;
				}
			}
		
			sort_bool=1;
			while(sort_bool>1)
			{
				sort_bool = 0;
				for( i = 0 ; i < (m-1) ; i++ )
				{
					if(cestica_val[i] > cestica_val[i+1])
					{
						g_best_tmp = cestica_val[i+1]; //g_best_tmp used as normal tmp var
						sort_bool = sort_pos[i+1]; //sort_bool used as normal tmp var
						promjena_tmp = promjena_wd[i+1];
						cestica_val[i+1] = cestica_val[i];
						sort_pos[i+1] = sort_pos[i];
						promjena_wd[i+1] = promjena_wd[i];
						cestica_val[i] = g_best_tmp;
						sort_pos[i] = sort_bool;
						promjena_wd[i] = promjena_tmp;
					}
				}
			}

			if( *g_best_abc > cestica_val[0] )
			{
				*g_best_abc = cestica_val[0];
				
				for( i = 0 ; i < dim ; i++ )
					cestica_g_best[i] = cestica[sort_pos[0]][i];
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
		}		

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
	free(epsilon);
	free(promjena_wd);
}
