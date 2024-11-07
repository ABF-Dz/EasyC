#include <stdio.h>
#include <stdlib.h>

struct Linked {
   int DATA;
   struct Linked *next;
};

struct Linked *First = NULL;
struct Linked *current = NULL;

// display the list
void Show(){
   struct Linked *ptr = First;
   printf("\n[");

   // start from the beginning
   while(ptr != NULL) {
      printf(" %d ", ptr->DATA);
      ptr = ptr->next;
   }
   printf("]");
}

// insertion at the beginning
void AddatFirst(int data){
   struct Linked *lk = (struct Linked*) malloc(sizeof(struct Linked));
   lk->DATA = data;
   lk->next = First;
   First = lk;
}

void AddatEnd(int data){
   struct Linked *lk = (struct Linked*) malloc(sizeof(struct Linked));
   lk->DATA = data;
   lk->next = NULL;

   if (First == NULL) {
      First = lk;
      return;
   }

   struct Linked *linkedlist = First;
   while (linkedlist->next != NULL)
      linkedlist = linkedlist->next;

   linkedlist->next = lk;
}

void Addafter(struct Linked *list, int data){
   struct Linked *lk = (struct Linked*) malloc(sizeof(struct Linked));
   lk->DATA = data;
   lk->next = list->next;
   list->next = lk;
}

void DeleteTheFirst(){
   if (First == NULL) return;

   struct Linked *temp = First;
   First = First->next;
   free(temp);
}

void DeleteTheLast(){
   if (First == NULL) return;

   if (First->next == NULL) {
      free(First);
      First = NULL;
      return;
   }

   struct Linked *linkedlist = First;
   while (linkedlist->next->next != NULL)
      linkedlist = linkedlist->next;

   free(linkedlist->next);
   linkedlist->next = NULL;
}

void DeleteX(int key){
   struct Linked *temp = First, *prev = NULL;

   if (temp != NULL && temp->DATA == key) {
      First = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->DATA != key) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) return;

   prev->next = temp->next;
   free(temp);
}

int SearchFor(int key){
   struct Linked *temp = First;
   while (temp != NULL) {
      if (temp->DATA == key) {
         return 1;
      }
      temp = temp->next;
   }
   return 0;
}

void main(){
   int k = 0;
   AddatFirst(12);
   AddatFirst(22);
   AddatEnd(30);
   AddatEnd(44);
   AddatFirst(50);
   Addafter(First->next->next, 33);

   printf("Linked List = ");
   Show();

   DeleteTheFirst();
   DeleteTheLast();
   DeleteX(12);

   printf("\nLinked List after deletion: ");
   Show();

   AddatFirst(4);
   AddatFirst(16);
   
   printf("\nUpdated Linked List: ");
   Show();

   k = SearchFor(16);
   if (k == 1)
      printf("\nElement is found");
   else
      printf("\nElement is not present in the list");
}
