#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11];
};

void assignValues(struct Employee *employee, int code, const char *name, const char *date) {
    employee->employeeCode = code;
    strcpy(employee->employeeName, name);
    strcpy(employee->dateOfJoining, date);
}

void checkTenure(struct Employee employees[], int size, const char *currentDate) {
    int count = 0;
    printf("Employees with tenure greater than 3 years:\n");
    for (int i = 0; i < size; i++) {
        int currentYear, currentMonth, currentDay;
        int joinYear, joinMonth, joinDay;
        sscanf(currentDate, "%d-%d-%d", &currentYear, &currentMonth, &currentDay);
        sscanf(employees[i].dateOfJoining, "%d-%d-%d", &joinYear, &joinMonth, &joinDay);
        int yearsDifference = currentYear - joinYear;
        if (yearsDifference > 3 || (yearsDifference == 3 && currentMonth > joinMonth) || 
            (yearsDifference == 3 && currentMonth == joinMonth && currentDay >= joinDay)) {
            printf("Employee Code: %d, Name: %s, Date of Joining: %s\n",
                   employees[i].employeeCode, employees[i].employeeName, employees[i].dateOfJoining);
            count++;
        }
    }
    printf("Total employees with tenure greater than 3 years: %d\n", count);
}

int main() {
    struct Employee employees[4];
    assignValues(&employees[0], 101, "Alice", "2018-02-15");
    assignValues(&employees[1], 102, "Bob", "2015-06-20");
    assignValues(&employees[2], 103, "Charlie", "2021-01-10");
    assignValues(&employees[3], 104, "David", "2019-12-05");
    char currentDate[11];
    printf("Enter the current date (YYYY-MM-DD): ");
    scanf("%s", currentDate);
    checkTenure(employees, 4, currentDate);
    return 0;
}
