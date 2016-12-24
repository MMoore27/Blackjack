//Player_test00.cpp
//
//Testing Simple bet function
#include "Player.h"
#include <cassert>

using namespace std;

int main()
{

	int returnValue;

	//Testing Bet Function
	const char *simplestr = "simple";
	Player *simple = player_factory(simplestr);

	int minimum = 5;
	int bet = simple->bet(100, minimum);

	if (bet == minimum)
    {
		cout << "Simple player 1 bet is: " << bet << endl;
		cout << "This player is correct\n\n";
		returnValue = 0;
	}
	else
    {
		cout << "Simple player 1 bet is: " << bet << endl;
		cout << "This player is buggy\n\n";
		returnValue = -1;
	}


	int bet1 = simple->bet(5, minimum);

	if (bet1 == minimum)
    {
		cout << "Simple player 2 bet is: " << bet1 << endl;
		cout << "This player is correct\n\n";
		returnValue = 0;
	}

	else
	{
		cout << "Simple player 2 bet is: " << bet1 << endl;
		cout << "This player is buggy\n\n";
		returnValue = -1;
	}

	cout << endl;

	return returnValue;
}
