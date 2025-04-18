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

struct node *tree_min (struct node *x);

struct node *tree_max (struct node *x);

void node_delete (struct node *z);

void tree_delete (struct tree *t, struct node *z);

void rb_insert (struct tree *t, struct node *x);

void rb_remove (struct tree *t, struct node *x);

#endif
