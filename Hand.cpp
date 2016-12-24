#include "Card.h"
#include "Hand.h"
#include <iostream>

using namespace std;


// Starts an empty  hand.
Hand::Hand()
{
    value = 0;
    soft = false;
}

// Resets the hand to the original "like new" state
void Hand::discard_all() {
    value = 0;
    soft = false;
}

// Adds card (c) to those presently in the hand
void Hand::add_card(Card c)
{

    switch(c.get_rank())
   //Goes through each card rank and checks to see if it will make the hand bust or not
    {
        case Card::TWO:
            if (soft && value > 19)
            {
                value -= 8;
                soft = false;
            }
            else
            {
                value += 2;
            }
            break;

        case Card::THREE:
            if (soft && value > 18)
            {
                value -= 7;
                soft = false;
            }
            else
            {
                value += 3;
            }
            break;

        case Card::FOUR:
            if (soft && value > 17)
            {
                value -= 6;
                soft = false;
            }
            else
            {
                value += 4;
            }
            break;

        case Card::FIVE:
            if (soft && value > 16)
            {
                value -= 5;
                soft = false;
            }
            else
            {
                value += 5;
            }
            break;

        case Card::SIX:
            if (soft && value > 15)
            {
                value -= 4;
                soft = false;
            }
            else
            {
                value += 6;
            }
            break;

        case Card::SEVEN:
            if (soft && value > 14)
            {
                value -= 3;
                soft = false;
            }
            else
            {
                value += 7;
            }
            break;

        case Card::EIGHT:
            if (soft && value > 13)
            {
                value -= 2;
                soft = false;
            }
            else
            {
                value += 8;
            }
            break;

        case Card::NINE:
            if (soft && value > 12)
            {
                value -= 1;
                soft = false;
            }
            else
            {
                value += 9;
            }
            break;
        //Realized all these cards would have the same value, so combined them
        case Card::TEN:
        case Card::JACK:
        case Card::QUEEN:
        case Card::KING:
            if (soft && value > 11)
            {
                soft = false;
            }
            else
            {
                value += 10;
            }
            break;

        case Card::ACE:  //Aces are tricky because they can either be hard (counted as 1) or soft (counted as 11)
                         //Needed to make if/else for each case
            if (!soft && value > 11)
            {

                value++;
            }
            else if (soft && value > 11)
            {

                value -= 10;
                soft = false;
                if (value > 11)
                    {
                    //if can't add soft ace, add hard ace
                    value++;
                    }
                else
                    {
                    //else add soft ace
                    value += 11;
                    soft = true;
                    }
            }

            else
            {
                //value <= 10, so add soft ace
                value += 11;
                soft = true;
            }
            break;
    }
}

// Returns the current value of the hand
int Hand::hand_value() const {
    //If there is an ace, we need to account for the fact that the hand is soft or hard
    if (soft && value>21)
    {
        return value-10;
    }
    //if value <= 21, return value
    return value;
}

// Returns true if ace will be counted as 11, returns false if it will be counted as 1
bool Hand::hand_is_soft() const
{
    //return if hand is soft or not
    return soft;
}

