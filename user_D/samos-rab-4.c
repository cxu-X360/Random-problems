#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Enter positive integer number k: "); 
	int k = 0;
	scanf("%d", &k);

	int n = 1;

	long int sum = 0; 
	long int old_sum = 0; 

	bool is_power_trouble = false;
	bool is_sum_trouble = false;

	while (n) //Увеличиваем n пока не заметим переполнение
	{
		old_sum = sum;
		sum = 0;

		for (long int i = 1; i <= k; i++) //Суммирование слагаемых k
		{
			long int a = 1; // Очередное слагаемое

			for (int j = 0; j < n; j++) //Возведение в степень n числа i
			{	
				is_power_trouble = __builtin_mul_overflow(a, i, &a);

			}
			printf("\t%d^%d = %ld  ", i, n, a);

			is_sum_trouble =  __builtin_add_overflow(sum, a, &sum);
			printf("sum = <%ld>, is_sum_trouble = %d, is_power_trouble = %d\n", sum, is_sum_trouble, is_power_trouble);	
			if (is_sum_trouble || is_power_trouble) break;	
		}

		printf("SUM(long int sum = <%ld>) at n = <%d>\n", sum, n);

		if (is_power_trouble || is_sum_trouble)
		{
			printf("OVERFLOW\n");
			break;
		}

		n++;
	}



	printf("ANSWER:\n");
	printf("%ld\n", old_sum);
	printf("%d\n", n-1);
	if (is_power_trouble) putchar('*');
	if (is_sum_trouble) putchar('+');



	return 0;
}