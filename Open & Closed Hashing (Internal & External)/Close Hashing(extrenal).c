#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

void init_file(const char* filename);
void insert_external(const char* filename, int key);
void display_external(const char* filename);

int main() {
    const char* filename = "hash_data.bin";

    init_file(filename);

    insert_external(filename, 12);
    insert_external(filename, 22);
    insert_external(filename, 32); 
    insert_external(filename, 45);

    display_external(filename);

    return 0;
}

void init_file(const char* filename) {
    FILE *fp = fopen(filename, "wb");
    int empty_val = EMPTY;
    for (int i = 0; i < SIZE; i++) {
        fwrite(&empty_val, sizeof(int), 1, fp);
    }
    fclose(fp);
}

void insert_external(const char* filename, int key) {
    FILE *fp = fopen(filename, "rb+");
    int index = key % SIZE;
    int start_index = index;
    int current_val;

    while (1) {
        fseek(fp, index * sizeof(int), SEEK_SET);
        fread(&current_val, sizeof(int), 1, fp);

        if (current_val == EMPTY) {
            fseek(fp, index * sizeof(int), SEEK_SET);
            fwrite(&key, sizeof(int), 1, fp);
            printf("Inserted %d at index %d\n", key, index);
            break;
        }

        index = (index + 1) % SIZE;

        if (index == start_index) {
            printf("Hash table file is full!\n");
            break;
        }
    }
    fclose(fp);
}

void display_external(const char* filename) {
    FILE *fp = fopen(filename, "rb");
    int current_val;
    printf("\nExternal Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        fseek(fp, i * sizeof(int), SEEK_SET);
        fread(&current_val, sizeof(int), 1, fp);
        if (current_val == EMPTY) {
            printf("[%d]: EMPTY\n", i);
        } else {
            printf("[%d]: %d\n", i, current_val);
        }
    }
    fclose(fp);
}

