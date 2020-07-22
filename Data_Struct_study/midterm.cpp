#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//����ó���� ���� StackEmpty class�� �߰��Ͻÿ�(add the "StackEmpty" class for exception process)

//class RuntimeException {
//private:
//	string errMsg;
//public:
//	RuntimeException(const string& err) : errMsg(err) {
//	}
//	string getMessage() const {
//		return errMsg;
//	}
//};

class StackEmpty :public runtime_error {
public:
	StackEmpty(const string& err) : runtime_error(err) {
	}
};

template <typename T >
class STACK :public std::stack<T> // STACK Ŭ������ STL stack�� ��ӹ���
{
public:
	bool empty()
	{
		return mystack.empty();
	}
	int size()
	{
		return mystack.size();
	}
	void push(T elem)
	{
		mystack.push(elem);
	}
	T& pop() throw(StackEmpty)
	{
		//stack�� ������� �������Ḧ ���� ����ó���� �ϰ� pop�� ����� �����ϴ� ����� �߰��Ͻÿ�.
		//add the exception code for checking the empty stack.
		//if (empty()) throw StackEmpty("Pop from empty stack");
		//return mystack.stack<T>::pop(); //void�� �����ϰ� ����
		try {
			if (mystack.empty()) throw StackEmpty("Stack is empty!");
			return mystack.stack<T>::pop();
		}
		catch (StackEmpty& obj) {
			cout << obj.getMessage() << endl;
			exit(1); // exit(1)�� ������ �����߿� ����
		}
	}
	T& top() throw(StackEmpty)
	{
		//stack�� ������� �������Ḧ ���� ����ó���� �Ͻÿ�.
		// add the exception code for checking the empty stack.
		if (mystack.empty()) throw StackEmpty("Pop from empty stack");
		return mystack.stack<T>::top();
		//try {
		//if (mystack.empty()) throw StackEmpty("Pop from empty stack");
		//return mystack.stack<T>::top();
		//}
		//catch (StackEmpty& obj) {
		//	cout << obj.getMessage() << endl;
			//exit(1); // exit(1)�� ������ �����߿� ������ �߻��� ����..
		//}
	}
private:
	std::stack<T> mystack;
};

//bool ParenMatch(string exp) {
//	//������ STACK �ڷᱸ���� �̿��Ͽ� Problem 3�� �����Ҽ� �ִ� ��ȣ��Ī �˰����� �����Ͻÿ�.
//	// implmention of parentheses matching algorithm for executing the Problem 3
//	stack<char> check_Stack;// �ݵ�� check_Stack�� �̿��Ͽ� ����� �����Ұ�(must be use this "check_Stack" object, don't remove  it!!!)
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

//int Problem1()
//{
//	stack<int> nStack; //���û���
//	nStack.push(1);
//	cout << nStack.top() << endl;
//	//cout << nStack.pop() << endl;
//	return 0;
//
//}
int Problem2()
{
	stack<int> nStack;
	nStack.top();
	return 0;

}

//int Problem3()
//{
//	stack<string> strStack;
//	string info = "(������):(12163291)"; // �ڱ� ������ �Է��Ұ�, input your real name and student  ID
//
//	strStack.push("( )(()){([(ice2004)])}");
//	strStack.push("((( )ice2004(( )){([( )])}");
//	strStack.push(")(( )){([( )])}");
//	strStack.push("({[ ])}");
//	strStack.push("(ice2004");
//	strStack.push(info);
//
//
//	int n = strStack.size();
//	for (int i = 0; i < n; i++)
//	{
//		cout << strStack.top();
//		if (ParenMatch(strStack.top()) == 1)
//		{
//			cout << ": correct" << endl;
//		}
//		else {
//			cout << ": incorrect" << endl;
//		}
//		strStack.pop();
//	}
//	strStack.pop();
//
//	system("pause");
//	return 0;
//}

int main()
{
	//Problem1();
	Problem2();
	//Problem3(); //ok
	return 0;
}