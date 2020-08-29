#include "reverse.cpp"

int main(int argc, char *argv[])
{
  switch (argc) {
    case 1:
      // Read from standard input and write to standard output
      std::cout << "1 argument" << std::endl;
      break;
    case 2:
      std::cout << "2 argument" << std::endl;
      break;
      // read input from first file, write reversed to second file
    case 3:
      std::cout << "3 argument" << std::endl;
      Reverser *reverser = new Reverser(argv[1], argv[2]);
      reverser->reverse();
      break;
  }
  return 0;
}
