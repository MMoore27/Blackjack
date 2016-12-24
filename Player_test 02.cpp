//Player_test07.cpp
//
//Testing draw when soft ace plus Hand value == 18
#include "Player.h"
#include "Card.h"
#include "Hand.h"
#include <cassert>

using namespace std;

int main() 

{

	const char *simplestr = "counting";
	Player *p = player_factory(simplestr);
	Hand playerhand;
	Hand dealerhand;

	Card player1 = Card(Card::ACE, Card::SPADES);
	Card dealer1 = Card(Card::SEVEN, Card::SPADES);
	Card player2 = Card(Card::SEVEN, Card::SPADES);

	playerhand.add_card(player1);
	dealerhand.add_card(dealer1);
	playerhand.add_card(player2);

	if (playerhand.hand_is_soft())
		cout << "Player's hand contains an Ace worth 11\n\n";
	else
		cout << "Player's hand contains an Ace worth 1\n\n";

	if (p->draw(dealer1, playerhand)) 
	{
		cout << "Dealer shows: " << dealerhand.hand_value() << endl;
		cout << "Player decides to hit on: " << playerhand.hand_value() << endl;
		cout << "This player is buggy\n\n";
		return -1;
	}
	
	else 
	{
		cout << "Dealer shows: " << dealerhand.hand_value() << endl;
		cout << "Player decides to stay on: " << playerhand.hand_value() << endl;
		cout << "This player is correct\n\n";
		return 0;
	}
}