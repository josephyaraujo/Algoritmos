#include <stdio.h>

void duplicaValores(int a[10]) {
	int i;
	for (i = 0; i < 10; i++) {
		a[i] = a[i] * 2;
	}
}

int main(int argc, char **argv) {
	int a1[10];
	int i;
	for (i = 0; i < 10; i++) {
		a1[i] = i;
	}
	duplicaValores(a1);
	for (i = 0; i < 10; i++) {
		printf ("%d \n", a1[i]);
	}
	return 0;
}