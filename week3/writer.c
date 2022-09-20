#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd = open("writer.txt", O_WRONLY | O_CREAT);
    char* buf = "Text was written!\n";
    write(fd, "Text was written!\n", strlen(buf));
}
