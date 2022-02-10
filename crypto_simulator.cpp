#include <iostream>
#include <string>
#include <list>


struct HashStream {
	typedef unsigned long long hashType;
	private:
	hashType res = 1337;
	void addData(int data) {
		srand(res);
		srand(rand() + data);
		res = rand();
	}

	friend HashStream &operator<<(HashStream &output, const hashType &data) {
		output.addData(data);
		return output;
	}

	friend HashStream &operator>>(HashStream &input, hashType &data) {
		data = input.res;
		return input;
	}

	friend std::ostream &operator<<(std::ostream &output, const HashStream &hs) {
		output << hs.res;
		return output;
	}
};


class User {
	public:
	const std::string &name;
	int credit;

	User(const std::string &name, int credit) : name(name), credit(credit) {}

	void printUserInfo() const {
		std::cout << "name: " << name << "\tcoins: " << credit << std::endl;
	}
};

class UserList {
	std::list<const User *> users;
	// std::list<std::reference_wrapper<User>> users;
	public:
	void addToList(const User *newUser) {
		users.push_back(newUser);
		// users.push_back(User("hh", 2));
	}

	void printUserList() const {
		for(const auto &user : users) {
			user->printUserInfo();
		}
	}
};

class Transaction {
	User &sender;
	User &reciever;
	const int sum;
	bool isValid;
	// std::unique_ptr<int> k;

	// HashStream::hashType hash;
	public:
	// HashStream hs;

	Transaction(User &sender, User &reciever, const int sum) : sender(sender), reciever(reciever), sum(sum) {
		// HashStream hst;
		// setHash(hs);
		// transfer();
		if(sender.credit < sum) {
			isValid = false;
		} else {
			isValid = true;
		}
	}

	void transfer() {
		sender.credit -= sum;
		reciever.credit += sum;
	}

	void setHash(HashStream &hs) {
		hs << sender.credit;
		for(const auto &c : sender.name) {
			hs << c;
		}
		hs << reciever.credit;
		for(const auto &c : reciever.name) {
			hs << c;
		}
		hs << sum;
		hs << isValid;
	}


	void printTransaction() const {
		// std::cout << "hash: " << hs << std::endl;
		sender.printUserInfo();
		reciever.printUserInfo();
		std::cout << "sent: " << sum << std::endl;
		std::cout << std::boolalpha;
		std::cout << "valid: " << isValid << std::endl;
		std::cout << std::noboolalpha;
		std::cout << std::endl;
	}
};


class TransactionList {
	std::list<Transaction> transactions;
	HashStream hs;
	public:

	void addTransaction(Transaction &trans) {
		// if(transactions.size() > 0) {
		// 	// trans.setHash(transactions.back());
		// }
		// hs.addData(trans.getHash());
		// trans.setHash(trans.hs);
		// hs << trans.hs.res;
		trans.setHash(hs);
		trans.transfer();
		transactions.push_back(trans);
	}


	void printTransactionList() const {
		for(const auto &transaction : transactions) {
			transaction.printTransaction();
		}
	}

	void printHash() const {
		std::cout << "hash: " << hs << std::endl;
	}
};

int main() {
	using std::cout, std::endl;


	// HashStream hs;

	// hs << 222;
	// hs << 222;

	// cout << hs << endl;



	// return 0;

	User a("Matilda", 400);
	User b("Henrik", 1000);
	User c("hehe", 200);

	UserList ulist;
	ulist.addToList(&a);
	ulist.addToList(&b);
	ulist.addToList(&c);

	ulist.printUserList();

	std::cout << std::endl;
	std::cout << std::endl;


	// return 0;
	// User aa("Matilda", 400);
	// User bb("Henrik", 1000);
	// Transaction t4(aa, bb, 200);
	// t4.printTransaction();

	// User aaa("Matilda", 400);
	// User bbb("Henrik", 1000);
	// Transaction t5(aaa, bbb, 2001);
	// t5.printTransaction();

	Transaction t1(a, b, 200);
	Transaction t2(b, c, 30);
	Transaction t3(c, a, 110);



	TransactionList tlist;
	tlist.addTransaction(t1);
	tlist.addTransaction(t2);
	tlist.addTransaction(t3);

	tlist.printTransactionList();

	// tlist.printHash();

	// HashStream hs;

	// cout << hs;

	// cout << t1.getHash() << endl;

	return 0;
}
