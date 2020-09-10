#include <iostream>
using namespace std;
class Stack
{
public:
    int Capacity;
    int Top;
    char *Array;
};
class Stack_Operations
{
public:
    Stack *stack;
    Stack_Operations()
    {
        stack = NULL;
    }
    void Creat_Stack(int cap)
    {
        stack = (Stack *)malloc(sizeof(Stack));
        stack->Top = -1;
        stack->Capacity = cap;
        stack->Array = (char *)malloc(sizeof(1) * cap);
    }
    int isFull()
    {

        if (stack->Top == stack->Capacity - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isEmpty()
    {
        if (stack->Top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int Peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        return stack->Array[stack->Top];
    }
    int push(char val)
    {
        if (!isFull())
        {
            stack->Top = stack->Top + 1;
            stack->Array[stack->Top] = val;
            return 1;
        }
        else
        {
            cout << "Stack is Full\n";
            return 0;
        }
    }
    int pop()
    {
        int itm;
        if (!isEmpty())
        {
            itm = stack->Array[stack->Top];
            stack->Top = stack->Top - 1;
            return itm;
        }
        return -1;
    }
};
class Infix_To_Prefix
{
public:
    Stack_Operations St;
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    void infixToPostfix(string s)
    {
        St.Creat_Stack(50);
        St.push('(');
        int size = s.length();
        string NS;
        for (int i = 0; i < size; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                NS += s[i];
            }
            else if (s[i] == '(')
            {
                St.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (St.Peek() != '(' && St.Peek() != ')')
                {
                    char c = St.Peek();
                    St.pop();
                    NS += c;
                }
                if (St.Peek() == '(')
                {
                    St.pop();
                }
            }
            else
            {
                while (St.Peek() != ')' && prec(s[i]) <= prec(St.Peek()))
                {
                    char c = St.Peek();
                    St.pop();
                    NS += c;
                }
                St.push(s[i]);
            }
        }
        while (St.Peek() != '(')
        {
            char c = St.Peek();
            St.pop();
            NS += c;
        }

        cout <<"The Result is = "<< NS << endl;
    }
};
int main()
{
    system("CLS");
    system("color 04");
    Infix_To_Prefix Obj;
    string exp = "A+((B+C)+(D+E)*F)/G";
    Obj.infixToPostfix(exp);
    return 0;
}