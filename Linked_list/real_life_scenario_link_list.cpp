#include <iostream>
#include <string>
using namespace std;
// Class to store person details
class Person
{
private:
    int id;
    string name;
    string phoneNumber;
    Person* next; // Pointer to the next person
public:
    // Default constructor
    Person()
    {
        id=0;
        name="";
        phoneNumber="";
        next=NULL;
    }
    // Constructor with parameters
    Person(int id, string name, string phoneNumber)
    {
        this->id=id;
        this->name=name;
        this->phoneNumber=phoneNumber;
        next=NULL;
    }
    // Getter methods
    int getId() 
    {
     return id; 
    }
    string getName() 
    { 
        return name; 
    }
    string getPhoneNumber() 
    { 
    return phoneNumber; 
}
    // Setter methods
    void setId(int id) 
    {
    this->id=id; 
    }
    void setName(string name)
    {
    this->name=name; 
}
    void setPhoneNumber(string phoneNumber) 
    {
         this->phoneNumber=phoneNumber; 
    }

    // Get and set next person
    Person* getNext() 
    {
    return next; 
}
    void setNext(Person* next) 
    {
    this->next=next; 
}
};
// Class to manage the list of people
class BankList
{
private:
    Person* head; // Points to the first person in the list

public:
    // Constructor
    BankList()
    {
        head=NULL;
    }

    // Check if list is empty
    bool isEmpty()
    {
        return head==NULL;
    }
 // Find a person by ID
    Person* findPerson(int id)
    {
        Person* temp=head;
        while(temp!=NULL)
        {
            if(temp->getId()==id)
            {
                return temp;
            }
            temp=temp->getNext();
        }
        return NULL;
    }
   // Add person at the start of the list
    void addAtStart(int id, string name, string phoneNumber)
    {
        Person* temp=new Person(id, name, phoneNumber);
        temp->setNext(head);
        head=temp;
    }
   // Add person at the end of the list
    void addAtEnd(int id, string name, string phoneNumber)
    {
        Person* temp=new Person(id, name, phoneNumber);
        if(isEmpty())
        {
            head=temp;
        }
        else
        {
            Person* current=head;
            while(current->getNext()!=NULL)
            {
                current=current->getNext();
            }
            current->setNext(temp);
        }
    }
   // Add person after a specific ID
    void addAfter(int targetId, int id, string name, string phoneNumber)
    {
        Person* target=findPerson(targetId);
        if(target==NULL)
        {
            cout<<"Person with ID "<<targetId<<" not found in list."<<endl;
            return;
        }
      Person* newPerson=new Person(id, name, phoneNumber);
        newPerson->setNext(target->getNext());
        target->setNext(newPerson);
    }
   // Display all people in the list
    void displayList()
    {
        Person* temp=head;
        cout<<"\n🏦 Current Bank List:\n";
        while(temp!=NULL)
        {
            cout<<"ID: "<<temp->getId()
                <<", Name: "<<temp->getName()
                <<", Phone: "<<temp->getPhoneNumber()<<endl;
            temp=temp->getNext();
        }
    }
};
// Main function
int main()
{
    BankList bank;

    // Add people to the list
    bank.addAtStart(101, "Ali", "03001234567");
    bank.addAtEnd(102, "Sara", "03007654321");
    bank.addAtEnd(103, "Ahmed", "03009876543");
    bank.addAfter(102, 104, "Zara", "03001112222"); // Add after Sara
    bank.addAfter(999, 105, "Unknown", "03000000000"); // ID not found

    // Show the list
    bank.displayList();

    return 0;
}