/* Dynamic list in C */
/* Felipe Scrochio Custódio */
#include <stdio.h>
#include <stdlib.h>

/*
* Why dynamic? Because heap memory is cooler and easier
*/

// Standard C doesn't have a boolean type, let's create one
enum bool {
    true, false
};

// By having an item type, it's easier to change what the list is made of
typedef struct item {

    // Int, float, potatoes, anything you need
    int content;

} ITEM;

typedef struct list {

    // Keeping track of the size facilitates operations
    int size;
    ITEM* vector;

} LIST;


LIST* initialize(int size) {
    int i;
    LIST* list = (LIST*)malloc(sizeof(LIST));
    for (i = 0; i < size; i++) {
        list->vector = (ITEM*)realloc(list->vector, sizeof(ITEM) * i+1);
        list->vector[i]->content = 0;
    }
    return list;
}


ITEM* insert(LIST* list, int content) {

}

ITEM* remove() {
    
}

int main(int argc, char const *argv[]) {

    return 0;
}
