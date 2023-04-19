#ifndef PIVOT_H
#define PIVOT_H

double** init_mat_pivot(prob_t *p,int col,int row);
void afficher_mat_pivot(double** mat_pivot,int col, int row);
int selectionner_col_pivot(double** mat_pivot, int col, int row,int n_var);
int selectionner_row_pivot(double** mat_pivot, int col, int row, int indice);
void deviser_ligne_pivot(double **mat_pivot, int col, int row,int indice,int indice2);
void mise_a_zero_col_pivot(double **mat_pivot, int col, int row,int indice,int indice2);
int continuer(double **mat_pivot, int row, int val);
#endif
