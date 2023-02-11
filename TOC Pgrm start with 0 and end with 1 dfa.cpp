#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LEN 50

int main()
{
  char input_string[MAX_LEN];
  int len;
  bool flag = false;

  printf("Enter a string: ");
  scanf("%s", input_string);

  len = strlen(input_string);

  if(input_string[0] == '0' && input_string[len-1] == '1')
    flag = true;

  if(flag)
    printf("Accepted\n");
  else
    printf("Not accepted\n");

  return 0;
}

