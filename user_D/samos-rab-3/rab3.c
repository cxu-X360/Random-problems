#include <stdio.h>

int main()
{
	long int max = 2147483647;

	long int a_old_old = 1l;
	long int a_old = 2l;

	int k = 0;
	scanf("%d", &k);

	long int sum = 0;

	for (int i = 1; i <= k; i++)
	{
		if (i == 1) sum = 1;
		else if (i == 2) sum = 3;
		else
		{
			long int a = 2*a_old + a_old_old;
			sum += a;

			a_old_old = a_old;
			a_old = a;
		}

		printf("%3d  %ld\n", i, sum);
	}


	putchar('\n');




	long int old_old_old_sum = 0, old_old_sum = 1, old_sum = 3, _sum = 0;
	long int b_old_old = 1l;
	long int b_old = 2l;
	k = 3;

	int is_overflow = 0;

	while (true)
	{	
		old_old_old_sum = old_old_sum;
		old_old_sum = old_sum;
		old_sum = _sum;

		long int b = 2 * b_old + b_old_old;
		b_old_old = b_old;
		b_old = b;

		if (_sum >= max - b) {printf("%3d %ld\n%3d %ld\n%3d %ld\n", k-3, old_old_old_sum, k-2, old_old_sum, k-1, old_sum); break;}

		_sum += b;
		k++;
	}



}