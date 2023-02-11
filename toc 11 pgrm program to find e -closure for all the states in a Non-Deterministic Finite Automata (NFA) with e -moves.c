#include<stdio.h>
#include<stdlib.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 20
#define MAX_TRANSITIONS 200
#define MAX_CLOSURE_STATES 200

int states, symbols, transitions, initial, final, closure_count[MAX_STATES];
char symbol[MAX_SYMBOLS];
int e_closure[MAX_STATES][MAX_CLOSURE_STATES];
int transition[MAX_STATES][MAX_SYMBOLS][MAX_CLOSURE_STATES];

void e_close(int state)
{
    int i, j;
    for (i = 0; i < closure_count[state]; i++)
    {
        int t = e_closure[state][i];
        for (j = 0; j < closure_count[t]; j++)
        {
            int s = e_closure[t][j];
            if (s != state)
            {
                e_closure[state][closure_count[state]++] = s;
            }
        }
    }
}

int main()
{
    int i, j, k, l, m;
    printf("Enter the number of states: ");
    scanf("%d", &states);
    printf("Enter the number of symbols: ");
    scanf("%d", &symbols);
    printf("Enter the symbols: ");
    for (i = 0; i < symbols; i++)
    {
        scanf(" %c", &symbol[i]);
    }
    printf("Enter the number of transitions: ");
    scanf("%d", &transitions);
    printf("Enter the transitions in the format 'from to on': \n");
    for (i = 0; i < transitions; i++)
    {
        int from, to;
        char on;
        scanf("%d %d %c", &from, &to, &on);
        if (on == 'e')
        {
            e_closure[from][closure_count[from]++] = to;
        }
        else
        {
            for (j = 0; j < symbols; j++)
            {
                if (symbol[j] == on)
                {
                    transition[from][j][closure_count[from]++] = to;
                }
            }
        }
    }
    printf("Enter the initial state: ");
    scanf("%d", &initial);
    printf("Enter the number of final states: ");
    scanf("%d", &final);
    printf("Enter the final states: ");
    int final_state[final];
    for (i = 0; i < final; i++)
    {
        scanf("%d", &final_state[i]);
    }
    for (i = 0; i < states; i++)
    {
        e_close(i);
    }
    printf("The epsilon closure for the given NFA is: \n");
    return 0;
}
