/*
 * numeros.c
 *
 *  Created on: 07/05/2012
 *      Author: cuki
 */
#include <stdio.h>
#include <math.h>

int isPrimo(int nr) {

	int aux;

	for (aux = nr - 1; aux > 1; aux--) {
		if (!(nr % aux))
			return 0;
	}
	return 1;
}

char feliz(double nr) {

	double cont = 0;
	double proximo = 0;
	int aux = 0;
	int aux2 = 0;

	for (cont = 0; (nr > exp10(cont)) && (cont <= 10); cont++)
		if (cont == 10)
			return 0;
	for (; cont; cont--) {
		if (cont > 1 || nr <= 99) {
//			aux = pow(((nr - (sqrt(aux) * exp10(cont))) / ((int) exp10(cont - 1))), 2);
			aux = sqrt(aux);
			aux *= exp10(cont);
			aux = nr - aux;
			aux /= (int) exp10(cont - 1);
			aux = pow(aux, 2);
			proximo += aux;
			aux2 += sqrt(aux) * exp10(cont - 1);
		} else {
			aux = nr - aux2;
			aux = pow(aux, 2);
			proximo += aux;
		}
	}

	if (proximo == 1 || proximo == 10 || nr == 1)
		return 1;
	else
		return feliz(proximo);
}

int main(int argc, char **argv) {

	int a = 0;

	printf("\nComeco");

//	for (a = 1; a < 10; a++) {
//		if (feliz(a))
//			printf("\n%d eh um nr feliz", a);
//	}

	feliz(7);

	printf("\nDone");

	return 0;

}

/* int primo(int nr, int aux) {

 if (aux == 1)
 return 1;
 else if (!(nr % aux))
 return 0;
 else
 return primo(nr, aux - 1);

 }

 int isPrimo(int nr) {
 return primo(nr, nr - 1);
 }*/
