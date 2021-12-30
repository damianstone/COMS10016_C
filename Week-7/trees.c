/* Demo for naturally sorted (unbalanced) binary trees */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// --------------------------------------------------------
// DATA STRUCTURES
// --------------------------------------------------------

// node in a binary tree
typedef struct node {
  struct node *left; // left side next node / always smaller key than before
  int key;
  struct node *right; // right side next node / always bigger key than before
} node;

// naturally sorted binary tree
typedef struct tree {
  node *root;
} tree;

// --------------------------------------------------------
// NODE IMPLEMENTATIONS
// --------------------------------------------------------

// create a new node with key value and no left or right node
node *newNode(int value) {
  node *p = malloc(sizeof(node));
  *p = (node) {NULL, value, NULL};
  return p;
}

// given the address of the pointer to a node insert an item n into a subtree
// insert key n into subtree returning new top node of the subtree
// its returns an updated node which the caller function has to replace the original node with
// better alternative to insert node with the address of the pointer to the current node. 
// so the function can update the pointer itself
// true if the key was inserted
bool insertNode(node **p, int n) {
  if (*p == NULL) {
    *p = newNode(n);
    return true;
  }
  else if (n < (*p)->key) return insertNode(&((*p)->left), n);
  else if (n > (*p)->key) return insertNode(&((*p)->right), n);
  else return false;
}

// return the node that contains n or NULL otherwise
node *findNode(node *p, int n) {
  if (p != NULL) { // only check deeper if there is no dead end
    if (n < p->key) p = findNode(p->left, n);
    else if (n > p->key) p = findNode(p->right, n);
    //in case n == p->key then p is returned and not updated
  }
  return p;
}

// returns the number of nodes in the subtree with top node p
int countNodes(node *p) {
  int n = 0;
  if (p != NULL) { // only check deeper if there is no dead end
    n += 1 + countNodes(p->left) + countNodes(p->right);
  }
  return n;
}

// append printed key value of a node to a string using spaces between values
void printNode(node *p, char *s) {
  char space[2] = " ";
  if (strcmp(s, "") == 0) space[0] = '\0';
  if (p != NULL) sprintf(s,"%s%s%d", s, space, p->key);
}

// print subtree given the top node
void printNodes(node *p, char *s) {
  if (p != NULL) {
    if (p->left == NULL) printNode(p, s);
    else {
      printNodes(p->left, s);
      printNode(p, s);
    }
    if (p->right != NULL) printNodes(p->right, s);
  }
}

// free subtree given the top node
void freeNodes(node *p) {
  if (p != NULL) {
    freeNodes(p->left);
    freeNodes(p->right);
    free(p);
  }
}

// --------------------------------------------------------
// TREE IMPLEMENTATIONS
// --------------------------------------------------------

// create a new empty trees
tree *newTree() {
  tree *t = malloc(sizeof(tree));
  t->root = NULL;
  return t;
}

// insert item into tree
bool insert(tree *t, int n) {
  return insertNode(&(t->root), n);
}

// report if key n is contained in tree
bool contains(tree *t, int n) {
  return (findNode(t->root, n) != NULL);
}

// print a tree
void print(tree *t, char *s, bool printToScreen) {
  printNodes(t->root, s);
  if (printToScreen) printf("%s\n", s);
}

// returns number of nodes in the tree
int count(tree *t) {
  return countNodes(t->root);
}

// free all memory associated to tree
void freeTree(tree *t) {
  freeNodes(t->root);
  free(t);
}

// --------------------------------------------------------
// TEST IMPLEMENTATIONS
// --------------------------------------------------------

// check that tree values check out with target string
bool check(tree *t, char *target) {
  char s[count(t) * 12 + 1]; // allocate string large enough to print all values of tree
  s[0] = '\0';
  print(t, s, false);
  return (strcmp(s, target) == 0);
}

// test the tree functionality and consistency
void test() {
  tree *t = newTree();
  assert(check(t, ""));
  assert(count(t) == 0);
  assert(insert(t, 5));
  assert(check(t, "5"));
  assert(count(t) == 1);
  assert(insert(t, 3));
  assert(check(t, "3 5"));
  assert(contains(t, 7) == false);
  assert(insert(t, 7));
  assert(check(t, "3 5 7"));
  assert(insert(t, 3) == false); // already in the tree
  assert(check(t, "3 5 7"));
  assert(contains(t, 7));
  assert(count(t) == 3);
  freeTree(t);
}

int main() {
  test();
  return 0;
}