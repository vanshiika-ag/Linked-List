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

//Print
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
bool brute(Node *head)
{
    stack<int> st;
    Node *temp=head;

    while(temp!=0)
    {
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=0)
    {
        if(temp->data!=st.top())
           {
            // cout<<temp->data<<" ";
             return false;
           }
        st.pop();
        temp=temp->next;
    }
    return true;
}   

//Reverse a LL
Node *reverse(Node *head)
{
    if(head==0 || head->next==0)
    {
        return head;
    }

    Node *newHead=reverse(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=0;
    return newHead;
}

//Optimal Solution
bool optimal(Node *head)
{
    if(head==0 || head->next==0)
    {
        return true;
    }

    Node *slow=head;
    Node *fast=head;
    while(fast->next!=0 && fast->next->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Node *newHead=reverse(slow->next);
    Node *first=head;
    Node *second=newHead;

    while(second!=0)
    {
        if(first->data!=second->data)
        {
            reverse(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }

    reverse(newHead);
    return true;


}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(2); 
    head->next->next->next->next=new Node(1);
    print(head);
    
    // cout<<brute(head);
    cout<<optimal(head);
}