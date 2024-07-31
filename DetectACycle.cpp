#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }

    Node(int data)
    {
        data=data;
        next=0;
    }
};


//Print the linked List
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
bool brute(Node *head)
{
    map<Node *,int>mpp;

    Node *temp=head;
    while(temp!=0)
    {
        if(mpp.find(temp)!=mpp.end())
            return true;
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}



//Optimal Solution
bool optimal(Node *head)
{
    Node *slow=head,*fast=head;
    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=head->next->next;
    // print(head);


     // cout<<brute(head);
    cout<<optimal(head);
}