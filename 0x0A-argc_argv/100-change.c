#include <stdlib.h>
#include <stdio.h>

/**
 * _change - prints the minimum number of coins to
 * make change for an amount of money
 * @amt: amount of money to change
 * Return: result
 */

int _change(int amt)
{
	int min_num_coins = 0;

	while (amt > 0)
	{
		if (amt >= 25)
		{
			amt -= 25;
			min_num_coins++;
		}
		else if (amt < 25 && amt >= 10)
		{
			amt -= 10;
			min_num_coins++;
		}
		else if (amt < 10 && amt >= 5)
		{
			amt -= 5;
			min_num_coins++;
		}
		else if (amt < 5 && amt >= 2)
		{
			amt -= 2;
			min_num_coins++;
		}
		else
		{
			amt -= 1;
			min_num_coins++;
		}
	}
	return (min_num_coins);
}

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 - successful, 1 - fail
 */

int main(int argc, char **argv)
{
	int amt, min_num_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amt = atoi(argv[1]);
	if (amt < 0)
	{
		printf("0\n");
		return (0);
	}
	min_num_coins = _change(amt);
	printf("%d\n", min_num_coins);
	return (0);
}
