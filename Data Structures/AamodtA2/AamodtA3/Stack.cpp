#include <iostream>
#include <iomanip>
#include <cstring>
#include  "Stack.h"
using namespace std;

/************************************************************************
*** FUNCTION    : Stack                                               ***
*************************************************************************
*** DESCIPTION  : This function will Create and initalizes a new stack***
***             :                                                     ***
*** INPUT ARGS  : N/A                                                 ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
Stack::Stack():STACK_SIZE(2)
{
    top = 0;
    stackArray = NULL;
    stackArray = new (std::nothrow) Element[STACK_SIZE] {0};
    if(!stackArray)
    {
        std::cout << "ERROR: Counld not allocate memory for new Stack" << std::endl;
    }
}
/************************************************************************
*** FUNCTION    : Stack(const int size)                               ***
*************************************************************************
*** DESCIPTION  : This function will create a new stack with the size ***
***             :  being what the user inputs                         ***
*** INPUT ARGS  : size, STACK_SIZE                                    ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
Stack::Stack(const int size) : STACK_SIZE(size)
{
    top = 0;

    stackArray = NULL;
    stackArray = new (std::nothrow) Element[STACK_SIZE] {0};

    if(!stackArray)
    {
        std::cout << "ERROR: Counld not allocate memory for new Stack" << std::endl;
    }
}
/************************************************************************
*** FUNCTION    : Stack (Stack &)                                              ***
*************************************************************************
*** DESCIPTION  : This function will copy a stack in the program      ***
***             :                                                     ***
*** INPUT ARGS  : Stack &                                             ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
Stack::Stack(Stack &copy) : STACK_SIZE(copy.STACK_SIZE)
{
    Stack temp(STACK_SIZE);
    Element t = 0;

    top = 0;

    stackArray = NULL;
    stackArray = new (std::nothrow) Element[STACK_SIZE] {0};

    if(!stackArray)
    {
        std::cout << "ERROR: Counld not allocate memory for new Stack" << std::endl;
    }

    while(copy.top > 0)
    {
        t = copy.pop();

        temp.push(t);
    }

    while(temp.top > 0)
    {
        t = temp.pop();

        copy.push(t);
        push(t);
    }
}

/************************************************************************
*** FUNCTION    : ~Stack                                              ***
*************************************************************************
*** DESCIPTION  : This function will Destroy a existing stack         ***
***             :                                                     ***
*** INPUT ARGS  : N/A                                                 ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
Stack::~Stack()
{
stackArray = NULL;
 delete [] stackArray;
}
/************************************************************************
*** FUNCTION    : void push                                           ***
*************************************************************************
*** DESCIPTION  : This function will take the stack and push a new    ***
***             : value to the top of the stack unless its full       ***
*** INPUT ARGS  : const Element e                                     ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
void Stack::push(const Element e)
{
    if (top+1 >= STACK_SIZE)
    {
        cout << "Overflow. Stack full please pop or view array."<<endl;
    }
    else
    {
        stackArray[top] = e;
        top++;
    }
}
/************************************************************************
*** FUNCTION    : Element pop                                         ***
*************************************************************************
*** DESCIPTION  : This function will pop the top value of the stack   ***
***             :  and take it off the stack                          ***
*** INPUT ARGS  : N/A                                                 ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : Element e                                           ***
************************************************************************/
Element Stack::pop()
{
    Element e = 0;
    if (top <= 0)
    {
        cout << "Stack is empty. Cannot pop."<<endl;
    }
    else
    {
        e = stackArray[top];
        top--;
    }
    return e;
}
/************************************************************************
*** FUNCTION    : Element peek                                        ***
*************************************************************************
*** DESCIPTION  : This function will show the top value of the stack  ***
***             : as long as the stack is not empty and return the top***
***             : value                                               ***
*** INPUT ARGS  : N/A                                                 ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
Element Stack::peek()
{
    Element out = 0;

    if(top <= 0)
    {
        std::cout << "Empty stack, cannot peek" << std::endl;
    }
    else
    {
        out = pop();
        push(out);
    }

    return stackArray[top];
}
/************************************************************************
*** FUNCTION    : void View                                           ***
*************************************************************************
*** DESCIPTION  : This function will show the whole stack that is     ***
***             : stored in stackArray                                ***
*** INPUT ARGS  : N/A                                                 ***
*** OUTPUT ARGS : N/A                                                 ***
*** IN/OUT ARGS : N/A                                                 ***
*** RETRUN      : N/A                                                 ***
************************************************************************/
void Stack::view()
{
    Stack temp(STACK_SIZE);
    Element t;

    if(top == 0)
    {
        std::cout << "TOP -> BOTTOM" << std::endl;
    }
    else
    {
        std::cout << "TOP -> ";

        while(top > 0)
        {
            t = pop();
            std::cout << t << " -> ";
            temp.push(t);
        }

        std::cout << "BOTTOM" << std::endl;

        while(temp.top > 0)
        {
            push(temp.pop());
        }
    }

    temp.~Stack();
}
