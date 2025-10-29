#include <stdio.h>
#include <stdbool.h>
#define MAX 10


void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void displaybinary(unsigned char set); // printing A = 2 {1} (00000010)
void display(unsigned char set);// {1, 3, 6, 7}
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char union_set(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);


int main(){
     unsigned char set[MAX];
     initialize(set);
    
    //set A
    char A = 0;
    initialize(&A);
    printf("Set A: ");
    printf("After inserting: \n");
    insert(&A, 1);
    displaybinary(A);
    insert(&A, 6);
    displaybinary(A);
    display(A);
    
    printf("After deleting:\n");
    delete(&A, 6);
    displaybinary(A);
    display(A);
    
    printf("After inserting: \n");
    insert(&A, 6);
    displaybinary(A);
    
    printf("\n");
    
    unsigned char set2[MAX];
     initialize(set2);
    //set B
    char B = 0;
    initialize(&B);
    printf("Set B: ");
    printf("After inserting: \n");
    insert(&B, 3);
    displaybinary(B);
    insert(&B, 6);
    displaybinary(B);
    insert(&B, 7);
    displaybinary(B);
    display(B);
    printf("\n");
    
    char C;
    //union
    printf("Union C: ");
    C = union_set(A, B);
    displaybinary(C);
    
    //intersection
    printf("Intersection C: ");
    C = intersection(A, B);
    displaybinary(C);
    
    //difference
    printf("Difference C: ");
    C = difference(A, B);
    displaybinary(C);
}

void initialize(unsigned char *set){
    for(int i = 0; i < MAX; i++){
        set[i] = 0;
    }
}

void insert(unsigned char *set, int element){
    
    if(element < 0 || element >= MAX * 8){
        printf("Error");
        return;
    }
    
    int byteindex = element / 8;
    int bitpos = element % 8;
    
    unsigned char mask = 1 << bitpos;
    set[byteindex] |= mask;
}

void displaybinary(unsigned char set){
    int decimal = set;
    
    printf("%d {", decimal); 
    
    int isfirst = 1;
    for(int i = 0; i < 8; i++){
        if(set & (1 << i)){
            if(!isfirst){
                printf(", ");
            }
            printf("%d", i);
            isfirst = 0;
        }
    }
    
    printf("} (");
    unsigned char bmask = 1 << 7;
    for(int i = 0; i < 8; i++){
        if(set & bmask){
            printf("1");
        }else{
            printf("0");
        }
        bmask >>= 1;
    }
    printf(")\n"); 
}

void display(unsigned char set){
    printf("{");
    int isfirst = 1;
    for(int i = 0; i < 8; i++){
        unsigned char mask = 1 << i;
        if(set & mask){
            if(!isfirst){
                printf(", ");
            }
        printf("%d", i);    
        isfirst = 0;
        }
    }
    printf("}\n");
}

void delete(unsigned char *set, int element){
    if(element < 0 || element >= MAX * 8){
        printf("Error");
        return;
    }
    
    int byteindex = element / 8;
    int bitpos = element % 8;
    
    unsigned char mask = 1 << bitpos;
    unsigned char invertmask = ~mask;
    set[byteindex] &= invertmask;
}


bool find(unsigned char set, int element){
    unsigned char mask = 1 << element;
    
    return (set & mask) != 0;
}

unsigned char union_set(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B){
    return A & ~B;    
}
