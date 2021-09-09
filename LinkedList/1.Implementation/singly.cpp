#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

//Helper method to create a new node
node *createNode(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

//Function to add node at the beginning of LinkedList
node * addAtBeginning(node *head,int x)
{
    node *newNode = createNode(x);
    if (!head)
    {
        head=newNode;       
    }
    else
    {
        newNode->next = head;
        head = newNode;        
    }
    return head;
}

//Function to add node at the end of LinkedList
node *addAtEnd(node *head,int x)
{
    node *newNode = createNode(x);
    node *temp = head;
    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

//Function to remove node at the end of LinkedList
node *removeFromEnd(node *head)
{
    if(!head)
        return head;
    if(head->next==NULL)
    {
        head = NULL;
        return head;
    }
    node *temp = head;
    while(temp->next->next!=NULL)
        temp = temp->next;
    node *delNode = temp->next;
    temp->next = NULL;
    delete (delNode);
    return head;
}

//Function to remove node at the beginning of LinkedList
node *removeFromBeginning(node *head)
{
    if(!head || !head->next)
    {
        head = NULL;
        return head;
    }
    else
    {
        node *delNode = head;
        head = head->next;
        delete (delNode);
        return head;
    }
}

//function to count Nodes

int lengthOfList(node *head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int countNodesRecursively(node *head)
{
    if(head == nullptr)
        return 0;
    int num = countNodesRecursively(head->next);
    return num + 1;
}

//Function to print LinkedList
void printLinkedList(node *head)
{
    node *temp = head;
    while(temp->next != NULL)
    {
        cout<<"hello"<< endl;
        cout << temp->data << endl;
        temp = temp->next;
    }
    return;
}

int main()
{
    // node *head = new node(); Uncomment this and comment the below line, u will get 1 extra node always.

    node *head = NULL;
    head = addAtBeginning(head, 1);
    head=addAtBeginning(head, 2);
    head=addAtBeginning(head, 3);
    head=addAtBeginning(head, 4);
    head=addAtBeginning(head, 5);
    head=addAtBeginning(head, 6);
    printLinkedList(head);
    head = removeFromBeginning(head);
    printLinkedList(head);
    cout<< "Length of List" << lengthOfList(head) << endl;
    cout << "Length of List" << countNodesRecursively(head)<<endl;

}