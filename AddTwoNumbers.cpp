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

//Add two numbers of the Linked List
Node *optimal(Node *list1,Node *list2)
{
    Node *dummy=new Node(-1);
    Node *temp=dummy;
    int carry=0;

    while(list1!=0 || list2!=0 ||carry)
    {
        int sum=0;
        
        if(list1)
        {
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2)
        {
            sum+=list2->data;
            list2=list2->next;
        }

        sum+=carry;
        carry=sum/10;
        Node *newnode=new Node(sum%10);
        temp->next=newnode;
        temp=temp->next;
        
    }
    return dummy->next;
}


int main()
{
    Node *list1=new Node(3);
    list1->next=new Node(5);
    // list1->next->next=new Node(3);
    print(list1);

    Node *list2=new Node(4);
    list2->next=new Node(5);
    list2->next->next=new Node(9);
    list2->next->next->next=new Node(9);
    print(list2);

    Node *newHead=optimal(list1,list2);
    print(newHead);
}