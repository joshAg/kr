#include <stdio.h>
#define SCALE	20
#define IN	1
#define OUT	0

/* make a horizontal histogram of word lengths*/
main()
{
	int c, i, j, max, length, state;
	int nlength[21];

	for (i = 0; i < 21; ++i)
		nlength[i] = 0;
	length = max = i = j = c = 0;
	state = OUT;

	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				if (length > 20)
					++nlength[0];
				else if (length > 0)
					++nlength[length];
				length = 0;
				state = OUT;
			}
		} else {
			state = IN;
			++length;
		}

	for (i = 0; i < 21; ++i)
		if (nlength[i] > max)
			max = nlength[i];
	printf("histogram\n");
	for (i = 1; i < 21; ++i) {
		printf("%3d:\t", i);
		for (j = 0; j < nlength[i] * 1.0 / max * SCALE; ++j)
			putchar('#');
		printf(" %3d", nlength[i]);
		putchar('\n');
	}
	printf(">20:\t");
	for (j = 0; j < nlength[0] * 1.0 / max * SCALE; ++j)
		putchar('#');
	printf(" %3d", nlength[0]);
	putchar('\n');
}
