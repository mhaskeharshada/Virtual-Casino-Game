//game name:virtual casino betting game.
// developer name : Mhaske Harshada Satish .
// date of performance : 4 Aug,2021

 //  ################################ Algorithm ##########################################
 
//there are 3 playing cards jack,queen,king
//computer shuffle this cards
//then, player has to guess the position of queen
//if he win , he takes 4*bet
//if he/her looses ,loss the bet amount 
// suppose player has $100 initially..

//#################################################################################################

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cash=100;
void play_game(int);
int main()
{
	int bet;
	printf("********************************\n");
	printf("Welcome to the virtual casino\n");
	printf("********************************\n");
	
	printf("Total cash of player = $%d\n",cash);
	while(cash>0)
	{
		printf("What is bet? : $");
		scanf("%d",&bet);
		if(bet<=0 || bet>cash)
		{
			break;
		}
		play_game(bet);
		printf("\n*******************\n");
	}
	return 0;
}

void play_game(int bet)
{
	char c[3]={'J','Q','K'};
	   
	printf("   ...Shuffling....\n");
	int i;
	srand(time(0));     // for seed the rand() 
	for(i=0;i<5;i++)
	{
		int x = rand() % 3;       // %3 because we take rand no less than 3 i.e,0,1,2
		int y = rand() % 3;
		int temp=c[x];
		c[x]=c[y];
		c[y]=temp;              // swapping of character at posion x and y		
	}
	int guess;
	printf(" What is the posion of King  1 ,2 or 3 ?");
	scanf("%d",&guess);
	if(guess>=4 || guess<=0)
 {
      printf("plzz enter position between 1 ,2 or 3 thank you ..\n");     // filter 
      return ;
 }
		  	
	if(c[guess-1]=='K')
	{
		cash =cash+3*bet;
		printf(" congrats ..You win !! result =\" %c  %c  %c \"\n total amount = %d \n",c[0],c[1],c[2],cash);
	}
	else
	{
		cash= cash-bet;
		printf("Opps.. You loose !! result = \" %c  %c  %c \" \ntotal amount = %d\n",c[0],c[1],c[2],cash);
	}
  
}

