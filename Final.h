#include <iostream>
#include <array>

using namespace std;

struct info
{
    string username;
    string password;
    double balance;

    struct info*next;
    // info *next;
    // info *prev;
};

class Bank
{
    int tableSize;
    info* *hashTable;
    info *createNode(string username, info *next);


    public:
        Bank(int bsize);
        // info hashTable[10000];
        bool login(std::string username, std::string password);//done
        bool createNewAccount(std::string username, std::string password);//done
        void deposit(string amount, string username);//done
        void withdraw(string amount, string username);
        bool deleteAccount(string username, string password);
        void printBalance(string username);//done
        bool isNum(string num);
        void printTable();

    private:
        bool insert(string username, string password);//done
        int stringToASCII(string username);//done
        bool search(std::string username, string password);//done
        // int tableSize;
        // info* user;
}; 