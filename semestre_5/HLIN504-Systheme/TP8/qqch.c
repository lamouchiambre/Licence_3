#include <stdio.h>
#include <unistd>

void cribe(int in[2]){
    close(in[1]);
    int P;
    if (0 != (P = read(in[0]))){
        printf("%d",P );
        int out[2]
        pipe(out);
        

    }
}

int main( int argc, char const *argv[]){

}