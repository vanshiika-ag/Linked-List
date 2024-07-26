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



//Print the linked list
void print(Node *head)
{
    Node *temp=head;

    while(temp!=0)
    {
        cout<< temp->data<<"  ";
        temp=temp->next;
    }
}


//Brute Force Solution
Node *brute(Node *head)
{
    if(head==0 ||head->next==0)
        return head;
    else
    {
        Node *temp=head;
    stack<int> st;

//Put values into stack
    while(temp!=0)
    {
        st.push(temp->data);
        temp=temp->next;
    }

    //Insert from stack

    temp=head;
    while(temp!=0)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
    }
}

//Optimal Solution 1
Node *optimal1(Node *head)
{
    if(head==0 || head->next==0)
    {
        cout<<"hii";
        return head;}
    else
    {
        Node *temp=head;
    Node *prev=0;

    while(temp!=0)
    {
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

    return prev;
    }
}


//Optimal Solution 2
Node *optimal2(Node *head)
{
    if(head==0 ||head->next==0)
        return head;
    else{
        Node *newHead=optimal2(head->next);
        Node *front=head->next;
        front->next=head;
        head->next=0;
        return newHead;
    }
}


int main()
{
    //Linked List(2,3,4,8)
    Node *head=new Node(2);
    head->next=new Node(3);
    head->next->next=new Node(4);
    head->next->next->next=new Node(8);

    // print(head);
    // head=brute(head);
    // head=optimal1(head);
    head=optimal2(head);
    print(head);



}