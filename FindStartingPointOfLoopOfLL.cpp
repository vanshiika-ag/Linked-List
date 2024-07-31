#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:

    int data;
    Node *next;

    Node (int data1,Node *next1)  {
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


//Brute Force Solution
Node *brute(Node *head)
{
    map<Node *,int>mpp;
    Node *temp=head;

    while(temp!=0)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
            
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}


//Optimal Solution
Node *optimal(Node *head)
{
    Node *slow=head,*fast=head;
    while(fast->next!=0 && fast!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
            
        }
    }
    return NULL;
}


int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    // head->next->next->next->next->next->next=head->next->next;
    // print(head);

    // Node *ans=brute(head);
        Node *ans=optimal(head);
    cout<<ans->data;
}
