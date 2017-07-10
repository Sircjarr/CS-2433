#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Player {
   public:
      virtual int getGuess() {
         return 0;
      }
   };

class HumanPlayer : public Player {
   public:
      int getGuess() {
         int guess;
         cin >> guess;
         return guess;
      }
   };

class ComputerPlayer : public Player {
   public:
      int getGuess() {
         int guess = rand() % 100;
         cout << "The computer guesses " << guess << endl;
         return guess;
      }
   };

//////////////////////////////////////
// Global functions given in project
//////////////////////////////////////

bool checkForWin(int guess, int answer)
{
  if (answer == guess)
  {
     cout << "You're right! You win!" << endl;
     return true;
  }
  else if (answer < guess)
     cout << "Your guess is too high." << endl;
  else
     cout << "Your guess is too low." << endl;
  return false;
}

void play(Player &player1, Player &player2)
{
  int answer = 0, guess = 0;
  answer = rand() % 100;
  bool win = false;

  while (!win)
  {
   cout << "Player 1's turn to guess." << endl;
   guess = player1.getGuess();
   win = checkForWin(guess, answer);
   if (win) return;

   cout << "Player 2's turn to guess." << endl;
   guess = player2.getGuess();
   win = checkForWin(guess, answer);
  }
}

int main()
{
	srand(1);
	HumanPlayer humanPlayer1;
	HumanPlayer humanPlayer2;
	ComputerPlayer computerPlayer1;
	ComputerPlayer computerPlayer2;
	cout << "Human vs Human\n";
	cout << "Press a key to continue..." << endl;
	char c;
	cin >> c;
	//cout << humanPlayer1.getGuess();
	play(humanPlayer1, humanPlayer2);

	cout << "Human vs Computer\n";
	cout << "Press a key to continue...";
	cin >> c;
	play(humanPlayer1, computerPlayer1);

	cout << "Computer vs Computer\n";
	cout << "Press a key to continue...";
	cin >> c;
	play(computerPlayer1, computerPlayer2);

	return 0;
}