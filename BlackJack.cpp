/*-------------------------------------------------
  BlackJack.cpp
  Definitions and implementations of
  functions in class blackjack
  Authors: Josh Kiss, Rob Piccirillo
  ------------------------------------------------*/
#include "BlackJack.h"



blackjack::blackjack()  //default constructor
{                       //initialize everything with default values
  srand(time(NULL));
  m_playerSum=0;
  m_dealerSum=0;

  DeckCounter=0;
}
//------------------------------------------------------------

void blackjack::dealPlayerCard()
{
  playerHand.push_back(Deck[DeckCounter]);
  cout << Deck[DeckCounter] << endl;
  DeckCounter++;
}
//------------------------------------------------------------

void blackjack::dealDealerCard()
{
  dealerHand.push_back(Deck[DeckCounter]);
  cout << Deck[DeckCounter] << endl;
  DeckCounter++;
}
//-------------------------------------------------------------

void blackjack::getPlayerHand()
{
  for (int i=0; i<playerHand.size(); i++)
    cout << playerHand[i] << " ";

  cout << endl;
}
//-------------------------------------------------------------

void blackjack::getDealerHand()
{
  for (int i=0; i<dealerHand.size(); i++)
    cout << dealerHand[i] << " ";

  cout << endl;
}
//-------------------------------------------------------------

void blackjack::playerSplit()  //player stop drawing cards
{
  dealerSplit(); //dealer stops drawing or draws again
}
//-------------------------------------------------------------

void blackjack::dealerSplit()
{
  if (m_dealerSum < 17)
    dealDealerCard();

  else
    playerWin();
}
//--------------------------------------------------------------

int blackjack::getPlayerSum() //get the sum of the players cards
{
  for (int i=0; i<playerHand.size(); i++)
    m_playerSum += playerHand[i];
  //move through playerHand vector and add up values into sum

  return m_playerSum;
}
//----------------------------------------------------------------

int blackjack::getDealerSum() //get sum of dealers cards
{
  for (int i=0; i<dealerHand.size(); i++)
    m_dealerSum += dealerHand[i];
  //move through dealerHand vector and add up values into sum

  if (m_dealerSum < 17) //dealers stop drawing when they have 17
    dealerSplit();

  return m_dealerSum;
}
//--------------------------------------------------------------

void blackjack::playerWin()
{
  getPlayerSum();
  getDealerSum();

  if (m_playerSum > m_dealerSum && m_playerSum <= BLACKJACK)
    cout << "You win!" << endl;

  if (m_playerSum < m_dealerSum && m_dealerSum <= BLACKJACK)
    cout << "Dealer wins" << endl;
}
//--------------------------------------------------------------

void blackjack::loadDeck()
{
  for (int i=0; i<DECKSIZE; i++)
    Deck.push_back( rand()%11+1 );
}

