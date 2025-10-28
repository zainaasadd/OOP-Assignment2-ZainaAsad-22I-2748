#include <iostream>
using namespace std;

struct Book {
    int BookID;
    string Title, Author;
    Book *next, *prev;
    Book(int id,string t,string a):BookID(id),Title(t),Author(a),next(NULL),prev(NULL){}
};

class Library {
    Book* head;
public:
    Library(): head(NULL){}
    void addAtBeg(int id,string t,string a){
        Book* n=new Book(id,t,a);
        n->next=head;
        if(head) head->prev=n;
        head=n;
    }
    void addAtEnd(int id,string t,string a){
        Book* n=new Book(id,t,a);
        if(!head){ head=n; return;}
        Book* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=n; n->prev=temp;
    }
    void deleteByID(int id){
        Book* t=head;
        while(t && t->BookID!=id) t=t->next;
        if(!t) return;
        if(t->prev) t->prev->next=t->next;
        else head=t->next;
        if(t->next) t->next->prev=t->prev;
        delete t;
    }
    void displayForward(){
        for(Book* t=head;t;t=t->next)
            cout<<t->BookID<<" "<<t->Title<<" by "<<t->Author<<endl;
    }
    void displayBackward(){
        if(!head) return;
        Book* t=head;
        while(t->next) t=t->next;
        while(t){
            cout<<t->BookID<<" "<<t->Title<<" by "<<t->Author<<endl;
            t=t->prev;
        }
    }
};

int main(){
    Library lib;
    cout<<"Q3 Library System! :) \n";
    lib.addAtEnd(1,"MicroEconomics","Maria");
    lib.addAtBeg(2,"Business Finance","Fatima");
    lib.addAtEnd(3,"C++ Programming Basics","Zaina");
    cout<<"\nBooks in order:\n"; lib.displayForward();
    cout<<"\nBooks in reverse:\n"; lib.displayBackward();
}
