// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#include "Book.h"
#include <iostream>

using namespace std;

//Contructor that takes no parameter
Book::Book():LendItem()
{   }

//Constructor that takes 3 parameters
Book::Book(string titl, string auth, char cover)
:LendItem(titl, 'B')
{
    setAuthor(auth);
    setCover(cover); 
};

//Function that sets the author's name
void Book::setAuthor(string auth)
{
    author = auth;
}

//Function that set the cover type
void Book::setCover(char type)
{
    coverType = type;
}

//Function that returns the name of the author
string Book::getAuth()const
{
    return author;
}

//Function that returns the cover type
char Book::getCover()const
{
    return coverType;
}

//Function that prints the information of Book
void Book::printAll(ostream& out)
{
    out << "Title : " << getTitle()
        << "\nMedium: Book";
    out << "\nAuthor: " << getAuth()
        << "\nCover : ";
        if(getCover() == 'S' || getCover() == 's')
            out << "Soft Copy";
        else if(getCover() == 'H' || getCover() == 'h')
            out << "Hard Copy";
    out << "\nStatus: ";
    if(getBorrowed() == true)
        out << "Borrowed";
    else if(getBorrowed() == false)
        out << "Available\n";
    
}