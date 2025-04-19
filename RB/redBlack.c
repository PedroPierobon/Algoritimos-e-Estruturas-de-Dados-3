#include "redBlack.h"
#include <stdio.h>
#include <stdlib.h>

struct node *create_node (int key, struct node *dad, struct tree *t){

   struct node *n = malloc(sizeof(struct node));
   n->key = key;
   n->left = t->nil;
   n->right = t->nil;
   n->dad = dad;
   n->color = 1; // vermelho
   return n;

}

struct node *search (struct node *n, int key, struct tree *t){

   if(n == t->nil){
      printf("%d não encontrado\n", key);
      return t->nil;
   }

   if(n->key > key)
      return search(n->left, key, t);
   else if(n->key < key)
      return search(n->right, key, t);

   return n;
}

struct node *tree_min(struct node *x, struct tree *t){
   while(x->left != t->nil)
      x = x->left;
   return x;
}

struct node *tree_max(struct node *x, struct tree *t){
   while(x->right != t->nil)
      x = x->right;
   return x;
}

void print_tree (struct node *root, int h, struct tree *t){ 
   if(root == t->nil) return;
   print_tree(root->left, h + 1, t);
   printf("%d,%d,%d\n", root->key, h, root->color);
   print_tree(root->right, h + 1, t);
   return;
}

void rot_left(struct tree *t, struct node *x){

   struct node *y = x->right;

   x->right = y->left;

   if(y->left != t->nil)
      y->left->dad = x;

   y->dad = x->dad;

   if(x->dad == t->nil)
      t->root = y;
   else if(x == x->dad->left)
      x->dad->left = y;
   else
      x->dad->right = y;

   y->left = x;
   x->dad = y;

}


void rot_right(struct tree *t, struct node *x){

   struct node *y = x->left;

   x->left = y->right;

   if(y->right != t->nil)
      y->right->dad = x;

   y->dad = x->dad;

   if(x->dad == t->nil)
      t->root = y;
   else if(x == x->dad->right)
      x->dad->right = y;
   else
      x->dad->left = y;

   y->right = x;
   x->dad = y;

}

void rb_insert_fixup(struct tree *t, struct node *z){

   struct node *y;
   while(z->dad != t->nil && z->dad->color == 1){

      if(z->dad == z->dad->dad->left){
         y = z->dad->dad->right;
         if(y != t->nil && y->color == 1){
            z->dad->color = 0;
            y->color = 0;
            z->dad->dad->color = 1;
            z = z->dad->dad;
         }
         else{ 
            if(z == z->dad->right){
               z = z->dad;
               rot_left(t, z);
            }
            z->dad->color = 0;
            z->dad->dad->color = 1;
            rot_right(t, z->dad->dad);
         }
      }
      else{
         if(z->dad == z->dad->dad->right){
            y = z->dad->dad->left;
            if(y != t->nil && y->color == 1){
               z->dad->color = 0;
               y->color = 0;
               z->dad->dad->color = 1;
               z = z->dad->dad;
            }
            else{ 
               if(z == z->dad->left){
                  z = z->dad;
                  rot_right(t, z);
               }
               z->dad->color = 0;
               z->dad->dad->color = 1;
               rot_left(t, z->dad->dad);
            }
         }

      }
   }
}



void rb_insert(struct tree *t, struct node *z){

   struct node *y = t->nil;
   struct node *x = t->root;

   while(x != t->nil){
      y = x;
      if(z->key < x->key){
         x = x->left;
      }
      else{
         x = x->right;
      }
   }

   z->dad = y;

   if(y == t->nil){
      t->root = z;
      z->color = 0;
      return;
   }
   else if(z->key < y->key)
      y->left = z;
   else
      y->right = z;
   z->left = t->nil;
   z->right = t->nil;
   rb_insert_fixup(t, z);
   t->root->color = 0;
}

// Somente aceita nós folhas
void node_delete(struct node *x, struct tree *t){
   if(x->dad != t->nil){
      struct node *y = x->dad;
      if(y->left == x)
         y->left = t->nil;
      else if(y->right == x)
         y->right = t->nil;
   }
   free(x);
}

// Substitui a subárvore com raiz no u pela com raiz no v
void rb_transplant(struct tree *t, struct node *u, struct node *v){
   if(u->dad == t->nil)
      t->root = v;
   else if(u == u->dad->left)
      u->dad->left = v;
   else u->dad->right = v;

   v->dad = u->dad;
}

void rb_remove_fixup(struct tree *t, struct node *x){
   while(x != t->root && x->color == 0){
      if(x == x->dad->left){
         struct node *w = x->dad->right;
         if(w->color == 1){
            w->color = 0;
            x->dad->color = 1;
            rot_left(t, x->dad);
            w = x->dad->right;
         }
         if(w->left->color == 0 && w->right->color == 0){
            w->color = 1;
            x = x->dad;
         }
         else{
            if(w->right->color == 0){
               w->left->color = 0;
               w->color = 1;
               rot_right(t, w);
               w = x->dad->right;
            }
            w->color = x->dad->color;
            x->dad->color = 0;
            w->right->color = 0;
            rot_left(t, x->dad);
            x = t->root;
         }
      }
      else{
         struct node *w = x->dad->left;
         if(w->color == 1){
            w->color = 0;
            x->dad->color = 1;
            rot_right(t, x->dad);
            w = x->dad->left;
         }
         if(w->right->color == 0 && w->left->color == 0){
            w->color = 1;
            x = x->dad;
         }
         else{
            if(w->left->color == 0){
               w->right->color = 0;
               w->color = 1;
               rot_left(t, w);
               w = x->dad->left;
            }
            w->color = x->dad->color;
            x->dad->color = 0;
            w->left->color = 0;
            rot_right(t, x->dad);
            x = t->root;
         }
      }
   }
   x->color = 0;
}

// Remover z
void rb_remove(struct tree *t, struct node *z){
   struct node *y = z;
   struct node *x;
   int ycolor = y->color;

   if (z->left == t->nil) {
      x = z->right;
      rb_transplant(t, z, z->right);//o que acontece com os filhos da direita?
   }
   else if(z->right == t->nil){
      x = z->left;
      rb_transplant(t, z, z->left);
   }
   else{
      y = tree_min(z->right, t);
      ycolor = y->color;
      x = y->right;
      if(y != z->right){
         rb_transplant(t, y, y->right);
         y->right = z->right;
         y->right->dad = y;
      }
      else{
         x->dad = y;
      }
      rb_transplant(t, z, y);
      y->left = z->left;
      y->left->dad = y;
      y->color = z->color;
   }
   if(ycolor == 0)
      rb_remove_fixup(t, x);
   t->root->color = 0;
   free(z);
}

void rb_destroy(struct node *n, struct tree *t){
   if(n == t->nil) return;
   rb_destroy(n->left, t);
   rb_destroy(n->right, t);
   free(n);
   return;

}
