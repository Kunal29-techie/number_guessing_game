#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int secret, guess, max_tries, range, score = 100;
    
    char difficulty, play_again;
    
    srand(time(0));
    
    printf("=== NUMBER GUESSING GAME ===\n");

    printf("Guess the secret number to win!\n\n");
    
    do {
      
        printf("Choose difficulty:\n");
        printf("E - Easy (1-50, 10 tries)\n");
        printf("M - Medium (1-100, 7 tries)\n");
        printf("H - Hard (1-200, 5 tries)\n");
        printf("Your choice: ");

        scanf(" %c", &difficulty);
        

        switch(difficulty)
        {
            case 'E': case 'e':
                range = 50; max_tries = 10; break;
            case 'M': case 'm':
                range = 100; max_tries = 7; break;
            case 'H': case 'h':
                range = 200; max_tries = 5; break;
            default:

                printf("Invalid choice! Using Medium.\n");
                range = 100; max_tries = 7;
        }
        
        secret = rand() % range + 1; //  random number
        score = 100; 
        
        printf("\nI'm thinking of a number between 1 and %d.\n", range);

        printf("You have %d tries. Let's begin!\n\n", max_tries);
        
        
        for(int tries = 1; tries <= max_tries; tries++)
        {
            printf("Attempt %d/%d | Score: %d\n", tries, max_tries, score);
            printf("Your guess: ");
            
            
            if(scanf("%d", &guess) != 1)
            {
                printf("Numbers only please!\n");

                while(getchar() != '\n'); 
                tries--; 

                continue;
            }
            
            
            if(guess == secret) 
            {
                printf("\n*** CORRECT! You won with %d points! ***\n", score);
                break;
                
            } 
            else if(guess < secret) 
            {
                printf("Too low! ");
                if(secret - guess <= 10) printf("(Very close!)\n");
                else printf("\n");
            }
            else
            {
                printf("Too high! ");
                if(guess - secret <= 10) printf("(Very close!)\n");
                else printf("\n");
            }
            
            score -= 100/max_tries; 
            
            
            if(tries == max_tries)
            {
                printf("\nGame over! The number was %d.\n", secret);
            }
        }
        
        
        printf("\nPlay again? (Y/N): ");

        scanf(" %c", &play_again);
        printf("\n");
        
    }
    
    while(play_again == 'Y' || play_again == 'y');
    
    printf("Thanks for playing!\n");
    
    return 0;
}

