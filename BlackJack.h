/*===============================================
Program that simulates the BlackJack card game 
with two players	
Authors: Josh Kiss, Rob Piccirillo
===============================================*/

#include <iostream> //for cout, cin
#include <vector>   //for vector
#include <string>
#include <ctime> 
#include <cstdlib>  //for srand, rand
using namespace std;

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#define DECKSIZE 52 //if needed
#define BLACKJACK 21	

class blackjack 
{
	public:
	blackjack();
	
	void dealCard(int numCards, vector <int> &Hand);
	void stand();

	int sumOfCards(vector <int> &Hand);
	bool win();
	//void shuffleCards();
	private:
	//data members
	vector <int> playerHand; 
	vector <int> dealerHand;
	int m_playerSum;
	int m_dealerSum;
	
};

#endif
