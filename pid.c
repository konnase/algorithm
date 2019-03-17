//
// Created by 李青坪 on 2019/3/1.
//

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE  (1024 * 1024)

static char child_stacks[STACK_SIZE];
char* const child_args[] = {
        "/bin/bash",
        NULL
};

int child_main (void* args) {
    printf("在子进程中\n");
    execv(child_args[0], child_args);
    return 1;
}

int main(){
    printf("程序开始：\n");
    int child_pid = clone(child_main, child_stacks + STACK_SIZE, SIGCHLD, NULL);
    waitpid(child_pid, NULL, 0);
    printf("已退出\n");
    return 0;
}