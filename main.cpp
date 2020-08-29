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
bool top_row=0,second_row=0,third_row=0,first_column=0,second_column=0,third_column=0,upward=0,downward=0,winFlag=0;




/*************************************************
This is the loop for play
***************************************************/

int playround=0;
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
   playround++;
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
  top_row  = (board[0][0] == board[0][1] && board[0][1]== board[0][2]);
  second_row = (board[1][0] == board[1][1] && board[1][1]== board[1][2]);
  third_row = (board[2][0] == board[2][1] && board[2][1]== board[2][2]);
  first_column = (board[0][0] == board[1][0] && board[1][0] == board[2][0]);
  second_column = (board[0][1] == board[1][1]&& board[1][1]== board[2][1]);
  third_column = (board[0][2] == board[1][2] &&board[1][2]== board[2][2]);
  upward = (board[2][0] == board[1][1] &&board[1][1]==board[0][2]);
  downward = (board[0][0] == board[1][1] &&board[1][1] ==board[2][2]);
   winFlag = (top_row||second_row||third_row||first_column||second_column||third_column||upward ||downward );

  if (winFlag)
    //jump out of the loop to terminate the play.
    break;
    else{
        //switch player
        playerIsX=!playerIsX;
    }


 if(!winFlag && playround ==9)
    break;


}while(true);


/*************************************************

when winner is decided, show the winning player and the winning place.
***************************************************/

if (playerIsX && top_row){
        cout<<"PlayerX wins on the top row"<<endl;}

else if(playerIsX &&second_row){
    cout<<"PlayerX wins on the second row"<<endl;}
else if(playerIsX &&third_row)
{cout<<"PlayerX wins on the third row"<<endl;}
else if(playerIsX &&first_column)
{cout<<"PlayerX wins on the first column"<<endl;}
else if(playerIsX &&second_column)
{cout<<"PlayerX wins on the second column"<<endl;}
else if(playerIsX &&third_column)
{cout<<"PlayerX wins on the third column"<<endl;}
else if(playerIsX &&upward)
{cout<<"PlayerX wins on the upward diagonal"<<endl;}
else if(playerIsX &&downward)
{cout<<"PlayerX wins on the downward diagonal"<<endl;}

else if (!playerIsX && top_row)
    {cout<<"PlayerO wins on the top row"<<endl;}
else if(!playerIsX && second_row)
{cout<<"PlayerO wins on the second row"<<endl;}
else if(!playerIsX && third_row)
{cout<<"PlayerO wins on the third row"<<endl;}
else if(!playerIsX && first_column)
{cout<<"PlayerO wins on the first column"<<endl;}
else if(!playerIsX && second_column)
{cout<<"PlayerO wins on the second column"<<endl;}
else if(!playerIsX && third_column)
{cout<<"PlayerO wins on the third column"<<endl;}
else if(!playerIsX && upward)
{cout<<"PlayerO wins on the upward diagonal"<<endl;}
else if(!playerIsX && downward)
{cout<<"PlayerO wins on the downward diagonal"<<endl;}

if(playround == 9&& !winFlag){
    cout<<" Draw. Nobody wins"<<endl;
}




}


