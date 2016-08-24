#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
  int x;
  struct node *next;
};

struct node *pushNode(struct node *head, int val);
struct node *generateList();
struct node *sortList(struct node *lists[], int len);
void displayList(struct node *head);
struct node *makeHead();

//ARGS: List and Value
//RETURNS: Node added to list
//ACTION: Adds a node to the end of a list
struct node *pushNode(struct node *head, int val){
  struct node *traverse = head;
  while (traverse->next!=NULL){
    traverse=traverse->next;
  }
  struct node * newNode;
  newNode=malloc(sizeof(struct node));
  
  newNode->x = val;
  newNode->next=NULL;
  traverse->next=newNode;
  return newNode;
}

//ARGS: None
//RETURNS: Pointer to head node of list
//ACTION: Creates a semi-random sorted list
struct node *generateList(){
  int j;
  int r;
  struct node *head;
  struct node *last;
  head=makeHead();
  last=head;
  for(j=0; j<100; j=j+r){
    last=pushNode(last, j);
    r=random()%10;
  }
  return head;
}

//ARGS: Array of head nodes.
//RETURNS: Head node of sorted list
//ACTION: Sorts sorted lists into a single list
struct node *sortList(struct node *lists[], int len){
  struct node *head;
  struct node *last;
  int i;
  int index=0;
  int min=lists[0]->x;
  head=makeHead();
  last=head;
  while(lists[0]!=NULL&&lists[1]!=NULL){
    for(i=0; i<len; i++){
      if(lists[i]->x < min){
	index=i;
	min=lists[i]->x;
      }
    }
    last=pushNode(last, min);
    lists[index]=lists[index]->next;
    if(lists[index]!=NULL){
      min=lists[index]->x;
    }
  }
  if(lists[0]==NULL){
    last->next=lists[1];
  }
  if(lists[1]==NULL){
    last->next=lists[0];
  }
  return head;
}

//ARGS: Head node of list
//RETURNS: None
//ACTION: Prints the contents of each node
void displayList(struct node *head){
  if(head==NULL){
    printf("Empty list\n");
    return;
  }
  while(head->next!=NULL){
    printf("%i\n",head->x);
    head=head->next;
  }
  printf("%i\n",head->x);
  return;
}

//ARGS: None
//RETURNS: Pointer to head node
//ACTION: Creates a new list
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
    heads[k]=generateList();
  }
  printf("\n");
  displayList(sortList(heads, j));
  return 0;
}

//TODO: Solve for n lists
