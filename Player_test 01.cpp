//Player_test01.cpp
//
//Testing draw: Dealt natural 21
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
	Card player2 = Card(Card::KING, Card::SPADES);

	playerhand.add_card(player1);
	dealerhand.add_card(dealer1);
	playerhand.add_card(player2);

	if (p->draw(dealer1, playerhand)) 
	{
		cout << "Dealer shows: " << dealerhand.hand_value() << endl;
		cout << "Player decides to hit: " << playerhand.hand_value() << endl;
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