#include <iostream>

using namespace std;

struct user
{
    int id;
    int credit;
};

class transaction
{
public:
    user dest;
    user receiver;
    int sum;
    int hash;
    
    // transaction()
    
    int getHash(transaction &prev) {
        
    };
};

class bc
{
    transaction root;
    
    
};



int hash(int data) {
    data *= 123456789;
    
    
    
}




int main()
{
    user a{0, 100};
    user b{1, 100};
    
    transaction t1;
    
    
    cout << "hello world" << endl;
    return 0;
}