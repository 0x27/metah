/*header za algoritmi.c*/
void PSO(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_pso, double* g_best_pso, double omega, double rop, double rog);
void ABC(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_abc, double* g_best_abc, int m, int e);
void OPSO(int funkcija, int br_iter, int n, int dim, double f_best, double greska, double border_l, double border_h, int* tren_iter_opso, double* g_best_opso, double omega, double ro_p, double ro_g, int e);
