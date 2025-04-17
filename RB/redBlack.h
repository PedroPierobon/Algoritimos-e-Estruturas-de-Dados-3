#ifndef RED__BLACK
#define RED__BLACK

struct tree {
  struct no *root;
};

struct no {
  int key;
  int color;
  int height;
  struct no *left;
  struct no *right;
  struct no *dad;

};

struct no *create_nodo (int key, struct no *pai);

struct no *search (struct no *n, int key);

void print_tree (struct no *no);

void rot_left (struct tree *t, struct no *x);

void rot_right (struct tree *t, struct no *x);

struct no *tree_min (struct no *n, struct no *x);

struct no *tree_max (struct no *n, struct no *x);

void transplant (struct tree *t, struct no *u, struct no *v);

void tree_delete (struct tree *t, struct no *z);

void rb_insert (struct no *t, struct no *x);

void rb_remove (struct tree *t, struct no *x);

#endif
