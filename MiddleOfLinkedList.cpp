#include<bits/stdc++.h>
using namespace std;

//CLass of Node

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

//Brute force solution
void *brute(Node *head)
{
    int cnt=0;
    Node *temp=head;

    while(temp!=0)
    {
        cnt++;
        temp=temp->next;
    }

    int mid=(cnt/2)+1;
    temp=head;

    while(temp!=0)
    {
        mid=mid-1;
        if(mid==0)
            break;
        temp=temp->next;
    }
    cout<<temp->data;
}


//Optimal Solution


int main()
{
    Node *head=new Node(11);
    head->next=new Node(22);
    head->next->next=new Node(33);
    head->next->next->next=new Node(44);
    head->next->next->next->next=new Node(55);
    head->next->next->next->next->next=new Node(66);


    brute(head);
}

