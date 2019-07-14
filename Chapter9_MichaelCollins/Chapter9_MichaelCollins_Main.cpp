//Main "driver" for Chapter 9
//Michael Collins
#include <iostream>
#include "DeckOfCards.h"
using namespace std;

//prototypes
bool fourKind(Card hand[5], int);
bool threeKind(Card hand[5], int);
bool pairOfCards(Card hand[5], int);
bool twoPair(Card hand[5], int);
bool straight(Card hand[5], int);
bool flush(Card hand[5], int);

int main()
{
	DeckOfCards deck;
	deck.shuffle();
//	int c = 0;
	int handSize = 5;
	Card hand1[handSize];
//	while (deck.moreCards()) {
//		Card card = deck.dealCard();
//		cout << card.toString() << endl;
//		c++;
//	}
	
	for(int i = 0; i < handSize; i++){
		hand1[i] = deck.dealCard();
		cout << hand1[i].toString() << endl;
	}
	
	if(fourKind(hand1, handSize)){
		cout << "Four of a kind!" << endl;
	}
	else if(threeKind(hand1, handSize)){
		cout << "Three of a kind!" << endl;
	}
	else if(pairOfCards(hand1, handSize)){
		//inside the pair check because you don't need to run two pair if there isn't one pair
		if(twoPair(hand1, handSize)){
			cout << "Two pair!" << endl;
		}
		else{
			cout << "pair!" << endl;
		}
	}
	else if(straight(hand1, handSize)){
			if(flush(hand1, handSize)){
				cout << "Straight Flush!" << endl;
			}
			else{
				cout << "Straight!" << endl;
			}
	}
	else if(flush(hand1, handSize)){
		cout << "Flush!" << endl;
	}
	else{
		cout << "Nothing.  Better luck next time!" << endl;
	}
	return 0;
}

//checks for four of a kind.
bool fourKind(Card hand[5], int s){
	//first sort cards by face value.
	for(int i = 0; i < (s - 1); i++){
		if(hand[i].getFace() > hand[i+1].getFace()){
			Card temp = hand[i];
			hand[i] = hand[i+1];
			hand[i+1] = temp;
		}
	}
	//since its sorted, we only need to check the ends of possible 4 groups.
	if(hand[0].getFace() == hand[3].getFace() || hand[1].getFace() == hand[4].getFace()){
		return true;
	}
	return false;
}

//checks for three of a kind.
bool threeKind(Card hand[5], int s){
	//first sort cards by face value.
	for(int i = 0; i < (s - 1); i++){
		if(hand[i].getFace() > hand[i+1].getFace()){
			Card temp = hand[i];
			hand[i] = hand[i+1];
			hand[i+1] = temp;
		}
	}
	//since its sorted, we only need to check the ends of possible 3 groups.
	if(hand[0].getFace() == hand[2].getFace()){
		return true;
	}
	else if(hand[1].getFace() == hand[3].getFace()){
		return true;
	}
	else if(hand[2].getFace() == hand[4].getFace()){
		return true;
	}
	return false;
}

//checks for two pair.
bool twoPair(Card hand[5], int s){
	int p = 0; //pair counter
	for(int i = 0; i < (s - 1); i++){
		for(int j = i+1; j < s; j++){
			if(hand[i].getFace() == hand[j].getFace()){
				p++;
			}
		}
	}
	if(p > 1){
		return true;
	}
	return false;
}

//checks for a single pair.
bool pairOfCards(Card hand[5], int s){
	for(int i = 0; i < (s - 1); i++){
		for(int j = i+1; j < s; j++){
			if(hand[i].getFace() == hand[j].getFace()){
				return true;
			}
		}
	}
	return false;
}

//checks for a straight
bool straight(Card hand[5], int s){
	int p = 0; //counter for consecutive.
	//first we sort by face value.
	for(int i = 0; i < (s - 1); i++){
		if(hand[i].getFace() > hand[i+1].getFace()){
			Card temp = hand[i];
			hand[i] = hand[i+1];
			hand[i+1] = temp;
		}
	}
	//counts cards that are consecutive.
	for(int i = 0; i < (s - 1); i++){
		for(int j = i + 1; j < s; i++){
			if(hand[i].getFace() + 1 == hand[j].getFace()){
				p++;
			}
		}
	}
	//if all are consecutive, return true.
	if(p == 4){
		return true;
	}
	return false;
}

//checks for flush
bool flush(Card hand[5], int s){
	//honestly this is simple.
	int p = 0; //counts matchs.
	for(int i = 0; i < (s - 1); i++){
		for(int j = i + 1; j < s; i++){
			if(hand[i].getSuit() == hand[j].getSuit()){
				p++;
			}
		}
	}
	if(p == 4){
		return true;
	}
	return false;
}