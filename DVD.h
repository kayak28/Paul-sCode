// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#ifndef __Marina_Cafe__DVD__
#define __Marina_Cafe__DVD__

#include <iostream>
#include "LendItem.h"

using namespace std;

class DVD : public LendItem
{
private:
    string rating;
    char screenType;
    
public:
    //Constructor with no paramter
    DVD();
    
    //Constructor that takes arguments
    DVD(string titl,string rating,char stype);
    
    //Function that sets the rating
    void setRating(string rate = "PG");
    
    //Function that sets the screen type
    void setScreen(char type);
    
    //Function that returns the rate
    string getRate();
    
    //Function that returns the type
    char getType();
    
    //Function that prints the information of DVD
    void printAll(ostream&);
};

#endif /* defined(__Marina_Cafe__DVD__) */
