/* This is a library module supporting lists. A list stores any number of items
and has a current item, which can be any item from the first item to the
last item or a unique 'none' position indicating
that no item is selected. Every operation is constant time.
The lists provided by this module are not thread safe. */

#include <stdbool.h>

// The type of items stored in the list. Change this for different applications.
typedef int item;

// The list type is opaque (declared here, and defined in lists.c).
struct list;
typedef struct list list;

// FUNCTION #1: Create a new empty list and make e the default item that is
// returned by functions in case no item is selected. No item is selected in an empty list.
list *newList(item e);

// FUNCTION #2: Free up the list and all the data in it. Does not have to run in O(1).
void freeList(list *xs);

// FUNCTIONS #3/#4: Set the current item to the first item or to the last
// item of the list. If the list has no items the functions do nothing
// and no item is selected.
void first(list *xs);
void last(list *xs);

// FUNCTION #5: Returns true if no item is selected, i.e. the 'none' position. 
// Otherwise it returns false.
bool none(list *xs);

// FUNCTION #6: Move the current item one place forwards in the list and return true.
// If after is called while the last item is the current item, then no item is
// selected and true is returned. If the function is called while no item
// is selected then the function does nothing and returns false.
bool after(list *xs);

// FUNCTION #7: Move the current item one place backwards in the list and return true.
// If before is called while the first item is the current item, then no item is
// selected and true is returned. If the function is called while no item
// is selected then the function does nothing and returns false.
bool before(list *xs);

// FUNCTION #8: Get the current item. If get is called and no item is selected
// then the default item is returned.
item get(list *xs);

// FUNCTION #9: Set the current item and return true. If set is called while no
// item is selected then the function does nothing and returns false.
bool set(list *xs, item x);

// FUNCTION #10: Inserts an item after the current item and makes it the current item.
// If insertAfter is called while no item is selected then
// the function inserts the item at the beginning of the list
// before the first item.
void insertAfter(list *xs, item x);

// FUNCTION #11: Inserts an item before the current item and makes it the current item.
// If insertAfter is called while no item is selected then the function inserts 
// the item at the end of the list after the last item.
void insertBefore(list *xs, item x);

// FUNCTION #12: Delete the current item and make its successor the current item, then
// return true. If deleteToAfter is called while the last item is the current item then 
// the last item is deleted, no item is selected, and true is returned. 
// If deleteToAfter is called while no item is selected then the
// function does nothing and returns false.
bool deleteToAfter(list *xs);

// FUNCTION #13: Delete the current item and make its predecessor the current item, then 
// return true. If deleteToBefore is called while the first item is the current item then
// the first item is deleted, no item is selected, and true is returned. 
// If deleteToBefore is called while no item is selected then the
// function does nothing and returns false.
bool deleteToBefore(list *xs);
