#include <stdio.h>
#define SCALE 20

/* make a horizontal histogram of character type frequencies*/
main()
{
	int c, i, j, nwhite, nother, max;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <='9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	max = nwhite;
	if (nother > max)
		max = nother;
	for (i = 0; i < 10; ++i)
		if (ndigit[i] > max)
			max = ndigit[i];
	printf("histogram\n");
	printf("whitespace:\t");
	for(i = 0; i < nwhite * 1.0 / max * SCALE; ++i)
		putchar('#');
	printf(" %3d", nwhite);
	putchar('\n');
	printf("other:\t\t");
	for(i = 0; i < nother * 1.0 / max * SCALE; ++i)
                putchar('#');
	printf(" %3d", nother);
        putchar('\n');
	for (i = 0; i < 10; ++i) {
		printf("%d:\t\t", i);
		for (j = 0; j < ndigit[i] * 1.0 / max * SCALE; ++j)
			putchar('#');
		printf(" %3d", ndigit[i]);
		putchar('\n');
	}
}
