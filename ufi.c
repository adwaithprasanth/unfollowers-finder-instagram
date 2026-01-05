#include <stdio.h>
#include <string.h>

#define MAX_LINES 2000
#define MAX_LEN 200

int main() {
    FILE *f1, *f2;
    char list1[MAX_LINES][MAX_LEN];
    char line[MAX_LEN];
    int count1 = 0;
    int found;

    f1 = fopen("list1.txt", "r");
    f2 = fopen("list2.txt", "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(line, MAX_LEN, f1)) {
        line[strcspn(line, "\n")] = '\0'; 
        strcpy(list1[count1++], line);
    }

    printf("Names present in FOLLOWING but NOT in FOLLOWERS:\n\n");

    while (fgets(line, MAX_LEN, f2)) {
        line[strcspn(line, "\n")] = '\0'; 
        found = 0;

        for (int i = 0; i < count1; i++) {
            if (strcmp(line, list1[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s\n", line);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
