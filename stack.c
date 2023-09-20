#include <stdio.h>

#define MAX_SIZE 10000

int stack[MAX_SIZE];

int top = -1;

void push(int data)
{
    if (top >= MAX_SIZE - 1)
    {
        //printf("stack overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        //printf("stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int size()
{
    return top + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    char cmd[6];
    int data;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", cmd);

        if (cmd[0] == 'p' && cmd[1] == 'u')
        {
            scanf("%d", &data);
            push(data);
        }
        else if (cmd[0] == 'p' && cmd[1] == 'o')
        {
            printf("%d\n", pop());
        }
        else if (cmd[0] == 's')
        {
            printf("%d\n", size());
        }
        else if (cmd[0] == 'e')
        {
            printf("%d\n", empty());
        }
        else if (cmd[0] == 't')
        {
            if (top == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[top]);
        }
    }
    return 0;
}
