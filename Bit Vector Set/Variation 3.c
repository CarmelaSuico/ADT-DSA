#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void union_set(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main(){
    Set A;
    initialize(A);
    insert(A, 0);
    insert(A, 2);
    insert(A, 7);
    printf("Set A: "); display(A);
    
    // delete(A, 0);
    // delete(A, 7);
    // display(A);
    
    printf("is the element there: %s\n\n", find(A, 2) ? "YES" : "NO");
    
    Set B;
    initialize(B);
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    printf("Set B: "); display(B);
    
    Set C;
    union_set(A, B, C);
    printf("Union C: "); display(C);
    
    intersection(A, B, C);
    printf("Intersection C: "); display(C);
    
    difference(A, B, C);
    printf("Difference C: "); display(C);
}

void initialize(Set set){
    for(int i = 0; i < ARRAY_SIZE; i++){
        set[i] = false;
    }
}

void insert(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE){
        printf("Error");
    }
    
    set[element] = true;
}

void delete(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE){
        printf("Error");
        return;
    }
    
    set[element] = false;
}

bool find(Set set, int element){
    if(element < 0 || element >= ARRAY_SIZE){
        printf("Error");
        return false;
    }
    
    return set[element];
}

void union_set(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] && !B[i];
    }
}

void display(Set set){
    printf("{");
    int isfirst = 1;
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(set[i] == true){
            if(!isfirst){
                printf(", ");
            }
        printf("%d", i);
        isfirst = 0;
        }
    }
    printf("}\n");
}
