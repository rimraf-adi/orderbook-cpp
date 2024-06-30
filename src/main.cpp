#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
	//data
	public:

	float data;
	Node * next;

	//constructors
	public: Node(float data)
	{
		this->data = data;
		this->next = nullptr;
	}

	//getter
	void getData()
	{
		cout << data << endl;
	}

	void getNext()
	{
		cout << next;
	}
};

class List
{
	Node * start;
	public:
		List(vector<float> a)
		{
			Node *first = new Node(a[0]);
			Node *mover = first;
			for (int i = 1; i < a.size(); i++)
			{
				Node *temp = new Node(a[i]);
				mover->next = temp;
				mover = temp;
			}

			this->start = first;
		}

        List() = default;

	void printList(Node *first, int size)
	{
		Node *mover = first;

		for (int i = 0; i < size; i++)
		{
			mover->getData();
			mover = mover->next;
		}
	}
    Node*getStart(){
        return start;
    }


};

class Orderbook
{

    List buy;
    List sell;
	float currentPrice;

	public: 
    
    Orderbook(vector<float> buy, vector<float> sell) {
        this->buy = List(buy);
        this->sell = List(sell);
        this-> currentPrice = -1;
    }

	void buyStocks(float price) {}

	void sellStocks(float price) {}

	void getDepth() {}

	void quote(float price) {}
};

int main()
{
	vector<float> a = { 1.23,2.99,3.45,4.67,5.98};

	List list = List(a);
    list.printList(list.getStart(), a.size());
	return 0;

}