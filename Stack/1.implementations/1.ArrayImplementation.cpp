#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int top;
    int maxSize;
    int *stackArray;

    public:
        Stack(int size)
        {
            top = -1;
            maxSize = size;
            stackArray = new int[maxSize];
        }
        void push(int x)
        {
            top++;
            if(top<maxSize)
                stackArray[top] = x;
            else
                cout << "Stack is full" << endl;
            return;
        }
        void pop(){
            if(top>=0)
                top--;
            else
                cout << "stack is empty already" << endl;
            return;
        }
        int topEl()
        {
            if(top>=0)
                return stackArray[top];
            else
                return -1;
        }
        void display()
        {
            for (int i = 0; i <= top;i++)
                cout << stackArray[i] << " ";
            cout << endl;
            return;
        }
};
int main()
{
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
}