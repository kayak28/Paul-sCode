// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#include "DVD.h"
#include <iostream>

using namespace std;

//Constructor with no paramter
DVD::DVD() :LendItem()
{   }

//Constructor that takes arguments
DVD::DVD(string titl,string rating,char stype)
:LendItem(titl, 'D')
{
    setRating(rating);
    setScreen(stype);
}

//Function that sets the rating
void DVD::setRating(string rate)
{
    rating = rate;
}

//Function that sets the screen type
void DVD::setScreen(char type)
{
    screenType = type;
}

//Function that returns the rate
string DVD::getRate()
{
    return rating;
}

//Function that returns the type
char DVD::getType()
{
    return screenType;
}

//Function that prints the information of DVD
void DVD::printAll(ostream& out)
{
    out << "Title : " << getTitle()
        << "\nMedium: DVD";
    out << "\nScreen: ";
        if(getType() == 'W' || getType() == 'w')
            out << "widescreen";
        else if(getType() == 'F' || getType() == 'f')
            out << "full screen";
    out << "\nRating: " << getRate();
    out << "\nStatus: ";
        if(getBorrowed() == true)
            out << "Borrowed";
        else if(getBorrowed() == false)
            out << "Available\n";

}