//
//  stack.hpp
//  Stack
//
//  Created by XieHaoyang on 10/19/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

template <class Type>
class Stack {
private:
    enum { MAX = 10};
    Type items[MAX];
    int top;
    
public:
    Stack() { top = 0 ; }
    ~Stack() {}
    bool isEmpty() ;
    bool isFull();
    bool push( const Type & item);
    bool pop(Type & item);
};


template <class Type>
bool Stack<Type>::isEmpty() {
    return top == 0;
}
template <class Type>
bool Stack<Type>::isFull() {
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push( const Type & item) {
    if(top < MAX) {
        items[top++] = item;
        
        return true;
    }
    else
        return false;
    
}

template <class Type>
bool Stack<Type>::pop(Type & item) {
    if(top > 0) {
        item = items[--top];
        return true;
    }
    else
        return false;
}


#endif /* stack_hpp */
