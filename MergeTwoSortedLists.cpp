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
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Convert ARRAY into Linked List
Node *convert(vector<int> &arr)
{
    Node *head=new Node(-1);
    Node *temp=head;

    for(int i=0;i<arr.size();i++)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
    return head->next;
}

//Brute Force Solution
Node *brute(Node *list1,Node *list2)
{
    Node *temp1=list1;
    vector<int> arr;

    while(temp1!=0)
    {
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }

    Node *temp2=list2;
    while(temp2!=0)
    {
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }

    sort(arr.begin(),arr.end());
    for(auto it:arr)
    {
        cout<<it<<"  ";
    }
   
    Node *head=convert(arr);
    return head;

}


//Optimal Solution
Node *optimal(Node *list1,Node *list2)
{
    Node *dummy=new Node(-1);
    Node *temp=dummy;

    Node *temp1=list1,*temp2=list2;
    while(temp1!=0 && temp2!=0)
    {
        if(temp1->data<=temp2->data)
        {
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else
        {
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }

    if(temp1) temp->next=temp1;
    else    temp->next=temp2;

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

    // Node *newhead=brute(list1,list2);
    Node *newhead=optimal(list1,list2);
    print(newhead);

}