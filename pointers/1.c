#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int var1, var2;
	int* p;

	var1 = 2;
	var2 = 3;

	p = &var1;

	printf("%p ", &var1); // Adresa lui var1
	printf("%p ", p); // Adresa lui var1 ca valoare a lui p
	printf("%p ", &p); // Adresa lui p
	printf("%d ", *p); // Valoarea de la adresa stocata in p

	return 0;
}