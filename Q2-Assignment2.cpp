
#include <iostream>
using namespace std;

class Feature {
public:
    string Name;
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n){ Name = n; }
    void analyze() override { cout << Name << ": Land area detected\n"; }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n){ Name = n; }
    void analyze() override { cout << Name << ": Water body detected\n"; }
};

struct Node {
    int FeatureID;
    Feature *data;
    Node *next;
    Node(int id, Feature* f): FeatureID(id), data(f), next(NULL) {}
};

class SinglyLinkedList {
    Node *head;
public:
    SinglyLinkedList(): head(NULL) {}
    void insertAtEnd(int id, Feature* f){
        Node *n = new Node(id, f);
        if(!head) head = n;
        else {
            Node *temp=head;
            while(temp->next) temp=temp->next;
            temp->next=n;
        }
    }
    void deleteByID(int id){
        Node *temp=head, *prev=NULL;
        while(temp && temp->FeatureID!=id){ prev=temp; temp=temp->next; }
        if(!temp) return;
        if(!prev) head=temp->next; else prev->next=temp->next;
        delete temp;
    }
    void displayAll(){
        for(Node* t=head;t;t=t->next) t->data->analyze();
    }
    void reverseList(){
        Node *prev=NULL,*curr=head,*next=NULL;
        while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; }
        head=prev;
    }
    ~SinglyLinkedList(){
        while(head){ Node* t=head; head=head->next; delete t; }
    }
};

int main(){
    cout<<"Q2 NASA Features! :)\n\n";
    SinglyLinkedList list;
    list.insertAtEnd(1,new LandFeature("Forest"));
    list.insertAtEnd(2,new WaterFeature("River"));
    list.insertAtEnd(3,new LandFeature("Desert"));
    cout<<"All features:\n"; list.displayAll();
    list.deleteByID(2);
    cout<<"\nAfter deleting ID 2:\n"; list.displayAll();
    list.reverseList();
    cout<<"\nAfter reversing:\n"; list.displayAll();
}
