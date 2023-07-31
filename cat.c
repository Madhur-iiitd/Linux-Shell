#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int a, char *args[])
{
    char *token = malloc(1024 * sizeof(char));
    strcpy(token, args[2]);
    FILE *fp;
    
    if (strcmp(args[1], "0") == 0 || args[1] == NULL)
    {
        fp = fopen(token, "r");
        if (fp == NULL)
        {
            printf("cat: %s: No such file or directory\n", token);
            fclose(fp);
        }
        else
        {
            char c = fgetc(fp);
            while (c != EOF)
            {
                printf("%c", c);
                c = fgetc(fp);
            }
            fclose(fp);
        }
    }
    else if (strcmp(args[1], "-v") == 0)
    {
        fp = fopen(token, "r");
        if (fp == NULL)
        {
            printf("cat: %s: No such file or directory\n", token);
            fclose(fp);
        }
        else
        {
            char c;
            while (1 == 1)
            {
                c = fgetc(fp);
                if (c == EOF)
                {
                    break;
                }
                else if (c == '\n')
                {
                    printf("^");
                }
                else if (c == '\t')
                {
                    printf("M-");
                }
                else
                {
                    printf("%c", c);
                }
            }
            fclose(fp);
        }
    }
    else if (strcmp(args[1], "-E") == 0)
    {
        fp = fopen(token, "r");
        if (fp == NULL)
        {
            printf("cat: %s: No such file or directory\n", token);
            fclose(fp);
        }
        else
        {
            char c;
            while (1 == 1)
            {
                c = fgetc(fp);
                if (c == EOF)
                {
                    break;
                }
                if (c == '\n')
                {
                    printf("$\n");
                }
                else
                {
                    printf("%c", c);
                }
            }
            fclose(fp);
        }
    }
    else
    {
        printf("Invalid tag\n");
    }
    return 0;
}