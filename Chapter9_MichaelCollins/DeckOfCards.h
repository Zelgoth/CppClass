//Deck of cards class
//Michael Collins
#include "Card.h"
using namespace std;

class DeckOfCards
{
private:
	Card Deck[52];
	int currentCard = 0;
public:
	DeckOfCards();
	void shuffle();
	bool moreCards();
	Card dealCard();
};
//constuctor
DeckOfCards::DeckOfCards() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Deck[currentCard] = Card(j, i);
			currentCard++;
		}
	}
}

//fuction to shuffle the deck
void DeckOfCards::shuffle() {
	Card temp;
	int rnd;
	for (int i = 0; i < currentCard; i++) {
		rnd = rand() % currentCard; //can suffle with any number of cards, stops at currentCard.
		if (rnd != i) {
			//standard swap method
			temp = Deck[rnd];
			Deck[rnd] = Deck[i];
			Deck[i] = temp;
		}
	}
}

//bool more cards
bool DeckOfCards::moreCards() {
	if (currentCard == 0) {
		return false;
	}
	return true;
}

//returns currentCard.  I know this -- looks funny but it has to be there.
Card DeckOfCards::dealCard() {
	currentCard--;
	return Deck[currentCard];
}