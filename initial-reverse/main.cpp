#include "reverse.cpp"

int main(int argc, char *argv[])
{
  Reverser *reverser;
  switch (argc) {
    case 1:
      // Read from standard input and write to standard output
      reverser = new Reverser();
      reverser->reverseInteractive();
      break;
      // Read from file and write to standard output
    case 2:
      reverser = new Reverser(argv[1]);
      reverser->reverseToSTDOUT();
      break;
      // read input from first file, write reversed to second file
    case 3:
      reverser = new Reverser(argv[1], argv[2]);
      reverser->reverseToFile();
      break;
  }
  return 0;
}
