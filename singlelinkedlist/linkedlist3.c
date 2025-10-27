#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st 
{
	int roll;
	char name[20];
	float marks;
	struct st* next;
};

void add_end(struct st**);
void print(struct st*);
void reversedata(struct st*);

int count(struct st*,int );
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
	reversedata(hptr);
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
void reversedata(struct st*ptr)
{
	int i,j,c;
	int size=sizeof(struct st)-8;
	c=count(ptr,0);
	struct st**a=(struct st**)malloc(c*sizeof(struct st*));
	for(i=0;i<c;i++)
	{
		a[i]=ptr;
		ptr=ptr->next;
	}
	for(i=0,j=c-1;i<j;i++,j--)
	{
		struct st temp;
		memcpy(&temp,a[i],size);
		memcpy(a[i],a[j],size);
		memcpy(a[j],&temp,size);
	}	

}

int count(struct st*p,int c)
{
	
	while(p->next!=0)
	{
		c++;
		p=p->next;
	}
	return c;
}

