#include <stdio.h>
#include <math.h>

#include "funkcije.h"
#include "mt64.h"

double sqr (double x );
double dmax (int n ,double * x );
double sgn (double x );
double dist2 (int n ,double * x ,double * y );
double distInf (int n ,double * x ,double * y );
double prod (int n ,double * x );

/*functions*/
double sphere(int n, double *x)
{
	int i;
	double sum;
	sum = 0.0;
	
	for (i = 0; i < n; i++)
	{
		sum += sqr(x[i]);
	}

	return sum;
}

double rosenbrock(int n, double * x)
{
	double s = 0.0;
	int i;
	
	for( i = 1; i < n; i++ )
		s += 100.0*(x[i]-x[i-1]*x[i-1])*(x[i]-x[i-1]*x[i-1]) + (x[i-1]-1.0)*(x[i-1]-1.0);

	return s;
}

double step(int n, double *x)
{
	int i;
	double sum, y;
	
	sum = 0.0;

	for (i = 0; i < n; i++)
	{
		y = floor(x[i]);
		sum += y*y;
	}
	//sum=6*n + sum;
	
	return sum;
}

double quartic(int n, double *x)
{
	int i;
	double sum, t;
	
	sum = 0.0;
	
	for (i = 0; i < n; i++) 
	{
		t = x[i];
		t = t*t;
		sum += (i*t*t + genrand64_real1());
	}
	
	return sum;
}

/* sets dimeenstion of space (0) 
 * best know value(1)
 * domain borders (donja 2, gornja 3)
 * acceptable error (error)
 * radeno po RMO clanku*/
double sphere_set(int val)
{
	switch (val)
	{
		case 0: 
			return 3;
		case 1: 
			return 0;
		case 2: 
			return -5.12; 
		case 3: 
			return 5.12;
		case 4:
			return 0.00001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double rosenbrock_set(int val)
{
	switch (val)
	{
		case 0: 
			return 30;
		case 1: 
			return 0;
		case 2: 
			return -2.048; 
		case 3: 
			return 2.048;
		case 4:
			return 0.00001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double step_set(int val)
{
	switch (val)
	{
		case 0: 
			return 5;
		case 1: 
			return 0;
		case 2: 
			return -5.12; 
		case 3: 
			return 5.12;
		case 4:
			return 0.001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double quartic_set(int val)
{
	switch (val)
	{
		case 0: 
			return 30;
		case 1: 
			return 0;
		case 2: 
			return -1.28; 
		case 3: 
			return 1.28;
		case 4:
			return 0.00001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

/*istpitaj vrijednost funkcije u toci*/
void ispitaj_vrijednost(double* g_best, int funkcija, int  dim, double* cestica)
{
	switch (funkcija)
	{
		case 1:
			*g_best = sphere(dim, cestica);
			break;
		case 2:
			*g_best = rosenbrock(dim, cestica); 
			break;
		case 3:
			*g_best = step(dim, cestica);
			break; 
		case 4:
			*g_best = quartic(dim, cestica);
			break;
		default:
			printf("ERROR function calculation!\n");
	}
}

/*pomocne funkcije*/
double sqr(double x)
{
	return x*x;
}

double dmax(int n, double *x)
{
	int i;
	double m = x[0];
	for (i = 1; i < n; i++) 
	{
		if (x[i] > m) m = x[i];
	}
	return m;
}

double sgn(double x)
{
	if (x < 0.0) return -1.0;
	return 1.0;
}
double dist2(int n, double *x, double *y)
{
	register int i;
	double s, t;
	s = 0.0;
	for (i = 1; i < n; i++) 
	{
		t = (x[i]-y[i]);
		s += t * t;
	}
	return s;
}

double distInf(int n, double *x, double *y)
{
	register int i;
	double t,m;
	m = fabs(x[0] - y[0]);
	for (i = 1; i < n; i++) 
	{
		t = fabs(x[i]-y[i]);
		if (t > m) 
		{
			m = t;
		}
	}
	return m;
}

double prod(int n, double *x)
{
	int i;
	double p;
	p = 1.0;
	for (i = 0; i < n; i++) 
	{
		p *= x[i];
	}
	return -p;
}
