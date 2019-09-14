#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct {
  int val;
  struct stack_struct *next;
} STACK;

STACK *push_stack(STACK *head, int val) {
  STACK *new = malloc(sizeof(STACK));
  new->val = val;
  new->next = head;
  return new;
}

int peek_stack(STACK *head) {
  if(head != NULL) {
    return head->val;
  }
}

int pop_stack(STACK **head) {
  STACK *killme = *head;
  if(head == NULL) {
    return -1;
  }

  int val = (*head)->val;
  (*head) = (*head)->next;
  free(killme);
  return val;
}

int main() {
  STACK* stack_head = NULL;
  char in_buf[255];
  int val = 0;

  do { 
    fgets(in_buf, sizeof(in_buf), stdin);
    sscanf(in_buf, "%d", &val);

    if(val >= 0) {
      stack_head = push_stack(stack_head, val);
    }
  } while(val >= 0);

  printf("The first value is %d\n", peek_stack(stack_head));

  while(stack_head != NULL) {
    printf("Popping off %d from the stack.\n", pop_stack(&stack_head));
  }

  printf("Stacks are fun.\n");
  return 0;
}
