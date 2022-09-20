#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000
#define CHILDREN_COUNT 3

int main(){
    
    int pipefd[2] = {};
    pipe(pipefd);
    int fork_return = fork();

    if(fork_return > 0){
        int messages_count = 0;
        char* buf = calloc(BUF_SIZE, sizeof(char));
        while(messages_count < 3){
            read(pipefd[0], buf, BUF_SIZE);
//----------Debug Output----------
/*            printf("Data from pipe: %s\n", buf);
            printf("Messages received: %d\n", messages_count);
            printf("First symbol: %c\n", buf[0]);
*/
//--------------------------------            
            switch (buf[0]){
            case '1' :
                printf("#1 Child said: %s\n", buf + 1);
                messages_count++;
                break;
            case '2' :
                printf("#2 Child said: %s\n", buf + 1);
                messages_count++;
                break;
            case '3' :
                printf("#3 Child said: %s\n", buf + 1);
                messages_count++;
                break;
            }

        }
    
    }else if(fork_return == 0){
            write(pipefd[1], "1Hey!", BUF_SIZE);    
            int fork_return_2 = fork();
            if(fork_return_2 == 0){
                write(pipefd[1], "2What's up!", BUF_SIZE);    
                int fork_return_3 = fork();
                if(fork_return_3 == 0){
                    write(pipefd[1], "3Hello!", BUF_SIZE);    
                } 
            }
                
            
    }else{
        printf("CAN'T FORK THE PROCESS!!!");
    }
    
    return 0;
}
