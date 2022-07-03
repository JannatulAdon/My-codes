#include <bits/stdc++.h>
long long genarate_prime(long long pn)
{
	long long x = sqrt(pn);
	for (long long i = 2; i <= x; i++)
	{
		if (pn % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	for (;;)
	{
		long long a;
		printf("  Type a number : ");
		scanf("%lld", &a);
		if (genarate_prime(a))
		{
			printf("\n  %lld is a prime number\n", a);
		}
		else
		{
			printf("\n  %lld = ", a);
			for (long long i = 2; i <= a;)
			{
				if (a % i == 0 && genarate_prime(i))
				{
					a = a / i;
					printf("%lld", i);
					if (a == 1)
					{
						printf("\n");
					}
					else
					{
						printf("*");
					}
				}
				else
				{
					i++;
				}
			}
		}
		printf("\n\n\n");
	}
}
