/*===============================================
Program that simulates the BlackJack card game
with two players
Authors: Josh Kiss, Rob Piccirillo
===============================================*/

#include <iostream> //cout, cin
#include <vector>   //vector
#include <string>   //string
#include <ctime>    //time
#include <cstdlib>  //srand, rand
#include <numeric> // accumulate
using namespace std;

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#define DECKSIZE 52 //set constant to initialize deck with 52 cards
#define BLACKJACK 21 //set constant to highest score you can get in blackjack

class BlackJack //: public player
{
 public:
  BlackJack();    //default constructor

  int dealCard();

  void dealPlayerCard();  //give card to player
  void dealDealerCard();  //give card to dealer

  void getPlayerHand();  //display players cards
  void getDealerHand();  //display dealers hands

  int getPlayerSum();    //return sum of players cards
  int getDealerSum();    //return sum of dealers cards

  void playerSplit();    //player or dealer stops drawing
  void dealerSplit();

  void playerWin();    //determine if player won game

  void loadDeck();    //put random cards in deck to start
  //~BlackJack();      //destructor, destroy array storing deck of cards

 private:
  //data members

  vector <int> playerHand;
  vector <int> dealerHand;
  /*-------------------------------------------
    vectors to hold players and dealers cards,
    size can be increased to hold more cards
  --------------------------------------------*/

  vector <int> Deck;
  /*----------------------------------------------------
    deck of cards with 52 cards stored in
    an vector of ints, each card has a numerical value and
    size does not need to be increased in game
    ----------------------------------------------------*/

  int m_playerSum; //values of the sum of the
  int m_dealerSum; //players and dealers cards

  int DeckCounter;  //counter to count position in vector of
                    //cards and move through the deck

};


#endif /*class BlackJack*/
