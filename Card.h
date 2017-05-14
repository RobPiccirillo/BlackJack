#include <iostream>
#include <string>

#ifndef CARD
#define CARD

using namespace std;


class Card {
public:
    Card();
    Card(int nameValue);
    int getValue() {return value; }
    virtual ~Card() {}
    void print();
private:
    int value;              //1-10 is number value, j=11, q=12, k=13, ace=14 - BlackJack Value calculated in game
    string name;            //
    
};

#endif
