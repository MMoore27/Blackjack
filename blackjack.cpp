#include "Player.h"
#include "Deck.h"
#include "rand.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cassert>
#include <cstring>


using namespace std;

void shuffleDeck(Deck& deck, Player * player)
{
	cout << "Shuffling the deck\n";
	//shuffle deck 7 times, output cut location
	int cut = 0;
	for (int i = 0; i<7; i++)
    {
		cut = get_cut();
		deck.shuffle(cut);
		cout << "cut at " << cut << endl;
	}
	//tell player deck was shuffled
	player->shuffled();
}

int main(int argc, char * argv[])
{
	//Makes sure there are  arguments before proceeding
	assert (argc == 4);
	int bankroll = atoi(argv[1]);
	int numHands = atoi(argv[2]);
	const char* playerType = argv[3];
	//create player according to inputted type
	Player * player = player_factory(playerType);
	Hand playerHand, dealerHand;

	Deck deck;

	const int MINIMUM = 5;


	shuffleDeck(deck, player);

	//start at first hand
	int FirstHand = 0;
	int Wager = 0;
	Card currentCard, holeCard;


	while (bankroll>=MINIMUM && FirstHand<numHands)
    {
		cout << "Hand " << FirstHand+1 << " bankroll " << bankroll << endl;
		//if deck has less than 20 cards, shuffle the deck
		if (deck.cards_remaining()<20)
		{
			shuffleDeck(deck, player);
		}

		//ask player for wager
		Wager = player->bet(bankroll, MINIMUM);
		cout << "Player bets " << Wager << endl;

		//deal player first card
		currentCard = deck.deal();
		cout << "Player dealt " << currentCard << endl;
		//add card to player's hand
		playerHand.add_card(currentCard);
		//flip card
		player->expose(currentCard);

		//deal dealer first card
		currentCard = deck.deal();
		cout << "Dealer dealt " << currentCard << endl;
		//add card to dealer's hand
		dealerHand.add_card(currentCard);
		// player to card
		player->expose(currentCard);

		//deal player second card
		currentCard = deck.deal();
		cout << "Player dealt " << currentCard << endl;
		//add card to player's hand
		playerHand.add_card(currentCard);
		//expose player to card
		player->expose(currentCard);

		//deal dealer second card (face-down)
		holeCard = deck.deal();
		//add card to dealer's hand
		//card is face-down, so don't expose player to card
		dealerHand.add_card(holeCard);
		if (playerHand.hand_value() == 21)
        {
			//player dealt natural 21
			//pay 3/2 of wager
			cout << "Player dealt natural 21\n";
			bankroll += (1.5*Wager);
		}

		else
		{
			//player not dealt  21
			Card currentDrawnCard;
			//play player's hand out
			while (player->draw(holeCard, playerHand))
            {
				//while player keeps drawing cards
				currentDrawnCard = deck.deal();
				cout << "Player dealt " << currentDrawnCard << endl;
				//add card to player's hand
				playerHand.add_card(currentDrawnCard);
				//expose player to card
				player->expose(currentDrawnCard);
			}
			cout << "Player's total is " << playerHand.hand_value() << endl;
			//check if bust
			if (playerHand.hand_value() > 21)
			{
				//player busted
				cout << "Player busts\n";
				//player lost, so take wager from bankroll
				bankroll -= Wager;
			}
			else
            {
				//player didn't bust
				//expose dealer's hole card
				player->expose(holeCard);
				cout << "Dealer's hole card is " << holeCard << endl;
				//play dealer's hand out
				while (dealerHand.hand_value() < 17)
				{
					//deal card from deck
					currentCard = deck.deal();
					//expose player to card
					player->expose(currentCard);
					//add card to dealer's hand
					dealerHand.add_card(currentCard);
					cout << "Dealer dealt " << currentCard << endl;
				}
				cout << "Dealer's total is " << dealerHand.hand_value()
					 << endl;
				//check if dealer busted
				if (dealerHand.hand_value() > 21)
				{
					//dealer busted
					cout << "Dealer busts\n";
					bankroll += Wager;
				}

                else
                {
					//dealer didn't bust, so compare hand values
					if (playerHand.hand_value() == dealerHand.hand_value())
					{
						//if hand values are equal
						cout << "Push\n";
					}
                else if (playerHand.hand_value() > dealerHand.hand_value())
                    {
						//player wins
						cout << "Player wins\n";
						//player wins wager
						bankroll += Wager;
					}
                else
                    {
						//dealer wins
						cout << "Dealer wins\n";
						// ig player loses wager
						bankroll -= Wager;
					}//end  hand values
				}//end check dealer bust
			}//end check player bust
		}//end current hand

		//reset
		playerHand.discard_all();
		dealerHand.discard_all();

		FirstHand++;

	}//end game

	//output ending bankroll total
	cout << "Player has " << bankroll << " after " << FirstHand
	 << " hands\n";


	return 0;
}
