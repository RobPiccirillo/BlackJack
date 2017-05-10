/*===============================================
Program that simulates the BlackJack card game 
with two players	
Authors: Josh Kiss, Rob Piccirillo
===============================================*/

#include <iostream> //for cout
#include <vector>   //for vector
#include <string>
#include <cstdlib>  //for rand
using namespace std;

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#define DECKSIZE 52
#define BLACKJACK 21	

class BlackJack
{
public:
BlackJack(); //default constructor
BlackJack shuffleDeck();	//shuffle deck of cards
	
//vector <int> rankval;//store value of card
int drawCard();
//BlackJack moves
void hit();	//add another card
void stand();   //add no more cards
	
~BlackJack();
	
private:
int m_val;
vector <int> m_playersHand;
vector <int> m_dealersHand;
  
int m_playersHandSum;
int m_dealershandSum;
	

};//blackjack

#endif

//this still seems too easy, and too hard at the same time
