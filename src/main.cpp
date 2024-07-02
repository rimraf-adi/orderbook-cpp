#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Node {
public:
	pair<float,float> data;
	Node *next;

public:
	Node(float price, float quantity) {
		this->data.first = price;
		this->data.second = quantity;
		this->next = nullptr;
	}
	Node()= default;

	void printData() {
		cout << data.first << " " << data.second << endl;

	}

	void getNext() {
		cout << next;
	}
};

class List {
	Node *start;
	Node *end;
	int size;

public:
	List(vector<pair<float,float>> a) {
		Node *first = new Node(a[0].first, a[0].second);
		Node *mover = first;
		for (int i = 1; i < a.size(); i++) {
			Node *temp = new Node(a[i].first, a[i].second);
			mover->next = temp;
			mover = temp;
			end = mover;
		}
		this->size = a.size();
		this->start = first;
	}
	List(){
		start = nullptr;
		end = nullptr;
	}

	Node* search(float target){
		Node* temp = nullptr;
		Node* iterator = start;

		for(int i = 0; i<size; i++){
			if(iterator->data.first == target){
				temp = iterator;
				return temp;
			}
			iterator = iterator->next;}
		return nullptr;

	}
	
	void printList(Node *first, int size) {
		Node *mover = first;
		for (int i = 0; i < size; i++) {
			mover->printData();
			mover = mover->next;
		}
	}

	void appendData(float price, float quantity){
		Node* tempNode = new Node(price, quantity);
		end->next = tempNode;
		end = end->next;
		size++;
	}

	int getSize(){
		return size;
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
	static bool comparePairs(pair<float,float>&a ,pair<float,float>&b) {
		if (a.first != b.first) return a.first > b.first; 
		return a.second > b.second; 
}
	Orderbook(vector<pair<float,float>>buy, vector<pair<float,float>>sell) {
		
		
		sort(buy.begin(), buy.end(), comparePairs);
		sort(sell.begin(), sell.end(), comparePairs);

		this->buy = List(buy);
		this->sell = List(sell);
		this->currentPrice = -1;
	}
	
	void buyStocks(float price, float quantity) {
		Node*iterator= sell.getEnd();
		iterator->printData();

			while(iterator!=nullptr){
			if(price>=iterator->data.first){
				
				
				if(quantity>iterator->data.second){
					quantity = quantity-iterator->data.second;
					//delete node;
					iterator->data.first = 0;
					iterator->data.second = 0;

				}
				else if (quantity<iterator->data.second){
						iterator->data.second = iterator->data.second - quantity;
						iterator = nullptr;
				}
			}
			
			}
	
	}

	void sellStocks(float price, float quantity) {}

	void getDepth() {
		sell.printList(sell.getStart(), sell.getSize());
		cout << "" << endl;
		cout << currentPrice << endl;
		cout << "" << endl;
		buy.printList(buy.getStart(), buy.getSize());

	}

	void quote(float price) {}
};

int main() {


	vector<pair<float, float>> sampleSell = {
        {149.73, 0.86},
        {149.72, 133.59},
        {149.71, 0.86},
        {149.70, 133.61},
        {149.66, 53.21},
        {149.65, 88.36},
        {149.64, 97.96},
        {149.63, 59.83},
        {149.61, 0.17}
	};
	vector<pair<float, float>> sampleBuy = {
        {149.60, 164.58},
        {149.59, 167.89},
        {149.57, 33.45},
        {149.56, 167.18},
        {149.55, 3.48},
        {149.54, 167.19},
        {149.53, 0.12},
        {149.51, 46.00}
    };
	List buyList = List(sampleBuy);
	List sellList = List(sampleSell);


	Orderbook sampleBook = Orderbook(sampleBuy, sampleSell);
	sampleBook.buyStocks(123,123);

	return 0;
}
