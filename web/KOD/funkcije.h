/*funkcije.c */
double sphere(int n, double *x);
double rosenbrock(int n, double * x);
double step(int n, double *x);
double quartic(int n, double *x);
double shekel(int n, double *x);
double schaffer(int n, double *x);
double rastrigin(int n, double *x);
double griewank(int n, double *x);
double hypell(int n, double *x);
double ackley(int n, double *x);

double sphere_set(int val);
double rosenbrock_set(int val);
double step_set(int val);
double quartic_set(int val);
double shekel_set(int val);
double schaffer_set(int val);
double rastrigin_set(int val);
double griewank_set(int val);
double hypell_set(int val);
double ackley_set(int val);

void ispitaj_vrijednost(double* g_best, int funkcija, int  dim, double* cestica);

double sqr (double x );
double dmax (int n ,double * x );
double sgn (double x );
double dist2 (int n ,double * x ,double * y );
double distInf (int n ,double * x ,double * y );
double prod (int n ,double * x );
