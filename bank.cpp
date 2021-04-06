#include <iostream>
#include "bank.h"
#include <array> 

//Suyogya Poudel

using namespace std; 

//Makes everything in the hash table NULL
Bank::Bank(int bsize)
{
    this->tableSize = bsize;
    hashTable = new info*[tableSize];
    for(int i = 0; i <bsize;i++)
    {
        hashTable[i] = NULL;
    }
}

//returns a unique string which will be used as a user's userID
string encodeCreds(string username, string password)
{
    return username+password;
}

//searches if the input from the user is within the hashtable. Returns true if there is and false if there isn't.
bool Bank::login(string u, string p)
{
    if(search(u,p))
    {
        return true;
    }
    return false;
}

//searches if the input from the user is within the hashtable. Returm false if there is already a user with the username
//if the user isn't found in the hash table than it inserts the user into the hashtable and returns true
bool Bank::createNewAccount(string u, string p)
{
    if(search(u, p))
    {
        return false;
    }
    insert(u,p);
    return true;
}

//finds the user using the search function and adds the a(amount) to the current balance of the user
void Bank::deposit(string a, string u, string p)
{
    double amount = stod(a);
    info* user = search(u, p);
    user->balance += amount;
}

//finds the user using the search function and can user can only withdraw if the money they are trying to withdraw is less than or equal 
//to their balance
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

//checks if the password that from the user input matches the password of the account using the search function
//if the password matches, sets the user node to the value gotten from the search function
//if it does
        //if is it the only user in the index, deletes everything in the index
        //if the previous node isn't NULL, makes the prev nodes next node NULL
        //if the next node isn't NULL, makes the next nodes previous node NULL
        //if the next and the previous node isn't NULL, connects the previous and the next node
        //at the end deletes the node and returns true
bool Bank::deleteAccount(string u, string p)
{
    string encoded =  encodeCreds(u,p);
    int index = stringToASCII(u);
    info *userLL;
    if(search(u,p))
    {
        userLL = search(u,p);
    }
    else
    {
        cout<<"\nYour password is incorrect\n"<<endl;
        return false;
    }
    
    while(userLL->userID == encoded && userLL->balance != 0)
    {
        cout<<"\nPlease withdraw all of the money currently in your account before closing it.\n"<<endl;
        return false;
    }
    if(userLL->next != NULL && userLL->prev != NULL)
    {
        userLL->next->prev = userLL->prev;
        userLL->prev->next = userLL->next;
        delete userLL;
        return true;
    }
    else if(userLL->prev != NULL)
    {
        userLL->prev->next = NULL;
        delete userLL;
        return true;
    }
    else if(userLL->next != NULL)
    {
        // userLL->next->prev = NULL;
        delete userLL;
        userLL = userLL->next;
        return true;
        // delete userLL;
    }
    else
    {
        hashTable[index] = NULL;
        delete userLL;
        return true;
    }
    
    return true;
}


//uses the search function to get the user information and prints the users balance
void Bank::printBalance(string u, string p)
{
    info *user = search(u,p);
    cout<<"\nCurrent Balance: $"<<user->balance<<"\n"<<endl;
}

//inserts the user at a specific index, which is the ASCII value of the username
//and if inserted returns true else returns false
bool Bank::insert(string u, string p)
{
    if(!search(u,p))
    {
        string encoded = encodeCreds(u,p);
        int index = stringToASCII(u);
        info *temp = hashTable[index];
        info *insert= new info;
        insert->next = NULL;
        // insert->prev = NULL;
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
            insert->prev = temp;
            temp->next = insert;
        }
        else//no collision
        {
            insert->userID = encoded;
            insert->prev = NULL;
            insert->username = u;
            insert->password = p;
            insert->balance = 0;
            hashTable[index] = insert;
        }
    }
    else
    {
        return false;
    }
    return true;
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

//goes to the specific index that was gotten from the ASCII of the username 
//and if the userID of the temp is the same as username+password
//than it returns if user otherwise returns NULL if the user wasn't found
info* Bank::search(string u, string p)
{
    string encoded = encodeCreds(u,p);
    int index = stringToASCII(u);
    info *temp = hashTable[index];
    while(temp)
    {
        if(temp->userID == encoded && temp->username == u)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//not needed as of right now due to there being default cases. Will be improving this function to be able to deposit or withdraw double instead of just integers
//To check if the user inputs are numbers. I ran into a problem where my program ran into
//an infinite loop if the user input were letters instead of int or double
//This function was made so that I can make sure my program doesn't go into an infinite loop
//instead just askes the user to input a number that is in the menu
// bool Bank::isNum(string num)
// {
//     for(int i = 0; i< num.length(); i++)
//     {
//         if(isdigit(num[i]) == false)
//         {
//             return false;
//         }
//     }
//     return true;
// }

void Bank::printTable()
{
	for(int i = 0; i < tableSize; i++)
	{
		cout<<i<<" || ";
		info *temp = hashTable[i];
		while(temp)
		{
			cout<<temp->username<<" || ";
			temp = temp->next;
		}
		cout<<endl;
	}
}