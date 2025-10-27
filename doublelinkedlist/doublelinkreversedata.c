
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void reversedata(struct st*);
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
	printf("after reversing data\n");
	reversedata(hptr);
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
void reversedata(struct st*p)
{
struct st temp;
int i,size;
size=sizeof(struct st)-16;
struct st*p1=p;
struct st*p2=p;
while(p2->next!=0)
{
	p2=p2->next;
}
for(i=0;i<2;i++)
{
memcpy(&temp.roll,&p1->roll,size);
memcpy(&p1->roll,&p2->roll,size);
memcpy(&p2->roll,&temp.roll,size);
p1=p1->next;
p2=p2->prev;
}


}
