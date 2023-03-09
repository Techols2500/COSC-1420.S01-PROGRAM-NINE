/*
DESCRIPTION: Programming Excerise Nine
CLASS: COSC 1420.SO1
AUTHOR: TYLER ECHOLS
DATE: Mar 2019
*/
#pragma warning (disable:4996)

#include <stdio.h>
#include "Dice.h"
void main()
{
	double total = 50.00;
	double bet = 0;
	char answer = 'n';
	char C;
	int dTotal = 0;
	int point = 0;
	int count = 0;


	printf(" Welcome to Craps. Roll a 7 or 11 on your 1st try you win, if you roll a 2,3, or a 12 you lose  \n ");

	do
	{
		printf("Your current total is  $%lf \n Place your bets \n  ", total);
		scanf ("%lf", &bet);
		scanf("%c", &C);
		while (bet > total)
		{

			printf("Incuffent Funds Current total  $%lf \n How much wwould you like to bet? \n ", total);
			scanf("%lf", &bet);
			scanf("%c", &C); 
		}
		while (bet <= 0)
		{
			printf("Incuffent Funds Not enough to play $%lf \n How much would you like to bet? \n", total);
			scanf("%lf", &bet);
			scanf("%c", &C);
		}
		dTotal = ThrowDice();
		printf("You rolled a %d \n", dTotal);

		if (dTotal == (7) || dTotal == (11))
		{
			total += bet;
			printf( "You win. Try again?  (y/n)  ");
			scanf ("%c", &answer);
			scanf("%c", &C);
		}

		else if (dTotal == (2) || dTotal == (3) || dTotal == (12))
		{
			total -= bet;
			if (total > 0)
			{
				printf("You lose. Try again?  (y/n)  ");
				scanf("%c", &answer);
				scanf("%c", &C);
			}
			else
			{
				printf("You lose. Game Over. Out of Funds  ");
				answer = 'n';
			}
		}
		else
		{
			point = dTotal;
			printf(" The Point is %d \n  ", point);
			dTotal = ThrowDice();
			printf("You rolled a %d ", dTotal);

			while ((dTotal != point) && (dTotal != 7))
			{
				printf("Please roll again   ");
				dTotal = ThrowDice();
				printf("You rolled a %d ", dTotal);
			}
			if (dTotal == point)
			{
				total += bet;
				printf(" You win. Try again?  (y/n)  ");
				scanf("%c", &answer);
				scanf("%c", &C);
			}
			else if (dTotal == 7)
			{
				total -= bet;
				if (total > 0)
				{
					printf("You Lose. Try again?  (y/n)  ");
					scanf("%c" ,&answer);
					scanf("%c", &C);
				}
				else
				{
					printf("You lose Game Over. Out of Funds  ");
					answer = 'n';
					system("pause");
				}
			}
		}
	} while ((answer == 'y') && (total > 0));
}


