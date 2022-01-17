#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Author: Ömer Bera Dinç (github: Supomera)
void clear(){ /* I explained this function at the bottom of the whole algorithm. */
    while (getchar() != '\n');
} 

int main()
{
	char move, r, p, s, cpmove; /* Defined my char variables  */
	int a, cpmovenumber, rr = 0, ss=0, pp =0, n=8, crtimes=0, cptimes=0, cstimes=0, urtimes=0, uptimes=0, ustimes=0; /* Defined my int variables */
	time_t t;
	srand((unsigned)time(&t)); /* Used time command to pick random number, we need this picking to decide on the computer's move  */
	while (n > 0)
	{
		printf("There are %d turn(s) to finish! \n", n);
		n = n-1;
		printf("Consider which move you're going to do; insert r for rock, p for paper, s for scissors and e to stop the game \n");
		move = getchar();
		clear();           /* I explained 20th, 21th lines and this function at the bottom of the whole algorithm */
		if (move == 'r')
		{
			rr = rr+2;
			a = 1;
			urtimes = urtimes+1;
		}
		else if (move == 'p')
		{
			pp = pp+2;
			a = 2;
			uptimes = uptimes+1;
		}
		else if (move == 's')
		{
			ss = ss+2;
			a = 3;
			ustimes = ustimes+1;
		}
		else if (move == 'e')
		{
			break;
		}
		else
		{
			printf("Please provide appropriate input! \n");
			printf("The number of rounds won't decrease with invalid inputs \n");
			a = 4;
			n = n+1;
		}
		switch(a) /* Firstly, I had defined "a" value for all situations and then wrote cases for these situations */
		{
			case 1: 	printf(" \n You played Rock! \n");
						cpmovenumber = rand() % 30; /* Picking random int from 0 to 30 */
						if (cpmovenumber < (10+ss-(rr/2)-(pp/2))) 
						{
							cpmove = 'r';
							crtimes = crtimes+1;
						}
						else if (cpmovenumber >= (10+ss-(rr/2)-(pp/2)) && cpmovenumber < (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 'p';
							cptimes = cptimes+1;
						}
						else if (cpmovenumber >= (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 's';
							cstimes = cstimes+1;
						}
						/* In these lines (52-63) computer deciding on it move due to the random number. We defined ss, rr, pp to change the interval of moves of computer.
						They are all calculated properly and carefully.  */
						if (cpmove == 'r')
						{	
							printf("Computer played Rock! \n");
							printf("Draw! \n");
						}
						else if (cpmove == 'p')
						{	
							printf("Computer played Paper! \n");
							printf("Computer won! \n");
						}
						else if (cpmove == 's')
						{
							printf("Computer played Scissors! \n");
							printf("You won! \n");                           /* And all of these are feedbacks for the user. */
						}
						if (n <= 2)
						{
							printf("This was the %d. round, \n computer played %d times paper, %d times scissors, %d times rock; \n you played %d times paper, %d times scissors, %d times rock", (8-n), cptimes, cstimes, crtimes, uptimes, ustimes, urtimes);
						} /* This is the code that prints out the number of the times each action is selected by both the user and the computer, when the total number of played rounds is greater than 5*/
						
						break; /* without this, algorithm continues with "case 2" so we are breaking and starting to a new round.  */
			case 2: 	printf(" \n You played Paper! \n");
						cpmovenumber = rand() % 30;
						if (cpmovenumber < (10+ss-(rr/2)-(pp/2)))
						{
							cpmove = 'r';
							crtimes = crtimes+1;
						}
						else if (cpmovenumber >= (10+ss-(rr/2)-(pp/2)) && cpmovenumber < (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 'p';
							cptimes = cptimes+1;
						}
						else if (cpmovenumber >= (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 's';
							cstimes = cstimes+1;
						}
						
						
						if (cpmove == 'r')
						{	
							printf("Computer played Rock! \n");
							printf("You Won!! \n");
						}
						else if (cpmove == 'p')
						{	
							printf("Computer played Paper! \n");
							printf("Draw! \n");
						}
						else if (cpmove == 's')
						{
							printf("Computer played Scissors! \n");
							printf("Computer Won! \n");
						}
						if (n <= 2)
						{
							printf("This was the %d. round, \n computer played %d times paper, %d times scissors, %d times rock; \n you played %d times paper, %d times scissors, %d times rock", (8-n), cptimes, cstimes, crtimes, uptimes, ustimes, urtimes);
						}
						break;			
			case 3: 	printf(" \n You played Scissors! \n");
						cpmovenumber = rand() % 30;
						if (cpmovenumber < (10+ss-(rr/2)-(pp/2)))
						{
							cpmove = 'r';
							crtimes = crtimes+1;
						}
						else if (cpmovenumber >= (10+ss-(rr/2)-(pp/2)) && cpmovenumber < (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 'p';
							cptimes = cptimes+1;
						}
						else if (cpmovenumber >= (20+(ss/2)+(rr/2)-pp))
						{
							cpmove = 's';
							cstimes = cstimes+1;
						}
						
						if (cpmove == 'r')
						{	
							printf("Computer played Rock! \n");
							printf("Computer won! \n");
						}
						else if (cpmove == 'p')
						{	
							printf("Computer played Paper! \n");
							printf("You won! \n");
						}
						else if (cpmove == 's')
						{
							printf("Computer played Scissors! \n");
							printf("Draw! \n");
						}
						if (n <= 2)
						{
							printf("This was the %d. round, \n computer played %d times paper, %d times scissors, %d times rock; \n you played %d times paper, %d times scissors, %d times rock", (8-n), cptimes, cstimes, crtimes, uptimes, ustimes, urtimes);
						}
						break;
			case 4: break;
									
		}	
	}
	
	return 0;
}
/* 
In normally, I used scanf instead of getchar but an error appeared and no one could solve it. I tried to solve it with many people that already knows c so well. 
If you can delete 21th line (clear function) and run this program, you will see that the loop turns twice without asking any input from user. And this input is being invalid thing.
I didn't want to send a mail, I thought this would be non-ethical and I searched this problem. I found this function with the usage of getchar, found it from stackoverflow. 
So I guess I have to give a credit for this situation: "How to clear input buffer in C" article from stackoverflow, this function's codes was there (jamesdlin & Penny & ipkiss, 2011).
There were no names of these people so I gave nicknames of them.   */
