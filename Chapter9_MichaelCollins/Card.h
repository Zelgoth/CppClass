//Card Class
//Michael Collins
#include <string>

class Card
{
private:
	int face;
	int suit;
	std::string faces[13];
	std::string suits[4];
public:
	Card();
	Card(const int, const int);
	std::string toString();
	int getFace();
	int getSuit();
};

Card::Card() {
	//default constructor
	face = 0;
	suit = 0;
}

Card::Card(int f, int s) {
	std::string number[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	std::string sign[] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	for (int i = 0; i < 13; i++) {
		faces[i] = number[i];
	}
	for (int j = 0; j < 4; j++) {
		suits[j] = sign[j];
	}

	face = f;
	suit = s;
}

std::string Card::toString() {
	std::string cardName = faces[face] + " of " + suits[suit];
	return cardName;
}

//returns face value for compairing
int Card::getFace(){
	return face;
}

//return suit value for compairing
int Card::getSuit(){
	return suit;
}
