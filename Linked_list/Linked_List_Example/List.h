#include"Node.h"
class List
{
    private:
    Node *head;
    Node *tail;

    public:
    List();

    void setHead(Node*);
    Node *getHead();
    void setTail(Node*);
    Node* getTail();

    bool isEmpty();
    Node* findNode(int);

    void insertAtHead(int);
    void insertAtTail(int);
    void insertAtTarget(int,int);

  //  void remove(int);

   // int count();
    void print();

};