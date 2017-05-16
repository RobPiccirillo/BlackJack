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
  DeckCounter++;
}
//------------------------------------------------------------

void BlackJack::dealDealerCard()
{
  dealerHand.push_back(Deck[DeckCounter]);
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

void BlackJack::playerSplit()  //player stop drawing cards
{
  dealerSplit();
}

void BlackJack::dealerSplit()
{
  if (m_dealerSum < 17)
    dealDealerCard();

  else
    playerWin();
}
//--------------------------------------------------------------

int BlackJack::getPlayerSum() //get the sum of the players cards
{
  m_playerSum = accumulate(playerHand.begin(), playerHand.end(), 0);

  //move through playerHand vector and add up values into sum

}
//----------------------------------------------------------------

int BlackJack::getDealerSum() //get sum of dealers cards
{
  for (int i=0; i<dealerHand.size(); i++)
    m_dealerSum = accumulate(dealerHand.begin(), dealerHand.end(), 0);

  //move through dealerHand vector and add up values into sum

  if (m_dealerSum < 17) //dealers stop drawing when they have 17
    dealerSplit();

}
//--------------------------------------------------------------

void BlackJack::playerWin()
{
  if (m_playerSum > m_dealerSum && m_playerSum <= BLACKJACK)
    cout << "You win!" << endl;

  if (m_playerSum < m_dealerSum && m_dealerSum <= BLACKJACK)
    cout << "Dealer wins" << endl;
}
//--------------------------------------------------------------

void BlackJack::loadDeck()
{
  for (int i=0; i<DECKSIZE; i++)
    Deck.push_back( rand()%11+1 );
}
