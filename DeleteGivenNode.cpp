#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }
    
    Node(int data1)
    {
        data=data1;
        next=0;
    }
};

//Print the linked l
void print(Node *head)
{   
    Node *temp=head;
    while(temp!=0)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

//Get the Node
Node *getNode(Node *head,int value)
{
   while(head->data!=value)
   {
    head=head->next;
   }
   return head;
}

//Delete the node
void *del(Node *node)
{
    Node *delnode=node->next;
    node->data=delnode->data;
    node->next=node->next->next;
    free(delnode);
}


int main()
{
   Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    print(head);

    Node *node=getNode(head,5);
    cout<<node->data;
    cout<<endl;
    del(node);
    print(head);
}