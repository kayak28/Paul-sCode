// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#ifndef __Marina_Cafe__Book__
#define __Marina_Cafe__Book__

#include "LendItem.h"
#include <iostream>

using namespace std;

class Book : public LendItem
{
private:
    string author;
    char coverType;
    
public:
    //Contructor that takes no parameter
    Book();
    
    //Constructor that takes 3 parameters
    Book(string titl, string auth, char cover);
    
    //Function that sets the author's name
    void setAuthor(string auth);
    
    //Function that set the cover type
    void setCover(char type);
    
    //Function that returns the name of the author
    string getAuth() const;
    
    //Function that returns the cover type
    char getCover() const;
    
    //Function that prints the information of Book
    void printAll(ostream&);
};

#endif /* defined(__Marina_Cafe__Book__) */
