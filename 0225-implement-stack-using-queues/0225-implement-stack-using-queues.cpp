#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int topElement;

    void push(int x) {
        q1.push(x);
        topElement = x;
    }

    int top() {
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }

    int pop() {
        if (q1.empty()) {
            return -1;
        }

        while (q1.size() > 1) {
            topElement = q1.front();
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q1.pop();

        swap(q1, q2);

        return val;
    }
};
