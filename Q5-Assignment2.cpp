#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};
class StackList {
    Node* top;
public:
    StackList():top(NULL){}
    void push(int v){ Node* n=new Node(v); n->next=top; top=n; }
    void pop(){ if(top){ Node* t=top; top=top->next; delete t; } }
    bool empty(){ return !top; }
};

class StackArray {
    int *arr, size, top;
public:
    StackArray(int s){ size=s; arr=new int[s]; top=-1; }
    void push(int v){ if(top<size-1) arr[++top]=v; }
    void pop(){ if(top>=0) top--; }
    bool empty(){ return top==-1; }
    ~StackArray(){ delete[] arr; }
};

int main(){
    cout<<"Q5 Linked List and Array Based Stacks by Zaina!\n";
    StackList s1; s1.push(10); s1.push(20); s1.pop();
    StackArray s2(5); s2.push(1); s2.push(2); s2.pop();
    cout<<"\nBoth stack types work fine, yay!\n";
}

