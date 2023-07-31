#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

// rm functionality
int main(int a, char *args[])
{
    if (strcmp(args[1], "-i") == 0)
    {
        printf("Are you sure? (y/n): ");
        char c;
        scanf("%c", &c);
        if (c == 'y' || c == 'Y')
        {
            DIR *dir = opendir(args[2]);
            if (dir == NULL)
            {
                if (remove(args[2]) != 0)
                {
                    FILE *file = fopen(args[2], "r");
                    if (file == NULL)
                    {
                        printf("rm: cannot remove '%s': No such file or directory\n", args[2]);
                    }
                    else
                    {
                        fclose(file);
                        printf("rm: Error deleting File(system error): %s\n", args[2]);
                    }
                }
            }
            else
            {
                printf("rm: Error: Use -d tag for directory\n");
                return -1;
            }
        }
    }
    else if (strcmp(args[1], "-d") == 0)
    {
        DIR *dir = opendir(args[2]);
        if (dir == NULL)
        {
            FILE* file = fopen(args[2], "r");
            if (file == NULL)
            {
                printf("rm: cannot remove '%s': No such file or directory\n", args[2]);
            }
            else
            {
                fclose(file);
                if(remove(args[2])!=0)
                {
                    printf("rm: Error deleting File: %s\n", args[2]);
                }
            }
        }
        else
        {
            if(rmdir(args[2])!=0)
            {
                printf("rm: Directory Not empty/system error %s\n", args[2]);
            }
        }
    }
    else if (strcmp(args[1], "0") == 0 || args[1] == NULL)
    {
        DIR *dir = opendir(args[2]);
        if (dir == NULL)
        {
            if (remove(args[2]) != 0)
            {
                FILE *file = fopen(args[2], "r");
                if (file == NULL)
                {
                    printf("rm: cannot remove '%s': No such file or directory\n", args[2]);
                }
                else
                {
                    fclose(file);
                    printf("rm: Error deleting File(system error): %s\n", args[2]);
                }
            }
        }
        else
        {
            printf("rm: Error: Use -d tag for directory\n");
            return -1;
        }
    }
    else
    {
        printf("Invalid tag\n");
    }
}