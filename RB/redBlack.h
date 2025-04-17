#ifndef RED__BLACK
#define RED__BLACK

struct tree {
  struct node *root;
};

struct node {
  int key;
  int color;
  struct node *left;
  struct node *right;
  struct node *dad;

};

struct node *create_nodedo (int key, struct node *pai);

struct node *search (struct node *n, int key);

void print_tree (struct node *node);

void rot_left (struct tree *t, struct node *x);

void rot_right (struct tree *t, struct node *x);

struct node *tree_min (struct node *n, struct node *x);

struct node *tree_max (struct node *n, struct node *x);

void transplant (struct tree *t, struct node *u, struct node *v);

void node_delete (struct node *z);

void tree_delete (struct tree *t, struct node *z);

void rb_insert (struct tree *t, struct node *x);

void rb_insert_fixup (struct tree *t, struct node *z);

void rb_remove (struct tree *t, struct node *x);

#endif
