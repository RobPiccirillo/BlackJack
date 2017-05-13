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
	
	char start;
	cin >> start;
	
	if (start =="Y" || start == "y")
	{
		bool run = true;
		while (run)
		{
		blackjack game;
		game.DealPlayerCard(2);
		game.DealDealerCard(2);
			
		cout << "dealer has cards: " << dealerHand << endl;
		cout << "you have cards: " << playerHand << endl;
		cout << "do you want to hit? (Y/N) " << endl;			
		
		char choice;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			dealCard(1);
		}
		
		cout << "you have cards: " << playerHand << endl;
		}
	}
	
	//still needs to be added
	
return 0;	
}
