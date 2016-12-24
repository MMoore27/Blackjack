#include "Card.h"
#include <iostream>

using namespace std;

const char* const ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const char* const suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};


//Creates a new card and makes the default card to a two of spades
Card::Card()
{

	rank = TWO;
	suit = SPADES;

}

//Creates a new card that has rank and suit parameters
Card::Card(Rank rank_in, Suit suit_in)
{

	rank = rank_in;
	suit = suit_in;

}

//Returns the rank of the card (Ace, two, three, etc.)
Card::Rank Card::get_rank() const
{

	return rank;
}

//Returns the suit of the card
Card::Suit Card::get_suit() const
{
	return suit;
}

//Prints the card to stream
std::ostream& operator<< (std::ostream& os, const Card& c) {

	os << ranks[c.get_rank()] << " of " << suits[c.get_suit()];

	return os;
}
