#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	struct stat etat;
	int i = lstat(argv[1], &etat);
	if (i == 0) {
		printf("le fichier a pour inode : %ld ", etat.st_ino);
		if (S_ISREG(etat.st_mode)) {
			printf(" est c'est un fichier régulier\n");
		}
		if (S_ISDIR(etat.st_mode)) {
			printf(" est un répertoire\n");
		}
		if (S_ISLNK(etat.st_mode)) {
			printf(" est un lien symbolique\n");
		}
		else {
			printf("est un fichier d'un autre type\n");
		}
	}

  return 0;
}