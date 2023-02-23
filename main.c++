include<iostream>
#include<string>
#include<stdlib.h>
#define GRID_SIZE 3
using namespace std;

class Game
{
    private:
      char grid[GRID_SIZE][GRID_SIZE];
     
    public:
    
      Game(){
          generate_grid();
          show_grid();
          check_for_win();
          while(true){
          ask_turn();
          show_grid();
          check_for_win();
          
          computer_player_turn();
          show_grid();
          check_for_win();
          }
      }
      
      void check_for_win(){
          const char* winning_moves[8]={
          "123",
          "456",
          "789",
          "147",
          "258",
          "369",
          "159",
          "753",
      };
      
      for(int i=0; i<8; i++){
         bool winner= true;
         char previous_grid ='0';
         const char* winning_move=winning_moves[i];
         for (int index=0; index<GRID_SIZE; index++){
             char character = winning_move[index];
             int entered_number = character-'0';
             int grid_space = entered_number-1;
             int row = grid_space/GRID_SIZE;
             int col = grid_space%GRID_SIZE;
             
             char grid_char=grid[row][col];
             
             if(previous_grid == '0'){
                 previous_grid=grid_char;
             }
             else if(previous_grid == grid_char){
                 continue;
             }
             else{
                 winner = false;    
             }
         }
         if(winner){
             puts("*******8  you have winnner ***********");
             printf("look like %c won , congratulation\n",previous_grid);
             exit(0);
             break;
         } 
       }
    }
          
      void generate_grid(){
          int number = 1;
          for( int x=0; x<GRID_SIZE; x++){
              for (int y=0; y<GRID_SIZE; y++){
                  grid[x][y]= to_string(number).c_str()[0];
                  number+= 1;
               }
           }
      }
      
      void show_grid(){
          printf("\n----------\n");
          for( int x=0; x<GRID_SIZE; x++){
              for (int y=0; y<GRID_SIZE; y++){
                 printf("%c | ", grid[x][y]);     
              }
              printf("\n----------\n");
          }  
     }
     
     void ask_turn(){
          string input;
          
          while (true){
             puts("where would you like to play");
             getline(cin,input);
             
             if (input !=""){
                char entered = input.c_str()[0];
                if(entered >= '1'&& entered <= '9'){
                    int entered_number = entered - '0'; // cahracter to integer
                    int index = entered_number - 1;
                    
                    int row = index/3;
                    int col = index%3;
                    char grid_position = grid[row][col];
                    if (grid_position == 'X' || grid_position == '0'){
                       puts("that grid position is already taken!");
                       }
                    else{
                       grid[row][col]='X';
                       break;
                       }
                    }
                else{
                    puts("you have to play in range 0-9!");
                   }
                 }
             else{
                puts("you must enter something");
                }
            }
       }
       
       void computer_player_turn(){
           
           while(true){
             int computer_choice = ( rand() % 9 ) + 1 ;
             int row = (computer_choice-1)/3;
             int col = (computer_choice-1)%3;
             char grid_position = grid[row][col];
             if(grid_position == 'X'|| grid_position == '0'){
                continue; 
             }
             else{
                printf("the computer will play at %d.\n",computer_choice);
                grid[row][col]='0';
                break;
             }
           }
       }
}; 
int main(int argc, char *argv[]){
    
    Game game;
    return 0;
}
