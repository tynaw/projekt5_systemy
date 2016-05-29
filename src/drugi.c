#ifndef HEAD
#define HEAD
#include "headers.h"
void second(key_t key);
#endif

#include <time.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    if(argc < 2){
        printf("Podaj klucz\n");
        return -1;
    }
    key_t key = *argv[1];
    second(key);
}

void second(key_t key){
    int msgflags = 0666;
    int i = 0, msqid = queue_access(key, msgflags);
    int flag = 0;
    message rec_msg;

    if (msgrcv(msqid, &rec_msg, MAXLEN, 0, 0) < 0) {
        perror("msgrcv");
    }
    time_t rawtime;
    struct tm * timeinfo;
    char bufor[4];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime(bufor,4,"%a",timeinfo);

    if( (strcmp(bufor,"Fri") == 0) || (strcmp(bufor,"Sat") == 0 ) || ( strcmp(bufor,"San") == 0 ) ){
        if(!isalpha(rec_msg.mes[0])){
            flag = 1;
        }
        for(i = 1; rec_msg.mes[i] != '\0'; i++) {
            if (!isascii(rec_msg.mes[i])) {
                flag = 1;
            }
        }
        if(flag == 0){
            printf("Wiadomosc jest poprawna\n");
            FILE *fp;
            if ((fp=fopen("data.txt", "w"))==NULL) {
                printf ("Nie mogę otworzyć pliku test.txt do zapisu!\n");
            }
            fprintf (fp, "%s", rec_msg.mes);
            fclose (fp);
            char choice;
            printf("Uruchomic aspell? [Y/N]");
            scanf("%c", &choice);
            if(choice == 'Y'){
                execlp("aspell", "aspell", "check", "data.txt", NULL);
            }
        }
        else{
            printf("Nie wszystkie znaki sa ASCII\n");
        }
    }
    else{
        printf("Teraz nie ma weekendu!\n");
    }
}
