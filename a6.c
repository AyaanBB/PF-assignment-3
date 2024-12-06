#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***speciesSupplies;
int numSpecies;

void initializeInventory(int speciesCount) {
    numSpecies = speciesCount;
    speciesSupplies = (char ***)malloc(numSpecies * sizeof(char **));
    for (int i = 0; i < numSpecies; i++) {
        speciesSupplies[i] = NULL;
    }
}

void addSupplies(int speciesIndex, int numSupplies) {
    if (speciesIndex < 0 || speciesIndex >= numSpecies) return;
    speciesSupplies[speciesIndex] = (char **)malloc(numSupplies * sizeof(char *));
    for (int i = 0; i < numSupplies; i++) {
        speciesSupplies[speciesIndex][i] = (char *)malloc(50 * sizeof(char));
        printf("Enter supply %d for species %d: ", i + 1, speciesIndex + 1);
        scanf("%s", speciesSupplies[speciesIndex][i]);
    }
}

void updateSupply(int speciesIndex, int supplyIndex, char *newSupply) {
    if (speciesIndex < 0 || speciesIndex >= numSpecies || !speciesSupplies[speciesIndex]) return;
    strcpy(speciesSupplies[speciesIndex][supplyIndex], newSupply);
}

void removeSpecies(int speciesIndex) {
    if (speciesIndex < 0 || speciesIndex >= numSpecies || !speciesSupplies[speciesIndex]) return;
    for (int i = 0; speciesSupplies[speciesIndex][i]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);
    speciesSupplies[speciesIndex] = NULL;
}

void displayInventory() {
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        if (speciesSupplies[i]) {
            for (int j = 0; speciesSupplies[i][j]; j++) {
                printf("  %s\n", speciesSupplies[i][j]);
            }
        } else {
            printf("  No supplies.\n");
        }
    }
}

int main() {
    initializeInventory(3);
    addSupplies(0, 2);
    addSupplies(1, 3);
    updateSupply(0, 1, "UpdatedSupply");
    displayInventory();
    removeSpecies(1);
    displayInventory();
    return 0;
}
