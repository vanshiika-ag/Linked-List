#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }
    Node (int data1)
    {
        data=data1;
        next=0;
    }
};


//Print the LL
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

//Reverse a Linked List
Node *reverseLL(Node *head)
{
    Node *temp=head;
    Node   *prev=0;
    while(temp!=0)
    {
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

//Get Kth node
Node *getkNode(Node *temp,int k)
{
    k=k-1;
    while(temp!=0 && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}


Node *reverse(Node *head,int k)
{
    Node *temp=head;
    Node *last=0;
    while(temp!=0)
    {
        Node *kth=getkNode(temp,k);
        if(kth==0)
        {
            
            if(last)
            {
                last->next=temp;
            }
            break;
        }

        Node *nextNode=kth->next;
        kth->next=0;
        reverseLL(temp);

        if(temp==head)
            head=kth;
        else    
            last->next=kth;

        last=temp;
        temp=nextNode;
    }
    return head;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next->next->next->next=new Node(10);
    print(head);

    int k=2;
    head=reverse(head,k);
    print(head);
}