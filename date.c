#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
int main(int a, char *args[])
{
    char str_time[1024];
    time_t t = time(NULL);
    struct tm *timeObj;
    if (args[1][0] == '-' || strcmp(args[1],"0")==0)
    {
        if (strcmp(args[1], "0") == 0 || strcmp(args[1], "-R") == 0)
        {
            timeObj = localtime(&t);
            if (strcmp(args[1], "-R") == 0)
            {
                strftime(str_time, 1024, "%a, %b %d %H:%M:%S %z", timeObj);
            }
            else
            {
                strftime(str_time, 1024, "%a %b %d %H:%M:%S %Z %Y", timeObj);
            }
            printf("%s\n", str_time);
        }
        else if (strcmp(args[1], "-u") == 0)
        {
            timeObj = gmtime(&t);
            strftime(str_time, 1024, "%a %b %d %H:%M:%S UTC %Y", timeObj);
            printf("%s\n", str_time);
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
}