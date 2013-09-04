#include    <stdio.h>
#include    <object.h>
#include    <sys/inter.h>

#define balloc()  _push(NULL,0)

int main(void){
    char *buff;
    buff = balloc();
    char *msg = buff;
    char ch;
    printf("\ey$ \ew");
    do{
        ch = getchar();
        if(ch == '\n'){
            *msg = '\0';
            if(msg != buff){
                ObjectDesc o = run(FS_PID,OPEN,0,0,buff);
                if(o != ERROR){
                    run(o,READ,0,0,0);
                    run(MM_PID,15,0,0,0);
                }
            }
            msg = buff;
            printf("\ey$ \ew");
        }else{
            *msg++ = ch;
        }
    }while(ch != 'q');
    run(MM_PID,CLOSE,0,0,0);
    return 0;
}
