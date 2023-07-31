#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
int main(){
    // char* args[256];
    // char str[1024];
    // fgets(str, 1024, stdin);
    // for(int i=0; i<256; i++){
    //     args[i] = NULL;
    // }
    // char* split_str = strtok(str, "\n");
    // char* token = strtok(split_str, " ");
    // int i =0 ;
    // while(token != NULL){
    //     if(strcmp(token, "rm")&&strcmp(token, "-i")&&strcmp(token, "-d")){
    //         args[i] = token;
    //         i++;
    //     }
    //     token = strtok(NULL, " ");
    // }
    // i =1;
    // char new[256];
    // strcpy(new,args[0]);
    // strcat(new, " ");
    // while(args[i] != NULL){
    //     printf("args:%s new:%s\n", args[i],new);
    //     strcat(new, args[i]);
    //     strcat(new," ");
    //     i = i+1; 
    // }
    // printf("new:%s\n", new);
    // int dit_check;
    // DIR* dir = opendir("main_shell.c");
    // if(dir == NULL){
    //     dit_check = 0;
    // }
    // else{
    //     dit_check = 1;
    // }
    // char* str = (char*)malloc(sizeof(char)*256);//rm -i file1 file2&t
    // fgets(str, sizeof(char)*256, stdin);
    // char* str1 = (char*)malloc(sizeof(char)*256);//str1 = str
    // strcpy(str1, str);
    // char* token = strtok(str, "\n");//str -\n
    // token = strtok(str, "&");  /// rm -i file1 file2, t
    // printf("token:%s\n", token);
    // char* str2 = (char*)malloc(sizeof(char)*256);//str2 = rm -i file1 file2
    // strcpy(str2, token);
    // printf("str2:%s\n", str2);
    // token = strtok(NULL, "&");//token = t
    // printf("token:%s\n", token);
    // if(token!=NULL && strcmp(token,"t")==0){
    //     printf("call to &t \t %s\n", str2);//threa exec
    // }
    // else{
    //     printf("%s\n", str1);//fork
    // }
    chdir("");
    printf("%s",getcwd(NULL, 0));
}
