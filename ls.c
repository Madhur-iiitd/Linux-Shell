#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
int main(int a, char *args[])
{
    // ls functionality
    DIR *directObj;
    struct dirent *directory;
    directObj = opendir(getcwd(NULL, 0));
    if (directObj == NULL)
    {
        printf("ls: SYSTEM ERROR\n");
        return 1;
    }
    if (args[1][0] == '-' || strcmp(args[1], "0") == 0)
    {
        if (strcmp(args[1], "-a") == 0)
        {
            if (directObj != NULL)
            {
                directory = readdir(directObj);
                while (directory != NULL)
                {
                    printf("%s\t", directory->d_name);
                    directory = readdir(directObj);
                }
                printf("\n");
            }
        }
        else if (strcmp(args[1], "-A") == 0)
        {
            if (directObj != NULL)
            {
                directory = readdir(directObj);
                while (directory != NULL)
                {
                    if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0)
                    {
                        printf("%s\t", directory->d_name);
                    }
                    directory = readdir(directObj);
                }
                printf("\n");
            }
        }
        else if (strcmp(args[1], "0") == 0 || args[1] == NULL)
        {
            if (directObj != NULL)
            {
                directory = readdir(directObj);
                while (directory != NULL)
                {
                    if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0 && (directory->d_name[0] != '.'))
                    {
                        printf("%s\t", directory->d_name);
                    }
                    directory = readdir(directObj);
                }
                printf("\n");
            }
        }
        else if (strcmp(args[1], "-i") == 0)
        {
            if (directObj != NULL)
            {
                directory = readdir(directObj);
                while (directory != NULL)
                {
                    if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0 && directory->d_name[0] != '.')
                    {
                        printf("%ji ", directory->d_ino);
                        printf("%s\n", directory->d_name);
                    }
                    directory = readdir(directObj);
                }
            }
        }
        else
        {
            printf("Invalid tag\n");
        }
    }
    else
    {
        printf("Invalid Syntax\n");
    }
    closedir(directObj);
    return (0);
}