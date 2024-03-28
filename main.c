#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void link_value(long long int list_pointer[], long long int object[]) {
    while (true) {
        if (list_pointer[1] == 0) {
            printf("Writing Object(%lld, %p) to %p[1]\n", object[0], object, list_pointer);
            list_pointer[1] = (long long int)object;
            return;
        } else {
            list_pointer = (long long int*)list_pointer[1];
        }
    }
}

void iter_linked_list(long long int *list_pointer) {
    printf("------ ALL LINKED LIST VALUES ------\n");
    while (true) {
        printf("  --> Value: %lld / Memory Address: 0x%x / Next Value Address: 0x%x\n", list_pointer[0], list_pointer, list_pointer[1]);
        if (list_pointer[1] == 0)
            break;
        list_pointer = (long long int*)list_pointer[1];
    }
}

int main() {
    long long int* object;
    long long int value, starting_object[2] = {0, 0};
    bool starting_initialized = false;

    printf("Type the value you want to add,\nif you want to stop insert -1\n");
    while (true) {
        printf("Value > ");
        scanf("%lld", &value);

        if (value == -1) break;

        if (!starting_initialized) {
            starting_object[0] = value;
            starting_initialized = true;
            continue;
        }

        object = (long long int*) malloc(2 * sizeof(long long int));
        object[0] = value;
        object[1] = 0;
        link_value(starting_object, object);
    }

    iter_linked_list(starting_object);
}

