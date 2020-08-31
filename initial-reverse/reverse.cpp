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
    void reverseToFile();
    void reverseToSTDOUT();
    void reverseInteractive();
    ~Reverser();

  protected:
    Stack<string> stack;

  private:
    char* input;
    char* output;
};

Reverser::Reverser(){
}
Reverser::Reverser(char* input){
  this->input = input;
}
Reverser::Reverser(char* input, char* output){
  this->input = input;
  this->output = output;
}

void Reverser::reverseInteractive(){
  string line;
  while(getline(cin, line)){
    stack.Push(line);
    while(!stack.isEmpty()){
      cout << stack.Pop() << endl;
    }
  }
}

void Reverser::reverseToSTDOUT(){
  ifstream inputFile(this->input);
  string line;
  if(inputFile.is_open()){
    while(getline(inputFile, line)){
      stack.Push(line);
    }
    inputFile.close();
  }else{
    cout << "Unable to open file\n";
  }
  while(!stack.isEmpty()){
    cout << stack.Pop() << endl ;
  }
}

void Reverser::reverseToFile(){
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
      outputFile << stack.Pop() << endl;
    }
  }
}

Reverser::~Reverser(){
  delete this;
}

