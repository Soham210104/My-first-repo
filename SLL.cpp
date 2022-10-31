#include<iostream>
using namespace std;

class Node
{
    public:
    int key;
    int data;
    Node* next;//Pointer of same class and of same data type which points to the next node and stores the address of the next node

    Node()
    {
        key = 0 ;
        data = 0;
        next = NULL; //initially the node are not stroing any addressses
    }

    Node(int k,int d)
    {
       k = key;
       d = data;
    }
};

class SinglyLinkedList
{
    public:
    Node* head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n) //passing an argument which stores address of a node object as an argument
    {
        head = n; //head will store the address of newly created node!
    }

    // 1st operation check if node value exist using key value

    Node * nodeExists(int k)
{
    Node* temp = NULL;   //creating a temp which stores NULL
    Node* ptr = head;   //initial state ptr is pointing to head and the starting of the head is pointing to NULL thus now ptr is pointing to NULL.
    while(ptr!=NULL)
    {
        if(ptr->key==k)              /*FOR EG..we want to check for key = 2..if key 2 exists thus at start ptr->key means ptr->key which is 1 is == 2 which is not thus comes outside the if part*/ 
        {
            temp = ptr;
        }

        ptr = ptr->next; //as 1 == 2 is false thus then ptr now points to the n2 node means next node which then again while loop starts then ptr -> key in which key is now 2 and thus 2 == 2.
    }
    return temp; //returns NULL if node value does not exist!
}

    //2nd operation appending a node:- ADDITION OF NODE AFTER THE LAST NODE
void appendNode(Node* n)
{
    if(nodeExists(n->key) != NULL)          /*If newly passed node Node *n has the same key value which is already present in the inputted nodes 
                                            then print that the key is already present please input another unique key value*/
    {
        cout<<"Key value already exists as :-"<<n->key<<"Please input another unique key value"<<endl;
    }

    else
    {
        if(head == NULL) //if head is pointing to NULL means there is no node present then make the first node to be the head node
        {
                head =  n;//head pointed to the address of the first node
        }
        else //head is already pointing to a node means further nodes are present now we have to traverse from node 1 to number of node
        {
            Node *ptr = head; //this storing the address of head and head is storing the address of node1 
            while(ptr->next!=NULL) //ptr pointing to next* of node 1 which is mot equal to NULL means next* of node 1 is pointing to the address of node n2.
            {
                ptr = ptr->next; //it will iterate untiil the ptr stores the address of the last node..thus at present ptr storing the data of last node
            }
            ptr->next = n; //now as ptr stores the data of last node it will let the next* to store the address of PASSED NODE 'n'.
            cout<<"Node Appended"<<endl;
        }
    }
}

//3. Prepend Node:- Addition of node at the start

    void prependNode(Node* n)
    {
        if(nodeExists(n->key) != NULL)     //checks if already a key is present or not    
         {
            cout<<"Key value already exists as :-"<<n->key<<"Please input another unique key value"<<endl;
         }

        else
         {
            n->next = head;
            head = n;
            cout<<"Node Prepended"<<endl;
         }
    }

  //4. Insertion of Node after a particular Node.
    
    void insertNode(int k,Node* n)//insertion of node after the key k that has beeen passed here.
    {
        Node* ptr = nodeExists(k); //we have passed k and it will check if the passed key value k is present in the list after which we want to add node...ptr stores the nodexist
        if(ptr==NULL)
        {
            cout<<"Node value doesnt exist please try another key value"<<endl; //ptr is NULL means no key value k exist in the list after which we can add the node
        }
        else
        {
            if(nodeExists(n->key) != NULL)     //checks if new node n has the unique key value in the list!    
            {
                cout<<"Key value already exists as :-"<<n->key<<"Please input another unique key value"<<endl;
            }
            else //og code is present here
            {
                n->next = ptr->next;//assume 3 nodes and we have to 4th node after the node 2nd node thus this line will create a linkage b/w 4th node and 3rd node as ptr is pointing to 2nd node next value which is stroing the address of 3rd node
                ptr->next = n;//2nd node next linkage with 4th node.
                cout<<"Node Inserted"<<endl;
            }
        }
    }

    //5. Deletion of node by a unique key

    void deleteNodebyKey(int k)
    {
        if(head == NULL) //if no nodes are present
        {
            cout<<"List is empty cant delete"<<endl;
        }
        else if(head != NULL)
        {
            if(head->key == k) //if the head value is equal to the first node means deletion of the first node..deletion actually means unlinking the head values
            {
                head = head->next; //for example 3 nodes then first node next storing the address of 2nd node now the head node pointing the next of first node which is storing the address of 2nd node thus head now poitning to 2nnd node
                cout<<"Node UNLINKED with key values: "<<k<<endl;
            }
            else //the key value is not the start of the head but its in b/w..assume three nodes and we have to delete the 2nd node
            {
                Node* temp = NULL; 
                Node* prevptr = head; //storing the address of head and head is n1 thus prevptr = n1.
                Node* currentptr = head->next;//storing the address of head(n1) of next which is n2
                while(currentptr!=NULL)
                {
                     if(currentptr->key == k) //the key value passed is 2 and if it matched
                     {
                        temp = currentptr; //temp is pointing to currentptr and the currentptr is linked to the node 2nd thus noow temp is storing 2nd node address
                        currentptr = NULL;
                     }
                     else
                     {
                        prevptr->next = temp->next;
                        currentptr = currentptr->next;
                     }
                }
                if(temp!=NULL)
                {
                    prevptr->next = temp->next; //now prevptr which is n1 links to the temp next value and the temp next value is n3 node thus n1 links to n3 which breaks the link b/w n1 and n2,n2 and n3
                    cout<<"Node is UNLINKED with key value :"<<k<<endl;
                }
                else
                {
                    cout<<"Node doesnt exist with key value :"<<k<<endl;
                }
            }
        }
    }

    //6. Update node by key:- We are chaanging the data value of the node by accessing the key

    void updateNodebyKey(int k,int d)
    {
        Node *ptr = nodeExists(k);//passed value k is present in the list 
        if(ptr!=NULL)
        {
            ptr->data = d; //changed the data value by d of the ptr
            cout<<"Node data updated successfully"<<endl;
        }
        else
        {
            cout<<"Node doesnt exist"<<endl; 
        }
    }
     //7 Printing the linked list.

    void printList()
    {
        if(head== NULL)
        {
            cout<<"No nodes in Singly Linked List"<<endl;
        }
        else
        {
            cout<<"Singly Linked List Values: "<<endl;
            Node *temp = head;

            while(temp!= NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<") -->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"\nWhat operation you want to choose.Choose option.Enter 0 to EXIT"<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNode()"<<endl;
        cout<<"4. deleteNodebyKey()"<<endl;
        cout<<"5. updateNodebyKey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option;
        Node *n1 = new Node(); 
        //n1 is object or pointer to object in heap memory
        //CONCEPT OF DYNAMIC MEMORY ALLOCATION
        //object of NODE N1 IS CREATED IN THE HEAP MEMORY.
        //We can also do Node n1 and then do n1.key type operations but now this dynamic memory allocation is preferable.

        switch(option)
        {
            case 0:
            break;

            case 1:
            cout<<"Append node operation \nEnter key and data of the Node to be Appended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;

            case 2:
            cout<<"Append node operation \nEnter key and data of the Node to be Appended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;

            case 3:
            cout<<"Insert Node After Operation \nEnter key of existing node after which you want to Insert new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of new Node first"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNode(k1,n1);
            break;

            case 4:
            cout<<"Delete Node by Key Operation - \nEnter key of the node to be deleted"<<endl;
            cin>>k1;
            s.deleteNodebyKey(k1);
            
            case 5:
            cout<<"Update Node by Key Operation - \nEnter key of the node to be deleted"<<endl;
            cin>>k1;
            cout<<"Enter the data to be updated"<<endl;
            cin>>data1;
            s.updateNodebyKey(k1,data1);
            break;

            case 6:
            s.printList();
            break;

            case 7:
            system("cls");
            break;

            default:
            cout<<"Invalid Option"<<endl;

        }

    }
    while(option!=0);

return 0;
}