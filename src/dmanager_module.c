#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void close_doors(struct door* door);
void sort_doors(struct door* doors, int count);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    close_doors(doors);
    sort_doors(doors, DOORS_COUNT);

    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i == DOORS_COUNT - 1) {
            printf("%d, %d", i, doors[i].status);
        } else {
            printf("%d, %d\n", i, doors[i].status);
        }
    }

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void sort_doors(struct door* doors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}