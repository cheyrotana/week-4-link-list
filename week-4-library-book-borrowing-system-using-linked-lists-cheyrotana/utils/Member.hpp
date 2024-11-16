#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <iostream>
#include "BookNode.hpp"
#include <string>

class Member{
private:
    std::string name;
    BookNode* firstBook;

public:
    Member(std::string name){
        this->name = name;
        firstBook = nullptr;
    }
    ~Member(){
        BookNode* current = firstBook;
        while(current){
            BookNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    BookNode* getFirstBook(){
        return firstBook;
    }

    void borrowBook(std::string title, std::string borrowDate){
        // your code here
        BookNode* newNode = new BookNode(title,borrowDate);
        if(firstBook==nullptr){//if the first book is empty
            firstBook=newNode;//
        }
        else{
            BookNode* current=firstBook;
            while(current->next){//if the next book is not empty
                current=current->next;//transversing
            }
            current->next=newNode;//connect the last book to the new book
        }
    }

    void returnBook(std::string title){
        // your code here
        BookNode* current=firstBook;
        BookNode* prev=nullptr;
        if(title==firstBook->title){
            firstBook = current->next;//connect the firstBook to Node 2
            delete current;//delete node 1
        }//Case 1: The Book to Remove is the First Node
        else{
            while(current){
                if(current->title==title){
                    prev->next=current->next;//connect the previous node to the next node
                    delete current;
                    break;
                }
                prev=current;//move the previous node to the current node
                current=current->next;//move the current node to the next node
            }
        }
    }

    void displayBorrowInfo(){
        BookNode* temp = firstBook;
        while (temp){
            std::cout<<"- ";
            std::cout<< temp->title <<" Borrow on: "<< temp->borrowDate << std::endl;
            temp = temp->next;
        }
    }

    std::string getName(){
        return this->name;
    }
};

#endif