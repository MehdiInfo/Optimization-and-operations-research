/*A completer*/
#include <stdlib.h>
#include <stdio.h>
#include "probleme.h"
#include "pivot.h"
#include <float.h>

double** init_mat_pivot(prob_t *p,int col, int row){
    
    double **mat_pivot = (double**)malloc(sizeof(double*)*(row));
    for(int i = 0; i < row ; i++)
    {
        mat_pivot[i] = (double*)malloc(sizeof(double)*(col));
        //
        for(int j = 0; j < col; j++){
            if(i == row - 1)

                if(j > p->n_var - 1) mat_pivot[i][j] = 0;
                else mat_pivot[i][j] = p->fonc_obj[j];
            else{
                if(j > p->n_var - 1){
                    if(j == col - 1) mat_pivot[i][j] = p->b[i];
                    else{
                        mat_pivot[i][j] = 0;
                        if(j == p->n_var + i) mat_pivot[i][j] = 1;
                    }
                }
                
                else mat_pivot[i][j] = p->a[i][j];
            }
                
            
        }
    }
    
    return mat_pivot;
}
void afficher_mat_pivot(double** mat_pivot,int col, int row){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%.2f ",mat_pivot[i][j]);
        }
        printf("\n");
    }
}

int selectionner_col_pivot(double** mat_pivot, int col, int row,int n_var){
    int indice;
    double max;
    indice = 0;
    max = mat_pivot[row-1][0];
    for(int i = 1; i < n_var; i++){
        if(mat_pivot[row-1][i] > max)
        {
            max = mat_pivot[row-1][i];
            indice = i;
        }

    }
    return indice;
}

int selectionner_row_pivot(double** mat_pivot, int col, int row,int indice){
    int indice2;
    double min = DBL_MAX;
    double temp;
    indice2 = -1;
    for(int i = 0; i < row - 1; i++)
    {
        temp = mat_pivot[i][col-1]/mat_pivot[i][indice];
        if(temp > 0.0 && temp < min){
            min = mat_pivot[i][col-1]/mat_pivot[i][indice];
            indice2 = i;
        }
    }
    return indice2;
}

void deviser_ligne_pivot(double **mat_pivot, int col, int row,int indice,int indice2){
    
    double pivot = mat_pivot[indice2][indice];
    for(int i = 0; i < col; i++){
        if(mat_pivot[indice2][i] != 0) mat_pivot[indice2][i] /= pivot;
    }
}
//
void mise_a_zero_col_pivot(double **mat_pivot, int col, int row,int indice,int indice2){
    double s;
    for(int i = 0; i < row; i++){
        s = mat_pivot[i][indice];
        if(i != indice2){
            for(int j = 0; j < col; j++){                
                mat_pivot[i][j] -= (s / mat_pivot[indice2][indice])*(mat_pivot[indice2][j]);
            }

        }
    }
}

int continuer(double **mat_pivot, int row, int val){
    int positive = 0;
    for(int i = 0; i < val ; i++){
        if(mat_pivot[row - 1][i] > 0)
        {
            positive = 1;
        }
    }
    return positive;
}
/**************************************/