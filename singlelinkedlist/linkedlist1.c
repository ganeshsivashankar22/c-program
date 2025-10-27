#include<stdio.h>
#include<stdlib.h>
struct st 
{
	int roll;
	char name[20];
	float marks;
	struct st* next;

};
void add_begin(struct st**);
void print(struct st*);
int main()
{
	char op;
	struct st* hptr=0;
do
{
	add_begin(&hptr);
	printf("do you want to create another node then enter 'y'\n");
	scanf(" %c",&op);
}while(op=='y');
print(hptr);
	
}
void add_begin(struct st** ptr)
{
	struct st* temp;
    temp=(struct st*)malloc(sizeof(struct st));
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
        temp->next=*ptr;
	*ptr=temp;

}
void print(struct st* ptr)
{
	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);

	ptr=ptr->next;	
	}

}


