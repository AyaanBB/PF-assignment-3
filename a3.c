#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email) {
    int atCount = 0, dotAfterAt = 0, atIndex = -1;
    int length = strlen(email);

    if (length == 0) return 0;

    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
            atIndex = i;
        }
        if (atCount == 1 && atIndex != -1 && email[i] == '.' && i > atIndex) {
            dotAfterAt = 1;
        }
    }

    return (atCount == 1 && dotAfterAt);
}

int main() {
    char *email;
    int maxLength;

    printf("Enter the maximum length of the email address: ");
    scanf("%d", &maxLength);

    email = (char *)malloc((maxLength + 1) * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter an email address: ");
    scanf("%s", email);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}
