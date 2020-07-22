#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//예외처리를 위한 StackEmpty class를 추가하시오(add the "StackEmpty" class for exception process)

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
class STACK :public std::stack<T> // STACK 클래스가 STL stack을 상속받음
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
		//stack이 비었을때 정상종료를 위한 예외처리를 하고 pop한 결과를 리턴하는 기능을 추가하시오.
		//add the exception code for checking the empty stack.
		//if (empty()) throw StackEmpty("Pop from empty stack");
		//return mystack.stack<T>::pop(); //void를 리턴하고 있음
		try {
			if (mystack.empty()) throw StackEmpty("Stack is empty!");
			return mystack.stack<T>::pop();
		}
		catch (StackEmpty& obj) {
			cout << obj.getMessage() << endl;
			exit(1); // exit(1)이 없으면 실행중에 에러
		}
	}
	T& top() throw(StackEmpty)
	{
		//stack이 비었을때 정상종료를 위한 예외처리를 하시오.
		// add the exception code for checking the empty stack.
		if (mystack.empty()) throw StackEmpty("Pop from empty stack");
		return mystack.stack<T>::top();
		//try {
		//if (mystack.empty()) throw StackEmpty("Pop from empty stack");
		//return mystack.stack<T>::top();
		//}
		//catch (StackEmpty& obj) {
		//	cout << obj.getMessage() << endl;
			//exit(1); // exit(1)이 없으면 실행중에 에러가 발생해 버림..
		//}
	}
private:
	std::stack<T> mystack;
};

//bool ParenMatch(string exp) {
//	//개발한 STACK 자료구조를 이용하여 Problem 3을 실행할수 있는 괄호매칭 알고리즘을 개발하시오.
//	// implmention of parentheses matching algorithm for executing the Problem 3
//	stack<char> check_Stack;// 반드시 check_Stack을 이용하여 기능을 개발할것(must be use this "check_Stack" object, don't remove  it!!!)
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
//	stack<int> nStack; //스택생성
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
//	string info = "(강현지):(12163291)"; // 자기 정보를 입력할것, input your real name and student  ID
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