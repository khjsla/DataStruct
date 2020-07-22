//������ 12163291
#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <exception>

using namespace std;

//����ó���� ���� StackEmpty class�� �߰��Ͻÿ�(add the "StackEmpty" class for exception process

class RuntimeException { //����ó�� Ŭ����
private:
	string errMsg;
public:
	RuntimeException(const string& err) {
		errMsg = err;
	}
	string getMsg() const {
		return errMsg;
	}
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException &e) {
	return cout << e.getMsg();
}

class StackEmpty: public RuntimeException { //����ó�� Ŭ����
public:
	StackEmpty(const string& err)  :RuntimeException(err){
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
	T& pop() throw(StackEmpty) {
		//stack�� ������� �������Ḧ ���� ����ó���� �ϰ� pop�� ����� �����ϴ� ����� �߰��Ͻÿ�.
		//add the exception code for checking the empty stack.
	
		try {
			if (mystack.empty()) throw StackEmpty("pop from empty stack");
			//������ ��� ����Ŭ������ ó���� ���ݴϴ�.
			else {
				T& out = mystack.top;
				mystack.pop;
				return out;
			}
			//�Ⱥ������ pop���ݴϴ�.
		}
		catch (StackEmpty& obj) {
			//���� ó�� �ϴ� �κ��Դϴ�.
			cout << obj.errMsg << endl;
			exit(1);
		}
	}

	T& top() throw(StackEmpty) {
		//stack�� ������� �������Ḧ ���� ����ó���� �Ͻÿ�.
		// add the exception code for checking the empty stack.
		try {
			if (mystack.empty()) throw StackEmpty("top from empty stack");
			//������ ��� ����Ŭ������ ó���� ���ݴϴ�.
			else return mystack.top();
			//�Ⱥ������ pop���ݴϴ�.
		}
		catch (StackEmpty& obj) {
			//���� ó�� �ϴ� �κ��Դϴ�.
			cout << obj.errMsg << endl;
			exit(1);
		}
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
//	for (int i = 0; i < exp.length(); i++)
//	{
//		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
//		{
//			check_Stack.push(exp[i]);
//			continue;
//		}
//
//		if (check_Stack.empty())
//			return false;
//
//		switch (exp[i])
//		{
//		case ')':
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '{' || x == '[')
//				return false;
//			break;
//
//		case '}':
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '(' || x == '[')
//				return false;
//			break;
//
//		case ']':
//			x = check_Stack.top();
//			check_Stack.pop();
//			if (x == '(' || x == '{')
//				return false;
//			break;
//		}
//	}
//
//	return (check_Stack.empty());
//}

int Problem1()
{
	stack<int> nStack; //���û���
	nStack.push(1);
	//printf("%d\n", nStack.pop);
	//printf("%d\n", nStack.pop);
	return 0;

}

int Problem2()
{
	stack<int> nStack;
	nStack.top();
	return 0;
}

//
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