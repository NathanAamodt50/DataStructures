#ifndef _STACK_H
#define _STACK_H

typedef double Element;

class Stack {
public:
    Stack();
    Stack( const int);
    Stack( Stack &);
    ~Stack();
    void push(const Element);
    Element pop();
    Element peek();
    void view();
private:
    const int STACK_SIZE;
    Element * stackArray;
    int top;
};
#endif
