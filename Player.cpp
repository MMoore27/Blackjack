#include "Player.h"
#include <cassert>
#include <cstring>
#include <string.h>
#include <iostream>

using namespace std;
////////////////////////////// Simple ///////////////////////////////

class Simple : public Player
{
    // A simple player class
    public:
    virtual int bet(unsigned int bankroll, unsigned int minimum)
    {
    	//makes sure the players cash is above the minimum required bet
        assert(bankroll >= minimum);
	    //Always bet the minimum
        return minimum;
    }


    virtual bool draw (Card dealer, const Hand &player)
    {
    	//The player has an Ace worth 1 (soft), or no ace at all

        if (!player.hand_is_soft())
            {
    		//The player's hand value is less than 12
            if (0 <= player.hand_value() and player.hand_value() <= 11)
    			return true;
            //The player's hand value = 12
    		else if (player.hand_value() == 12)
    		{
    			//The dealer shows between 4 and 6
                if(2 <= dealer.get_rank() and dealer.get_rank() <= 4)
    				return false;
    			else
    				return true;
    		}
            //The player's hand value is between 13 and 16
    		else if (13 <= player.hand_value() and player.hand_value() <= 16)
    		{
                //The dealer shows 2 through 6
                if (dealer.get_rank() <= 4)
                    return false;
                else
    				return true;
    		}
            //The player's hand value is greater than 16
    		else
    			return false;
    	}
    	//The player has an Ace worth 11 (hard)
        else
        {
            //The player's hand value is less than 18
    		if (player.hand_value() <= 17)
    			return true;
            //The player's hand value is 18
    		else if (player.hand_value() == 18)
    		{
    			//The dealer shows 2, 7, or 8
                if (dealer.get_rank() == 0 or dealer.get_rank() == 5
                        or dealer.get_rank() == 6)
    				return false;
    			else
    				return true;
    		}
            //The player's hand value is greater than 18
    		else
    			return false;
    	}
	}
	virtual void expose(Card c) {
    	return;
    }

    virtual void shuffled()  {
    	return;
    }


};

//////////////////////////// End Simple /////////////////////////////



///////////////////////////// Counting //////////////////////////////

class Counting : public Simple
{

    public:
    //Returns the player's bet
    virtual int bet(unsigned int bankroll, unsigned int minimum) {
    	//Make sure players available cash is higher than minimum
        assert(bankroll >= minimum);

        //if the player cannot bet double, then all in
        if (get_count() >= 2)
        {
            if (bankroll >= 2*minimum)
                return 2*minimum;
            else
                return bankroll;
        }
        //Otherwise bet minimum
        else
            return minimum;
    }


    //Lets the player see the newest available card (flips it)
    virtual void expose(Card c)
    {
    	//If the card is 6 or less add 1 to the count
        if (c.get_rank() <= 4)
            count++;
        //If the card is ten or greater subtract 1 from the count
        else if (c.get_rank() >= 8)
            count--;

        return;
    }


    //Returns if the deck has been shuffled
    virtual void shuffled()
    {
    	count = 0;
        return;
    }


     int get_count()
    {
        return count;
    }


private:
    int count;
};

/////////////////////////// End Counting ////////////////////////////


//////////////////////////// Competitor ////////////////////////////

class Competitor : public Counting
{

    public:
    virtual int bet(unsigned int bankroll, unsigned int minimum)
    {
    	//If count is greater than 2, raises the bet
    	if (get_count() >= 2)
        {
            if (bankroll >= 4.0*minimum)
                return 4.0*minimum;
            else
                return bankroll;
        }
        //Otherwise, bet the minimum
        else
        {
            if (bankroll >= 2*minimum)
                return 2*minimum;
            else
                return bankroll;
        }
    }

};

////////////////////////// End Competitor //////////////////////////

//Declaration of global player types
static Simple simple;
static Counting counting;
static Competitor competitor;

Player * player_factory(const char * s) {
	//input strings
    std::string simplestr = "simple";
	std::string countingstr = "counting";
	std::string competitorstr = "competitor";

    //Check which type of player to produce

	if (strcmp(s, simplestr.c_str()) == 0)
		return &simple;
	else if (strcmp(s, countingstr.c_str()) == 0)
		return &counting;
	else if (strcmp(s, competitorstr.c_str()) == 0)
		return &competitor;

		//assert(0);
}

