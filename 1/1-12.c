#include <stdio.h>\

#define IN	1
#define OUT	0

/* print one word of input per line */
main()
{
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		} else {
			state = IN;
			putchar(c);
		}
	}
}
