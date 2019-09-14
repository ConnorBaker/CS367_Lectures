#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
  int val;
  struct node_struct *next;
} NODE;

NODE *enqueue(NODE *head, int val) {
  NODE *new = malloc(sizeof(NODE));
  new->val = val;
  new->next = NULL;

  if(head == NULL) {
    return new;
  }
 
}


int main() {
  NODE *head = NULL;
  char in_buf[255];
  int val;

  do {
    fgets(in_buf, sizeof(in_buf), stdin);
    sscanf(in_buf, "%d", &val);

    if(val >= 0) {
      head = enqueue(head, val);
    }
  } while(val >= 0); 

  printf("The front of the queue is %d\n", peek(head));

  while(queue != NULL) {
    printf("%d\n", dequeue(&head));
  }

  printf("Queues are fun!\n");

  return 0;
} 
