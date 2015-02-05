#include <stdio.h>
#include <math.h>

#include "funkcije.h"
#include "mt64.h"

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

#ifndef M_E
#define M_E           2.71828182845904523536
#endif

double sqr (double x );


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
		sum += y;  //bilo y*y
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

double shekel(int n, double *x)
{
	int j;
	double s, t0, t1;
	static double a[2][25] = {
		{-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32},
		{-32,-32,-32,-32,-32,-16,-16,-16,-16,-16,0,0,0,0,0,16,16,16,16,16,32,32,32,32,32}
	};
	s = 0.0;

	for (j = 0; j < 25; j++) 
	{
		t0 = x[0] - a[j][0]; //promjena indeksiranja
		t1 = x[1] - a[j][1];
		t0 = (t0 * t0 * t0);
		t0 *= t0 * t0 * t0; //falio *t0
		t1 = (t1 * t1 * t1);
		t1 *= t1 * t1 * t1; //falio *t1
		s += 1.0/ ((double) j + t0 + t1);
	}
	
	return 1.0 / (1.0/500.0 + s);
}

double schaffer(int n, double *x)
{
	return 0.5 + (sqr(sin(sqrt(sqr(x[0]) + sqr(x[1])))) - 0.5) / sqr(1.0 + 0.001 * (sqr(x[0])+sqr(x[1])));
}

double rastrigin(int n, double *x)
{
	int i;
	double sum, t;

	sum = 0.0;
	for (i = 0; i < n; i++) 
	{
		t= x[i];
		sum += t*t - 10*cos(2.0 * M_PI * x[i]); //falilo 10*
	}
	
	return sum + n*10;
}

double griewank(int n, double *x)
{
	int i;
	double sum=0 ;
	double prod=1 ;
	
	for (i=0 ; i<10 ; i++) 
	{
		sum+=x[i]*x[i];
		prod*=cos(x[i]/sqrt((double)(i+1)));
	}

	return sum/4000.0-prod + 1;
}

double hypell(int n, double *x)
{
	int i;
	double s = 0.0;
	
	for (i = 0; i < n; i++) 
	{
		s += i * i * x[i]*x[i]; // * izmedu i i x[i], bio +
	}
	
	return s;
}

double ackley(int n, double *x)
{
	int i;
	double t, s1, s2;
	s1 = s2 = 0.0;
	for (i = 0; i < n; i++) 
	{
		t = x[i];
		s1 += t * t;
		s2 += cos(2.0*M_PI * x[i]);
	}
	
	return -20.0 * exp(-0.2 * sqrt(s1/n)) - exp(s2 / n) + 20.0 + M_E;
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
			return 3;
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
			return 3;
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


double shekel_set(int val)
{
	switch (val)
	{
		case 0: 
			return 2;
		case 1: 
			return 0.998;
		case 2: 
			return -65.536; 
		case 3: 
			return 65.536;
		case 4:
			return 0.001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double schaffer_set(int val)
{
	switch (val)
	{
		case 0: 
			return 2;
		case 1: 
			return 0;
		case 2: 
			return -100.0; 
		case 3: 
			return 100.0;
		case 4:
			return 0.00001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double rastrigin_set(int val)
{
	switch (val)
	{
		case 0: 
			return 10;
		case 1: 
			return 0;
		case 2: 
			return -60.0; 
		case 3: 
			return 60.0;
		case 4:
			return 0.0001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double griewank_set(int val)
{
	switch (val)
	{
		case 0: 
			return 10;
		case 1: 
			return 0;
		case 2: 
			return -400; 
		case 3: 
			return 400;
		case 4:
			return 0.001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double hypell_set(int val)
{
	switch (val)
	{
		case 0: 
			return 30;
		case 1: 
			return 0;
		case 2: 
			return -1.0; 
		case 3: 
			return 1.0;
		case 4:
			return 0.001;
	}
	return 0; //kompajler se buni ako nema ovoga
}

double ackley_set(int val)
{
	switch (val)
	{
		case 0: 
			return 10;
		case 1: 
			return 0;
		case 2: 
			return -30; 
		case 3: 
			return 30;
		case 4:
			return 0.001;
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
		case 5:
			*g_best = shekel(dim, cestica);
			break;
		case 6:
			*g_best = schaffer(dim, cestica);
			break;
		case 7:
			*g_best = rastrigin(dim, cestica);
			break;
		case 8:
			*g_best = griewank(dim, cestica);
			break;
		case 9:
			*g_best = hypell(dim, cestica);
			break;
		case 10:
			*g_best = ackley(dim, cestica);
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
