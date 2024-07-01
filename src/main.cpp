#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	float data;
	Node *next;

public:
	Node(float data) {
		this->data = data;
		this->next = nullptr;
	}
	Node()= default;

	void getData() {
		cout << data << endl;
	}

	void getNext() {
		cout << next;
	}
};

class List {
	Node *start;
	Node *end;

public:
	List(vector<float> a) {
		Node *first = new Node(a[0]);
		Node *mover = first;
		for (int i = 1; i < a.size(); i++) {
			Node *temp = new Node(a[i]);
			mover->next = temp;
			mover = temp;
			end = mover;
		}
		this->start = first;
	}
	List(){
		start = nullptr;
		end = nullptr;
	}

	void printList(Node *first, int size) {
		Node *mover = first;
		for (int i = 0; i < size; i++) {
			mover->getData();
			mover = mover->next;
		}
	}

	void appendData(float data){
		Node* tempNode = new Node(data);
		end->next = tempNode;
		end = end->next;
	}
	Node *getStart() {
		return start;
	}
	Node*getEnd(){
		return end;
	}
};

class Orderbook {
	List buy;
	List sell;
	float currentPrice;

public:
	Orderbook(vector<float> buy, vector<float> sell) {
		this->buy = List(buy);
		this->sell = List(sell);
		this->currentPrice = -1;
	}

	void buyStocks(float price) {}

	void sellStocks(float price) {}

	void getDepth() {}

	void quote(float price) {}
};

int main() {
	vector<float> a = {1.23, 2.99, 3.45, 4.67, 5.98};
	List myList = List(a);
	myList.appendData(55.444);
	// myList.printList(myList.getStart(), a.size()+1);
	Node* end = myList.getEnd();
	end->getData();
	return 0;
}
