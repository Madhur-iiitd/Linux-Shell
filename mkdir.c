#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
int main(int a, char *args[])
{
    char *initial_path = getcwd(NULL, 0);
    int success = 0;
    if (strcmp(args[1], "0") == 0)
    {
        if (args[2] == NULL)
        {
            printf("Error: No arguments given\n");
            return 1;
        }
        else
        {
            success = mkdir(args[2], 0777);
            if (success != 0)
            {
                DIR *dir = opendir(args[2]);
                if (dir)
                {
                    printf("mkdir: Error: Directory already exists\n");
                    closedir(dir);
                    return 1;
                }
                else
                {
                    FILE *file = fopen(args[2], "r");
                    if (file)
                    {
                        printf("mkdir: Error: File already exists\n");
                        fclose(file);
                        return 1;
                    }
                    else
                    {
                        printf("mkdir: Error: Unknown error\n");
                        return 1;
                    }
                }
                return 1;
            }
        }
    }
    else if (strcmp(args[1], "-v") == 0)
    {
        if (args[2] == NULL)
        {
            printf("mkdir: Error: No arguments given\n");
            return 1;
        }
        else
        {
            success = mkdir(args[2], 0777);
            if (success == 0)
            {
                printf("Directory created: %s\n", args[2]);
            }
            if (success != 0)
            {
                DIR *dir = opendir(args[2]);
                if (dir)
                {
                    printf("mkdir: Error: Directory already exists\n");
                    closedir(dir);
                    return 1;
                }
                else
                {
                    FILE *file = fopen(args[2], "r");
                    if (file)
                    {
                        printf("mkdir: Error: File already exists\n");
                        fclose(file);
                        return 1;
                    }
                    else
                    {
                        printf("mkdir: Error: Unknown error\n");
                        return 1;
                    }
                }
                return 1;
            }
        }
    }
    else if (strcmp(args[1], "-p") == 0)
    {
        if (args[2] == NULL)
        {
            printf("mkdir: Error: No arguments given\n");
            return 1;
        }
        else
        {
            char *newStr = strtok(args[2], "/");
            while (newStr != NULL)
            {
                mkdir(newStr, 0777);
                chdir(newStr);
                newStr = strtok(NULL, "/");
            }
            chdir(initial_path);
        }
    }
    else
    {
        printf("mkdir: Invalid tag\n");
        return 1;
    }
    return 0;
}
