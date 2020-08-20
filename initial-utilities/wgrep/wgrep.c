#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void checkExists(FILE* , char* );
void searchInFiles(int, char**);
void searchInStdImput(char*);

int main(int argc, char *argv[])
{
  switch (argc) {
    case 0:
      exit(1);
      break;
    case 1:
      // Control, to make sure user knows how to use
      // wgrep
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
      break;
    case 2:
      // Get text/line grom standard input
      searchInStdImput(argv[1]);
      break;
    default:
      searchInFiles(argc, argv);
      break;
  }
  return 0;
}

//TODO: Finish standard input implementation
void searchInStdImput(char* term){
  char buf[100];
  char* match;
  while (fread(buf, strlen(term), 1, stdin) != 0) { // Read the data from input
  // Do something with data stored in buffer
    if (( match = strstr(buf, term)) != NULL ) {
      printf("\033[1;31m");
      printf("%s", term);
      printf("\033[0m;");
    }
  }
}

// Function that searches for occurences of a string in subsequent
// lines of the files passed in as parameters
void searchInFiles(int fileNumber, char** files){
  // Get the first parameter.
  // This is the string we have to look for
  // in the files passed thereafter
  char* search = files[1];

  // Start at 2 beause the first term (0) is the
  // program name and the second term (1) is the
  // word we are going to look for
  for (int i = 2; i < fileNumber; ++i) {
    FILE* file;
    // Open file
    if( (file = fopen(files[i], "r")) == NULL ){
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    // For every line in the file,
    // Search for word
    checkExists(file, search);

    if( fclose(file) == -1 ){
      perror("Error closing file");
    }
  }
}

void checkExists(FILE* file, char* search){
    char* line, *match;
    size_t N = 0;
    ssize_t gl;
    int lineNumber = 0;
    while ( (gl = getline(&line, &N, file)) > 0 ) {
      if (gl == -1) {
        printf("Error reading file\n");
      } else {
        lineNumber++;
        //Perform search function
        if (( match = strstr(line, search)) != NULL ) {
          printf("\033[1;31m");
          printf("%d: %s", lineNumber, line);
          printf("\033[0m;");
        }
      }
    }
}
