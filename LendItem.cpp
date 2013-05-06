// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#include "LendItem.h"
#include <iostream>

using namespace std;

//Default constructor
LendItem::LendItem()
{
    title = " ";
    mediumType = ' ';
    borrowNumber = 0;
    borrowed = false;
}

//constructor with arguments (to initialize title and mediumType)
LendItem::LendItem(string titl, char med)
{
    setTitle(titl);
    setMedium(med);
    borrowNumber = 0;
    borrowed = false;
}

//Function that sets the title of the medium
void LendItem::setTitle(string manu)
{
    title = manu;
}

//Function that sets what medium it is
void LendItem::setMedium(char med)
{
    mediumType = med;
}

//Function that sets the borrowed number
void LendItem::setBNumber(int bNumber)
{
    borrowNumber = bNumber;
}

//Function that checks the status of the medium
void LendItem::setBorrowed(bool bstatus)
{
    borrowed = bstatus;
}

//Function that returns the status of the the medium
bool LendItem::getBorrowed()
{
    return borrowed;
}

//Function that returns the title of the medium
string LendItem::getTitle()
{
    return title;
}

//Function that returns the medium type
char LendItem::getMedium()
{
    return mediumType;
}

//Function that returns the borrowed number
int LendItem::getBNumber()
{
    return borrowNumber;
}

//Friend function
ostream& operator << (ostream& out, const LendItem& obj)
{
    std::cout << obj.title << endl;
    if(obj.borrowed)
        out << "Number: " << obj.borrowNumber;
    
    return out;
}


