#include "Card.h"

#include "Card.h"

Card::Card(int nameValue, int numsuit){
    value = nameValue;
    switch (nameValue) {
        case 2:
            name = "Two";
            break;
        case 3:
            name = "Three";
            break;
        case 4:
            name = "Four";
            break;
        case 5:
            name = "Five";
            break;
        case 6:
            name = "Six";
            break;
        case 7:
            name = "Seven";
            break;
        case 8:
            name = "Eight";
            break;
        case 9:
            name = "Nine";
            break;
        case 10:
            name = "Ten";
            break;
        case 11:
            name = "Jack";
            break;
        case 12:
            name = "Queen";
            break;
        case 13:
            name = "King";
            break;
        case 14:
            name = "Ace";
            break;
        default:
            break;
    }
}

void Card::print() {
    std::cout<< name << endl;
}
