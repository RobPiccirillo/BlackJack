/*--------------------------------------
main.cpp
compiled with BlackJack.cpp
BlackJack driver program
Authors: Josh Kiss, Rob Piccirillo
---------------------------------------*/
#include "BlackJack.h"

int main()
{
  cout << "welcome to blackjack" << endl;
  cout << "ready to play? (press Y/N)" << endl;

  string start;
  cin >> start;

  if (start =="Y" || start == "y")
    {
          blackjack game;
          game.loadDeck(); //initialize deck with card values
          bool run = true;


          //start player and dealer off with two cards
          game.dealPlayerCard();
          game.dealDealerCard();
          game.dealPlayerCard();
          game.dealDealerCard();

          cout << "You have cards:" << endl;
          game.getPlayerHand(); //display players cards

          cout << "Dealer has cards:" << endl;
          game.getDealerHand(); //display dealers cards

          cout << "Do you want to draw a card? (Y/N)" << endl;
          string draw;
          cin >> draw;

          while (draw == "y" || draw == "Y")
            {
              game.dealPlayerCard();

              game.dealerSplit();//check to see if dealer splits

            }
    }

          else
            {
              game.playerSplit();  //player stops
              game.playerWin();
            }


    }


  return 0;

}
