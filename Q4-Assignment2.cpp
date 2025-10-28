#include <iostream>
using namespace std;

struct Customer {
    int id, tickets;
    string name;
    Customer* next;
    Customer(int i,string n,int t):id(i),name(n),tickets(t),next(NULL){}
};

class Queue {
    Customer *front,*rear;
public:
    Queue():front(NULL),rear(NULL){}
    void enqueue(int id,string n,int t){
        Customer* c=new Customer(id,n,t);
        if(!rear) front=rear=c;
        else{ rear->next=c; rear=c; }
    }
    void dequeue(){
        if(!front){ cout<<"Queue empty\n"; return;}
        Customer* t=front;
        front=front->next;
        if(!front) rear=NULL;
        cout<<"\nServing "<<t->name<<" ("<<t->tickets<<" tickets)\n";
        delete t;
    }
    void display(){
        for(Customer* t=front;t;t=t->next)
            cout<<t->id<<" "<<t->name<<" wants "<<t->tickets<<" tickets\n";
    }
    ~Queue(){ while(front) dequeue(); }
};

int main(){
    cout<<"Q4 Movie Queue System! :) \n\n";
    Queue q;
    q.enqueue(1,"Zaina",2);
    q.enqueue(2,"Maria",4);
    q.enqueue(3,"Sumayya",1);
    cout<<"Current queue:\n"; q.display();
    q.dequeue();
    cout<<"\nAfter serving one:\n"; q.display();
}
