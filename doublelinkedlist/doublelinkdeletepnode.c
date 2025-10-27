#include<stdio.h>
#include<stdlib.h>
struct st
{
	struct st* prev;
	int roll;
	char name[20];
	float marks;
	struct st* next;
};
void add_begin(struct st**);
void print(struct st*);
void rev_print(struct st* );
void deletepnode(struct st**,int );
int main()
{
	char ch;
	struct st* hptr=0;
	do
	{
		add_begin(&hptr);
		printf("enter y if you want another node\n");
	        scanf(" %c",&ch);	
	}while(ch=='y');
	print(hptr);
	print(hptr);
	deletepnode(&hptr,5);
	printf("after deleting node\n");
	print(hptr);
	
}
void add_begin(struct st** ptr)
{
	struct st *temp=0;
	temp=(struct st*)malloc(sizeof(struct st));
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
	temp->next=*ptr;
	temp->prev=0;
	if(*ptr!=0)
		(*ptr)->prev=temp;
	*ptr=temp;


}
void print(struct st*p)
{
	while(p!=0)
	{
	printf("%d %s %f\n",p->roll,p->name,p->marks);
	p=p->next;
	}

}
void deletepnode(struct st**p,int n)
{
struct st*temp=*p;
struct st* prev;
while(temp!=0)
{
	if(temp->roll==n)
	{
		if(*p==temp)
			*p=temp->next;
		else
		{
			prev->next=temp->next;
			temp->next->prev=temp->prev;

		}
		free(temp);
		return ;
	}
	else
	{
	prev=temp;
	temp=temp->next;
	}
}
}
