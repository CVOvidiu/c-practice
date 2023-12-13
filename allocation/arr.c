#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

float avg(int* v, int n) {
	int s = 0;
	for (int i = 0; i < n; i++)
		s += v[i];

	return (float)(s / n);
}

int main() {
	int* v;
	int n;
	
	printf("Nr elem: ");
	scanf("%d", &n);

	// Alocare
	v = (int*)malloc(n * sizeof(int));

	// Verificare memorie
	if (v == NULL) {
		perror("Memorie insuficienta!");
		return 1;
	}

	// Citire date
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	// Afisare date
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("\nMedia este: %.2f", avg(v, n));

	// Eliberare memorie
	free(v);

	return 0;
}