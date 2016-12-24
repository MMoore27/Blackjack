//Deck_test07.cpp:
//	cards_remaining() - Deals 17 cards. Should be 35 remaining.

#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>

using namespace std;

//Test 
int main() 
{

	Deck d;

	for (int i = 0; i < 17; ++i) 
	{
		d.deal();
	}

	assert(d.cards_remaining() == 35);

	cout << "Cards Dealt = 17\n";
	cout << "Cards Remaining = 35\n";

	return 0;
}