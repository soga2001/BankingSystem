#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <array>

#include "Final.h"

//Suyogya Poudel

using namespace std;

int main(int argc, char const *argv[]){
    bool exit = false; 
    bool exit2 = false;
    Bank bank(1000);
    cout<<"\nHi, Welcome to Suyogya's Banking System.\n"<<endl;
    while(exit == false){
        ///menu
            std::string dmenu = "###############\n"
                    "#  Main Menu  #\n"
                    "###############\n"
                    "1. Login\n"
                    "2. New to our banking system? Create A New Account\n"
                    "3. Quit";
    
    string Choice;
    
    cout << dmenu << endl;
    
    while(cin >> Choice) {
        
        
        cin.clear();
        cin.ignore();
        while(!bank.isNum(Choice))
        {
            cout<<"Please Enter An Integer Between 1 and 3."<<endl;
            cin>>Choice;
            // break;
        }
        int choice = stoi(Choice);
        
        switch (choice) 
        {
            case 1:
            {
                string username;
                string password;
                cout<<"Username are case sensative."<<endl;
                cout<<"Username: "<<endl;
                cin>>username;
                cout<<"Password: "<<endl;
                cin>>password;
                if(bank.login(username, password))
                {
                    while(exit2 == false)
                    {
                        cout<<"\nLogin Successful!\n"<<endl;    
                        string loginMenu = "################\n"
                        "#  Login Menu  #\n"
                        "################\n"
                        "1. Check Balance\n"
                        "2. Deposit\n"
                        "3. Withdraw\n"
                        "4. Close Your Account\n"
                        "5. LogOut";

                        string login;

                        cout<<loginMenu<<endl;

                        while(cin>>login)
                        {
                            cin.clear();
                            cin.ignore();
                            while(!bank.isNum(login))
                            {
                                cout<<"Please Enter An Integer Between 1 and 5."<<endl;
                                cin>>login;
                                // break;
                            }

                            int choice2 = stoi(login);

                            switch(choice2)
                            {
                                case 1:
                                {
                                    bank.printTable();
                                    bank.printBalance(username, password);
                                    break;
                                }

                                case 2:
                                {
                                    string amount;
                                    bank.printBalance(username, password);
                                    cout<<"How much would you like to deposit?"<<endl;
                                    cin>>amount;
                                    while(!bank.isNum(amount))
                                    {
                                        cout<<"Please enter numbers"<<endl;
                                        cin>>amount;
                                    }
                                    bank.deposit(amount, username, password);
                                    bank.printBalance(username, password);
                                    
                                    break;
                                }

                                case 3:
                                {
                                    string amount;
                                    bank.printBalance(username, password);
                                    cout<<"How much would you like to withdraw?"<<endl;
                                    cin>>amount;
                                    while(!bank.isNum(amount))
                                    {
                                        cout<<"Please enter numbers"<<endl;
                                        cin>>amount;
                                    }
                                    bank.withdraw(amount, username, password);
                                    bank.printBalance(username, password);

                                    break;
                                }

                                case 4:
                                {
                                    string passWord;
                                    cout<<"\nTo make sure no one other then the owner of the account can close their account"<<endl;
                                    cout<<"Please re-enter your password:"<<endl;
                                    cin>>passWord;
                                    if(bank.deleteAccount(username, passWord))
                                    {
                                        cout<<"\nYour account has been closed.\n"<<endl;
                                        exit2 = true;
                                    }
                                    break;
                                }

                                case 5:
                                {
                                    exit2 = true;
                                    cout<<endl;
                                    break;
                                }
                            }
                            if(exit2)
                            {
                                break;
                            }
                            cout << loginMenu << endl;
                        }
                    }
                }
                else
                {
                    cout<<"\nThe username or password is invalid. Please try again.\n"<<endl;
                }
                
                exit2 = false;

                break;
    
            }
            case 2:
            {
                string username;
                string password;
                string password2;
                cout<<"Please Enter Without Spaces."<<endl;
                cout<<"Username: "<<endl;
                cin>>username;
                cout<<"Password: "<<endl;
                cin>>password;
                cout<<"Please retype your password"<<endl;
                cin>>password2;
                while(password != password2)
                {
                    cout<<"Please make sure the password matches"<<endl;
                    cin>>password2;
                }
                if(bank.createNewAccount(username, password))
                {
                    cout<<"\nYour account has been created. Please login using option 1.\n"<<endl;
                }
                else
                {
                    cout<<"\nThere is already an account with this username so your account couldn't be created\n"<<endl;
                }
                
                break;
            }
            case 3:
            {
                exit = true;
                break;
            }
        }
        if (exit) {
                break;
            }
        cout << dmenu << endl;
    }
    }
}