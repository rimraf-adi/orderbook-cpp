#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    //data
    public:

    float data;
    Node*next;

    //constructors
    public:

    Node(float data, Node*next){
        this -> data = data;
        this -> next = next;}
    Node(float data){
        this -> data = data;
        this -> next = nullptr;}

    //getter
    void getData(){
        cout << data;}

    void getNext(){
        cout << next;}



};

class List{
    public:
        Node* start;
        Node* end;
        int size;

    public:
    //constructor
    List(vector<int> lldata ){
        this-> size = lldata.size();

        Node* first = new Node(lldata[0], start);
        Node* mover = first;
        for(int i = 1; i<lldata.size(); i++){

            Node* temp = new Node(lldata[i]);
            mover->next = temp;
            mover = temp;
            }

    }
    //getter
    void getData(){
        Node* iterator = start;

        while(iterator!= end){

        }



        }




};

class Orderbook{
    private:

};



int main(){

    vector<int> a = {1,2,3,4,5};

    List * list = new List(a);
    cout << list->start;
    return 0;

}