#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int alternierende_quersumme(int zahl, int basis) {
	int summe = 0; // Es speichert das Endergebnis, das wir bisher berechnen.
	int sign = 1; //  Es stellt sicher, dass die Summe alternierend ist und wechselt das Vorzeichnen jeder Ziffer : "+", "-", "+", ....

	while (zahl > 0) {
		int ziffer = zahl % basis;
		summe += sign * ziffer;
		sign = -sign;
		zahl /= basis;
	}
	return summe;
}

void print_in_basis(int zahl, int basis) { // Funktion, um Zahl in Basis b auszugeben (nur zur Sicherheit)

	if (zahl == 0) {
		printf("0");
		return;
	}

	int digits[32];
	int i = 0;
	while (zahl > 0) {
		digits[i++] = zahl % basis;
		zahl /= basis;
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d", digits[j]);
	}

	printf("\n");

}


int main(void) {

	int zahl, basis;

	printf(" Zahl eingeben : ");
	scanf_s("%d", &zahl);
	printf(" Basis eingeben : ");
	scanf_s("%d", &basis);


	printf(" A in Basis %d : ", basis);
	print_in_basis(zahl, basis);
	
	int q = alternierende_quersumme(zahl, basis);
	printf(" Alternierende Quersumme (z1 - z2 + z3 -z4 + z5 -...) : %d\n", q);

	return 0;
}