// This is an example test case which runs a simple test involving
// your shuffle and deal functions.

#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
    Deck d;

    Card before = d.deal();
    d.shuffle(26); // Should replace the dealt card before shuffling

    d.deal(); // Throw one away
    Card after = d.deal(); // Should be the same as before.

    cout << "First card in new deck: " << before << endl;
    cout << "Second card in shuffled deck: " << after << endl;

    assert(before.get_rank() == after.get_rank());
    assert(before.get_suit() == after.get_suit());
    return 0;
}
