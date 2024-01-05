// code for cd linux command
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pthread.h>
#include <dirent.h>

void* System_T(void *(args))
{
  system(args);
}
void thread_T(char *path_args)
{
  pthread_t thread;
  pthread_create(&thread, NULL, System_T, path_args);
  pthread_join(thread, NULL);
}
char *mergeArgs(char *path, char *tag, char *args)
{
  char *new = (char *)malloc(sizeof(char) * 1024);
  strcpy(new, path);
  strcat(new, " ");
  strcat(new, tag);
  strcat(new, " ");
  strcat(new, args);
  return new;
}
// pwd
void pwd(char *tag)
{
  char *cwd;
  char temp[1024];
  cwd = getcwd(temp, 1024);
  if (cwd != NULL)
  {
    if (tag != NULL && tag[0] == '-')
    {
      if (strcmp(tag, "-L") == 0)
      {
        printf("%s\n", temp);
      }
      else if (strcmp(tag, "-P") == 0)
      {
        printf("%s\n", cwd);
      }
      else
      {
        printf("Invalid tag\n");
      }
    }
    else
    {
      printf("%s\n", getcwd(NULL, 0));
    }
  }
  else
  {
    printf("pwd: Error Occurred while getting current working directory\n");
  }
}
// cd
void cd(char *path)
{
  int success = chdir(path);
  if (success != 0)
  {
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
      printf("cd: Error: Directory does not exist\n");
      closedir(dir);
    }
    else
    {
      printf("cd: Error: Unknown error\n");
    }
  }
  else
  {
    printf("\n");
  }
  return;
}
// echo
void echo(char *split_str, char *tag)
{
  if (tag != NULL && tag[0] == '-')
  {
    if (strcmp(tag, "-E") == 0)
    {
      while (split_str != NULL)
      {
        printf("%s ", split_str);
        split_str = strtok(NULL, " ");
      }
      printf("\n");
    }
    else if (strcmp(tag, "-n") == 0)
    {
      while (split_str != NULL)
      {
        printf("%s ", split_str);
        split_str = strtok(NULL, " ");
      }
    }
    else
    {
      printf("Invalid tag\n");
    }
  }
  else
  {
    while (split_str != NULL)
    {
      printf("%s ", split_str);
      split_str = strtok(NULL, " ");
    }
    printf("\n");
  }
}
// mkdir
void mkdir1(char *tag, char *directory)
{
  char *path_mkdir = (char *)malloc(1024 * sizeof(char));
  path_mkdir = "./mkdir";
  int *s;
  pid_t pid = fork();
  if (pid < 0)
  {
    printf("Error Occurred\n");
  }
  if (pid == 0)
  {
    if (tag == NULL)
    {
      execl(path_mkdir, "null", "0", directory, NULL);
    }
    else if (strcmp(tag, "-v") == 0)
    {
      execl(path_mkdir, "null", "-v", directory, NULL);
    }
    else if (strcmp(tag, "-p") == 0)
    {
      execl(path_mkdir, "null", "-p", directory, NULL);
    }
    else
    {
      printf("Invalid tag\n");
    }
  }
  else if (pid > 0)
  {
    waitpid(pid, s, 0);
    return;
  }
}
// cat
void cat(char *tag, char *directory)
{
  char *path_cat = (char *)malloc(1024 * sizeof(char));
  path_cat = "./cat";
  int *s;
  pid_t pid = fork();
  if (pid < 0)
  {
    printf("Error Occurred\n");
  }
  if (pid == 0)
  {
    if (tag == NULL)
    {
      execl(path_cat, "null", "0", directory, NULL);
    }
    else if (strcmp(tag, "-v") == 0)
    {
      execl(path_cat, "null", "-v", directory, NULL);
    }
    else if (strcmp(tag, "-E") == 0)
    {
      execl(path_cat, "null", "-E", directory, NULL);
    }
    else
    {
      printf("Invalid tag\n");
    }
  }
  else if (pid > 0)
  {
    waitpid(pid, s, 0);
    return;
  }
}
// ls
void ls(char *tag)
{
  char *path_ls = (char *)malloc(1024 * sizeof(char));
  path_ls = "./ls";
  int *s;
  pid_t pid = fork();
  if (pid < 0)
  {
    printf("Error Occurred\n");
  }
  if (pid == 0)
  {
    if (strcmp(tag, "-A") == 0)
    {
      execl(path_ls, "null", "-A", NULL);
    }
    else if (strcmp(tag, "-a") == 0)
    {
      execl(path_ls, "null", "-a", NULL);
    }
    else if (strcmp(tag, "-i") == 0)
    {
      execl(path_ls, "null", "-i", NULL);
    }
    else if (strcmp(tag, "0") == 0 || tag == NULL)
    {
      execl(path_ls, "null", "0", NULL);
    }
    else
    {
      if(tag[0] == '-')
      {
        printf("Invalid tag\n");
      }
      else
      {
        printf("Invalid Syntax\n");
      }
    }
  }
  else if (pid > 0)
  {
    waitpid(pid, s, 0);
    return;
  }
}
// date
void date(char *tag)
{
  char *path_date = (char *)malloc(1024 * sizeof(char));
  path_date = "./date";
  int *s;
  pid_t pid = fork();
  if (pid < 0)
  {
    printf("Error Occurred\n");
  }
  if (pid == 0)
  {
    if (strcmp(tag, "-u") == 0)
    {
      execl(path_date, "null", "-u", NULL);
    }
    else if (strcmp(tag, "-R") == 0)
    {
      execl(path_date, "null", "-R", NULL);
    }
    else if (strcmp(tag, "0") == 0 || tag == NULL)
    {
      execl(path_date, "null", "0", NULL);
    }
    else
    {
      printf("Invalid tag\n");
    }
  }
  else if (pid > 0)
  {
    waitpid(pid, s, 0);
    return;
  }
}
// rm
void rm(char *tag, char *directory)
{
  char *path_rm = (char *)malloc(1024 * sizeof(char));
  path_rm = "./rm";
  int *s;
  pid_t pid = fork();
  if (pid < 0)
  {
    printf("Error Occurred\n");
  }
  if (pid == 0)
  {
    if (tag == NULL)
    {
      execl(path_rm, "null", "0", directory, NULL);
    }
    else if (strcmp(tag, "-i") == 0)
    {
      execl(path_rm, "null", "-i", directory, NULL);
    }
    else if (strcmp(tag, "-d") == 0)
    {
      execl(path_rm, "null", "-d", directory, NULL);
    }
    else
    {
      printf("Invalid tag\n");
    }
  }
  else if (pid > 0)
  {
    waitpid(pid, s, 0);
    return;
  }
}
// main
int main()
{
  while (1 == 1)
  {
    int thread_flags = 0;
    printf("%s >>>", getcwd(NULL, 0));
    char *str = (char *)malloc(sizeof(char) * 1024);
    fgets(str, 1024, stdin);
    char *str1 = (char *)malloc(sizeof(char) * 1024);
    strcpy(str1, str);
    if (strlen(str) > 1)
    {
      char *split_str;
      char *token;
      token = strtok(str, "\n");
      strcpy(str1, token);
      token = strtok(str, "&");
      char *str2 = (char *)malloc(sizeof(char) * 1024);
      strcpy(str2, token);
      token = token = strtok(NULL, "&");
      if (token != NULL && strcmp(token, "t") == 0)
      {
        thread_flags = 1;
        split_str = strtok(str2, " ");
      }
      else
      {
        thread_flags = 0;
        split_str = strtok(str1, " ");
      }
      if (strcmp(split_str, "exit") == 0)
      {
        return 0;
      }
      // pwd
      if (strcmp(split_str, "pwd") == 0)
      {
        split_str = strtok(NULL, " ");
        if (split_str == NULL)
        {
          pwd("");
        }
        else
        {
          char *temp = split_str;
          split_str = strtok(NULL, " ");
          pwd(temp);
        }
      }
      // echo
      else if (strcmp(split_str, "echo") == 0)
      {
        split_str = strtok(NULL, " ");
        if (split_str == NULL)
        {
          printf("\n");
          continue;
        }
        if (strcmp(split_str, "-n") == 0)
        {
          split_str = strtok(NULL, " ");
          if (split_str == NULL)
          {
            printf("");
          }
          else
          {
            echo(split_str, "-n");
          }
        }
        else if (strcmp(split_str, "-E") == 0)
        {
          split_str = strtok(NULL, " ");
          if (split_str == NULL)
          {
            printf("");
          }
          else
          {
            echo(split_str, "-E");
          }
        }
        else
        {
          echo(split_str, NULL);
        }
      }
      // cd
      else if (strcmp(split_str, "cd") == 0)
      {
        split_str = strtok(NULL, " ");
        if (split_str == NULL)
        { // cd
          cd("/home/user");
        }
        else
        {
          char *tag = (char *)malloc(1024 * sizeof(char)); //-L
          strcpy(tag, split_str);
          if (tag[0] == '-')
          {
            split_str = strtok(NULL, " "); // file
            if (split_str == NULL)
            {
              if (strcmp(tag, "-L") == 0 || strcmp(tag, "-P") == 0)
              {
                cd("/home/user");
              }
              else
              { // cd file
                printf("cd: Invalid Tag\n");
              }
            }
            else
            {
              char *tag2 = (char *)malloc(1024 * sizeof(char)); // file1
              strcpy(tag2, split_str);
              split_str = strtok(NULL, " "); // file2
              if (strcmp(tag, "-L") == 0 || strcmp(tag, "-P") == 0)
              {
                if (split_str == NULL)
                {
                  cd(tag2);
                }
                else
                {
                  printf("Invalid command Syntax\n");
                }
              }
              else
              {
                printf("cd: Invalid Tag\n");
              }
            }
          }
          else
          {
            cd(tag);
          }
        }
      }
      // date
      else if (strcmp(split_str, "date") == 0)
      {
        split_str = strtok(NULL, " ");
        if (thread_flags == 1)
        {
          char *path = (char *)malloc(1024 * sizeof(char));
          if (split_str == NULL)
          {
            path = mergeArgs("./date", "0", "");
            thread_T(path);
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            split_str = strtok(NULL, " ");
            if (split_str == NULL)
            {
              path = mergeArgs("./date", tag, "");
              thread_T(path);
            }
            else
            {
              printf("Invalid Command Syntax\n");
            }
          }
        }
        else
        {
          if (split_str == NULL)
          {
            date("0");
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            split_str = strtok(NULL, " ");
            if (split_str == NULL)
            {
              date(tag);
            }
            else
            {
              printf("Invalid Command Syntax\n");
            }
          }
        }
      }
      // rm
      else if (strcmp(split_str, "rm") == 0)
      {

        split_str = strtok(NULL, " ");
        if (thread_flags == 1)
        {

          char *path = (char *)malloc(1024 * sizeof(char));
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            if(tag[0] == '-')
            {
              if (strcmp(tag, "-i") == 0 || strcmp(tag, "-d") == 0)
              {
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    path = mergeArgs("./rm", tag, split_str);
                    thread_T(path);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("rm: Invalid Tag\n");
              }
            }
            else
            {
              while (split_str != NULL)
              {
                path = mergeArgs("./rm", "0", split_str);
                thread_T(path);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
        else
        {
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag;
            if(split_str[0] =='-')
            {
              if (strcmp(split_str, "-i") == 0 || strcmp(split_str, "-d") == 0)
              {
                tag = split_str;
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    rm(tag, split_str);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("rm: Invalid Tag\n");
              }
            }
            else
            {
              tag = NULL;
              while (split_str != NULL)
              {
                rm(tag, split_str);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
      }
      // ls
      else if (strcmp(split_str, "ls") == 0)
      {
        split_str = strtok(NULL, " ");
        if (thread_flags == 1)
        {
          char *path = (char *)malloc(1024 * sizeof(char));
          if (split_str == NULL)
          {
            path = mergeArgs("./ls", "0", "");
            thread_T(path);
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            split_str = strtok(NULL, " ");
            if (split_str == NULL)
            {
              path = mergeArgs("./ls", tag, "");
              thread_T(path);
            }
            else
            {
              printf("Invalid Command Syntax\n");
            }
          }
        }
        else
        {
          if (split_str == NULL)
          {
            ls("0");
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            split_str = strtok(NULL, " ");
            if (split_str == NULL)
            {
              ls(tag);
            }
            else
            {
              printf("Invalid Command Syntax\n");
            }
          }
        }
      }
      // mkdir
      else if (strcmp(split_str, "mkdir") == 0)
      {
        split_str = strtok(NULL, " ");
        if (thread_flags == 1)
        {
          char *path = (char *)malloc(1024 * sizeof(char));
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            if(tag[0] == '-')
            {
              if (strcmp(tag, "-v") == 0 || strcmp(tag, "-p") == 0)
              {
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    path = mergeArgs("./mkdir", tag, split_str);
                    thread_T(path);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("mkdir: Invalid Tag\n");
              }
            }
            else
            {
              while (split_str != NULL)
              {
                path = mergeArgs("./mkdir", "0", split_str);
                thread_T(path);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
        else
        {
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag;
            if(split_str[0] =='-')
            {
              if (strcmp(split_str, "-v") == 0 || strcmp(split_str, "-p") == 0)
              {
                tag = split_str;
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    mkdir1(tag, split_str);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("mkdir: Invalid Tag\n");
              }
            }
            else
            {
              tag = NULL;
              while (split_str != NULL)
              {
                mkdir1(tag, split_str);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
      }
      // cat
      else if (strcmp(split_str, "cat") == 0)
      {
        split_str = strtok(NULL, " ");
        if (thread_flags == 1)
        {
          char *path = (char *)malloc(1024 * sizeof(char));
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag = (char *)malloc(1024 * sizeof(char));
            strcpy(tag, split_str);
            if(tag[0] == '-')
            {
              if (strcmp(tag, "-E") == 0 || strcmp(tag, "-v") == 0)
              {
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    path = mergeArgs("./cat", tag, split_str);
                    thread_T(path);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("cat: Invalid Tag\n");
              }
            }
            else
            {

              while (split_str != NULL)
              {
                path = mergeArgs("./cat", "0", split_str);
                thread_T(path);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
        else
        {
          if (split_str == NULL)
          {
            printf("Missing Arguments\n");
          }
          else
          {
            char *tag;
            if(split_str[0] =='-')
            {
              if (strcmp(split_str, "-E") == 0 || strcmp(split_str, "-v") == 0)
              {
                tag = split_str;
                split_str = strtok(NULL, " ");
                if (split_str == NULL)
                {
                  printf("Missing Arguments\n");
                }
                else
                {
                  while (split_str != NULL)
                  {
                    cat(tag, split_str);
                    split_str = strtok(NULL, " ");
                  }
                }
              }
              else
              {
                printf("cat: Invalid Tag\n");
              }
            }
            else
            {
              tag = NULL;
              while (split_str != NULL)
              {
                cat(tag, split_str);
                split_str = strtok(NULL, " ");
              }
            }
          }
        }
      }
      else
      {
        printf("Invalid command\n");
      }
    }
    else
    {
      continue;
    }
  }
}