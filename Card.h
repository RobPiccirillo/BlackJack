#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
	public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
			JACK, QUEEN, KING };   // Enumerate values of cards
			
			friend ostream& operator << (ostream & os, const Card& c);			
			Card(rank r = ACE, bool ifu = true);			
			int GetValue() const;  // Return value of card
			void Flip(); // Flips a card
	private:
		int m_Rank;
		bool m_IsFaceUp;
};

#endif


			