/*--------------------------------------
main.cpp
compiled with BlackJack.cpp
BlackJack driver program
Authors: Josh Kiss, Rob Piccirillo
---------------------------------------*/
#include "BlackJack.h"

//std::ostream& operator<<(std::ostream& os, const BlackJack& game)
// {
   // os << b.dealPlayerCard << "/" << endl;
	// os << b.dealDealerCard << "/" << endl;
   // return os;
// }


int main()
{
  cout << "Welcome to BlackJack!" << endl;
  cout << "Ready to play? (press Y/N)" << endl;

  string start;
  cin >> start;

  BlackJack game;
  if (start =="Y" || start == "y")
	{
	int bet;
	int money = 1000;	
	do 		// Runs the game while you have money.
	{
		cout << "You currently have $" << money << endl;
		cout << "Place your bet: (Minimum: $10, Maxmimum: $" << money << "): " << endl;
		cin >> bet;               // Takes players input for the bet
		while ( bet <10 || bet > money )      // Place restrictions on how to bet
		{
		if (bet < 10)
		cout << "\nWe ain't playing kiddie BlackJack! Make a real bet!";
		if (bet > money)
		cout << "\nYou don't have enough money!";
		cout << "Place your bet: (Minimum: $10, Maxmimum: $" << money << "): " << endl;
		cin >> bet;
		}
		cout << "\nYou bet $" << bet << endl;
		cout << "\n\n Press any key to play:" << endl;
		cin.get();  // Allows player to interact & choose when to continue

          game.loadDeck(); //initialize deck with card values
          bool run = true;


          //start player and dealer off with two cards
		  cout << "Your first card is a(n) ";
          game.dealPlayerCard();
		  cout << "\n\n Press any key to continue:" << endl;

		  cout << " " << endl;
		  cout << " " << endl;

		  cin.get();
		  
		  cout << "The dealer draws his first card: ";
          game.dealDealerCard();
		  cout << "\n\n Press any key to continue:" << endl;
		  cout << " " << endl;
		  cout << " " << endl;
		  cin.get();
		  
		  cout << "Your second card is a(n) "; 
          game.dealPlayerCard();
		  cout << "\n\n Press any key to continue:" << endl;
		  cout << " " << endl;
		  cout << " " << endl;
		  cin.get();
		  
		  cout << "The dealer draws his second card: ";
          game.dealDealerCard();
		  cout << "\n\n Press any key to continue:" << endl;
		  cout << " " << endl;
		  cout << " " << endl;
		  cin.get();
		  
		  
		  cout << "You have cards:" << endl;
          game.getPlayerHand(); //display players cards
		  cout << " = " << game.getPlayerSum() << endl;
		  cout << " " << endl;
		  cout << " " << endl;

          cout << "Dealer has cards:" << endl;
          game.getDealerHand(); //display dealers cards
		  cout << " = " << game.getDealerSum() << endl;
		  cout << " " << endl;
		  cout << " " << endl;

		  hitagain:
		  
          cout << "Do you want to draw a card? (Y/N)" << endl;
          string draw;
          cin >> draw;

          if (draw == "y" || draw == "Y")
            {
			  cout << "You've drawn a..." << endl;
              game.dealPlayerCard();
			  cout << "You stand at: " << game.getPlayerSum() << endl;
			  cout << " " << endl;
			  cout << " " << endl;

			  cin.get();
			  if (game.getDealerSum() < 17)
			  {
				  game.dealDealerCard();
				  cout << "The dealer stands at: " << game.getDealerSum() << endl;
		          cout << "\n\n Press any key to continue:" << endl;
				  cin.get();

				  if (game.getDealerSum() > 21) // Can't go over 21!
					{
						cout << "The dealer bust! You've won!" << endl;
						money += bet;
						cout << " " << endl;
						cout << " " << endl;
						game.clearHands();
					}

				}
			  if (game.getPlayerSum() < 22) goto hitagain;	

			  else 
			  {
				  cout << "You gone over 21! You're at: " << game.getPlayerSum() << endl;
			  }
			  
            }
		  if (game.getPlayerSum() > 21)
		  {
			cout << "You bust!" << endl;
			money -= bet;
			game.clearHands();
		  }
		  else
		  {
			  while (game.getDealerSum() < 17) // As long as dealer has less than
			  {
				cout << "The dealer hits again... And now has... " << endl;
				game.dealDealerCard();
				cout << "The dealer stands at... " << game.getDealerSum() << endl;
				cout << " " << endl;
				cout << " " << endl;		
				cin.get();
			  }
			  if (game.getDealerSum() > 21) // Can't go over 21!
			  {
				  cout << "The dealer bust! You've won!" << endl;
				  money += bet;
				  cout << " " << endl;
				  cout << " " << endl;
				  game.clearHands();
			  }
			  
			  
			  {
				  cout << "The dealer stands at: "; 
				  cout << game.getDealerSum() << endl;
				  if (game.getPlayerSum() == game.getDealerSum())
				  {
					  cout << "We have a draw!" << endl;
					  game.clearHands();
				  }
				  else {}
				  if (game.getPlayerSum() == 21)
				  {
					  cout << "You got blackjack! You win!" << endl;
					  money += bet;
					  game.clearHands();
				  }
				  else {}
				  if (game.getPlayerSum() > game.getDealerSum())
				  {
					  cout << "You win!" << endl;					  
					  money += bet;
					  cout << " " << endl;
					  cout << " " << endl;
					  game.clearHands();
				  }
				   else {}
				   if (game.getPlayerSum() < game.getDealerSum())
				   {
					   cout << "You lose!" << endl;
					   money -= bet;
					   cout << " " << endl;
					   cout << " " << endl;
					   game.clearHands();
				   }
			  }
	}
	}
	while (money > 10); // Let's player know the game is over!
	{
	  cout << "You're all out of money! Come back another time." << endl;
	  cout << "Good game!" << endl;
	  exit;
	
	}
  	  
		  
    }

	

  
  return 0;
  

}
