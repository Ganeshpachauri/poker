#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<string.h>



void rules();                      //rules of playing
int round1();                      //openning round
int nextround();                   //for remainning rounds 
void intro();                      //intro of player
void intro2( int);                 //to print the name and deposite amount in round1 fn 
void intro3( int);                 //to print the name and remainnig amount in nextround fn
void ccolor(int clr);              //for color text
void cls();                        //clear screen
void pwellcome();                  // welcome console
void loadingbar();                 //loding bar
void tab(int);                     //to tab space for specific number of time
void newline(int);                 //to start content from new line 
void win();                        //to write u win 
void win2();                       //when casino is in the loss
void loss();                       //to write to loss
void loss2();                      //when player lossing consicutively
void start();                      //main fn where code start
void bye();                        //for closing of game  
void dice();                       //to display dice rolling

char name[50];                     //name of player
char a;                            //for take enter  
int namelen;                       // chracter in name of player
int deposit;                       //deposite amount
int bet;                           //bet amount in round1 fn
int computer;                      //the outcome or the winning number calculated randomly in round1 fn
int guess;                         // number guess by player in round1 fn
int bet2;                          //to store the winning amount in round1 fn
int new_amt;                       //new amount updated everytime
int decision;                      //to take the input from player to replay
int bet3;                          //input for bet in nextround fn
int guess2;                        //take input of of bet no guess
int b;                             //to store the winning amount in nextround fn
int rounds=1;                      //to find random number
int won;                           //to count win
int lost;                          //to count loss

int main()
{
     start();//starting the game
     return 0;
}

void start()
{
     system(">>>>>>>>>>> Pirates Casion<<<<<<<<<<<<");//for consloe
	system("mode con: cols=80 lines=30");//for console
     loadingbar(); 
     cls();
	pwellcome();
	Sleep(300);//to stop screen
	cls();
     rules();
     intro();
}

int round1()
{    
     intro2(deposit);
     tab(5);scanf("%d", &bet);
     bets:
     if(bet>deposit||bet<1)//to check bet is not greater then deposit or not less then 1
     {    
          tab(4);printf("Money not in the limt of deposit ,");newline(2);
          tab(4);printf("Enter Again : $");newline(2);
          tab(5);scanf("%d", &bet);
          cls();
          newline(6);
          goto bets;
     }
     if (namelen>=5)//expression for random genration of bet number
     computer=(namelen*2)%12;
     else
     computer = namelen%12;
     cls();
     tab(4);newline(6);
     tab(4);printf("Guess a number from 1 to 12 :");
     tab(5);scanf("%d", &guess);
     
     gusses:
     if(guess>12||guess<1)//to check that guess no is not greater than 12 or less than 1
     {
          tab(4);printf("Number in not in the limt,");newline(2);
          tab(4);printf("Enter Again : ");newline(2);
          tab(5);scanf("%d", &guess);
          cls();
          newline(6);
          goto gusses;
     }
     Sleep(200);
     cls();
     newline(5);
     if(computer==0)
     computer=computer+12;
     dice();
     //checking condition of guess

     if(guess==computer)
     {
          win();
          rounds++;
          won++;
          bet2 = bet * 10;
          tab(4);printf("You have won $%d", bet2);newline(2);
          new_amt = bet2 + (deposit-bet);//new amount after winning
          
          tab(4);printf("You have won $%d as total", new_amt);newline(2);
          //asking to play again or not 
          tab(4);printf("Press 1 for YES");newline(2);
          tab(4);printf("Press 2 for NO");newline(2);
          tab(4);printf("Do you want continue : ");newline(2);
          tab(4);scanf("%d", &decision);     
          if(decision==1)
          {
               nextround();    
          }
          else if(decision==2)
          {
               tab(4);printf("Have a good day sir");
               bye();
          }
          
     }
     else if(guess!=computer)
     {
          loss();
          rounds++;
          lost++;
          tab(4);printf("You have loss $%d", bet);newline(2);          
          tab(4);printf("The correct number is : %d", computer);newline(2);          
          new_amt = deposit - bet;//new amont after loss
          tab(4);printf("Now you have $ %d as a balance", new_amt);newline(2);
          if(new_amt==0)
          {
               tab(4);printf("Sir,you have $ %d as a balance",new_amt);newline(2);
               tab(4);printf("You have no more money to play");newline(2);
               tab(4);printf("Have a nice day");newline(2);
               bye();
          }
          else
          {
               //asking to play again or not 
               tab(4);printf("Press 1 for YES");newline(2);
               tab(4);printf("Press 2 for NO");newline(2);
               tab(4);printf("Do you want continue :");newline(2);
               tab(4);scanf("%d", &decision);newline(2);
               
               
               if(decision==1)
               {
                    nextround();    
               }
               else if(decision==2)
               {
                    tab(4);printf("Have a good day sir");
                    bye();
                    
               }
          }
          
     }
     return 0;
     
}

int nextround()
{
     cls();
     rounds++;
     if((won+lost)>=5)//if player play 5 chance
     {
          newline(6);
          tab(4); printf("Nice time with you %s",name);newline(2);
          tab(4); printf("You have no chance left for game vist another day");newline(4);
          tab(4); printf("Thank U ");
          Sleep(5000);
          bye();
     
     }
     else if(won==3) //if player won three chance
     {
          win2();
     }
     else if(lost==4)//if player lost four consicutive chance
     {
          loss2();
     }
                         
     intro3(new_amt);
     newline(6);                    
     tab(4);printf("Enter the money to bet : $");newline(2);
     tab(4);scanf("%d", &bet3);newline(2);
          bets:
     if(bet3>new_amt||bet3<1)
          {
               tab(4);printf("Money not in the limt of deposit ,");newline(2);
               tab(4);printf("Enter Again : $");newline(2);
               tab(5);scanf("%d", &bet3);
               cls();
               newline(6);
               goto bets;
          }
          
     cls();
     newline(6);
     tab(4);printf("Enter a number from 1 to 12 : ");newline(2);
     tab(4);scanf("%d", &guess2);newline(2);          
     if (rounds%2==0)
     {    
     if (namelen>=5)
     computer=(namelen*2*rounds+won)%12;
     else
     computer =(namelen*rounds+won)%12;
     }
     else
     {
          if (namelen>=5)
     computer=(namelen*2*rounds+lost)%12;
     else
     computer =(namelen*rounds+lost)%12;
     }
          gusses:
     if(guess2>12||guess2<1)
     {
          tab(4);printf("Number in not in the limt,");newline(2);
          tab(4);printf("Enter Again : ");newline(2);
          tab(5);scanf("%d", &guess2);
          cls();
          newline(6);
          goto gusses;
     }
     if(computer==0)
     computer=computer+12;
     dice();
     if(guess2==computer)
     {
          win(); 
          won++;    
          b= bet3 * 10;
          tab(4);printf("You have won $ %d", b);newline(2); 
          new_amt=b+(new_amt-bet3);
          tab(4);printf("You have won $%d as total",new_amt);newline(2);
          tab(4);printf("Press 1 for YES");newline(2);
          tab(4);printf("Press 2 for NO");newline(2);
          tab(4);printf("Do you want continue : ");newline(2);
          tab(4);scanf("%d", &decision);     
          if(decision==1)
          {
               nextround();    
          }
          else if(decision==2)
          {
               tab(4);printf("Have a good day sir");
               bye();
                    
          }
     }
     else if(guess2!=computer)
     {
          loss();
          lost++;
          tab(4);printf("You have loss $ %d", bet3);newline(2);
          tab(4);printf("The correct number is : %d", computer);newline(2);
          
          new_amt = new_amt - bet3;       
          
          if(new_amt==0)
          {
               tab(4);printf("You have $ %d as a balance",new_amt);newline(2);
               tab(4);printf("You have no more money to play");newline(2);
               tab(4);printf("Have a nice day");newline(2);
               bye();
          }
          else
          {
               tab(4);printf("You have $%d as a total", new_amt);newline(2);
               tab(4);printf("Press 1 for YES");newline(2);
               tab(4);printf("Press 2 for NO");newline(2);
          
               tab(4);printf("Do you want continue : ");newline(2);
               tab(4);scanf("%d", &decision);newline(2);
               if(decision==1)
               {
                    nextround();    
               }
               else if(decision==2)
               {
                    tab(4);printf("Have a good day sir");
                    bye();
               }
          }
     }     
          
          
        return 0;  
}

void rules()
{
     cls();
     int space;
     char welcome[100]= "=================================================================";
     char welcome2[100]="|                             RULES                             |";
     char welcome3[100]="================================================================ ";
     char welcome4[100]="|1. Choose any number between 1 to 12                           |";
     char welcome5[100]="|2. If you win you will get 10 times of money you bet           |";
     char welcome6[100]="|3. if you bet on wrong number you will lose your betting amount|";
     char welcome7[100]="=================================================================";
     newline(5);
     tab(2);
     ccolor(26);
      for(int wlc=0; wlc<strlen(welcome);wlc++){
             ccolor(120);

		printf(" %c",welcome[wlc]);
	} 
     newline(1);
     tab(2);
     ccolor(26);
     for(int wlc2=0; wlc2<strlen(welcome2);wlc2++)
     {
          space=welcome2[wlc2];    
          if(wlc2==0||wlc2==84)
          {
               ccolor(120);
		     printf(" %c",welcome2[wlc2]);
          }
          else if(space==32)
          {
               ccolor(120);
		     printf(" %c",welcome2[wlc2]);
          }
          else
          {
               ccolor(120+wlc2);
	     	printf(" %c",welcome2[wlc2]);
		     Sleep(200);
          }
	}
     newline(1);
     tab(2);
     Sleep(300);
     ccolor(26);
      for(int wlc3=0; wlc3<strlen(welcome3);wlc3++)
      {
          ccolor(120);
          printf(" %c",welcome[wlc3]);
	}
     newline(1);
     tab(2);
     Sleep(300);
     ccolor(26);
      for(int wlc4=0; wlc4<strlen(welcome4);wlc4++)
      {
          space=welcome4[wlc4];    
             if(wlc4==0||wlc4==84)
          {
               ccolor(120);
		     printf(" %c",welcome4[wlc4]);
               

          }
          else if(space==32)
          {
               ccolor(120);
		     printf(" %c",welcome4[wlc4]);
          }
          else
          {
               ccolor(120+wlc4);
	     	printf(" %c",welcome4[wlc4]);
		     Sleep(50);
          }
	}
     newline(1);
     tab(2);
     Sleep(300);
     ccolor(26);
      for(int wlc5=0; wlc5<strlen(welcome5);wlc5++)
      {
          space=welcome5[wlc5];    
            if(wlc5==0||wlc5==84)
          {
               ccolor(120);
		     printf(" %c",welcome5[wlc5]);
               

          }
         else if(space==32)
          {
               ccolor(120);
		     printf(" %c",welcome5[wlc5]);
          }
          else
          {
               ccolor(120+wlc5);
	     	printf(" %c",welcome5[wlc5]);
		     Sleep(50);
          }
	}
     newline(1);
     tab(2);
     Sleep(300);
     ccolor(26);
      for(int wlc6=0; wlc6<strlen(welcome6);wlc6++)
      {
          space=welcome6[wlc6];    
          if(wlc6==0||wlc6==84)
          {
               ccolor(120);
		     printf(" %c",welcome6[wlc6]);
               Sleep(50);

          }
          else if(space==32)
          {
               ccolor(120);
		     printf(" %c",welcome6[wlc6]);
          }
          else
          {
               ccolor(120+wlc6);
	     	printf(" %c",welcome6[wlc6]);
		     Sleep(50);
          }
	} 
     newline(1);
     tab(2);
     Sleep(300);
     ccolor(26);
     for(int wlc7=0; wlc7<strlen(welcome7);wlc7++)
     {
          ccolor(120);
          printf(" %c",welcome7[wlc7]);
	}
     newline(1);
     tab(4);printf("Press ENTER !!\n\n\t\t\t\tPress ENTER !!");
     scanf("%c",&a);
     cls();
     ccolor(26);
}

void intro()
{
	system("mode con: cols=80 lines=30");
     newline(6);
     tab(5);
     ccolor(26);
     char welcome[100]="Enter your name:";
     for(int wlc=0; wlc<strlen(welcome);wlc++)
     {
          ccolor(120+(wlc*12));
		printf(" %c",welcome[wlc]);
		Sleep(50);
	}
     ccolor(26);
     tab(6);
     gets(name);
     namelen=strlen(name);
     Sleep(500);
     newline(4);
     tab(5);
    char welcome2[100]="Enter the amount of money to deposit for the game : $";
    for(int wlc2=0; wlc2<strlen(welcome2);wlc2++)
    {
          ccolor(120+(wlc2*7));
		printf(" %c",welcome2[wlc2]);
		Sleep(50);
	}
     newline(1);
     tab(6);
     scanf("%d", &deposit);  
     Sleep(500);
     cls();
     round1();
}

void intro2( int amount)
{
	system("mode con: cols=80 lines=30");
     char welcome[50]="Hii,";
	char welcome2[50];
     strcpy(welcome2,strupr(name));
	char welcome3[50]="Your current balance is : $ ";
     char welcome4[50]="Enter the money to bet: $";

     newline(5);
     tab(3);
	for(int wlc=0; wlc<strlen(welcome);wlc++){
             ccolor(120+(wlc*9));

		printf(" %c",welcome[wlc]);
		Sleep(50);
	}
	ccolor(26);
	newline(3);
     tab(4);
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
            ccolor(160+(wlc2*7));

		printf(" %c",welcome2[wlc2]);
		Sleep(50);
	}
	ccolor(26);
	newline(3);
     tab(3);
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='a'){
		    ccolor(121+(wlc3*4));

			printf(" %c",welcome3[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(50);
	}
     newline(3);
     tab(12);
	ccolor(26);
	
	
                ccolor(121+(5*4));

			printf(" %d",amount);
		
		Sleep(50);
	newline(3);
     tab(3);
	ccolor(26);
     for(int wlc4=0; wlc4<strlen(welcome4);wlc4++){
             ccolor(120+(wlc4*12));

		printf(" %c",welcome4[wlc4]);
		Sleep(50);
	}
     ccolor(26);
     newline(2);
}

void intro3( int amount)
{
     char welcome[50]="Hii,";
	char welcome2[50];
     strcpy(welcome2,name);
	char welcome3[50]="Now You, have left with amount $";

     newline(6);
     tab(3);
	for(int wlc=0; wlc<strlen(welcome);wlc++){
          ccolor(120+(wlc*9));

		printf(" %c",welcome[wlc]);
		Sleep(50);
	}
     tab(1);
	ccolor(26);
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
          ccolor(160+(wlc2*9));

		printf(" %c",welcome2[wlc2]);
		Sleep(50);
	}
	ccolor(26);
	newline(5);
     tab(3);
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='a'){
		    ccolor(121+(wlc3*4));

			printf(" %c",welcome3[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(50);
	}
     newline(2);
	ccolor(26);
	tab(7);
	
                ccolor(121+(5*4));

			printf(" %d",amount);
		
		Sleep(50);
	
	ccolor(26);


}

void win()
{
     char yay[3]="YAY";
     char hurrah[8]="HURRAH !";
     char congrats[20]="Congratulation......";
     cls();
     newline(4);
     tab(4);
     for(int f=0;f<3;f++)
     {
          ccolor(120+(f*20));
          printf("%c",yay[f]);
          Sleep(50);
     }
     tab(2);
     for(int s=0;s<8;s++)
     {
          ccolor(120+(s*2));
          printf("%c",hurrah[s]);
          Sleep(50);

     }
     tab(2);
     for(int f=0;f<3;f++)
     {
          ccolor(120+(f*20));
          printf("%c",yay[f]);
          Sleep(50);
     }
     newline(3);
     tab(6);
     for(int t=0;t<20;t++)
     {
          ccolor(120+(t*4));
          printf("%c",congrats[t]);
          Sleep(50);
     }
          ccolor(26);
          newline(4);
         tab(4);printf("           @         @              @          @   @ @ @ @ @ @  @           @        ");newline(1);
         tab(4);printf("           @         @              @          @   @         @  @  @        @        ");newline(1);
         tab(4);printf("           @         @              @          @   @         @  @    @      @        ");newline(1);
         tab(4);printf("           @         @              @    @     @   @         @  @      @    @        ");newline(1);
         tab(4);printf("           @         @              @  @    @  @   @         @  @        @  @        ");newline(1);
         tab(4);printf("           @ @ @ @ @ @              @          @   @ @ @ @ @ @  @           @        ");newline(1);
          
          newline(2);
          printf("You have lot of moneny play again press ENTER!!");
          scanf("%c",&a);
          Sleep(2000);
          cls();
          newline(6);
          ccolor(26);
}

void win2()
{
     cls();
     newline(6);
     tab(4);printf("You Have a very lucky day....");newline(2);Sleep(300);
     tab(5);printf("We have lost too much..... ");newline(2);Sleep(300);
     tab(6);printf("Play when you have your bad luck with you");newline(2);Sleep(300);
     Sleep(1000);
     bye();
}

void loss()
{
     char yay[3]="OHH";
     char noo[3]="NOO";
     char hurrah[8]="Bad luck";
     char congrats[21]="Better luck next time";
     cls();
     newline(4);
     tab(4);
     for(int f=0;f<3;f++)
     {
          ccolor(120+(f*20));
          printf("%c",yay[f]);
          Sleep(50);
     }
     tab(2);
     for(int n=0;n<3;n++)
     {
          ccolor(120+(n*20));
          printf("%c",noo[n]);
          Sleep(50);
     }
     tab(2);
     for(int s=0;s<8;s++)
     {
          ccolor(120+(s*2));
          printf("%c",hurrah[s]);
          Sleep(50);

     }
     newline(3);
     tab(6);
     for(int t=0;t<20;t++)
     {
          ccolor(120+(t*4));
          printf("%c",congrats[t]);
          Sleep(50);
     }
          ccolor(26);
          newline(4);
         tab(4);printf("           @         @              @              @ @ @ @ @ @   @  @  @  @     @  @  @  @  @    ");newline(1);
         tab(4);printf("           @         @              @              @         @   @                    @          ");newline(1);
         tab(4);printf("           @         @              @              @         @   @  @  @  @           @          ");newline(1);
         tab(4);printf("           @         @              @              @         @            @           @          ");newline(1);
         tab(4);printf("           @         @              @              @         @            @           @          ");newline(1);
         tab(4);printf("           @ @ @ @ @ @              @ @ @ @ @ @    @ @ @ @ @ @   @  @  @  @           @          ");newline(1);
          
          newline(2);
          printf("Play again press ENTER!!");
          scanf("%c",&a);
          Sleep(2000);
          cls();
          newline(6);
          ccolor(26);
}

void loss2()
{
     cls();
     newline(6);
     tab(4);printf("You Have a very bad day....");newline(2);Sleep(300);
     tab(5);printf("You have lost too much..... ");newline(2);Sleep(300);
     tab(6);printf("Come daily, you are our one of the  best coustmore");newline(2);Sleep(300);
     Sleep(1000);
     bye();
}

void cls()
{

	system("cls");

}

void ccolor(int clr)
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

}

void pwellcome(){

	ccolor(26);

	char welcome[50]=" WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]="PIRATES";
	char welcome4[50]="CASINO";
	newline(6);
     tab(3);
	for(int wlc=0; wlc<strlen(welcome);wlc++){
             ccolor(120+(wlc*9));

		printf(" %c",welcome[wlc]);
		Sleep(200);
	}
	ccolor(26);
	newline(3);
     tab(5);
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
            ccolor(160+(wlc2*9));

		printf(" %c",welcome2[wlc2]);
		Sleep(200);
	}
	ccolor(26);
	newline(3);
     tab(6);
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='T'){
		    ccolor(121+(wlc3*4));

			printf(" %c",welcome3[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(200);
	}
	ccolor(26);
	newline(3);
     tab(8);
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
                ccolor(121+(wlc3*4));

			printf(" %c",welcome4[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(200);
	}
	ccolor(26);

}

void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}

void tab(int n){
     int i;
     for(i=1;i<=n;i++)
     {
          printf("\t");
     }
}

void newline(int n){
     int i;
     for(i=1;i<=n;i++)
     {
          printf("\n");
     }
}

void bye()
{
     cls();
   char byee[50]="Thanks for playing ....";
   char byee2[50]="Game presented by";
   newline(1);
   ccolor(26);
   tab(4);
   for(int f=0;f<strlen(byee);f++)
   {
     ccolor(120+(f*5));
     printf("%c",byee[f]);
   }
   newline(2);
   tab(7);
   for(int f=0;f<strlen(byee2);f++)
   {
     ccolor(120+(f*3));
     printf("%c",byee2[f]);
   }
   ccolor(26);
     newline(4);
     tab(4);printf("@ @ @ @ @    @ @ @ @    @       @    @ @ @ @ @    @ @ @ @ @    @       @   ");newline(1);
     tab(4);printf("@            @     @    @ @     @    @            @            @       @   ");newline(1);
     tab(4);printf("@     @ @    @ @ @ @    @   @   @    @ @ @ @      @ @ @ @ @    @ @ @ @ @   ");newline(1);
     tab(4);printf("@       @    @     @    @     @ @    @                    @    @       @   ");newline(1);
     tab(4);printf("@ @ @ @ @    @     @    @       @    @ @ @ @ @    @ @ @ @ @    @       @   ");newline(2);

     tab(5);printf(" # # # #     # # # #    # # # #     #     #     # # # #     #       #    # # #    # # # #");newline(1);
     tab(5);printf(" #     #     #     #    #           #     #     #     #     #       #    #   #       #   ");newline(1);
     tab(5);printf(" # # # #     # # # #    #           # # # #     # # # #     #       #    # # #       #   ");newline(1);
     tab(5);printf(" #           #     #    #           #     #     #     #     #       #    #  #        #   ");newline(1);
     tab(5);printf(" #           #     #    # # # #     #     #     #     #     # # # # #    #   #    # # # #");newline(1);
     
     exit(0);
}

void dice()
{    
     cls();
     int k=0;
     for (int i=0;i<120;i+=10){

		cls();
		ccolor(26);
          k++;

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		/* The code is printing a message indicating that k number of dice are being rolled. The message is
          formatted to include a tab and two new lines before the message is printed. */
          printf("%d... dices rolling...\n\n\t\t",k);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==100 || i==30){
			Sleep(100);
		}

	}
     newline(6);
    
}