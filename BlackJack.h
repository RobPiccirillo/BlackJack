/*===============================================
Program that simulates the BlackJack card game 
Authors: Josh Kiss, Rob Piccirillo
===============================================*/

#include <iostream> //for cout
#include <vector>   //for vector
#include <string>
#include <cstdlib>  //for rand
using namespace std;

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#define BLACKJACK 21

class Player
{
public:
Player();

private:
int m_hand;
}

class BlackJack: public Player
{
	public:
	BlackJack(); //default constructor
  
  void hit();
  void stand();
  
  private:
  int m_val;
  int m_playersHand;
  int m_dealersHand;
  
};//blackjack

#endif
