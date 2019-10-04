#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    if( argc != 3){
        perror("nombre de parametre inccorect");
        return -1;
    }
    int f = open(argv[1], O_RDONLY);
    if (f == -1)
    {
        perror("le fichier est inexitant ou vide");
        return -1;
    }
    char rechercher = argv[2][0];
    int deb = 0;
    int fin = lseek(f, 0, SEEK_END);;
    int mil;
    char c;
    lseek(f, 0, SEEK_SET);

    do
    {
        mil = (fin + deb)/2;
        lseek(f, mil, SEEK_SET);
        read(f,&c, 1);
        printf("%c = %c\n", c, rechercher);
        if (c > rechercher){ 
            fin = mil - 1;}
        else
        {
            if (c < rechercher)
            {
                deb = mil +1;
            }
        }
        
    } while (c != rechercher && deb <= fin);
    if (c == rechercher)
    {
        printf("youpi\n");
    }
    else
    {
        printf("flut\n");
    }
    
    
    

    


    return 0;
}
