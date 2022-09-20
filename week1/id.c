#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define BUFF_SIZE 100
#define FILE_NAME "users_data.txt"

int search(char *filename, char *user_name){

    FILE *users = fopen(filename, "a+");
    assert(users);

    int user_id = getuid();

//    printf("Hello! Enter your name:\n|-->")

    char current_name[BUFF_SIZE] = {};
    int current_id = 0;
    int result = 0;

    do{
        result = fscanf(users, "%s %d", current_name, &current_id);
        if(result != EOF){
//            printf("Scanned name, and id: %8.8s %-d\n", current_name, current_id);
            if(user_id == current_id){
//                printf("User has been found\n");
                strcpy(user_name, current_name);
                return 1;
            }
//                printf("Entered name doesn't match to current name\n");
        }
    }while(result != EOF);
    
    return 0;
}

int append(char *filename, char *user_name){
    FILE *users = fopen(filename, "a");
    assert(users);

    fprintf(users,"%s %d", user_name, getuid());
}

int main(){

char* username = calloc(BUFF_SIZE, sizeof(char));
int is_found = search(FILE_NAME, username);

if(is_found)
    printf("Hello %s!\n", username);
else{
    printf("What is your name?\n");
    scanf("%s", username);
    append(FILE_NAME, username);
    }
}
