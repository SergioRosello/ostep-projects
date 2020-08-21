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
int createBlocks(FILE*, struct Blocks*);
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
  struct Blocks* blocks = (struct Blocks*) malloc(sizeof(struct Blocks) * 10);
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
        block_num = createBlocks(file, blocks);
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

/*! \brief Creates blocks
 *
 *  Creates blocks from original file.
 *  Each block consists of a 4-byte binary integer
 *  and a char, to specify the character read
 *
 * \param FILE* file The file pointer to read data from
 * \param struct Blocks* Pointer to the list of blocks 
 * \return int numBlocks The number of blocks that have been created
 */
int createBlocks(FILE* file, struct Blocks* blocks){
  char buf, previous_buf;
  int occurence = 0, numBlocks = 0;

  int first = 1;
  while ((fread(&buf, sizeof(char), 1, file)) != 0){
    // TODO: Is it really necesary?  
    if(first == 1) {
      previous_buf = buf;
      first = 0;
    }
    if(buf != previous_buf){
      struct Blocks block;
      block.character = previous_buf;
      block.occurences = occurence;
      blocks[numBlocks] = block;
      numBlocks++;
      previous_buf = buf;
      occurence = 1;
    }else{ 
      occurence++;
    }
  }

  return numBlocks;
}

// Write blocks array until it has finished
void writeBlocks(struct Blocks* blocks, int block_num){
  //                      DATA                SIZE        COUNT             STREAM
  // fwrite(const void *restrict __ptr, size_t __size, size_t __n, FILE *restrict __s)
//  if (fwrite(&blocks, BLOCK_SIZE, block_num, stdout) != block_num){
//    perror("Error writing");
//  }
  
  for (int i = 0; i < block_num; ++i) {
    printf("%d%c", blocks[i].occurences, blocks[i].character);
  }
}
