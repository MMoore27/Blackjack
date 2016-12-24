#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Hand.h"


class Player {
    // A virtual base class, providing the player interface
 public:
    virtual int bet(unsigned int bankroll, unsigned int minimum) = 0; 
    // REQUIRES: bankroll >= minimum
    // EFFECTS: returns the player's bet, between minimum and bankroll 
    // inclusive

    virtual bool draw(
                      Card dealer, // Dealer's "up card"
                      const Hand &player // Player's current hand
                      ) = 0;
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.

    virtual void expose(Card c) = 0;
    // EFFECTS: allows the player to "see" the newly-exposed card c.
    // For example, each card that is dealt "face up" is expose()d.
    // Likewise, if the dealer must show his "hole card", it is also
    // expose()d.  Note: not all cards dealt are expose()d---if the
    // player goes over 21 or is dealt a natural 21, the dealer need
    // not expose his hole card.

    virtual void shuffled() = 0;
    // EFFECTS: tells the player that the deck has been re-shuffled.

    virtual ~Player() { }
    // Note: this is here only to suppress a compiler warning.
    //       Destructors are not needed for this project.
};

Player * player_factory(const char * s);
// REQUIRES: s is a C-string: "simple" "counting" or "competitor"
// EFFECTS: returns a pointer to the specified Player

#endif
