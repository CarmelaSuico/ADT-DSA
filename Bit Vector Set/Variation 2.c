#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
}Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set union_set(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);

int main(){
    printf("Set A:\n");
    Set A;
    initialize(&A);
    //inserting
    printf("After inserting:\n");
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    display(A.field);
    
    //deleting
    printf("After deleting:\n");
    delete(&A, 5);
    delete(&A, 4);
    display(A.field);
    
    //finding
    printf("Is the element there: %s\n", find(A, 0) ? "Yes" : "No");
    printf("\n");
    
    printf("Set B: \n");
    Set B;
    initialize(&B);
    //inserting
    printf("After inserting:\n");
    insert(&B, 2);
    insert(&B, 5);
    display(B.field);
    
    Set C;
    
    //union_set
    printf("Union C: ");
    C = union_set(A, B);
    display(C.field);
    
    //intersection
    printf("Intersection C: ");
    C = intersection(A, B);
    display(C.field);
    
    //difference
    printf("Difference C: ");
    C = difference(A, B);
    display(C.field);
}

void initialize(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element < 0 || element >= 8){
        printf("Error");
        return;
    }
    
    unsigned int mask = 1U << element;
    set->field |= mask;
}

void delete(Set *set, int element){
    if(element < 0 || element >=  8){
        printf("Error");
        return;
    }
    
    unsigned int mask = 1U << element;
    unsigned int invert = ~mask;
    
    set->field &= invert;
}

bool find(Set set, int element){
    unsigned int mask = 1U << element;
    return (set.field & mask) != 0;
}

void display(unsigned char set){
    int decimal = set;
    
    printf("%d {", decimal);
    int isfirst = 1;
    for(int i = 0; i < 8; i++){
        if(set & (1U << i)){
            if(!isfirst){
                printf(", ");
            }
            printf("%d", i);
            isfirst = 0;
        }
    }
    printf("}\n");
}

Set union_set(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set intersection(Set A, Set B){
    Set result;
    result.field = A.field & B.field;
    return result;
}
Set difference(Set A, Set B){
    Set result;
    result.field = A.field & ~B.field;
    return result;
}

