#include <iostream>
#include "Final.h"
#include <array> 

//Suyogya Poudel

using namespace std;    

Bank::Bank(int bsize)
{
    this->tableSize = bsize;
    hashTable = new info*[tableSize];
    for(int i = 0; i <bsize;i++)
    {
        hashTable[i] = NULL;
    }
}

string encodeCreds(string username, string password)
{
    return username+password;
}

bool Bank::login(string u, string p)
{
    if(search(u,p))
    {
        return true;
    }
    return false;
}

bool Bank::createNewAccount(std::string u, std::string p)
{
    if(search(u, p))
    {
        return false;
    }
    insert(u,p);
    return true;
}

void Bank::deposit(string a, string u, string p)
{
    double amount = stod(a);
    info* user = search(u, p);
    user->balance += amount;
}

void Bank::withdraw(string a, string u, string p)
{
    
    double amount = stod(a);
    info* user = search(u,p);
    if(amount > user->balance)
    {
        cout<<"\nThe amount you are currently trying to withdraw is greather than what is in your bank account. Please try again.\n"<<endl;
    }
    else
    {
        user->balance -= amount;
    }
    
}

bool Bank::deleteAccount(string u, string p)
{
    string encoded =  encodeCreds(u,p);
    int index = stringToASCII(encoded);
    info* userLL = hashTable[index];
    while(userLL->username == u && userLL->balance != 0)
    {
        cout<<"\nPlease withdraw all of the money currently in your account before closing it.\n"<<endl;
        return false;
    }
    hashTable[index] = NULL;
    return true;
}

void Bank::printBalance(string u, string p)
{
    info *user = search(u,p);
    cout<<"\nCurrent Balance: $"<<user->balance<<"\n"<<endl;
}

bool Bank::insert(string u, string p)
{
    if(!search(u,p))
    {
        string encoded = encodeCreds(u,p);
        int index = stringToASCII(encoded);
        info *temp = hashTable[index];
        info *insert= new info;
        if(temp)//collision
        {
            while(temp->next)
            {
                temp = temp->next;
            }
            insert->userID = encoded;
            insert->username = u;
            insert->password = p;
            insert->balance = 0;
            temp->next = insert;
        }
        else//no collision
        {
            insert->userID = encoded;
            insert->username = u;
            insert->password = p;
            insert->balance = 0;
            insert->next = NULL;
            hashTable[index] = insert;
        }
    }
    else
    {
        return false;
    }
    return true;

    //an attempt at probing
    
    
}

//can also be called hashSum and it just turns the username into an ascii
int Bank::stringToASCII( string up ) {
    int seed = 101;
    unsigned int hash = 0;
    for(int i = 0; i < up.length(); i++) {
        hash = (hash * seed) + up[i];
    }

    hash = hash % tableSize;
    return hash;
}

info* Bank::search(string u, string p)
{
    string encoded = encodeCreds(u,p);
    int index = stringToASCII(encoded);
    info *temp = hashTable[index];
    while(temp)
    {
        if(temp->userID == encoded)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//too check is the inputs are numbers so that the program doesn't go to an infinite loop if the input is not a number
bool Bank::isNum(string num)
{
    for(int i = 0; i< num.length(); i++)
    {
        if(isdigit(num[i]) == false)
        {
            return false;
        }
    }
    return true;
}
