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
void reverselink(struct st**);
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
	printf("reverse linking\n");
	reverselink(&hptr);
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
void reverselink(struct st ** p)
{
	struct st* temp;
	while(*p!=0)
	{
	
		temp=(*p)->prev;
		(*p)->prev=(*p)->next;
		(*p)->next=temp;
		*p=(*p)->prev;


	}
	*p=temp->prev;
}
