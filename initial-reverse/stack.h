#ifndef __StackClassH__
#define __StackClassH__

#include <assert.h>

template<class Elem> 
class Stack
{
  public:
    Stack(int MaxSize=500);
    Stack(const Stack<Elem> &OtherStack);
    ~Stack(void);
    // Adds elem to the top
    inline void Push(const Elem &item);
    inline Elem Pop(void);
    inline const Elem &Peek(const int depth) const;
    inline const bool isEmpty();

  protected:
    Elem *Data;
    int CurrElemNum;
    const int MAX_NUM;
};

template<class Elem>
inline const bool Stack<Elem>::isEmpty(void){
  return (CurrElemNum == 0) ? true : false;
}

template<class Elem>
Stack<Elem>::Stack(int MaxSize) : MAX_NUM(MaxSize)
{
  Data = new Elem[MAX_NUM];
  CurrElemNum = 0;
}

template<class Elem>
Stack<Elem>::~Stack<Elem>(void){
  delete [] Data;
}

template <class Elem>
inline void Stack<Elem>::Push(const Elem &Item){
  assert(CurrElemNum < MAX_NUM);
  Data[CurrElemNum++] = Item;
}

template<class Elem>
inline Elem Stack<Elem>::Pop(void){
  // Error Check: Make sure we aren't popping from an empty Stack
  assert(CurrElemNum > 0);

  return Data[--CurrElemNum];
}

template<class Elem>
inline const Elem &Stack<Elem>::Peek(int Depth) const{

  assert(Depth < CurrElemNum);

  return Data[ CurrElemNum - (Depth + 1) ];

}

#endif /*__StackClassH__*/
