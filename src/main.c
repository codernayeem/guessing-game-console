#include<stdio.h>
#include<conio.h>


void start_game(int min, int max)
{
    int range[] = {min , max};

    printf("You have to guess a number between %d and %d.\n Are you ready ? ", min , max);
    if (getYorN() != 1){
        printf("\nOK\n");
    }else{
        printf("\nLet's start......!\n");
        int ans, count = 0;
        while(max - min > 1){
            count++;
            printf("\nIs your number is between %d and %d ?", min , ((min+max) / 2));
            ans = getYorN();
            if (ans == 1){
                max = (min+max) / 2;
            }else if (ans == 2){
                min = (min+max) / 2 + 1;
            }
        }

        if(max - min == 1){
            printf("\nIs your number is between %d and %d ? " , max , (max + 1));
            ans = getYorN();
            count++;
            if (ans == 1){
                Result(max , count, range[0], range[1]);
            }else if (ans == 2){
                Result(min , count, range[0], range[1]);
            }
        }else if(max == min){
            Result(min , count, range[0], range[1]);
        }
    }
}

void Result(int res, int count, int min, int max){
    if(count == 1){
        printf("\n\tHa! Got it in an easy step. Your number is = %d\n" ,res);
    }else{
        printf("\n\tHa! Got it in %d step. Your number is = %d\n" , count,res);
    }
}

int getYorN(){
    char c;
    while (1){
        printf("\n(y/n)--: ");

        if(scanf(" %c", &c) == 1){
            if (c == 'Y' || c == 'y'){
                return 1;
            }else if(c == 'n' || c == 'N'){
                return 2;
            }

        }else{
            printf("Command did not found. Try again.");
        }
    }
}

int main()
{
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\t\t\t*    Welcome to Guessing Game   *");
    printf("\n\t\t\t*                               *");
    printf("\n\t\t\t*\xB1\xB1\xB1\xB1 Made by  @codernayeem \xB1\xB1\xB1\xB1*");
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\nLet's play a game.\n\n");

    start_game(1, 100);

    getch();
    return 0;
}
