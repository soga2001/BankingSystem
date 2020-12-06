#include <iostream>
#include "Final.h"
#include <array> 

using namespace std;

info* Bank::createNode(string u, info* next)
{
    info *user = new info;
    user->username = u;
    user->next = next;
    return user;
}

Bank::Bank(int bsize)
{
    this->tableSize = bsize;
    hashTable = new info*[tableSize];
    for(int i = 0; i <bsize;i++)
    {
        hashTable[i] = NULL;
    }
}

bool Bank::login(string u, string p)
{
    if(search(u, p))
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

void Bank::deposit(string a, string u)
{
    int index = stringToASCII(u);
    double amount = stod(a);
    hashTable[index]->balance += amount;
}

void Bank::withdraw(string a, string u)
{
    int index = stringToASCII(u);
    double amount = stod(a);
    if(amount > hashTable[index]->balance)
    {
        cout<<"\nThe amount you are currently trying to withdraw is greather than what is in your bank account. Please try again.\n"<<endl;
    }
    else
    {
        hashTable[index]->balance -= amount;
        // user->balance -= amount;
        // cout<<"\nNew balance: "<<user.balance<<"\n"<<endl;
    }
    
}

bool Bank::deleteAccount(string u, string p)
{
    int index = stringToASCII(u);
    if(hashTable[index] != NULL && search(u,p) && hashTable[index]->balance != 0)
    {
        cout<<"\nPlease withdraw all of the money currently in your account before closing it.\n"<<endl;
        return false;
    }
    hashTable[index] = NULL;
    return true;
}

void Bank::printBalance(string u)
{
    int index = stringToASCII(u);
    cout<<"\nCurrent Balance: "<<hashTable[index]->balance<<"\n"<<endl;
}

bool Bank::insert(string u, string p)
{
    // if(!search(u,p))
	// {
	// 	int index = stringToASCII(u);
	// 	info *temp = hashTable[index];
	// 	info *insert= new info;
	// 	insert->username = u;
    //     insert->password = p;
    //     insert->balance = 0;
	// 	insert->next = NULL;
	// 	if(temp)//collision
	// 	{
	// 		while(temp->next)
	// 		{
	// 			temp = temp->next;
	// 		}
    //         insert->username = u;
    //         insert->password = p;
    //         insert->balance = 0;
	// 		temp->next = insert;
	// 	}
	// 	else//no collision
	// 	{
    //         insert->username = u;
    //         insert->password = p;
    //         insert->balance = 0;
    //         insert->next = NULL;
	// 		hashTable[index] = insert;
	// 	}
	// }
	// else
	// {
	// 	return false;
	// }
    // return true;

    int index = stringToASCII(u);

    while(hashTable[index] != NULL) //&& hashTable[index]->username != u)
    {
        index++;
        index %= tableSize;
    }
    hashTable[index]->username = u;
    hashTable[index]->password = p;
    hashTable[index]->balance = 0;
    
}

//can also be called hashSum and it just turns the username into an ascii
int Bank::stringToASCII(string u)
{
    int l = u.length();
    int convert = 0;
    for(int i = 0; i < l; i++)
    {
        convert += u[i];
    }
    int sum = convert % tableSize;
    // cout<<sum<<endl;
    return sum;
     
}

bool Bank::search(string u, string p)
{
    // int index = stringToASCII(u);
    // // if(hashTable[index] != NULL)
    // if(hashTable[index]->username == u && hashTable[index]->password == p)
    // {
    //     user = hashTable[index];
    //     return true;
    // }
    // return false;

    int index = stringToASCII(u);
	info *temp = hashTable[index];
	while(temp)
	{
		if(temp->username == u && temp->password == p)
		{
			return hashTable[index];
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

//Since the HashTable size is 10000, please lower the
// void Bank::printTable()
// {
// 	for(int i = 0; i < tableSize; i++)
// 	{
// 		cout<<i<<" || ";
// 		info *temp = hashTable[i];
// 		while(temp)
// 		{
// 			cout<<temp->username<<" ";
// 			temp = temp->next;
// 		}
// 		cout<<endl;	
// 	}
// }