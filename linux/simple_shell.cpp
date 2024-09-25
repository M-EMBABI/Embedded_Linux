#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char input[1000];
    while (1)
    {
        std::cout<<"embabi_Shell$ ";
        fgets(input,100,stdin);
        if(input[0]=='\n'){
            continue;
        }
        //return the input and if \n is exist replace it with \0
        input[strcspn(input, "\n")]='\0';
        /* code */
        //0: If both strings are identical.
        
        if(strcmp(input,"exit")==0 || strcmp(input,"quit")==0){
            printf("exit shell\n");
            break;
        }
        char *command = strtok(input," ");//ls
        char *argument[10000];
        int arg_count = 0;
        while (command !=nullptr)
        {
            /* code */
            argument[arg_count++]=command;
            command = strtok(nullptr," ");
       }
        argument[arg_count]=nullptr; // Null terminate the argument list

        pid_t child_pid = fork();// Fork to create a new process
        if(child_pid == -1){
            std::cerr<<"FORK FAILD\n";
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0 ) {
            execvp(argument[0],argument);
            std::cerr<<"EXECUTION FAILD\n";
            exit(EXIT_FAILURE);
        }else {
            int status;
            waitpid(child_pid, nullptr,  0);
        }   
    }
}
