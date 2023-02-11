#include<stdio.h>
#include<string.h>

#define MAX_STATES 3
#define MAX_SYMBOLS 2
#define MAX_TRANSITIONS 5

int transitions[MAX_STATES][MAX_SYMBOLS][MAX_STATES] = 
{
    {{0, 1}, {-1, -1}},
    {{-1, -1}, {2, -1}},
    {{-1, -1}, {-1, -1}}
};

int initial_state = 0;
int final_states[] = {2};
int num_final_states = 1;

int get_next_state(int current_state, char symbol)
{
    int next_state = -1;
    switch (symbol)
    {
        case 'a':
            next_state = transitions[current_state][1][0];
            break;
        case 'b':
            next_state = transitions[current_state][0][0];
            break;
        default:
            break;
    }
    return next_state;
}

int is_final_state(int state)
{
    int i;
    for (i = 0; i < num_final_states; i++)
    {
        if (state == final_states[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char input_string[100];
    printf("Enter the input string: ");
    scanf("%s", input_string);
    int length = strlen(input_string);
    int current_state = initial_state;
    int i;
    for (i = 0; i < length; i++)
    {
        char symbol = input_string[i];
        current_state = get_next_state(current_state, symbol);
        if (current_state == -1)
        {
            break;
        }
    }
    if (is_final_state(current_state))
    {
        printf("The input string is accepted by the NFA.\n");
    }
    else
    {
        printf("The input string is not accepted by the NFA.\n");
    }
    return 0;
}
