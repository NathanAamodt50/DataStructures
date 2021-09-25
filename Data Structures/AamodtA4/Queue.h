#ifndef _QUEUE_H

const int STRING_SIZE = 10;
typedef char Element [ STRING_SIZE + 1];

class Queue {
public:
    Queue();
    Queue(Queue &);
    ~Queue();
    void enqueue( const Element);
    void dequeue( Element);
    void view();
private:
    struct QNode;
    typedef QNode * QNodePtr;
    struct QNode {
        Element element;
        QNodePtr next;
    };
    QNodePtr front, back;
};
#endif // _QUEUE_H
