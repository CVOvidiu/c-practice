#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
	// Files
	FILE* fin;
	FILE* fout;
	char fname[255];

	int** v;
	int n, m;
	
	// Citire nume fisier intrare de la tastatura
	// 'gets' a fost scos, 'fgets' trebuie scos new line-ul din el ca sa nu fie probleme
	char* p;
	fgets(fname, sizeof(fname), stdin);
	if ((p = strchr(fname, '\n')) != NULL) {
		*p = '\0'; /* remove newline */
	}
	//printf(fname);
	
	// Deschidere fisiesr intrare
	fin = fopen(fname, "rb");

	// Verificare fisier intrare
	if (fin == NULL) {
		printf("Fisierul %s nu a putut fi deschis!", fname);
		return 1;
	}

	fscanf(fin, "%d%d", &n, &m);

	// Alocare I
	v = (int**)malloc(n * sizeof(int*));

	// Verificare memorie I
	if (v == NULL) {
		perror("Memorie insuficienta!");
		return 1;
	}

	// Alocare II
	for (int i = 0; i < n; i++) {
		v[i] = (int*)malloc(m * sizeof(int));
	
		// Verificare memorie II
		if (v[i] == NULL) {
			perror("Memorie insuficienta!");
			return 1;
		}
	}

	// Citire date
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			fscanf(fin, "%d", &v[i][j]);

	// Afisare date
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}

	// Afisare in fisier
	fout = fopen("out.txt", "w");
	if (fout == NULL) {
		printf("Fisierul de iesire nu a putut fi deschis!");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			fprintf(fout, "%d ", v[i][j]);
		fprintf(fout, "\n");
	}

	// Eliberare memorie
	for (int i = 0; i < n; i++)
		free(v[i]);
	free(v);

	// Inchidere fisisere
	fclose(fin);
	fclose(fout);

	return 0;
}