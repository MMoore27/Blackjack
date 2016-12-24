//Deck_test02.cpp:
//	shuffle(8) - Shuffles 8. Tests with cut less than half the deck.


#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>


using namespace std;


int main()
{
	Deck d;
	d.reset();

	//Burns 8 card
	for (int i = 0; i < 8; ++i)
	{
		d.deal();
	}

	Card before = d.deal();
	d.shuffle(8);

	//Should be the same card
	Card after = d.deal();

	cout << "Eighth Card in new deck: " << before;
	cout << endl<< "First Card in shuffled deck: " << after;

	assert(before.get_suit() == after.get_suit());
	assert(before.get_rank() == after.get_rank());

	return 0;
}
