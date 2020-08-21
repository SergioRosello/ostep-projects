#include <stdlib.h>
// For fwrite
#include <stdio.h>
// Compress a file given as a parameter
// with run-length encoding (RLE)
// each entry will have 5 bytes
// 4 bytes for the binary occurences of
// the character and the 5th byte for
// the character that has ocurred X times
// aaaaaaaaaabbbb -> 10a4b

// The size of each individual block
#define BLOCK_SIZE 5

struct Blocks{
  // Number (Binary) of occurences
  unsigned int occurences;
  // Character that has occured number times
  char character;
};

// Create a array of blocks to be
// written to standard output.
struct Blocks* createBlocks(FILE*);
// Write to standard output
// as many blocks as we have created
void writeBlocks(struct Blocks*, int);
// Open a file and return its
// pointer
FILE* openFile(char*);


int main(int argc, char *argv[])
{
  FILE* file;
  // Array of blocks
  struct Blocks* blocks = NULL;
  int block_num = 0;

  switch (argc) {
    case 0:
      printf("Error\n");
      break;
    case 1:
      printf("wzip: file1 [file2 ...]\n");
      break;
    default:
      for (int i = 1; i < argc; ++i) {
        if( !(file = openFile(argv[i]))) return 1;
        createBlocks(file);
        writeBlocks(blocks, block_num);
        fclose(file);
      }
  }
  return 0;
}

FILE* openFile(char* fileName){
  FILE* p_file;
  if (!(p_file = fopen(fileName, "rb"))) {
    perror("Error reading file");
  }
  return p_file;
}

// TODO: BLOCK_NUM has to be calculated here.
// As we create the blocks, we have to increase block_num
struct Blocks* createBlocks(FILE* file){
  printf("Buenas!\n");
  char buf, previous_buf;
  struct Blocks block;
  block.occurences = 0;
  while ((fread(&buf, sizeof(char), 1, file)) != 0) {
    printf("%c", buf);
    if (buf == previous_buf) {
      block.occurences++;
      //TODO This can be optimized to be set once characters differ.
      block.character = buf;
    } else {
      previous_buf = buf;
    }
    
  }
  struct Blocks* blocks = (struct Blocks*) malloc(sizeof(struct Blocks) * 1);
  return blocks;
}

// Write blocks array until it has finished
void writeBlocks(struct Blocks* block, int block_num){
  //                      DATA                SIZE        COUNT             STREAM
  // fwrite(const void *restrict __ptr, size_t __size, size_t __n, FILE *restrict __s)
  if (fwrite(&block, BLOCK_SIZE, block_num, stdout) != block_num){
    perror("Error writing");
  }
}
