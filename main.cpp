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
  cout << "welcome to BlackJack" << endl;
  cout << "ready to play? (press Y/N)" << endl;

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
		while ( bet <10 || bet > money )      
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
		  cout << "." << endl;
		  cin.get();
		  
		  cout << "The dealer draws his first card: ";
          game.dealDealerCard();
		  cout << "." << endl;
		  cin.get();
		  
		  cout << "Your second card is a(n) "; 
          game.dealPlayerCard(); 
		  cout << "." << endl;
		  cin.get();
		  
		  cout << "The dealer draws his second card: ";
          game.dealDealerCard();
		  cout << "." << endl;
		  cin.get();
		  
		  
		  cout << "You have cards:" << endl;
          game.getPlayerHand(); //display players cards
		  cout << " = ";
		  game.getPlayerSum();

          cout << "Dealer has cards:" << endl;
          game.getDealerHand(); //display dealers cards
		  cout << " = ";
		  game.getPlayerSum();
	
		  hitagain:
		  
          cout << "Do you want to draw a card? (Y/N)" << endl;
          string draw;
          cin >> draw;

          if (draw == "y" || draw == "Y")
            {
              game.dealPlayerCard();
			  if (game.getPlayerSum() < 22) goto hitagain;	

			  else 
			  {
				  cout << "You stayed at :";
				  game.getPlayerSum();
				  cout << "." << endl;
			  }
			  
            }
		  if (game.getPlayerSum() > 21)
		  {
			cout << "You bust!" << endl;
			money -= bet;
		  }
		  else
		  {
			  cout << "The dealer hits again... And got a(n) " << endl;
			  game.dealDealerCard();
			  while (game.getDealerSum() < 17)
			  {
				cout << "The dealer hits again... And got a(n) " << endl;
				game.dealDealerCard();
				cin.get();
			  }
			  if (game.getDealerSum() > 21)
			  {
				  cout << "The dealer bust! You've won!" << endl;
				  money += bet;
			  }
			  
			  else
			  {
				  cout << "The dealer stands at: "; 
				  game.getDealerSum();
				  if (game.getPlayerSum() == game.getDealerSum())
				  {
					  cout << "We have a draw!" << endl;
				  }
				  else {}
				  if (game.getPlayerSum() == 21)
				  {
					  cout << "You got blackjack! You win!" << endl;
					  money += bet;
				  }
				  else {}
				  if (game.getPlayerSum() > game.getDealerSum())
				  {
					  cout << "You win!" << endl;
					  money += bet;
				  }
				   else {}
				   if (game.getPlayerSum() < game.getDealerSum())
				   {
					   cout << "You lose!" << endl;
					   money -= bet;
				   }
				  }
				   
			  }
		  }
	
		  
			  
    

        


    }

	

  return 0;

}
