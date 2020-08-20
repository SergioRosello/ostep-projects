// File I/O
#include <stdio.h>
#include <stdlib.h>
// For write
#include <unistd.h>
// This program is going to concatenate files and
// print them on the standard output

// Argc is the number of arguments the program has received
// argv is the arguments themselves
int main(int argc, char *argv[])
{
  // Handle arguments
  for (int i = 1; i < argc; i++) {
   // open files to concatenate in order of argv appearence
    FILE* file;
    char* line = NULL;
    size_t N = 0;
    if ( (file = fopen(argv[i], "r")) == NULL){
      perror("wcat: cannot open file\n");
      exit(1);
    }
   // read files to standard output.
   // fopen(), fgets(), and fclose().
   // instead of fgets, the info page recommends using getline
    while ( getline(&line, &N, file ) > 0){
      printf("%s", line);
    }
    fclose(file);
  }
  return 0;
}
