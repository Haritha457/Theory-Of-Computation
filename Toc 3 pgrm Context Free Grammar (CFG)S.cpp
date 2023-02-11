#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int check_A(char *input_string, int start, int end)
{
    int i;

    for (i = start; i <= end; i++) {
        if (input_string[i] == '0') {
            if (check_A(input_string, i + 1, end) == 1)
                return 1;
        } else if (input_string[i] == '1') {
            if (check_A(input_string, i + 1, end) == 1)
                return 1;
        } else {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char input_string[MAX_LEN];
    int length;

    printf("Enter the input string: ");
    scanf("%s", input_string);
    length = strlen(input_string);

    if (length < 2) {
        printf("Reject\n");
        return 0;
    }

    if (input_string[0] == '0' && input_string[length - 1] == '1') {
        if (check_A(input_string, 1, length - 2) == 1)
            printf("Accept\n");
        else
            printf("Reject\n");
    } else {
        printf("Reject\n");
    }

    return 0;
}
