#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define sum(a, b) a+b

int main() {
	int var1, var2;
	scanf("%d%d", &var1, &var2);

	printf("sum(var1, var2) = %d", sum(var1, var2));

	return 0;
}