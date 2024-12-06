#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d (1-10): ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] < 1 || ratings[i][j] > 10) {
                    printf("Invalid input. Ratings must be between 1 and 10.\n");
                }
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    float highestAverage = 0;

    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        float average = (float)totalScore / numPeriods;
        if (average > highestAverage) {
            highestAverage = average;
            bestEmployee = i;
        }
    }

    return bestEmployee;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    float highestAverage = 0;

    for (int j = 0; j < numPeriods; j++) {
        int totalScore = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalScore += ratings[i][j];
        }
        float average = (float)totalScore / numEmployees;
        if (average > highestAverage) {
            highestAverage = average;
            bestPeriod = j;
        }
    }

    return bestPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    float lowestAverage = 10;

    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        float average = (float)totalScore / numPeriods;
        if (average < lowestAverage) {
            lowestAverage = average;
            worstEmployee = i;
        }
    }

    return worstEmployee;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
