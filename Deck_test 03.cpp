//Deck_test09.cpp:
//	shuffle() - runs shuffle multiple times to make sure correct when looped.

#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>

using namespace std;


int main()

{
	Deck d;
	d.reset();

	Card KingofSpades = Card(Card::KING, Card::SPADES);
	Card KingofClubs = Card(Card::KING, Card::CLUBS);
	Card ThreeofSpades = Card(Card::THREE, Card::SPADES);
	Card ThreeofDiamonds = Card(Card::THREE, Card::DIAMONDS);


	d.shuffle(32);
	d.shuffle(40);
	d.shuffle(28);
	d.shuffle(43);
	d.shuffle(23);

	//Should be same as before
	Card after0 = d.deal();
	Card after1 = d.deal();
	Card after2 = d.deal();
	Card after3 = d.deal();

	cout << "Expected First Four Cards:\n";
	cout << KingofSpades <<" "<< KingofClubs << " " <<ThreeofSpades<< " " << ThreeofDiamonds;
	cout << endl<< "Actual First Four Cards:\n";
	cout << after0 <<" " << after1 <<" " << after2 <<" " << after3;

	assert(KingofSpades.get_rank() == after0.get_rank());
	assert(KingofClubs.get_rank() == after1.get_rank());
	assert(ThreeofSpades.get_rank() == after2.get_rank());
	assert(ThreeofDiamonds.get_rank() == after3.get_rank());
	assert(KingofSpades.get_suit() == after0.get_suit());
	assert(KingofClubs.get_suit() == after1.get_suit());
	assert(ThreeofSpades.get_suit() == after2.get_suit());
	assert(ThreeofDiamonds.get_suit() == after3.get_suit());


	return 0;
}
