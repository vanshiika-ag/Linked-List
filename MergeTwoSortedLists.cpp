#include<bits/stdc++.h>
using namespace std;

class Node
{
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

//Print the linked List
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

//Convert Array into Linked List
Node *convert(vector<int> arr)
{
    Node *dummy=new Node(-1);
    Node *temp=dummy;

    for(int i=0;i<arr.size();i++)
    {
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return dummy->next;
}


//Brute Force Solution
Node *brute(Node *list1,Node *list2)
{
    vector<int>arr;
    Node *temp1=list1,*temp2=list2;

    while(temp1!=0)
    {
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }

    while(temp2!=0)
    {
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }

    sort(arr.begin(),arr.end());
    Node *head=convert(arr);
    return head;
}


//Optimal Solution
Node *optimal(Node *list1,Node *list2)
{
    Node *t1=list1,*t2=list2;
    Node *dummy=new Node(-1);
    Node *temp=dummy;

    while(t1!=0 && t2!=0)
    {
        if(t1->data<=t2->data)
        {
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else
        {
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }

    if(t1)temp->next=t1;
    else    temp->next=t2;

    return dummy->next;

}

int main()
{
    Node *list1=new Node(2);
    list1->next=new Node(4);
    list1->next->next=new Node(8);
    list1->next->next->next=new Node(10);
    print(list1);

    Node *list2=new Node(1);
    list2->next=new Node(3);
    list2->next->next=new Node(3);
    list2->next->next->next=new Node(6);
    list2->next->next->next->next=new Node(11);
    list2->next->next->next->next->next=new Node(14);
    print(list2);

    // Node *newHead=brute(list1,list2);
    Node *newHead=optimal(list1,list2);
    print(newHead);
}