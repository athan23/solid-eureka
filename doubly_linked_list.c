#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
   struct node *prev;
   int data;
   struct node *next;
} node;

void add_data(node **head, int d) {
   node *temp;

   if (*head == NULL) {
      *head = malloc(sizeof(node));
      (*head)->prev = NULL;
      (*head)->data = d;
      (*head)->next = NULL;
   }
   else {
      temp = *head;
      while (temp->next != NULL) {
         temp = temp->next;
      }

      node *n = malloc(sizeof(node));
      n->data = d;
      n->prev = temp;
      n->next = NULL;

      temp->next = n;
   }
}

void remove_data(node **head, int d) {
   node *temp;

   if (*head == NULL) {
      return;
   }
   else if ((*head)->next == NULL) {
      if ((*head)->data == d) {
         free(*head);
         *head = NULL;
      }
      else {
         printf("%d is not in the linked list\n", d);
      }
   }
   else {
      temp = *head;

      while (temp != NULL) {

         if (temp->data == d) {

            if (temp == *head) {
               *head = temp->next;
               (*head)->prev = NULL;
            }
            else if (temp->next == NULL) {
               temp->prev->next = NULL;
            }
            else {
               temp->prev->next = temp->next;
               temp->next->prev = temp->prev;
            }

            free(temp);
            temp = NULL;
         }
         else {
            temp = temp->next;
         }
      }
   }
}

void print_doubly_linked_list(node *head) {
   node *temp = head;

   if (head == NULL) {
      printf("List is empty");
   }

   while (temp != NULL) {
      printf("- %d -", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

void delete_all(node **head) {
   node *temp = *head;

   while (temp != NULL) {
      *head = temp->next;
      free(temp);
      temp = *head;
   }
}

int main(int argc, char *argv[]) {
   node **head = calloc(1, sizeof(node *));

   add_data(head, 3);
   add_data(head, 5);
   add_data(head, 7);
   add_data(head, 9);
   add_data(head, 11);

   print_doubly_linked_list(*head);

   delete_all(head);

   print_doubly_linked_list(*head);

   delete_all(head);
   free(head);

   return 0;
}
