// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#ifndef __Marina_Cafe__LendItem__
#define __Marina_Cafe__LendItem__

#include <iostream>

using namespace std;

class LendItem
{
private:
    string title;
    char mediumType;
    bool borrowed;
    int borrowNumber;
    
public:
    //Constructor with no parameter
    LendItem();
    
    //constructor with arguments (to initialize title and mediumType)
    LendItem(string titl, char med);
    
    //Function that sets the title of the medium
    void setTitle(string manu);
    
    //Function that sets what medium it is
    void setMedium(char med);
    
    //Function that sets the borrowed number
    void setBNumber(int bNumber);
    
    //Function that checks the status of the medium
    void setBorrowed(bool bstatus);
    
    //Function that returns the status of the the medium
    bool getBorrowed();
    
    //Function that returns the title of the medium
    string getTitle();
    
    //Function that returns the medium type
    char getMedium();
    
    //Function that returns the borrowed number
    int getBNumber();
    
    //Virtual function that prints information of (Books or DVD)
    virtual void printAll(ostream&) = 0;
    
    //Friend function
    friend ostream& operator<<(ostream& out, const LendItem& obj);
};
#endif /* defined(__Marina_Cafe__LendItem__) */
