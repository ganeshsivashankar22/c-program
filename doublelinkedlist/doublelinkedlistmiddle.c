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
void print(struct st*);
void add_middle(struct st**);
int main()
{
	char ch;
	struct st* hptr=0;
	do
	{
		add_middle(&hptr);
		printf("enter y if you want another node\n");
	        scanf(" %c",&ch);	
	}while(ch=='y');
	print(hptr);
	
}

void add_middle(struct st** ptr)
{
	struct st*temp=0;
	temp=(struct st*)malloc(sizeof(struct st));
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
	if((*ptr==0)||(temp->roll<(*ptr)->roll))
	{
	temp->next=*ptr;
	temp->prev;
	if(*ptr!=0)
		(*ptr)->prev=temp;
	*ptr=temp;
	}
	else
	{
		struct st* last=*ptr;
		while((last->next!=0)&&(temp->roll>last->next->roll))
			last=last->next;
		temp->next=last->next;
		temp->prev=last;
		if(last->next!=0)
		last->next->prev=temp;
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
