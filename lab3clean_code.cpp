//сортування за спаданням по рядкам методом обміну
//середнє арифметичне значення елементів у кожному стовпці матриці; 
//середнє геометричне значення
#include "pch.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#define n 5
void sort_metod_swap_rydoc_from_big_to_small(int matrix[n][n]);
void dia_on_matrix(int matrix[n][n]);
int main(void)
{
	int i, j;
	static int matrix[n][n];
	system("cls");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("a[%d][%d] =", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}
	printf("old array\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", matrix[i][j]);
		printf("\n");
	}
	sort_metod_swap_rydoc_from_big_to_small(matrix);
	printf("\nnew array\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	 dia_on_matrix( matrix);


	
}
void sort_metod_swap_rydoc_from_big_to_small(int matrix[n][n])
{
	int i, k, j, value_of_change;
	for (i = 0; i < n; i++)
	{
		for (k = n - 1; k >= 0; k--)
		{
			for (j = 0; j < k; j++)
			{
				if (matrix[i][j] < matrix[i][j + 1])
				{
					value_of_change = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = value_of_change;
				}
			}
		}
	}
} 
void dia_on_matrix(int matrix[n][n])
{
	static double value_seredne_arefmetichne[n];
	double  seredne_geometric=0, seredne_arefmetichne = 0;
	int sum=0, dobutoc = 1;

	for (int j = 0; j < n; j++) //середнє арифметичне значення елементів у кожному стовпці матриці; 

	{
		for ( int i = 0; i < n; i++)
		{
			
			sum = matrix[i][j] + sum  ;
			seredne_arefmetichne = sum / n;
		}

		printf("seredne_arefmetichne rydok%d=%lf  ", j + 1, seredne_arefmetichne);
		value_seredne_arefmetichne[j] = seredne_arefmetichne;
		sum = 0;
	}

	for (int j = 0; j < n; j++)//середнє геометричне значення
	{
		dobutoc = fabs(value_seredne_arefmetichne[j] ) * dobutoc;
	}
	
	seredne_geometric = pow(dobutoc, 1.0 / n);
	printf("seredne_geometric=%lf", seredne_geometric);
}


