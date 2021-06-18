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
		this->res = rand();
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

	void printUserInfo() {
		std::cout << "name: " << name << "\tcoins: " << credit << std::endl;
	}
};

class UserList {
	std::list<User> users;

	public:
	void addToList(User &newUser) {
		users.push_back(newUser);
	}

	void printUserList() {
		for(auto user : users) {
			user.printUserInfo();
		}
	}
};

class Transaction {
	User &sender;
	User &resiver;
	int sum;
	// HashStream::hashType hash;
	HashStream hs;
	public:

	Transaction(User &sender, User &resiver, int sum) : sender(sender), resiver(resiver), sum(sum) {
		// HashStream hst;
		setHash(hs);
		// transfer();
	}

	void transfer() {
		sender.credit -= sum;
		resiver.credit += sum;
	}

	// void setHash(Transaction &prev) {
	// 	this->hash = ((prev.getHash() << 5) * 101 + 10101) % 12345;
	// };

	void setHash(HashStream &hs) {
		hs << sender.credit;
		for(auto c: sender.name) {
			hs << c;
		}
		hs << resiver.credit;
		for(auto c: resiver.name) {
			hs << c;
		}
		hs << sum;
		// hs >> this->hash;
	}

	HashStream &getHash() {
		return hs;
	}
	// HashStream::hashType getHash() {
	// 	return hash;
	// }

	void printTransaction() {
		std::cout << "hash: " << hs << std::endl;
		std::cout << "sent: " << sum << std::endl;
		sender.printUserInfo();
		resiver.printUserInfo();
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
		trans.setHash(hs);
		trans.transfer();
		transactions.push_back(trans);
	}


	void printTransactionList() {
		for(auto transaction : transactions) {
			transaction.printTransaction();
		}
	}

	void printHash() {
		std::cout << "hash: " << hs << std::endl;
	}
};

int main() {
	User a("Matilda", 400);
	User b("Henrik", 1000);
	User c("hehe", 200);

	// UserList ulist;
	// ulist.addToList(a);
	// ulist.addToList(b);
	// ulist.addToList(c);

	// ulist.printUserList();

	// std::cout << std::endl;

	User aa("Matilda", 400);
	User bb("Henrik", 1000);
	Transaction t4(aa, bb, 200);
	t4.printTransaction();

	User aaa("Matilda", 400);
	User bbb("Henrik", 1000);
	Transaction t5(aaa, bbb, 200);
	t5.printTransaction();

	Transaction t1(a, b, 200);
	Transaction t2(b, c, 30);
	Transaction t3(c, a, 10);





	TransactionList tlist;
	tlist.addTransaction(t1);
	tlist.addTransaction(t2);
	tlist.addTransaction(t3);

	tlist.printTransactionList();

	tlist.printHash();
	
	HashStream hs;
	
	std::cout << hs;

	return 0;
}
