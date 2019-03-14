#include <iostream>
#include <cstdlib>

using namespace std;

//Prints the board
void printBoard(int boardArray[3][3], int OVR[9]);

//Converts integers to X/O/whitespace
char numToChar(int value);

//Update the board with the player selection
void updateBoard(int boardArray[3][3], int value, int player);

//Validate the user choice
int validChoice(int choice, int OVR[9]);

//Check if there is a winning combination on the board
bool checkWinState(int boardArray[3][3]);


int main() {

  srand(time(0)); //Seed for random values

  //Print the menu 
  cout << "Welcome to Tic-Tac-Toe OVER-RIDE" << endl << endl;
  cout << "The rules are simple. It's just like regular tic-tac-toe," << endl;
  cout << "except, you can place a piece over your opponent's." << endl;
  cout << "There is a limit though, each piece can only be overridden" << endl;
  cout << "a set number of times. That number is in the top left" << endl;
  cout << "of each square." << endl;
  cout << "Each time you place a piece, the adjacent squares limit goes up by 1." << endl;
  cout << endl << endl;
  cout << "Would you like to play?" << endl;
  cout << "1.Yes" << endl;
  cout << "2.No" << endl;
  int userChoice;
  cin >> userChoice; //Validate input

  cout << "\033[2J\033[1;1H"; //Clear the console

  while(userChoice == 1){
    //Set the override limit for each square to a random integer 
    //bewtween 1 & 3
    int overRideLimit1 = 1; //rand() % 2 + 2;
    int overRideLimit2 = 1; //rand() % 2 + 2;
    int overRideLimit3 = 1; //rand() % 2 + 2;
    int overRideLimit4 = 1; //rand() % 2 + 2;
    int overRideLimit5 = 1; //rand() % 2 + 2;
    int overRideLimit6 = 1; //rand() % 2 + 2;
    int overRideLimit7 = 1; //rand() % 2 + 2;
    int overRideLimit8 = 1; //rand() % 2 + 2;
    int overRideLimit9 = 1; //rand() % 2 + 2;

    //Generate an array to hold all the values
    int OVR[9] ={overRideLimit1,overRideLimit2,overRideLimit3,
                 overRideLimit4,overRideLimit5,overRideLimit6,
                 overRideLimit7, overRideLimit8, overRideLimit9};

      
      cout << "Player 1 will be X and Player 2 will be O." << endl;
      cout << "Player 1 will go first." << endl << endl << endl;
      
      int board[3][3] ={}; //Generate the game board

      printBoard(board, OVR); //Print the empty game board
      cout << endl << endl;
      
      bool winState = false; //Set the win state to false before the game

      while(winState == false){
        //Player 1 goes first
        cout << "Player 1, enter your selection" << endl;
        cout << "1 is the top left, 9 is the bottom right" << endl;
        int boardChoice;
        cin >> boardChoice;

        boardChoice = validChoice(boardChoice, OVR);

        updateBoard(board, boardChoice, 1); //Update the board with the user's choice

        cout << "\033[2J\033[1;1H"; //Clear the old board

        printBoard(board, OVR); //Print the revised board
        cout << endl << endl;

        winState = checkWinState(board); //Check for a winning state

          if(winState == true){

              cout << "Player 1 has defeated Player 2." << endl;
          } 


        //Check for the win before the next player's turn
        if(winState == false){

          cout << "Player 2, enter your selection" << endl;
          cout << "1 is the top left, 9 is the bottom right" << endl;
          int boardChoice;
          cin >> boardChoice; 

          boardChoice = validChoice(boardChoice, OVR); //Validate the player's choice

          updateBoard(board, boardChoice, 2); //Update the board with the user's choice

          cout << "\033[2J\033[1;1H"; //Clear the old board

          printBoard(board, OVR); //print the revised board
          cout << endl << endl;

          winState = checkWinState(board); //Check for a winning move

            if(winState == true){

              cout << "Player 2 has defeated Player 1." << endl;
            }

        }

      }

      //Ask the user to play again
      cout << "Would you like to play again?" << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;
      cin >> userChoice; // Validate

      cout << "\033[2J\033[1;1H"; //Clear the console
  }

  if(userChoice == 2){
    cout << "Goodbye!" << endl;
  }

  

}

//This function prints the number of overrides left as well as the players pieces and
//the board.
void printBoard(int boardArray[3][3], int OVR[9]){

  cout << OVR[0] << " " << numToChar(boardArray[0][0]) << " | " << OVR[1] << " " << numToChar(boardArray[0][1]) << " | " << OVR[2] << " " << numToChar(boardArray[0][2]) << endl;
      cout << "----|-----|-----" << endl;
      cout << OVR[3] << " " << numToChar(boardArray[1][0]) << " | " << OVR[4] << " " << numToChar(boardArray[1][1]) << " | " << OVR[5] << " " << numToChar(boardArray[1][2]) << endl;
      cout << "----|-----|-----" << endl;
      cout << OVR[6] << " " << numToChar(boardArray[2][0]) << " | " << OVR[7] << " " << numToChar(boardArray[2][1]) << " | " << OVR[8] << " " << numToChar(boardArray[2][2]) << endl;

}


//This function takes integer values and converts them to player pieces like X and O.
//1=X, 2=O, 0=whitespace/empty
char numToChar(int value){

  char c;

  if(value == 0){
    c = ' ';
  }
  else if(value == 1){
    c = 'X';
  }
  else if(value == 2){
    c = 'O';
  }

return c;

}


//This function updates the current board with the players choice.
//It takes the board, the spot they chose, and the player (1 or 2)
//and updates accordingly.
void updateBoard(int boardArray[3][3], int value, int player){

  if(value == 1){
    boardArray[0][0] = player;
  }
  else if(value == 2){
    boardArray[0][1] = player;
  }
  else if(value == 3){
    boardArray[0][2] = player;
  }
  else if(value == 4){
    boardArray[1][0] = player;
  }
  else if(value == 5){
    boardArray[1][1] = player;
  }
  else if(value == 6){
    boardArray[1][2] = player;
  }
  else if(value == 7){
    boardArray[2][0] = player;
  }
  else if(value == 8){
    boardArray[2][1] = player;
  }
  else if(value == 9){
    boardArray[2][2] = player;
  }


}


//This function validates the users choice to make sure it
//is between 1 & 9 and that the space can still be overriden.
//Once the spot has been validated, the override value is deducted.
int validChoice(int value, int OVR[9]){

  if((value >= 1 || value <= 9) && OVR[value-1] > 0 ){
      --OVR[value-1];
      //Increase adjacent spaces
      if(value == 1){
        OVR[1]++;
        OVR[3]++;

      }
      else if(value == 2){
        OVR[0]++;
        OVR[2]++;
        OVR[4]++;

      }
      else if(value == 3){
        OVR[1]++;
        OVR[5]++;
        
      }
      else if(value == 4){
        OVR[0]++;
        OVR[4]++;
        OVR[6]++;
      }
      else if(value == 5){
        OVR[1]++;
        OVR[3]++;
        OVR[5]++;
        OVR[7]++;
        
      }
      else if(value == 6){
        OVR[2]++;
        OVR[4]++;
        OVR[8]++;
        
      }
      else if(value == 7){
        OVR[3]++;
        OVR[7]++;
        
      }
      else if(value == 8){
        OVR[4]++;
        OVR[6]++;
        OVR[8]++;
        
      }
      else if(value == 9){
        OVR[5]++;
        OVR[7]++;
        
      }
  }
  else{
    cout << "Please enter a valid choice:";
    int choice;
    cin >> choice;
    value = validChoice(choice,OVR);
  }

  return value;

}


//This function checks for a winning state.
//It first checks all rows for 3 in a row,
//then all columns and lastly all diagonals.
//It also makes sure they are non-zero values.
bool checkWinState(int boardArray[3][3]){

  bool winState = false;

  //Check rows
  if((boardArray[0][0] == boardArray[0][1] && boardArray[0][0] == boardArray[0][2] && boardArray[0][0] != 0) ||
     (boardArray[1][0] == boardArray[1][1] && boardArray[1][0] == boardArray[1][2] && boardArray[1][0] != 0) ||
     (boardArray[2][0] == boardArray[2][1] && boardArray[2][0] == boardArray[2][2] && boardArray[2][0] != 0) ){
   
       winState = true;

  }

  //Check Columns
  if((boardArray[0][0] == boardArray[1][0] && boardArray[0][0] == boardArray[2][0] && boardArray[0][0] > 0) ||
     (boardArray[0][1] == boardArray[1][1] && boardArray[0][1] == boardArray[2][1] && boardArray[0][1] > 0) ||
     (boardArray[0][2] == boardArray[1][2] && boardArray[0][2] == boardArray[2][2] && boardArray[0][2] > 0) ){
       winState = true;

  }

  //Check diagonals
  if((boardArray[0][0] == boardArray[1][1] && boardArray[0][0] == boardArray[2][2] && boardArray[0][0] > 0) ||
     (boardArray[2][0] == boardArray[1][1] && boardArray[2][0] == boardArray[0][2] && boardArray[2][0] > 0) ){

      winState = true;
  }

  return winState;
}

