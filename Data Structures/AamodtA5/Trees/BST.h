#pragma once

typedef char Key;
struct TNode;
typedef TNode *TNodePtr;
struct TNode {
    Key key;
    TNodePtr left,right;
};

class BST {
public:
    BST();
    BST(const BST &);
    ~BST();
    void insert( const Key);
    void remove( const Key);
    TNodePtr search( const Key) const;
    void preView() const;
    void inView() const;
    void postView() const;
private:
    TNodePtr root;
    void copy( TNodePtr &);
    void destroy( TNodePtr &);
    void removeNode( TNodePtr &);
    void findMinNode(TNodePtr &, TNodePtr &);
    void insert( const Key, TNodePtr &);
    void remove ( const Key, TNodePtr &);
    TNodePtr search( const Key, const TNodePtr ) const;
    void preView( const TNodePtr) const;
    void inView( const TNodePtr) const;
    void postView(const TNodePtr) const;
};
