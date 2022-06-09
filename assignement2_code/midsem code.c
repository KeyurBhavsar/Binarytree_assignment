
#include<stdio.h>
#include<stdlib.h>

struct node {
	int a;
	struct node* b;
};

void Dis(struct node* root) {
	struct node* digit = root;
	printf("\nHere is LinkedList output: ");

	while (digit != NULL) 
	{
		printf("%d", digit->a);
		digit = digit->b;
	}
	
}

int main() {

	int a[10] = { 0 };

	struct node* head = NULL;
	for (int i = 0; i < 10; i++)
	{   
		printf("\n Enter 10 numbers: ");
		scanf_s("%d", &a[i]);
	}
	Dis(head);


}