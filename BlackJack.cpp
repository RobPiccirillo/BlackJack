/*-------------------------------------------------
  BlackJack.cpp
  Definitions and implementations of
  functions in class BlackJack
  Authors: Josh Kiss, Rob Piccirillo
  ------------------------------------------------*/
#include "BlackJack.h"
#include <numeric>


BlackJack::BlackJack()  //default constructor
{                       //initialize everything with default values
  srand(time(NULL));
  m_playerSum=0;
  m_dealerSum=0;

  DeckCounter=0;
}
//------------------------------------------------------------

void BlackJack::dealPlayerCard()
{
  playerHand.push_back(Deck[DeckCounter]);
  cout << Deck[DeckCounter] << endl;
  DeckCounter++;
}
//------------------------------------------------------------

void BlackJack::dealDealerCard()
{
  dealerHand.push_back(Deck[DeckCounter]);
  cout << Deck[DeckCounter] << endl;
  DeckCounter++;
}
//-------------------------------------------------------------

void BlackJack::getPlayerHand()
{
  for (int i=0; i<playerHand.size(); i++)
    cout << playerHand[i] << " ";

  cout << endl;
}
//-------------------------------------------------------------

void BlackJack::getDealerHand()
{
  for (int i=0; i<dealerHand.size(); i++)
    cout << dealerHand[i] << " ";

  cout << endl;
}
//-------------------------------------------------------------

int BlackJack::getPlayerSum() //get the sum of the players cards
{
  m_playerSum = accumulate(playerHand.begin(), playerHand.end(), 0);
  return m_playerSum;
  //move through playerHand vector and add up values into sum

}
//----------------------------------------------------------------

int BlackJack::getDealerSum() //get sum of dealers cards
{
    m_dealerSum = accumulate(dealerHand.begin(), dealerHand.end(), 0);
	return m_dealerSum;

  //move through dealerHand vector and add up values into sum

}
//--------------------------------------------------------------


void BlackJack::loadDeck()
{
  for (int i=0; i<DECKSIZE; i++)
    Deck.push_back( rand()%11+1 );
}

void BlackJack::clearHands()
{
	playerHand.clear();
	dealerHand.clear();
}

