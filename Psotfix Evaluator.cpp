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
        stack = new Stack();
        stack->Top = -1;
        stack->Capacity = cap;
        stack->Array = new char[cap];
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
// The main function that returns value of a given postfix expression 
int evaluatePostfix(string exp) 
{ 
	Stack_Operations st;
	// Create a stack of capacity equal to expression size 
	st.Creat_Stack(exp.length()); 
	int i; 

	// Scan all characters one by one 
	for (i = 0; i < exp.length(); ++i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack. 
		if (isdigit(exp[i]))
		{
			st.push(exp[i] - '0'); 
	    }

		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = st.pop(); 
			int val2 = st.pop(); 
			switch (exp[i]) 
			{ 
			case '+': 
				st.push(val2 + val1); 
				break; 
			case '-': 
				st.push(val2 - val1);
				break; 
			case '*': 
				st.push(val2 * val1);
				break; 
			case '/': 
				st.push(val2/val1);
				break; 
			} 
		} 
	} 
	return st.pop(); 
} 

// Driver program to test above functions 
int main() 
{ 
	string exp = "456*+"; 
	cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
	return 0; 
}
