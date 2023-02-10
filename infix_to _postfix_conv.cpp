//Write a C++ program to perform infix to postfix conversion using stack.
//murtuza kapasi

#include <iostream>
using namespace std;

class stack{
    public:
char store[20];
int top;
stack()
{
    top=-1;
}
int precedence(char x);
void push(char x);
char pop();
};

int stack::precedence(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
}

char stack::pop()
{
    if (top == -1)
        return -1;
    else
        return store[top--];
}

void stack::push(char x)
{
    store[++top] = x;
}

int main()
{   
    stack s;
    char exp[20];
    // exp->(2*3+4*(5-6));
    cout << "Enter expression: ";
    cin >> exp;
    char *e, x;
    e = exp;    
    while (*e != '\0')
    {
        if (isalnum(*e))
            cout << *e;
        else if (*e == ')')
        {
            while ((x = s.pop()) != '(')
                cout << x;
        }
        else if (*e == '(')
        {
            s.push('(');
        }
        else
        {
            if (s.precedence(*e) <= s.precedence(s.store[s.top]))
                cout <<s.pop();
            s.push(*e);
        }
        e++;
    }
    while (s.top != -1)
        cout << s.pop();
    return 0;
}
