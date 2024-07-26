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
        next=nullptr;
    }

};

//Print the Linked List
void print(Node *head)
{
    Node *temp=head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Brute Force Solution
Node *brute(Node *head)
{
    int count=0;
    Node *temp=head;

    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }

    int mid=(count/2)+1;
    temp=head;
    while(temp!=0)
    {
        mid=mid-1;
        if(mid==0)
            break;
        temp=temp->next;
    }
    return temp;
}


//Optimal Solution
Node *optimal(Node *head)
{
    Node *slow=head;
    Node *fast=head;

    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    
    
    // Node *ans=brute(head);
    Node *ans =optimal(head);
    cout<<ans->data;


}