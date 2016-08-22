#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//If I get around to changing it the value field could have a better name
struct node {
  int x;
  struct node *next;
};

void pushNode(struct node *head, int val);
void generateList(struct node *head);
struct node *sortList(struct node *lists[], int len);
void displayList(struct node *head);
struct node *makeHead();

//I am traversing the whole list every time which is inefficient
void pushNode(struct node *head, int val){
  struct node *traverse = head;
  while (traverse->next!=NULL){
    traverse=traverse->next;
  }
  struct node * newNode;
  newNode=malloc(sizeof(struct node));
  
  newNode->x = val;
  newNode->next=NULL;
  traverse->next=newNode;
}

//Should generate a sorted list of integers
void generateList(struct node *head){
  int j;
  int r;
  r=rand()%10;//adding some randomness to the lists
  for(j=0; j<100; j=j+r){
    pushNode(head, j);
    r=random()%10;
  }
  return;
}

//args an array of head nodes.
//Pass by value if I care about preserving original lists.
struct node *sortList(struct node *lists[], int len){
  struct node *head;
  int i;
  int index=0;

  for(i=0; i<len; i++){
    lists[i]=lists[i]->next;//advance past head nodes
  }
  int min = lists[0]->x;//ignore the head node
  head=makeHead();
  printf("about to sort\n");
  while(lists[0]!=NULL){
    printf("min is %i \n", min);
    for(i=0; i<len; i++){
      printf("lists[%i]->x is %i ", i, lists[i]->x);
      if(lists[i]->x < min){
	index=i;
	min=lists[i]->x;
      }
    }
    printf("pushing node %i\n", min);
    pushNode(head, min);
    lists[index]=lists[index]->next;
    printf("where is the beef\n");
    if(lists[index]!=NULL){
      min=lists[index]->x;
    }
    }
    
  if(lists[0]==NULL){
    while(lists[1]!=NULL){
      pushNode(head, lists[1]->x);
      lists[1]=lists[1]->next;
    }
  }
  else{
    while(lists[0]!=NULL){
      pushNode(head, lists[0]->x);
      lists[0]=lists[0]->next;
    }
  }
  return head;
}

void displayList(struct node *head){
  if(head->next==NULL){
    printf("Empty list\n");
    return;
  }
  head=head->next;
  while(head->next!=NULL){
    printf("%i\n",head->x);
    head=head->next;
  }
  printf("%i\n",head->x);
  return;
}

struct node *makeHead(){
  struct node *i;
  i = malloc(sizeof(struct node));
  i->x=-1;
  i->next=NULL;
  return i;
}

int main(){
  int j;
  int k;
  
  srand(time(NULL));
  printf("How many lists would you like?\n");
  scanf("%i", &j);
  struct node *heads[j];
  for(k=0; k<j; k++){
    heads[k]=makeHead();
    generateList(heads[k]);
  }
  printf("\n");
  displayList(heads[0]);
  displayList(heads[1]);
  displayList(sortList(heads, j));
  return 0;
}


//TODO: Get rid of head nodes
//TODO: Solve for 2 lists
//TODO: Solve for n lists
