class Node
{
    private:
        int data;
        Node* next;
    public:
        Node();
        Node(int);

        int getData();
        void setData(int);

        Node *getNext();
        void setNext(Node*);
};