#include <stdio.h>
#include <stdlib.h> // needed for malloc
#include <time.h> // Needed for time()
#include "ll.h" // Just to show off headers again

// Prototypes
NUM *add_num(int val, NUM *head);
void print_num(NUM *head);
void free_num(NUM *head);

// This program will insert, in order, random numbers into a singly linked list

int main() {
  srand(time(NULL)); // Seed the random number generator
  NUM *head = NULL; // Linked List head pointer (initialized to NULL)
  int i;

  // Add 10 random numbers to the linked list, to be inserted in order
  for(i = 0; i < 10; i++) {
    head = add_num(rand()%10, head);
    print_num(head); // Print the linked list after each insert.
  }

  free_num(head); // Free the linked list
  head = NULL; // Good measure after freeing, set the pointer to NULL
  return 0;
}

// Print the entire linked list
void print_num(NUM *head) {
  NUM *walker = NULL;
  for(walker = head; walker != NULL; walker = walker->next) {
    printf("%d->", walker->val);
  }
  printf("NULL!\n");
}

// Free the entire linked list
void free_num(NUM *head) {
  NUM *reaper = NULL;
  while(head != NULL) {
    reaper = head; // Never free head, then access head->next!  Always use another ptr.
    head = head->next;
    free(reaper);
  }
}

// Insert a new node into the linked list, in ascending val order
// Returns the new head.  You can also pass NUM **head as the second argument instead
NUM *add_num(int val, NUM *head) {
  NUM *walker = NULL;
  
  // Create the new struct instance for our value
  NUM *new_num = malloc(sizeof(NUM));
  new_num->val = val;
  new_num->next = NULL; // Always initialize pointers to NULL

  // Case 1: Head is null, so let this new one be the head
  if(head == NULL) {
    return new_num;    
  }
  
  // Case 2: The new node should come before the current head
  if(val <= head->val) {
    new_num->next = head;
    return new_num;
  }
 
  // Case 3: This will be inserted somewhere in the middle or at the end
  for(walker = head; walker->next && walker->next->val < val; walker = walker->next);
  // Careful here, this for loop has a ; at the end of it, so it has no body!
  // - We know that walker is not NULL, we checked for that in Case 1
  // - So, we're looking to see if the next node after the current exists...
  // - ... and if it has a lower value than the one we want to insert.

  // We broke out of the loop ... so, are we at the middle or end?
  // - It doesn't matter!  We can do the same final steps in either case.
  new_num->next = walker->next;
  walker->next = new_num;
  return head;
}
