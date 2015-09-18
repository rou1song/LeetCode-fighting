/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
*/

class Queue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (st2.empty()) {
            int length = st1.size();
            for (int i = 0; i < length; i++) {
                int peek = st1.top();
                st1.pop();
                st2.push(peek);
            }
        }
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (st2.empty()) {
            int length = st1.size();
            for (int i = 0; i < length; i++) {
                int peek = st1.top();
                st1.pop();
                st2.push(peek);
            }
        }
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (st1.size() + st2.size() == 0)
            return true;
        else
            return false;
      //return st1.empty() && st2.empty();
    }
};
