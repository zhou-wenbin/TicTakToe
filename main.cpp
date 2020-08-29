#include <iostream>

using namespace std;

/*************************************************
This is the funciton to print the board
***************************************************/

void showBoard(char *pSquare)
{ cout<< "     "<<endl;
      for (int y=0;y<3;y++){
        if (y!=2){
    for (int x = 0;x<3;x++){

            if (x!=2){
        char outChar = *pSquare;
        cout<<outChar;
        pSquare++;
        cout<< "|";}
        else{
               char outChar = *pSquare;
        cout<<outChar<<endl;
        pSquare++;}
    }
    cout<< "     "<<endl;
    cout<< "-+-+-"<<endl;
    cout<< "     "<<endl;
        }
        else
        {
        for (int x = 0;x<3;x++){

            if (x!=2){
        char outChar = *pSquare;
        cout<<outChar;
        pSquare++;
        cout<< "|";}
        else{char outChar = *pSquare;
        cout<<outChar<<endl;
        pSquare++;}
    }
        }
  }
cout<< "     "<<endl;
}


int main()

{
  const char PLAYER_X = 'X';
  const char PLAYER_O = 'O';
  int chosenSquare = 0;
  char lastPlayer = PLAYER_O , currentPlayer = PLAYER_X;
  char board[3][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  };



  // There is no need to use pointer here, for learning purpose i used a pointer here on purpose.
  char *pFirstSquare = &board[0][0];

// X plays first
bool playerIsX = true;
bool top_row,second_row,third_row,first_column,second_column,third_column,upward,downward;





/*************************************************
This is the loop for play
***************************************************/


do {
    char mark = (playerIsX)? 'X':'O';

  cout<< "Player " << mark <<", enter a number between 1 and 9: ";
  cin>>chosenSquare;
  cout<< "     "<<endl;
 /*
 ref: https://marycore.jp/prog/c-lang/convert-number-to-char/

 char '0' represents 48, if added a number, say 5, it becomes 53, which is represented by char '5'
 */

  char StrChosenSquare = '0'+ chosenSquare;


   if ((chosenSquare < 10 || chosenSquare > 1 )&&( board[(chosenSquare-1) / 3][(chosenSquare-1) % 3] == StrChosenSquare))

  {
   board[(chosenSquare-1) / 3][(chosenSquare-1) % 3]  = mark;
  }
   else if (chosenSquare > 9 || chosenSquare < 0)
   {
       cout<<"Not a valid choice"<<endl;
       continue;
   }
   else if (board[(chosenSquare-1) / 3][(chosenSquare-1) % 3] != StrChosenSquare)
   {
       cout<<"The square is not available. Try again."<<endl;
       continue;
   }



  cout<< "current board state: "<<endl;
  showBoard(pFirstSquare);
  bool top_row = (board[0][0] == board[0][1] && board[0][1]== board[0][2]);
  bool second_row = (board[1][0] == board[1][1] && board[1][1]== board[1][2]);
  bool third_row = (board[2][0] == board[2][1] && board[2][1]== board[2][2]);
  bool first_column = (board[0][0] == board[1][0] && board[1][0] == board[2][0]);
  bool second_column = (board[0][1] == board[1][1]&& board[1][1]== board[2][1]);
  bool third_column = (board[0][2] == board[1][2] &&board[1][2]== board[2][2]);
  bool upward = (board[2][0] == board[1][1] &&board[1][1]==board[0][2]);
  bool downward = (board[0][0] == board[1][1] &&board[1][1] ==board[2][2]);
  bool winFlag = (top_row||second_row||third_row||first_column||second_column||third_column||upward ||downward );

  if (winFlag)
    //jump out of the loop to terminate the play.
    break;
    else{
        //switch player
        playerIsX=!playerIsX;
    }


}while(true);


/*************************************************

when winner is decided, show the winning player and the winning place.
***************************************************/

if (playerIsX){

    if (top_row){cout<<"PlayerX wins on the top row"<<endl;}
else if(second_row){cout<<"PlayerX wins on the second row"<<endl;}
else if(third_row) {cout<<"PlayerX wins on the third row"<<endl;}
else if(first_column) {cout<<"PlayerX wins on the first column"<<endl;}
else if(second_column) {cout<<"PlayerX wins on the second column"<<endl;}
else if(third_column) {cout<<"PlayerX wins on the third column"<<endl;}
else if(upward) {cout<<"PlayerX wins on the upward diagonal"<<endl;}
else if(downward) {cout<<"PlayerX wins on the downward diagonal"<<endl;}



}
else {
    if (top_row){cout<<"PlayerO wins on the top row"<<endl;}
else if(second_row){cout<<"PlayerO wins on the second row"<<endl;}
else if(third_row) {cout<<"PlayerO wins on the third row"<<endl;}
else if(first_column) {cout<<"PlayerO wins on the first column"<<endl;}
else if(second_column) {cout<<"PlayerO wins on the second column"<<endl;}
else if(third_column) {cout<<"PlayerO wins on the third column"<<endl;}
else if(upward) {cout<<"PlayerO wins on the upward diagonal"<<endl;}
else if(downward) {cout<<"PlayerO wins on the downward diagonal"<<endl;}

}
}


