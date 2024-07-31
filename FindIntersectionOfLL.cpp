#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node(int data1,Node*next1)
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
Node *brute(Node *head1,Node *head2)
{
    map<Node*,int> mpp;

    Node *temp=head1;
    while(temp!=0)
    {
        mpp[temp]=1;
        temp=temp->next;
    }

    temp=head2;
    while(temp!=0)
    {
        if(mpp.find(temp)!=mpp.end())
            return temp;
        temp=temp->next;
    }
    return NULL;
}


//Find the Collision Point
Node *collisionPt(Node *head1,Node *head2,int diff)
{
    while(diff)
    {
        diff--;
        head2=head2->next;
    }

    while(head1!=head2)
    {
        head1=head1->next;
        head2=head2->next;
    }
    return head1;
}

//Better Solution
Node *better(Node *head1,Node *head2)
{
     int l1=0,l2=0;
    Node *temp=head1;
    while(temp!=0)
    {
        l1++;
        temp=temp->next;
    }

    temp=head2;
    while(temp!=0)
    {
        l2++;
        temp=temp->next;
    }

    if(l1>l2)
        return collisionPt(head2,head1,l1-l2);
    else
        return collisionPt(head1,head2,l2-l1);
}


//Optimal Solution
Node *optimal(Node *head1,Node *head2)
{
    Node *t1=head1,*t2=head2;

    while(t1!=t2)
    {
        t1=t1==0?head2->next:t1->next;
        t2=t2==0?head1->next:t2->next;
    }
    return t1;
}

int main()
{

    //List1
    Node *head1=new Node(3);
    head1->next=new Node(1);
    head1->next->next=new Node(4);
    head1->next->next->next=new Node(6);
    head1->next->next->next->next=new Node(2);
    print(head1);

    //List2
    Node *head2=new Node(4);
    head2->next=new Node(2);
    head2->next->next=new Node(1);
    head2->next->next->next=new Node(5);
    head2->next->next->next->next=head1->next->next;
    head2->next->next->next->next->next= head1->next->next->next;
    head2->next->next->next->next->next->next=head1->next->next->next->next;
    print(head2);

    // Node *ans=brute(head1,head2);
    // Node *ans=better(head1,head2);
     Node *ans=optimal(head1,head2);
    cout<<ans->data;

}