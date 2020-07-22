//// CPP program to check for balanced parenthesis. 
//#include<stack>
//#include<string>
//#include<iostream>
//using namespace std;
//
//// function to check if paranthesis are balanced 
//bool areParanthesisBalanced(string exp)
//{
//	stack<char> check_Stack;
//	char x;
//
//	// Traversing the Expression 
//	for (int i = 0; i < exp.length(); i++)
//	{
//		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
//		{
//			// Push the element in the stack 
//			check_Stack.push(exp[i]);
//			continue;
//		}
//
//		// IF current current character is not opening 
//		// bracket, then it must be closing. So stack 
//		// cannot be empty at this point. 
//		if (check_Stack.empty())
//			return false;
//
//		switch (exp[i])
//		{
//		case ')':
//
//			// Store the top element in a 
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '{' || x == '[')
//				return false;
//			break;
//
//		case '}':
//
//			// Store the top element in b 
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '(' || x == '[')
//				return false;
//			break;
//
//		case ']':
//
//			// Store the top element in c 
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '(' || x == '{')
//				return false;
//			break;
//		}
//	}
//
//	// Check Empty Stack 
//	return (check_Stack.empty());
//}
//
//// Driver program to test above function 
//int main()
//{
//	string expr;// = "{()}[]";
//	cin >> expr;
//
//	if (areParanthesisBalanced(expr))
//		cout << "Balanced";
//	else
//		cout << "Not Balanced";
//	return 0;
//}