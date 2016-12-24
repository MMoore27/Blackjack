#ifndef CARD_H
#define CARD_H

#include <iostream>


class Card {
 public:
  // types for rank and suit
  enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};
  enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
             JACK, QUEEN, KING, ACE};

  //EFFECTS: initializes Card to Two of Spades
  Card();

  //EFFECTS: initializes Card with rank_in and suit_in
  Card(Rank rank_in, Suit suit_in);

  //EFFECTS: returns rank
  Rank get_rank() const;

  //EFFECTS: returns suit
  Suit get_suit() const;

 private:
  Rank rank; // rank of this card
  Suit suit; // suit of this card
};

//EFFECTS: Writes the Card to the stream
//  for example "Two of Spades"
std::ostream& operator<< (std::ostream& os, const Card& c);

#endif
