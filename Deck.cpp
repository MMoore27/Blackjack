#include "Deck.h"
#include <iostream>
#include <cassert>

using namespace std;

// Makes a deck of cards. Goes through all the suits and ranks
Deck::Deck()
{
    //for loop to go through all 4 suits
    for (int suit = 0; suit<4; suit++)
        {
            //go through ranks
            for (int rank = 0; rank<13; rank++) {
             //array to put cards to the proper position
            cards[(suit*13)+rank] = Card(Card::Rank(rank), Card::Suit(suit));
        }
    }
    //Pointer that sets the array position to beginning of the deck
    next = &(cards[0]);
}

//
void Deck::reset()
{
    //make deck in original new deck order
    Deck deck1;
    for (int i = 0; i<52; i++)
    {
        cards[i] = deck1.deal();
    }
    //Moves pointer to the beginning of the deck
    next = &(cards[0]);
}


void Deck::shuffle(int n)
{

    //array to hold left half of deck
    Deck leftHalf;
    //array to hold right half of deck
    Deck rightHalf;

    //copy first n cards into one array
    for (int i = 0; i<n; i++)
    {
        leftHalf.cards[i] = cards[i];
    }
    //copy rest of deck into other array
    for (int i = 0; i<52-n; i++) //
    {
        rightHalf.cards[i] = cards[n+i];
    }


    int small = 0;

    if (n > (52-n))
    {
        small = 52-n;
    }

    else
    {
        small = n;
    }
    //Arranges the cards up until it hits "small" (which is the size of the smaller array between leftHalf and rightHalf)
   //Once it knows which is bigger, that part is added back to the deck

    int IndexForBoth = 0;

    int cardsIndex = 0;

    while (IndexForBoth < small)
    {
        cards[cardsIndex] = rightHalf.cards[IndexForBoth];
        cards[cardsIndex+1] = leftHalf.cards[IndexForBoth];

        cardsIndex += 2;
        IndexForBoth++;
    }
    //Figuring out which half is bugger

    int remaining = cardsIndex;

    if (small == (52-n)) //When leftHalf is the bigger one
    {

        while (remaining<52)
            {
                //add left half to deck
                cards[remaining] = leftHalf.cards[IndexForBoth];
                IndexForBoth++;
                remaining++;
            }
    }

    else //when rightHalf is bigger
    {

        while (remaining<52)
        {
            //add right half to deck
            cards[remaining] = rightHalf.cards[IndexForBoth];
            remaining++;
            IndexForBoth++;
        }
    }
    //reset next pointer to beginning of deck
    next = &(cards[0]);
}


//Deals the next card. If there are no cards, outputs error message
Card Deck::deal()
{
    if (cards_remaining() == 0)
    {
        cout << "No cards left. Get a new deck!" << endl;
        assert(0);
    }

    next++;
    return *(next-1);
}


// Goes through all the cards until one is repeated and then we have to reset/shuffle again
int Deck::cards_remaining()
const
{

    //Check if the end of the deck has been reached
    if (&(cards[51]) == (next-1))
    {
        return 0;
    }

   //Go through the deck until we hit the same card that we are at right now
    bool done = false;
    int remaining = 0;
    while(!done && remaining < 52)
    {
        //start at last card, move up in deck comparing current card to next card
        if (&(cards[51-remaining]) == next)
        {
            done = true;  //Loop stops if current card and next card are the same
        }

        remaining++; //Move remaining cards up by 1
    }
    return remaining;
}
