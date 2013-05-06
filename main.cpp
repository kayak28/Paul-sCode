// Paul Williams Diaz
// pauldiaz@my.smccd.edu
// CIS 256 C++ Methods
// Project # 7
// Prof. Stacey Grasso
// 4/29/13

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include "LendItem.h"
#include "Book.h"
#include "DVD.h"

using namespace std;

int main()
{
    string titlebook, booksearch, moviesearch, itemsearch1;
    string itemsearch2, titlemovie, author;
    string rating, item2, searchAuthor;
    string item1;
    int choice, borrow, id, search, case7;
    int bookCount = 0;
    int dvdCount = 0;
    char cover;
    
    int const SIZE = 15;
    
    Book* bookCollection[SIZE];
    DVD* dvdCollection[SIZE];
    
    std::cout << "\n";
    do
    {
        std::cout << "Enter 0 to exit" << endl;
        std::cout << "Enter 1 to enter a book." << endl;
        std::cout << "Enter 2 to enter a DVD."<< endl;
        std::cout << "Enter 3 to borrow a book or DVD." << endl;
        std::cout << "Enter 4 to print all books stored." << endl;
        std::cout << "Enter 5 to print all DVDs stored." << endl;
        std::cout << "Enter 6 to search an item (title)." << endl;
        std::cout << "Enter 7 to print info of an item (title)." << endl;
        std::cout << "Enter 8 to print all books wrote (author)." << endl;
        std::cout << "Enter 9 to items (books & movies) owned by the Marina,"<< endl;
        std::cout << "             but unavailable: ";
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cout << "\nEnter book's title: ";
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, titlebook);
                
                std::cout << "Enter book's author: ";
                getline(std::cin, author);
                
                std::cout << "Enter cover type: ";
                std::cin >> cover;
                
                //std::cout << "Case 1 " << bookCount <<endl;
                Book* myBook = new Book(titlebook, author, cover);
                bookCollection[bookCount] = myBook;
    
                //std::cout << bookCollection[bookCount];
                //bookCollection[bookCount]->printAll(cout);
                bookCount++;
                std::cout << "\n";
                break;
            }
            case 2:
            {
                std::cout << "\nEnter movie's title: ";
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, titlemovie);
                
                std::cout << "Rate this movie: ";
                getline(std::cin, rating);
                
                std::cout << "Enter screen type: ";
                std::cin >> cover;
                
                DVD* myDVD = new DVD(titlemovie, rating, cover);
                dvdCollection[dvdCount] = myDVD;
                
                dvdCount++;
                std::cout << "\n";
                break;
            
            }
            //3 borrow a Book or DVD, user provides title of item to be borrowed
            case 3:
            {
                std::cout << "\nEnter 1 to borrow a book."<< endl;
                std::cout << "Enter 2 to borrow a movie: ";
                std::cin >> borrow;
                std::cout << "\n";
                
                if(borrow == 1)
                {
                    std::cout << "Enter book's title: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, booksearch);
                    
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(bookCollection[i]->getTitle() == booksearch)
                        {
                            if(!bookCollection[i]->getBorrowed())
                            {
                                std::cout << "Enter your ID number: ";
                                std::cin >> id;
                                
                                bookCollection[i]->setBorrowed(true);
                                bookCollection[i]->setBNumber(id);
                                
                                std::cout << "--Success!--\n";
                                break;
                                
                            }
                            else
                            {
                                std::cout << "\nThis book is out/borrowed.\n";
                            }
                        }
                        else if(bookCollection[i]->getTitle() != booksearch)
                        {
                            
                            std::cout << "\nThis book doesn't exists in the array\n";
                            break;
                        }
                    }//end for loop
                    
                    std::cout << "\n";
                }//end if
                
                else if(borrow == 2)
                {
                    std::cout << "Enter movies's title: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, moviesearch);
                    
                    //std::cout << "Test 1" << endl;
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(dvdCollection[i]->getTitle() != moviesearch)
                        {
                            std::cout << "\nThis movie doesn't exists in the array.\n";
                            break;
                            
                        }//end if statement
                        
                        else
                        {
                            if(!dvdCollection[i]->getBorrowed())
                            {
                                std::cout << "Enter your ID number: ";
                                std::cin >> id;
                                
                                dvdCollection[i]->setBorrowed(true);
                                dvdCollection[i]->setBNumber(id);
                                
                                std::cout << "--Success!--\n";
                                break;
                            }
                            else
                            {
                                std::cout << "\nThis movie is out/borrowed.\n";
                            }
                        }
                    }//end if else statement
                    std::cout << "\n";
                }//end for loop
            
                break;
            }
        
          //4 print out the title and borrowed status of all Books currently stored
            case 4:
                std::cout << "\n----- Books -----" << endl;
                for(int i = 0; i < SIZE; i++)
                {
                    bookCollection[i]->printAll(cout);
                    std::cout << "\n" << endl;
                    
                }
                std::cout << endl;
                break;
            //5 print out the title and borrowed status of all DVDs currently stored 
            case 5:
                std::cout << "\n----- DVDs -----" << endl;
                for(int i = 0; i < SIZE; i++)
                {
                    dvdCollection[i]->printAll(cout);
                    std::cout << "\n" << endl;
                    
                }
                std::cout << endl;
                break;
        
            //6 accept a title as input, and output a message indicating if that item is owned marina, and if so, is available to borrow
            case 6:
            {
                std::cout << "\n";
                std::cout << "Enter 1 to search a book.\n";
                std::cout << "Enter 2 to search a movie: ";
                std::cin >> search;
                
                if(search == 1)
                {
                    std::cout << "\nEnter the title of the item: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, item1);
                    
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(bookCollection[i]->getTitle() == item1)
                        {
                            std::cout << "\nThis book is owned by the Marina Cafe.";
                            
                            if(!bookCollection[i]->getBorrowed())
                            {
                                std::cout << "\nThis book is available\n" << endl;
                                break;
                            }
                            else
                            {
                                std::cout << "\nThis book is out/borrowed.\n";
                                std::cout << "Borrowed by: " << bookCollection[i]->getBNumber() << endl;
                                break;
                            }
                        }
                        else if(bookCollection[i]->getTitle() != item1)
                        {
                            std::cout << "\nThis book doesn't exists in the array.\n" << endl;
                            break;
                        }//end if
                    }//end for loop
                }//end if
    
                else if(search == 2)
                {
                    string item2;
                    
                    std::cout << "\nEnter the title of the item: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, item2);
                    
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(dvdCollection[i]->getTitle() == item2)
                        {
                            std::cout << "\nThis movie is owned by the Marina Cafe.";
                            
                            if(!dvdCollection[i]->getBorrowed())
                            {
                                std::cout << "\nThis movie is available\n";
                                break;
                            }
                            else
                            {
                                std::cout << "\nThis movie is out/borrowed.\n";
                                std::cout << "Borrowed by: " << dvdCollection[i]->getBNumber() << endl;
                                break;
                            }
                        }
                        
                        else
                        {
                            std::cout << "\nThis movie doesn't exists in the array.\n" << endl;
                            break;
                        }//end if
                        
                    }//end for loop
                }
                break;
            }
            //7 accept a title as input, and output all stored information about that title
            case 7:
                std::cout << "\n";
                std::cout << "Enter 1 to search a book.\n";
                std::cout << "Enter 2 to search a movie: ";
                std::cin >> case7;
                
                if(case7 == 1)
                {
                    bool exists = false;
                    std::cout << "\nEnter the title of the item: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, itemsearch1);
                    
                    //std::cout << "Test " << bookCount << " " << SIZE << endl;
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(bookCollection[i]->getTitle() != itemsearch1)
                        {
                           exists = false;
                        }
                        else if(bookCollection[i]->getTitle() == itemsearch1)
                        {
                            exists = true;
                        }
                    }//end for loop
                    if(exists)
                    {
                        std::cout << "\n---Book Information---\n";
                        bookCollection[i]->printAll(cout);
                        std::cout << "\n";
                    }
                    else
                    {
                        std::cout << "Book does not exsist in the array\n";
                    }
                }//end of if statement
                
                else if(case7 == 2)
                {
                    std::cout << "\nEnter the title of the item: ";
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, itemsearch2);
                    
                    for(int i = 0; i < SIZE; i++)
                    {
                        if(dvdCollection[i]->getTitle() != itemsearch2)
                        {
                            std::cout << "\nThis movie doesn't exists in the array.\n" << endl;
                            break;
                        }
                        else if(dvdCollection[i]->getTitle() == itemsearch2)
                        {
                            std::cout << "\n---DVD Information---\n";
                            dvdCollection[i]->printAll(cout);
                            std::cout << "\n";
                            break;
                        }
                    }//end for loop
                }//end of else statement
                std::cout << "\n";
                break;
                
            //8 accept an author name as input, and output the title of all books by the author which are owned by the marina
            case 8:
                std::cout << "\n";
                std::cout << "Enter author's name: ";
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, searchAuthor);
                
                std::cout << "\n---Books of " << searchAuthor << "---";
                
                for(int i = 0; i < SIZE; i++)
                {
                    if(bookCollection[i]->getAuth() != searchAuthor)
                    {
                        std::cout << "\nThis author doesn't exists in the array.\n";
                        break;
                    }
                    
                    else
                    {
                        std::cout << "" << endl;
                        
                        for(int i = 0; i < SIZE; i++)
                        {
                            std::cout << i + 1  << ": " << bookCollection[i]->getTitle();
                            std::cout << "\n";
                        }
                        break;
                    }
                }
                std::cout << "-----------------------------\n\n";
                break;
        
            //9 output the Name only of all items which are currently owned but unavailable (ie have been borrowed)
            case 9:
                std::cout << "\nBooks that are owned by the Marina\n-----but unavailable-----\n";
                
                
                for(int i = 0; i < SIZE; i++)
                {
                    if(bookCollection[i]->getBorrowed())
                    {
                        std::cout << "\n" << bookCollection[i]->getTitle() << endl;
                        std::cout << "Borrowed by: " << bookCollection[i]->getBNumber() << endl;
                        std::cout << "\n";
                    }
                }
                std::cout << "----------------------------------\n";
                std::cout << "\nMovies that are owned by the Marina\n-----but unavailable-----\n";
                
                for(int i = 0; i < SIZE; i++)
                {
                    if(dvdCollection[i]->getBorrowed())
                    {
                        std::cout << "\n" << dvdCollection[i]->getTitle() << endl;
                        std::cout << "Borrowed by: " << dvdCollection[i]->getBNumber() << endl;
                        std::cout << "\n";
                    }
                }
                std::cout << "----------------------------------\n\n";
                break;
        }//end switch
    }while(choice != 0);//end do while
    
    std::cout << "\nThank you." << endl;
    std::cout << "Programmed by: Paul Diaz";
    return 0;
}

