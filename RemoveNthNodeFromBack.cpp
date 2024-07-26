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


//Print the Linked List
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


//Brute Force Solution
Node *brute(Node *head,int n)
{
    int count=0;
    Node *temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
   
    if(count==n)
    {
        Node *newHead=head->next;
        free(head);
        return newHead;
    }

    temp=head;
    int res=count-n;

    // int i=1;
    // while(i<res)
    // {
    //     temp=temp->next;
    //     i++;
    // }

    while(temp!=0)
    {
        res=res-1;
        if(res==0)
            break;
        temp=temp->next;
    }
    Node *delnode=temp->next;
    temp->next=temp->next->next;
    free(delnode);
    return head;
}

//Optimaal Solution
Node *optimal(Node *head,int n)
{
    if(head==0 || head->next==0)
    {
        head=0;
        return head;
    }

    Node *slow=head,*fast=head;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }

    //if Nth node from end is head
   if(fast->next==0)
    {
        Node *newHead=head->next;
        free(head);
        return newHead;
    }

    while(fast->next!=0)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node *delnode=slow->next;
    slow->next=slow->next->next;
    free(delnode);
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
    print(head);

    int n=3;
    // head=brute(head,n);
    head=optimal(head,n);
    print(head);
}