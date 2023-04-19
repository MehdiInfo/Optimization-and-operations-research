#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "probleme.h"
#include "simplexe.h"
#include "pivot.h"

int main (int argc, char *argv[]) {
	char nom_fichier[20];
	prob_t probleme = {0,0,0,NULL,NULL,NULL,NULL};
	strcpy(nom_fichier, argv[1]);
	int positive = 1;
	if (!lire_probleme(nom_fichier, &probleme)) {
		afficher_probleme(&probleme);
	}
	else {
		printf("Probleme lecture Probleme\n");
		return -1;
	}
	int row = probleme.n_cont + 1;
    int col = probleme.n_var + probleme.n_cont + 1;
	double **mat_pivot = init_mat_pivot(&probleme,col,row);
	afficher_mat_pivot(mat_pivot,col,row);
	int indice;
	int indice2;
	// deviser_ligne_pivot(mat_pivot, col,row,indice,indice2);
	// printf("------------------\n");
	// afficher_mat_pivot(mat_pivot,col,row);
	// mise_a_zero_col_pivot(mat_pivot, col,row,indice,indice2);
	// printf("------------------\n");
	
	while(positive){
		indice = selectionner_col_pivot(mat_pivot, col, row, probleme.n_var);
		indice2 = selectionner_row_pivot(mat_pivot, col, row, indice);
		deviser_ligne_pivot(mat_pivot, col,row,indice,indice2);
		printf("------------------\n");
		afficher_mat_pivot(mat_pivot,col,row);
		mise_a_zero_col_pivot(mat_pivot, col,row,indice,indice2);
		printf("------------------\n");
		afficher_mat_pivot(mat_pivot,col,row);
		positive = continuer(mat_pivot,row, probleme.n_var);
	}
	printf("------------------\n");
	printf("Valeur des variables principales :\n");
	for(int i = 0; i < probleme.n_var;i++) printf("x%d = %.2f\n",i,-mat_pivot[row-1][i]);
	printf("Valeur des variables  d'ecart :\n");
	for(int i = probleme.n_var; i < col-1;i++) printf("x%d = %.2f\n",i,-mat_pivot[row-1][i]);
	printf("Valeur de la fonction objectif z = %.2f\n",-mat_pivot[row-1][col-1]);


	liberer_memoire_probleme(&probleme);
	return 0;
}


