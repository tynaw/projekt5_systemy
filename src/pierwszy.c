#ifndef HEAD
#define HEAD
#include "headers.h"
void first(key_t key);
#endif


int main(int argc, char * argv[]){
	
    if(argc < 2){
        printf("Podaj klucz\n");
        return -1;
    }
    
    key_t key = *argv[1];
    first(key);
}

void first(key_t key){
	
    int i = 0, c, msgflags = IPC_CREAT | 0660;
    int msqid = queue_access(key, msgflags);
    
    message send_msg;
    size_t msg_len; //rozmiar wiadomosci
    char*buffer = (char*)malloc(MAXLEN*sizeof(char));
    send_msg.mtype = 1; //typ wiadomosci
    printf("Wpisz wiadomosc, wpisz \"enter\" aby zakonczyc: ");
    
    while( (c = getchar()) != '\n'){
        buffer[i] = c;
        i++;
    }
    
    strcpy(send_msg.mes, buffer);
    msg_len = strlen(send_msg.mes) + 1;
    
    if (msgsnd(msqid, &send_msg, msg_len, IPC_NOWAIT) < 0) {
        printf ("%d, %ld, %s, %zu\n", msqid, send_msg.mtype, send_msg.mes, msg_len);
        perror("msgsnd");
    }
    else
        printf("Wiadomosc: \"%s\" wyslana\n", send_msg.mes);
    free(buffer);
}
