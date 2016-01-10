#include <stdio.h>

/* count newlines, tabs, and spaces */
main()
{
	int c, nl, t, s;
	nl = 0;
	t = 0;
	s = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++t;
		else if (c == ' ')
			++s;
	printf("lines:\t%d\n", nl);
	printf("tabs:\t%d\n", t);
	printf("spaces:\t%d\n", s);
}

