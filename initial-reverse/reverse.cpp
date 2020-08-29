#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace::std;

struct ErrorCodes{
  string TOOMANYIMPUTS = "usage: reverse <input> <output>";
}Errors;


void write(){
}

class Reverser
{
  public:
    Reverser();
    Reverser(char* input);
    Reverser(char* input, char* output);
    void reverse();
    ~Reverser();

  protected:
    Stack<string> stack;

  private:
    char* input;
    char* output;
};

Reverser::Reverser(char* input, char* output){
  this->input = input;
  this->output = output;
}

void Reverser::reverse(){
  ifstream inputFile(this->input);
  ofstream outputFile(this->output);
  string line;
  if(inputFile.is_open()){
    while(getline(inputFile, line)){
      stack.Push(line);
    }
    inputFile.close();
  }else{
    cout << "Unable to open file\n";
  }
  if(outputFile.is_open()){
    while(!stack.isEmpty()){
      outputFile << stack.Pop();
      outputFile << endl;
    }
  }
}

Reverser::~Reverser(){
  delete this;
}

