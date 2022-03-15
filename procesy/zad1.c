#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void wypisz_identyfikatory(){
    printf("%d\n", getuid());
    printf("%d\n", getgid());
    printf("%d\n", getpid());
    printf("%d\n", getppid());
    printf("%d\n", getpgid(0));
}

int main()
{
   // wypisz_identyfikatory();

    for(int i = 0;i<3; i++){
        switch (fork()){
            case -1:
            perror("fork error");
            exit(1);
            case  0:
            // akcja dla procesu potomnego
            wypisz_identyfikatory();
            default:
            // akcja dla procesu macierzystego, np. wywolanie funkcji wait
            wait();
            wypisz_identyfikatory();
            };
    }

}
