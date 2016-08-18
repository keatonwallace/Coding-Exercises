#include <stdio.h>
#include <stdlib.h>

struct node {
  int x;
  struct node *next;
};

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

void generateList(struct node *head){
  int j;
  for(j=0; j<10; j++){
    pushNode(head, j);
  }
  return;
}

//args an array of head nodes.
//Pass by value if I care about preserving original lists.
struct node *sortList(){
  
  //pick lowest of head nodes
  //insert node into new list
  //advance list that had that node
  //repeat
  return;
}

void displayList(struct node *head){
  head=head->next;
  while(head->next!=NULL){
    printf("%i\n",head->x);
    head=head->next;
  }
  printf("%i\n",head->x);
  return;
}

int main(){
  struct node *i;
  i = malloc(sizeof(struct node));
  i->x=-1;
  i->next=NULL;
  generateList(i);
  displayList(i);
  return 0;
}
