#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 24;

class User
{
    string name;
    int coins;

public:
    void set_values(string n, int x)
    {
        name = n;
        coins = x;
    }
    void printUserInfo()
    {
        cout << "name: " << name << " coins: " << coins << endl;
    }
    string who()
    {
        return name;
    }
    int amount()
    {
        return coins;
    }
};

class UserList
{
    int numberOfUsers = 0;
    User user[MAX_USERS];

public:
    void addToList(User newUser)
    {
        user[numberOfUsers++] = newUser;
    }
    void printUserList()
    {
        for (int i = 0; i < numberOfUsers; i++)
        {
            user[i].printUserInfo();
        }
    }
};

class Transaktion
{
    string transfer[2];
    int transactionValue;
    // public:
};

int main()
{
    User Matilda, Henrik, hehe;
    Matilda.set_values("Matilda", 4);
    Henrik.set_values("Henrik", 1);
    hehe.set_values("hehe", 2);
    
    UserList lista;
    lista.addToList(Matilda);
    lista.addToList(Henrik);
    lista.addToList(hehe);
    lista.printUserList();

    return 0;
}
