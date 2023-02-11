#include<stdio.h>
#include<string.h>

int S(char *s, int i)
{
    if (s[i] == '0')
    {
        i++;
        if (S(s, i))
        {
            i++;
            if (s[i] == '0')
                return 1;
        }
    }
    else if (A(s, i))
        return 1;
    return 0;
}

int A(char *s, int i)
{
    if (s[i] == '1')
    {
        i++;
        if (A(s, i))
            return 1;
    }
    else if (s[i] == '\0')
        return 1;
    return 0;
}

int main()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);
    if (S(s, 0))
        printf("The string belongs to the language.\n");
    else
        printf("The string does not belong to the language.\n");
    return 0;
}
