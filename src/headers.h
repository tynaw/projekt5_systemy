#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

typedef struct message{
    char mes[MAXLEN];
    long mtype;
}message;


int queue_access(key_t keyval, int msg_flags){
    int msqid;
    if( (msqid = msgget(keyval, msg_flags) == -1) ){
        perror("msgget");
        return -1;
    }
    return msqid;
}





