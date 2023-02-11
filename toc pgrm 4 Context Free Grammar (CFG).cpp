#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int check_S(char *input_string, int start, int end)
{
    if (start > end)
        return 1;

    if (input_string[start] == '0') {
        if (input_string[end] == '0')
            return check_S(input_string, start + 1, end - 1);
        else
            return 0;
    } else if (input_string[start] == '1') {
        if (input_string[end] == '1')
            return check_S(input_string, start + 1, end - 1);
        else
            return 0;
    } else {
        return 0;
    }
}

int main()
{
    char input_string[MAX_LEN];
    int length;

    printf("Enter the input string: ");
    scanf("%s", input_string);
    length = strlen(input_string);

    if (check_S(input_string, 0, length - 1) == 1)
        printf("Accept\n");
    else
        printf("Reject\n");

    return 0;
}
