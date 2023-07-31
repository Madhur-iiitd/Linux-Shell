all: ./main_shell
	gcc main_shell.c -o main_shell
	gcc mkdir.c -o mkdir
	gcc date.c -o date
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc cat.c -o cat
