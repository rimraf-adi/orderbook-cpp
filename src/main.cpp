#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    //data
    private:

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
    private:
        Node* start;
        Node* end;
        int size;
    
    public:
    //constructor
    List(vector<int> lldata ){

        for(int i = 0; i<lldata.size(); i++){
            Node* first = new Node(lldata[i]);
            
            if(i == lldata.size()-1) Node* second = new Node(lldata[i]);
            
            Node* second = new Node(lldata[i+1],first);
        }
        
        this-> size = lldata.size();
    }
    //getter
    void getData(){
        Node* iterator = start;

        while(iterator!= end){
            
        }



        }
    }


    
};

class Orderbook{
    private:
        
};



int main(){
    
    
    Node * head = new Node(180.2);
    head->getNext();
    return 0;

}