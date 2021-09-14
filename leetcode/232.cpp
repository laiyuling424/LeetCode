//
// Created by 赖於领 on 2021/8/17.
//


#include <stack>
#include <iostream>

using namespace std;

/**
 *  用栈实现队列
    请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

    实现 MyQueue 类：
    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false

     说明：
    你只能使用标准的栈操作 —— 也就是只有push to top,peek/pop from top,size, 和is empty操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

    进阶：
    你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。

 */



class MyQueue {
private:
    void move_stack() {
        int size = stack_1.size();
        for (int i = 0; i < size; i++) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
    }

    void insert_stack() {
        int size = stack_2.size();
        for (int i = 0; i < size; i++) {
            stack_1.push(stack_2.top());
            stack_2.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    int size;
    stack<int> stack_1;
    stack<int> stack_2;

    MyQueue() {
        size = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (stack_2.empty()) {
            stack_1.push(x);
        } else {
            insert_stack();
            stack_1.push(x);
        }
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack_2.empty()) {
            move_stack();
        }
        int top = stack_2.top();
        stack_2.pop();
        size--;
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (stack_2.empty()) {
            move_stack();
        }
        return stack_2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//int main() {
//    MyQueue *myQueue = new MyQueue;
//    myQueue->push(1);
//    myQueue->push(2);
//    cout << myQueue->pop() << endl;
//    myQueue->push(3);
//    myQueue->push(4);
//    cout << myQueue->pop() << endl;
//    cout << myQueue->peek() << endl;
////    myQueue->push(5);
////    cout << myQueue->pop() << endl;
////    cout << myQueue->pop() << endl;
////    cout << myQueue->pop() << endl;
////    cout << myQueue->pop() << endl;
//    return 0;
//}