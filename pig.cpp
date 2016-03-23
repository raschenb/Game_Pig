#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  int die;
  int myScore = 0;
  int computerScore = 0;
  int turnScore = 0;
  char choice;
  bool change = false;

  bool weHaveAWinner = false;
  cout << "Welcome to Pig! Please select from the following menu: ";

    //Enclosing infinite loop, only can exit on return
    while (true) {
    //Player turn loop, can exit with breaks to main loop
    while (true){
      cout << "\nRoll [r], Hold [h], or Quit [q].";
      cin >> choice;

      if(choice == 'r'){
        die=(rand() % 6 + 1); //Number generator for die

        if(die > 1){
          cout << "You rolled a " << die << "." << endl;
          turnScore += die;
          if (turnScore + myScore >=100) {
            cout << "You win!" << endl;
            //Winning condition met. Game over and return.
            return 0;
          }
          cout << "You will add " << turnScore << " points if you pass now. ";}
        else{
          cout << "You rolled a 1. You lose your points and your turn ends." << endl;
          turnScore = 0;
          //End turn. Breaks secondary loop.
          break;
        }
      }

      if(choice == 'h')   {
        myScore += turnScore;
        cout << "Your score is now " << myScore << "." << endl;
        turnScore = 0;
        change = true;
        //End turn. Breaks secondary loop.
        break;
      }  //needs to go to Computer now


      if(choice == 'q')
      {cout << "\n\tThanks for playing!\n ";
        return 0; }

      else if(choice > 'r' || choice < 'h')
      {cout << "Please select from the choices listed."; }

    }

    while (true){
       //Computers turn loop, can exit with breaks to main loop
      if(myScore > computerScore && turnScore < 17 || computerScore > myScore && turnScore < 12 || computerScore > 84){

        choice='r';
        cout << "The Computer rolls! " << endl;

        if(choice == 'r'){
          die=(rand() % 6 + 1); //Number generator for die
          if(die > 1){
            cout << "The Computer rolls a " << die << "." << endl;
            turnScore += die;
            if (turnScore + computerScore >=100) {
              //Winning condition met. Game over and return.
              cout << "The Computer wins!" << endl;
              return 0;
            }
          }else{
            cout << "The Computer rolls a 1. He loses his points and now it's your turn!" << endl;
            turnScore = 0;
            change = false;
            //End turn. Breaks secondary loop.
            break;
          }

        }
      }else{

        cout << "The Devil chooses to pass. ";
        computerScore += turnScore;
        choice='h';
        turnScore = 0;
        cout << "He has " << computerScore << " points. " << endl;
        cout << "The Computer now has " << computerScore << " points." << endl;
        change = false;
        //End turn. Breaks secondary loop.
        break;
      }
    }
  }
}
