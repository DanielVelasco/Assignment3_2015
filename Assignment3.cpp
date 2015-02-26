#include <iostream>
//#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string cityArray[10] = {"Boston","New York","Washington, D.C.","Atlanta","Chicago","St. Louis","Dallas","Denver","Phoenix","Los Angeles"};
string prevCity = "Chicago";
string cityName = "Alaska";
class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        string name;
        string message;
        Node *next;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
        tail = NULL;
    }

    // This prepends a new value at the beginning of the list
    void addValue(string name){
        Node *n = new Node();   // create new Node
        n->name = name;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }


        void traverse_and_print();

        void Transmit();
        Node *DeleteCity();
        Node *removeNodes();
        Node *insertNode();
// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *tail;
};




LinkedList::Node* LinkedList::DeleteCity(){



    Node *pPre = NULL, *pDel = NULL;

    /* Check whether it is the head node?
     if it is, delete and update the head node */
    if (head->name == cityName) {
        /* point to the node to be deleted */
        pDel = head;
        /* update */
        head = pDel->next;
        delete pDel;
        return head;
    }

    pPre = head;
    pDel = head->next;

    /* traverse the list and check the value of each node */
    while (pDel != NULL) {
        if (pDel->name == cityName) {
            /* Update the list */
            pPre->next = pDel->next;
            /* If it is the last node, update the tail */
            if (pDel == tail) {
                tail = pPre;
            }
            delete pDel; /* Here only remove the first node with the given value */
            break; /* break and return */
        }
        pPre = pDel;
        pDel = pDel->next;
    }



    return head;


}


void LinkedList::Transmit(){


 std::ifstream in("messageIn.txt");
 std::string text;




                 while (in >> text)
                    {

                         Node *p = head;

    /* The list is empty? */
                if (head == NULL) {
                    cout << "The list is empty" << endl;
                    return;
                }


            /* A basic way of traversing a linked list */
            while (p != NULL) { /* while there are some more nodes left */
        /* output the value */




                    if(p->next != NULL) {


                    /* The pointer moves along to the next one */
                        p->message = text;
                        p->next->message =  p->message;
                        p->message = "";
                        cout << p->name << " received " << p->next->message << endl;

                        p = p->next;

                    }else{
                     p->message = text;
                     cout << p->name << " received " << text << endl;
                    break;
                    }

                }

                    }




}

LinkedList::Node* LinkedList::removeNodes()
{
  Node *pDel = NULL;

  pDel = head;

while (pDel != NULL) {
        //city name delete list
        cout << pDel->name << endl;

        /* update */
        head = pDel->next;
        delete pDel;
        pDel = pDel->next;

        if(pDel == NULL){


        return head;



        }


    }

}

LinkedList::Node* LinkedList::insertNode()
{


  Node *pDel = NULL;
 Node *tempP = NULL;
  pDel = head;
int counter = 0;
while (pDel != NULL) {


    if(pDel->name == prevCity){
        tempP = pDel->next;
        Node *n = new Node();   // create new Node
        n->name = cityName;             // set value
       pDel->next = n;
        n->next = tempP;



    } if(pDel == NULL) {

        cout << "NULL" << endl;

    }



        pDel = pDel->next;



        }
        return head;


    }



void LinkedList::traverse_and_print()
{
    Node *p = head;

    /* The list is empty? */
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    cout << "===CURRENT PATH===" << endl;
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value */
        cout << p->name << " -> ";
        /* The pointer moves along to the next one */
        p = p->next;

        if(p == NULL) {

        cout << " NULL" << endl;

    }

    }

    cout << "=================" << endl;

}


LinkedList MainList;

void BuildNetwork(){


    for (int i=0;i<10;i++){

         MainList.addValue(cityArray[i]);

    }
        MainList.traverse_and_print();

  }


int main()
{


    int choice = 0;
    do
    {
        cout
             << "======Main Menu=====" << endl


             << "1. Build Network" << endl
             << "2. Print Network Path" << endl
             << "3. Transmit Message Coast-To-Coast" << endl
             << "4. Add City" << endl
             << "5. Delete City" << endl
             << "6. Clear Network" << endl
             << "7. Quit" << endl;
        cin >> choice;
       if(choice == 1){

           // cout << "Build Network" << endl;
            BuildNetwork();

        }if(choice == 2){

           //  cout << "Print Network Path" << endl;
            MainList.traverse_and_print();

        }if(choice == 3){

           // cout << "Transmit Message Coast-To-Coast" << endl;
            MainList.Transmit();
        }if(choice == 4){
        cin.ignore();

         cout << "Enter a city name: " << endl;
        getline(cin, cityName);

        cout << "Enter a previous city name: " << endl;
        getline(cin, prevCity);



         MainList.insertNode();
            // cout << "Add City" << endl;
        }if(choice == 5){


           //  string input = "";
            // cout << "Please enter 1 char: ";
           // getline(cin, input);

           cin.ignore();
           cout << "Enter a city name: " << endl;

            getline(cin, cityName);

           MainList.DeleteCity();



        }if(choice == 6){

           //cout << "Clear Network" << endl;
            MainList.removeNodes();
        }if(choice == 7){

           cout << "Goodbye!" << endl;
            break;
        }


}while(choice != 7);



    return 0;
}
