#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Card {

    std::string card;
    char type;
    char suit;

public:

    Card(std::string);
    std::string getCard();
    char getType();
    char getSuit();
    int getValue();
    bool operator== (const Card&);
};

Card::Card(std::string _card) {
    card = _card;
    type = _card[0];
    suit = _card[1];
}

std::string Card::getCard() {
    return card;
}

char Card::getType() {
    return type;
}

char Card::getSuit() {
    return suit;
}

int Card::getValue() {
    switch (type) {
        case 'A':
            return 12;
        case 'K':
            return 11;
        case 'Q':
            return 10;
        case 'J':
            return 9;
        case 'T':
            return 8;
        default:
            return type - 50;
    }
}

bool Card::operator== (const Card& other) {
    return card == other.card;
}


std::vector<Card> split(const std::string &s, char delim) {
    std::vector<Card> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(Card(item));
    }
    return elems;
}


class Hand {

    std::vector<Card> hand;
    int rank;
    int fourPairValue;
    int threePairValue;
    int twoPair1Value;
    int twoPair2Value;

public:

    Hand();
    Hand(std::vector<Card>);

    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPairs();
    bool isOnePair();

    int getRank();
    void computeRank();
    int getFourPairValue();
    int getThreePairValue();
    int getTwoPair2Value();
    int getTwoPair1Value();
    Card getHighCard();
    std::vector<Card> getCards();
    Card getCard(int);
    Card operator[] (int);
    void removeCard(int);
    void removeCard(int, int);
    void removeCard(Card);
};

Hand::Hand() {}

Hand::Hand(std::vector<Card> _hand) {
    hand = _hand;
    fourPairValue = -1;
    threePairValue = -1;
    twoPair1Value = -1;
    twoPair2Value = -1;
    computeRank();
}

bool Hand::isRoyalFlush() {
    return isFlush() && isStraight() && getHighCard().getType() == 'A';
}

bool Hand::isStraightFlush() {
    return isFlush() && isStraight();
}

bool Hand::isFourOfAKind() {
    int cards[13] = {0};
    for (Card card : hand) {
        ++cards[card.getValue()];
    }
    for (int i = 0; i < 13; ++i) {
        if (cards[i] == 4) {
            fourPairValue = i;
            return true;
        }
    }
    return false;
}

bool Hand::isFullHouse() {
    std::vector<Card> handCopy = hand;
    if (isThreeOfAKind() && isOnePair()) {
        return true;
    }
    threePairValue = -1;
    twoPair1Value = -1;
    hand = handCopy;
    return false;
}

bool Hand::isFlush() {
    char suit = hand[0].getSuit();
    for (int i = 1; i < hand.size(); ++i) {
        if (hand[i].getSuit() != suit) {
            return false;
        }
    }
    return true;
}

bool Hand::isStraight() {
    bool cards[13] = {false};
    for (Card card : hand) {
        if (!cards[card.getValue()]) {
            cards[card.getValue()] = true;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (cards[i]) {
            return std::all_of(cards + i, cards + i + 5, [](bool b){return b;});
        }
    }
    return false;
}

bool Hand::isThreeOfAKind() {
    std::vector<Card> handCopy = hand;
    int cards[13] = {0};
    for (Card card : hand) {
        ++cards[card.getValue()];
    }
    for (int i = 0; i < 13; ++i) {
        if (cards[i] == 3) {
            threePairValue = i;
            removeCard(3, i);
            return true;
        }
    }
    hand = handCopy;
    return false;
}

bool Hand::isTwoPairs() {
    std::vector<Card> handCopy = hand;
    if (isOnePair() && isOnePair()) {
        return true;
    }
    twoPair1Value = -1;
    twoPair2Value = -1;
    hand = handCopy;
    return false;
}

bool Hand::isOnePair() {
    std::vector<Card> handCopy = hand;
    int cards[13] = {0};
    for (Card card : hand) {
        ++cards[card.getValue()];
    }
    for (int i = 0; i < 13; ++i) {
        if (cards[i] == 2) {
            if (twoPair1Value == -1) {
                twoPair1Value = i;
            }
            else {
                twoPair2Value = i;
            }
            removeCard(2, i);
            return true;
        }
    }
    hand = handCopy;
    return false;
}

int Hand::getRank() {
    return rank;
}

void Hand::computeRank() {
    if (isRoyalFlush()) {
        rank = 9;
    }
    else if (isStraightFlush()) {
        rank = 8;
    }
    else if (isFourOfAKind()) {
        rank = 7;
    }
    else if (isFullHouse()) {
        rank = 6;
    }
    else if (isFlush()) {
        rank = 5;
    }
    else if (isStraight()) {
        rank = 4;
    }
    else if (isThreeOfAKind()) {
        rank = 3;
    }
    else if (isTwoPairs()) {
        rank = 2;
    }
    else if (isOnePair()) {
        rank = 1;
    }
    else {
        rank = 0;
    }
}

int Hand::getFourPairValue() {
    return fourPairValue;
}

int Hand::getThreePairValue() {
    return threePairValue;
}

int Hand::getTwoPair1Value() {
    return twoPair1Value;
}

int Hand::getTwoPair2Value() {
    return twoPair2Value;
}

Card Hand::getHighCard() {
    Card highCard = Card("2C");
    for (Card card : hand) {
        if (card.getValue() > highCard.getValue()) {
            highCard = card;
        }
    }
    return highCard;
}

std::vector<Card> Hand::getCards() {
    return hand;
}

Card Hand::getCard(int i) {
    return hand[i];
}

Card Hand::operator[] (int i) {
    return hand[i];
}

void Hand::removeCard(int i) {
    hand.erase(hand.begin() + i);
}

void Hand::removeCard(int n, int value) {
    while (n > 0) {
        for (int i = 0; i < hand.size(); ++i) {
            if (hand[i].getValue() == value) {
                removeCard(i);
                --n;
                break;
            }
        }
    }
}

void Hand::removeCard(Card card) {
    for (int i = 0; i < hand.size(); ++i) {
        if (hand[i] == card) {
            removeCard(i);
            break;
        }
    }
}


class PokerGame {

public:

    Hand player1Hand;
    Hand player2Hand;
    int player1Wins;
    int player2Wins;

    PokerGame();
    void newHands(std::string);
    void compareHighCards();
    void compareHands();
};

PokerGame::PokerGame() {
    player1Wins = 0;
    player2Wins = 0;
}

void PokerGame::newHands(std::string stringHand) {
    std::vector<Card> vectorHand = split(stringHand, ' ');
    player1Hand = Hand(std::vector<Card>(&vectorHand[0], &vectorHand[5]));
    player2Hand = Hand(std::vector<Card>(&vectorHand[5], &vectorHand[10]));
}

void PokerGame::compareHighCards() {
    while (player1Hand.getHighCard().getValue() == player2Hand.getHighCard().getValue()) {
        player1Hand.removeCard(player1Hand.getHighCard());
        player2Hand.removeCard(player2Hand.getHighCard());
    }
    if (player1Hand.getHighCard().getValue() > player2Hand.getHighCard().getValue()) {
        ++player1Wins;
    }
    else {
        ++player2Wins;
    }
}

void PokerGame::compareHands() {
    int player1Rank = player1Hand.getRank();
    int player2Rank = player2Hand.getRank();
    if (player1Rank > player2Rank) {
        ++player1Wins;
    }
    else if (player1Rank < player2Rank) {
        ++player2Wins;
    }
    else {
        switch (player1Rank) {
            case 9: // Royal Flush
            {
                compareHighCards();
            }
            break;
            case 8: // Straight Flush
            {
                compareHighCards();
            }
            break;
            case 7: // Four of a Kind
            {
                if (player1Hand.getFourPairValue() > player2Hand.getFourPairValue()) {
                    ++player1Wins;
                }
                else if (player1Hand.getFourPairValue() < player2Hand.getFourPairValue()) {
                    ++player2Wins;
                }
                else {
                    compareHighCards();
                }
            }
            break;
            case 6: // Full House
            {
                if (player1Hand.getThreePairValue() > player2Hand.getThreePairValue()) {
                    ++player1Wins;
                }
                else if (player1Hand.getThreePairValue() < player2Hand.getThreePairValue()) {
                    ++player2Wins;
                }
                else {
                    compareHighCards();
                }
            }
            break;
            case 5: // Flush
            {
                compareHighCards();
            }
            break;
            case 4: // Straight
            {
                compareHighCards();
            }
            break;
            case 3: // Three of a Kind
            {
                if (player1Hand.getThreePairValue() > player2Hand.getThreePairValue()) {
                    ++player1Wins;
                }
                else if (player1Hand.getThreePairValue() < player2Hand.getThreePairValue()) {
                    ++player2Wins;
                }
                else {
                    compareHighCards();
                }
            }
            break;
            case 2: // Two Pair
            {
                int player1PairValue1 = player1Hand.getTwoPair1Value();
                int player2PairValue1 = player2Hand.getTwoPair1Value();
                int player1PairValue2 = player1Hand.getTwoPair2Value();
                int player2PairValue2 = player2Hand.getTwoPair2Value();

                int player1HigherPair = player1PairValue1 > player1PairValue2 ? player1PairValue1 : player1PairValue2;
                int player2HigherPair = player2PairValue1 > player2PairValue2 ? player2PairValue1 : player2PairValue2;
                int player1LowerPair = !player1PairValue1 > player1PairValue2 ? player1PairValue1 : player1PairValue2;
                int player2LowerPair = !player2PairValue1 > player2PairValue2 ? player2PairValue1 : player2PairValue2;

                if (player1HigherPair > player2HigherPair) {
                    ++player1Wins;
                }
                else if (player1HigherPair < player2HigherPair) {
                    ++player2Wins;
                }
                else {
                    if (player1LowerPair > player2LowerPair) {
                        ++player1Wins;
                    }
                    else if (player1LowerPair < player2LowerPair) {
                        ++player2Wins;
                    }
                    else {
                        compareHighCards();
                    }
                }
            }
            break;
            case 1: // One Pair
            {
                int player1PairValue = player1Hand.getTwoPair1Value();
                int player2PairValue = player2Hand.getTwoPair1Value();
                if (player1PairValue > player2PairValue) {
                    ++player1Wins;
                }
                else if (player1PairValue < player2PairValue) {
                    ++player2Wins;
                }
                else {
                    compareHighCards();
                }
            }
            break;
            case 0: // High Card
            {
                compareHighCards();
            }
            break;
        }
    }
}

int main() {

    PokerGame Game;

    std::ifstream input("0054.txt");
    std::string line;
    int p1pw = 0;
    int p2pw = 0;
    int c = 0;
    while (std::getline(input, line)) {
        Game.newHands(line);
        Game.compareHands();
    }

    std::cout << Game.player1Wins << std::endl;

    return 0;
}
