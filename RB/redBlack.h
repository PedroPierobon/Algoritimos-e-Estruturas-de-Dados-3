#ifndef RED__BLACK
#define RED__BLACK

struct tree {
  struct node *root;
  struct node *nil;
};

struct node {
  int key;
  int color;
  struct node *left;
  struct node *right;
  struct node *dad;

};

struct node *create_node (int key, struct node *pai, struct tree *t);

struct node *search (struct node *n, int key, struct tree *t);

//h representa a altura e deve ser iniciado com 0
void print_tree (struct node *node, int h,struct tree *t);

struct node *tree_min (struct node *x, struct tree *t);

struct node *tree_max (struct node *x, struct tree *t);

void node_delete (struct node *z, struct tree *t);

void tree_delete (struct tree *t, struct node *z);

void rb_insert (struct tree *t, struct node *x);

void rb_remove (struct tree *t, struct node *x);

void rb_destroy (struct node *n, struct tree *t);

#endif
