#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//If I get around to changing it the value field could have a better name
struct node {
  int x;
  struct node *next;
};

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
struct node *sortList(int *lists, int len){
  struct node *head;
  int i;
  int index=0;
  int min = lists[0]->x;
  head=makeHead();
  for(i=0; i<len; i++){
    if(lists[i]->x<=min){
      index=i;
      min=lists[i]->x;
    }
  }
  pushNode(head, lists[index]->x);
  lists[index]=lists[index]->next;
  //pick lowest of head nodes
  //insert node into new list
  //advance list that had that node
  //repeat
  
  return head;
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
  }
  return 0;
}
