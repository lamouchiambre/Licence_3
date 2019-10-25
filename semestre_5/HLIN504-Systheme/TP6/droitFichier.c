#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	struct stat etat;
	int i = lstat(argv[1], &etat);


  return 0;
}