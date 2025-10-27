#include<stdio.h>
#include<stdlib.h>
struct st 
{
	int roll;
	char name[20];
	float marks;
	struct st* next;
};

void add_end(struct st**);
void print(struct st*);
int main()
{
	char op;
	struct st* hptr=0;
	do
	{
		add_end(&hptr);
		printf("if you want to enter another node enter 'y'");
		scanf(" %c",&op);
	}while(op=='y');
	print(hptr);
	}


void add_end(struct st**ptr)
{	
	
	struct st* temp=0;
	
	temp=(struct st*)malloc(sizeof(struct st));
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st* last;
		last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->next=last->next;
		last->next=temp;


	}

	
		

}
void print( struct st* ptr)
{
while(ptr!=0)
{
	printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	ptr=ptr->next;
}
}


