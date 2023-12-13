#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

float max(int** v, int n, int m) {
	float mx = v[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] > mx)
				mx = v[i][j];

	return mx;
}

float avg(int** v, int n, int m) {
	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s += v[i][j];

	return (float)(s / (m * n));
}

int main() {
	int** v;
	int n, m;
	
	printf("Nr linii si coloane: ");
	scanf("%d%d", &n, &m);

	// Alocare I
	v = (int**)malloc(m * sizeof(int*));

	// Verificare memorie I
	if (v == NULL) {
		perror("Memorie insuficienta!");
		return 1;
	}

	// Alocare II
	for (int i = 0; i < m; i++) {
		v[i] = (int*)malloc(n * sizeof(int));
	
		// Verificare memorie II
		if (v[i] == NULL) {
			perror("Memorie insuficienta!");
			return 1;
		}
	}

	// Citire date
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &v[i][j]);

	// Afisare date
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}

	printf("\nMedia este: %.2f", avg(v, n, m));
	printf("\nMax elem este: %.2f", max(v, n, m));

	// Eliberare memorie
	for (int i = 0; i < m; i++)
		free(v[i]);
	free(v);

	return 0;
}