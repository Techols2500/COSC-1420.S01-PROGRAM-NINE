#include <stdlib.h>		/* use this for random number functions */
#include <time.h>

#include "Dice.h"

void InitDice()
{
	srand(time(0));
}

int ThrowDice()
{
	return ThrowDie() + ThrowDie();
}

int ThrowDie()
{
	int Num;

	Num = rand();	/* gives back a random number from 0 to 32767 */
	Num = (Num % 6) + 1;
	return Num;
}