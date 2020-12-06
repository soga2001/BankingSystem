#include <iostream>
#include <array>

//Suyogya Poudel

using namespace std;

struct info
{
    string username;
    string password;
    double balance;

    struct info*next;
    string userID;
};

class Bank
{
    int tableSize;
    info* *hashTable;
    info *createNode(string username, info *next);


    public:
        Bank(int bsize);
        bool login(std::string username, std::string password);//done
        bool createNewAccount(std::string username, std::string password);//done
        void deposit(string amount, string username, string password);//done
        void withdraw(string amount, string username, string password);
        bool deleteAccount(string username, string password);
        void printBalance(string username, string password);//done
        bool isNum(string num);

    private:
        bool insert(string username, string password);//done
        int stringToASCII(string namePass);//done
        info* search(std::string username, string password);//done
}; 