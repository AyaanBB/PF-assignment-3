#include <stdio.h>
#include <stdlib.h>

#define USERS 1000
#define CATEGORIES 50
#define DEVICES 10

double engagementMatrix[USERS][CATEGORIES];
int *deviceMatrix[USERS][DEVICES];
char *contentMetadata[CATEGORIES];

void initializeEngagementMatrix() {
    for (int i = 0; i < USERS; i++) {
        for (int j = 0; j < CATEGORIES; j++) {
            engagementMatrix[i][j] = 0.0;
        }
    }
}

void initializeDeviceMatrix() {
    for (int i = 0; i < USERS; i++) {
        for (int j = 0; j < DEVICES; j++) {
            deviceMatrix[i][j] = malloc(3 * sizeof(int));
            deviceMatrix[i][j][0] = 0; 
            deviceMatrix[i][j][1] = 0; 
            deviceMatrix[i][j][2] = 0; 
        }
    }
}

void initializeContentMetadata() {
    for (int i = 0; i < CATEGORIES; i++) {
        contentMetadata[i] = malloc(100 * sizeof(char));
        sprintf(contentMetadata[i], "Category %d metadata", i);
    }
}

void updateEngagement(int userIndex, int categoryIndex, double score) {
    engagementMatrix[userIndex][categoryIndex] = score;
}

void updateDevicePreferences(int userIndex, int deviceIndex, int resolution, int bandwidth, int position) {
    deviceMatrix[userIndex][deviceIndex][0] = resolution;
    deviceMatrix[userIndex][deviceIndex][1] = bandwidth;
    deviceMatrix[userIndex][deviceIndex][2] = position;
}

void printEngagementMatrix() {
    for (int i = 0; i < USERS; i++) {
        for (int j = 0; j < CATEGORIES; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

void printDevicePreferences(int userIndex, int deviceIndex) {
    printf("Resolution: %d, Bandwidth: %d, Position: %d\n",
           deviceMatrix[userIndex][deviceIndex][0],
           deviceMatrix[userIndex][deviceIndex][1],
           deviceMatrix[userIndex][deviceIndex][2]);
}

void freeResources() {
    for (int i = 0; i < USERS; i++) {
        for (int j = 0; j < DEVICES; j++) {
            free(deviceMatrix[i][j]);
        }
    }
    for (int i = 0; i < CATEGORIES; i++) {
        free(contentMetadata[i]);
    }
}

int main() {
    initializeEngagementMatrix();
    initializeDeviceMatrix();
    initializeContentMetadata();
    updateEngagement(0, 0, 4.5);
    updateDevicePreferences(0, 0, 1080, 5000, 60);
    printDevicePreferences(0, 0);
    freeResources();
    return 0;
}
