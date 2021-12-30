// SORTING puts elements ina list intom a specific oder, such as a numerical or lexicographical order.

/* Demo for sorting algorithms applied to arrays */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int ITEM_NO = 6; // no of items for testing
const int SEED = 5; // seed for pseudo-random number generator

typedef int item; // the item type to sort

// HELPER FUNCTIONS
// ----------------

// swap items in locations i and j in array xs
void swap(int i, int j, item xs[]) {
  item temp = xs[i];
  xs[i] = xs[j];
  xs[j] = temp;
}

// between and including indices lo and (hi-1)
// partion array xs and return split index of resulting array
int partition(int lo, int hi, item xs[hi]) {
  swap(lo + (hi - lo)/2, lo, xs);
  item p = xs[lo]; // pivot element
  while (true) {
    while (xs[lo] < p) lo++;
    while (xs[hi - 1] > p) hi--;
    if (hi - lo <= 1) return hi;
    swap(lo, hi - 1, xs);
    lo++;
    hi--;
  }
}

// merge two sorted segments in array xs into one new sorted
// array segment in array other
void merge(int lo, int mid, int hi, item xs[hi], item other[hi]) {
  int i = lo, j = mid;
  for (int k = lo; k < hi; k++) {
    if (i < mid && (j >= hi || xs[i] <= xs[j])) {
      other[k] = xs[i++];
    } else {
      other[k] = xs[j++];
    }
  }
}

// SELECTION SORT
// --------------

// RECURSION WAY
// select one item and sort the rest 
void sort(int n, item xs[n]){
    if (n <= 1) return;
    for (int i = 0; i < n-1; i++) {
        if (xs[i] > xs[n-1]) sawp(i, n-1, xs);
    }
    sort(n-1, xs);
}


// INSERTION SORT
// --------------

// sort the n items in xs
void insertionSort(int n, item xs[n]) {
  for (int m = 1; m < n; m++) {
    item x = xs[m];
    int i = m;
    while (i > 0 && xs[i-1] > x) {
      xs[i] = xs[i-1];
      i--;
    }
    xs[i] = x;
  }
}

// SELECTION SORT
// --------------

// sort the n items in xs
void selectionSort(int n, item xs[n]) {
  for (int m = n-1; m > 0; m--) {
    for (int i = 0; i < m; i++) {
      if (xs[i] > xs[m]) swap(i, m, xs);
    }
  }
}

// QUICK SORT
// ----------

// sort items in xs between and including index lo and (hi-1)
void quickSort(int lo, int hi, item xs[hi]) {
  if (hi - lo <= 1) return;
  int split = partition(lo, hi, xs);
  quickSort(lo, split, xs);
  quickSort(split, hi, xs);
}

// MERGE SORT
// ----------

// sort items in xs between and including index lo and (hi-1) into other
void mergeSort(int lo, int hi, item xs[hi], item other[hi]) {
  if (hi - lo <= 1) return;
  int mid = lo + (hi - lo)/2;
  mergeSort(lo, mid, other, xs);
  mergeSort(mid, hi, other, xs);
  merge(lo, mid, hi, xs, other);
}

// ALL TESTING (FOR INT ITEMS)
// ---------------------------

// check if two arrays have same content
bool check(int n, item source[n], item target[n]) {
  for (int i = 0; i < n; i++) {
    if (source[i] != target[i]) return false;
  }
  return true;
}

// print an array of ints
void print(int n, item a[n]) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n-1) printf(", ");
  }
  printf("\n");
}

// fill array a with pseudo-random content
void create(int n, item a[n]) {
  srand(SEED);
  for (int i = 0; i < n; i++) {
    a[i] = rand();
  }
}

// copy content of array source into array target
void init(int n, item source[n], item target[n]) {
  for (int i = 0; i < n; i++) {
    target[i] = source[i];
  }
}

// test all sorting functions
void test() {
  printf("\nBASIC SORTING ALGORITHM TESTS\n");
  printf("-----------------------------\n");
  item a[5][5];
  init(5, (int[]) {5, 7, 3, 1, 4}, a[0]);
  for(int i = 1; i < 5; i++) {
    init(5, a[0], a[i]);
  }
  printf("Original Array:      ");
  print(5, a[0]);
  selectionSort(5, a[1]);
  insertionSort(5, a[2]);
  quickSort(0, 5, a[3]);
  mergeSort(0, 5, a[0], a[4]);
  printf("After SelectionSort: ");
  print(5, a[1]);
  printf("After InsertionSort: ");
  print(5, a[2]);
  printf("After QickSort:      ");
  print(5, a[3]);
  printf("After MergeSort:     ");
  print(5, a[4]);
  // check against correctly sorted array
  for(int i = 1; i < 5; i++) {
    assert(check(5, a[i], (int[]) {1, 3, 4, 5, 7}));
  }
  
  printf("\nEXTENDED SORTING ALGORITHM TESTS\n");
  printf("--------------------------------\n");
  item b[5][ITEM_NO];
  create(ITEM_NO, b[0]);
  for(int i = 1; i < 5; i++) {
    init(ITEM_NO, b[0], b[i]);
  }
  printf("Original Array:      ");
  print(ITEM_NO, b[0]);
  selectionSort(ITEM_NO, b[1]);
  insertionSort(ITEM_NO, b[2]);
  quickSort(0, ITEM_NO, b[3]);
  mergeSort(0, ITEM_NO, b[0], b[4]);
  printf("After SelectionSort: ");
  print(ITEM_NO, b[1]);
  printf("After InsertionSort: ");
  print(ITEM_NO, b[2]);
  printf("After QickSort:      ");
  print(ITEM_NO, b[3]);
  printf("After MergeSort:     ");
  print(ITEM_NO, b[4]);
  //cross-check all algorithms
  for(int i = 1; i < 5; i++) {
    for(int j = 1; j < 5; j++) {
      assert(check(ITEM_NO, b[i], b[j]));
    }
  }
}

int main() {
  test();
  return 0;
}