// copy.c --------------
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 struct stat buf;

  umask(0);
    
    printf("%d\n", argc);
   if (argc != 3)
        perror("usage: a.out ");

    printf("copy: %s %s ", argv[1], argv[2]);
    if (stat(argv[1], &buf) < 0) {
        perror("stat error");
    }
    printf("source mode [%o]\n", buf.st_mode);
    open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)
        return 1;
    
    struct stat buffer_one;
    int status_one;
    status_one = stat("a", &buffer_one);
    
    struct stat buffer_two;
    int status_two;
    status_two = stat("b", &buffer_two);
    
    if(buffer_one.st_mode == buffer_two.st_mode){
        printf("File permissions are equal");
    } else{
        printf("Failed!");
    }

}
