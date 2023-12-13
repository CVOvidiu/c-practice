#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char nume[50];
	char prenume[50];
	int varsta;
	float salariu;
} Persoana;

void citirePers(Persoana* p) {
	scanf("%s", p->nume);
	scanf("%s", p->prenume);
	scanf("%d%f", &p->varsta, &p->salariu);
}

void writePers(Persoana p) {
	printf("%s %s %d %.2f\n", p.nume, p.prenume, p.varsta, p.salariu);
}

int compPers(Persoana p1, Persoana p2) {
	return strcmp(p1.nume, p2.nume);
}

void swap(Persoana* p1, Persoana* p2) {
	Persoana aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

int part(Persoana* p, int st, int dr) {
	Persoana piv = p[(st + dr) / 2];
	int i = st;

	for(int j = st; j < dr - 1; j++)
		if (compPers(p[j], piv) > 0) {
			swap(&p[i], &p[j]);
			i++;
		}

	swap(&p[i], &p[dr]);
	return i;
}

void QS(Persoana* p, int st, int dr) {
	if (st < dr) {
		int pi = part(p, st, dr);

		QS(p, st, pi - 1);
		QS(p, pi + 1, dr);
	}
}

Persoana cMM(Persoana* p, int st, int dr) {
	if (st == dr)
		return p[st];

	int mij = (st + dr) / 2;

	if (cMM(p, st, mij).salariu > cMM(p, mij + 1, dr).salariu)
		return cMM(p, st, mij);
	return cMM(p, mij + 1, dr);
}

int main() {
	// Lab 9
	int n;
	printf("n = ");
	scanf("%d", &n);

	Persoana* p;
	p = (Persoana*)malloc(n * sizeof(Persoana));

	printf("\nIntroduceti persoanele in formatul: <Nume> <Prenume> <Varsta> <Salariu>\n");
	for (int i = 0; i < n; i++)
		citirePers(&p[i]);

	QS(p, 0, n - 1);

	printf("\nPersoanele sortate:\n");
	for (int i = 0; i < n; i++)
		writePers(p[i]);

	Persoana max = cMM(p, 0, n - 1);

	printf("\nPersoana cu salariul cel mai mare: %s %s %d %.2f\n", max.nume, max.prenume, max.varsta, max.salariu);

	return 0;
}