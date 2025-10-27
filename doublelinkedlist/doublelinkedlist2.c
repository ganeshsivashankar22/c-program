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
void add_end(struct st**);
void print(struct st*);
void rev_print(struct st* );
int main()
{
	char ch;
	struct st* hptr=0;
	do
	{
		add_end(&hptr);
		printf("enter y if you want another node\n");
	        scanf(" %c",&ch);	
	}while(ch=='y');
	print(hptr);
	printf("reverse printing\n");
	rev_print(hptr);
}
void add_end(struct st** ptr)
{
	struct st *temp=0;
	temp=(struct st*)malloc(sizeof(struct st));
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
	if(*ptr==0)
	{
		temp->next=*ptr;
		temp->prev=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st *last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->next=last->next;
		temp->prev=last;
		last->next=temp;

	}


}
void print(struct st*p)
{
	while(p!=0)
	{
	printf("%d %s %f\n",p->roll,p->name,p->marks);
	p=p->next;
	}

}
void rev_print(struct st* p)
{
	while(p->next!=0)
	{
		p=p->next;
	}
	while(p!=0)
	{
		printf("%d %s %f\n",p->roll,p->name,p->marks);
		p=p->prev;
	}
}

