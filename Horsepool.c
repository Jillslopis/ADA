#include <stdio.h>
#include <string.h>
#define MAX_ALPHABET_SIZE 256

// Function to create the bad character shift table
void createShiftTable(char pattern[], int m, int shiftTable[]) {
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        shiftTable[i] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        shiftTable[(int)pattern[j]] = m - 1 - j;
    }
}

// Function to perform Horsepool's algorithm
int horsepoolSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shiftTable[MAX_ALPHABET_SIZE];

    createShiftTable(pattern, m, shiftTable);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1; // Pattern found at index (i - m + 1)
        } else {
            i += shiftTable[(int)text[i]];
        }
    }
    return -1; // Pattern not found
}

int main() {
    char text[] = "ACGTACGTGACG";
    char pattern[] = "TACG";

    int position = horsepoolSearch(text, pattern);
    if (position != -1) {
        printf("Pattern found at index: %d\n", position);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}

