#include "redBlack.h"
#include <stdio.h>
#include <stdlib.h>


struct no *create_nodo (int key, struct no *dad){

   struct no *n = malloc(sizeof(struct no));
   n->key = key;
   n->left = NULL;
   n->right = NULL;
   n->dad = dad;
   return n;

}

struct no *search (struct no *n, int key){

   if(n == NULL)
      return create_nodo (key, n);

   if(n->key > key)
      return search(n->right, key);
   else if(n->key < key)
      return search(n->left, key);

   return n;
}

/*
void print_tree (struct no *n){ //não sei com implementar

   if(n == NULL)
      return;

      printf("%d, %d, %d", find_min(n), , n->color);

}
*/

void rot_left(struct tree *t, struct no *x){

   struct no *y = x->right;

   x->right = y->left;

   if(y->left != NULL)
      y->left->dad = x;

   y->dad = x->dad;

   if(x->dad == NULL)
      t->root = y;
   else if(x == x->dad->left)
      x->dad->left = y;
   else
      x->dad->right = y;

   y->left = x;
   x->dad = y;

}

void rb_remove(struct tree *t, struct no *x){

}

void rot_right(struct tree *t, struct no *x){

   struct no *y = x->left;

   x->left = y->right;

   if(y->right != NULL)
      y->right->dad = x;

   y->dad = x->dad;

   if(x->dad == NULL)
      t->root = y;
   else if(x == x->dad->right)
      x->dad->right = y;
   else
      x->dad->left = y;

   y->right = x;
   x->dad = y;

}

void rb_insert(struct tree *t, struct no *z){

   struct no *y = NULL;
   struct no *x = t->root;

   while(x != NULL){
      y = x;
      if(z->key < x->key)
         x = x->left;
      else
         x = x->right;
   }

   z->dad = y;

   if(y == NULL)
      t->root = z;
   else if(z->key < x->key)
      y->left = z;
   else
      y->right = z;
   z->left = NULL;
   z->right = NULL;
   z->color = 1;
   rb_insert_fixup(t, z);
}

