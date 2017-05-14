#include "Card.h"


// Constructor
Card::Card(rank r, bool ifu): m_Rank(r), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
	// If the card is face down, it's value is 0
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		
		// Value is 10 for face cards
		if (value &gt;10)
			value = 10;
	}
	return value;
}
void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

	