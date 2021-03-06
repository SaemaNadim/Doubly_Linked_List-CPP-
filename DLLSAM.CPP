#include<iostream.h>
#include<conio.h>
struct node
{
	int data;
	node *next,*prev;
};
node *list;
void push(int x)
{

	node *temp,*temp1;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	temp1=list;
	while(temp1->next!=NULL)
	temp1=temp1->next;
	temp1->next=temp;
	temp->prev=temp1;
	temp->next=NULL;
}
void traversal()
{
	node *t;
	t=list;
	cout<<"list is : \n";
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
void insertafter(int x,int key)
{
	node *temp1,*temp;
	temp1=list;
	temp=new node;
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	while(temp1->next!=NULL&&temp1->data!=key)
	temp1=temp1->next;
	if(temp1->data==key&&temp1->next!=NULL)
	{
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp->prev=temp1;
		temp1->next=temp;
	}
	else if(temp1->data==key&&temp1->next==NULL)
	{
		temp1->next=temp;
	    temp->prev=temp1;
	}
	else
	cout<<"key not found";
}
void insertbefore(int x,int key)
{
	node *temp,*temp1;
	temp1=list;
	temp=new node;
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
    if(temp1->data==key)
	{
	    temp->next=list;
	    list->prev=temp;
	    list=temp;
	}
	while(temp1->next!=NULL&&temp1->data!=key)
		temp1=temp1->next;
    if(temp1!=list)
	if(temp1->data==key)
	{
		temp->next=temp1;
		temp1->prev->next=temp;
		temp->prev=temp1->prev;
		temp1->prev=temp;
	}
	else
	cout<<"key not found";
}
void deletedll(int key)
{
	node *temp;
	temp=list;
	if(temp->data==key)
	{
		list=list->next;
		list->prev=NULL;
		delete temp;
	}
	else
	{
		while(temp->next!=NULL&&temp->data!=key)
		temp=temp->next;
	if(temp->data==key)
	{
	    if(temp->next==NULL)
	    {
		temp->prev->next=NULL;
		    delete temp;
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete temp;
		}
	}
	else
	cout<<"key not found";
    }
}
int main()
{
	clrscr();
	int x,ch;
	char c,p;
	list=new node;
	cout<<"Enter data in the first node of the first list\n";
	cin>>x;
	list->data=x;
	list->next=NULL;
	cout<<"Do you want to enter more??\n y or n\n";
	cin>>c;
	while(c=='y'||c=='Y')
	{
		cout<<"Enter values :\n";
		cin>>x;
		push(x);
		cout<<"more???\n";
		cin>>c;
	}
	do
	{
		cout<<"Enter 1 if you want to traverse the list \n";
		cout<<"Enter 2 if you want to insert an element after a particular node \n";
		cout<<"Enter 3 if you want to insert an element before a particular node \n";
		cout<<"Enter 4 if you want to delete a particular node \n";
		cin>>ch;
		if(ch==1)
		{
			traversal();
		}
		else if(ch==2)
		{
			int x,key;
			cout<<"Enter the data you want to insert :\n";
			cin>>x;
			cout<<"Enter the element of the node after which you want to insert the data :\n";
			cin>>key;
			insertafter(x,key);
			traversal();
		}
		else if(ch==3)
		{
			int x,key;
			cout<<"Enter the data you want to insert :\n";
			cin>>x;
			cout<<"Enter the element of the node before which you want to insert the data :\n";
			cin>>key;
			insertbefore(x,key);
			//cout<<list->data;
			traversal();
		}
		else if(ch==4)
		{
			int key;
			cout<<"Enter the element of the node which you want to delete :\n";
			cin>>key;
			deletedll(key);
			traversal();
		}
		else
		cout<<"you have entered a wrong choice !!!!";
		cout<<"Do you want to perform more operations :\n";
		cin>>p;
	}while(p=='y'||p=='Y');
	getch();
	return 0;
}
