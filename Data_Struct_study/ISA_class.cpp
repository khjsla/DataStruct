//#pragma warning(disable:4996)
//
//#include <iostream>
//using namespace std;
//
//class Shape { //부모 Base Class
//private: 
//	int price;
//protected:
//	double x, y;
//public:
//	char *owner;
//	Shape(const Shape &s) {
//	} //자기주소 카피
//	Shape(int don = 0, double x = 0, double y = 0, const char *s = "you") {
//		cout << "Shape의 default constructor" << endl;
//		price = don;
//		this->x = x;
//		this->y = y;
//		owner = new char[strlen(s) + 1]; //! 오너 딜리트 해줘야함, new를 사용했으므로
//		strcpy(owner, s);
//	} //초기값 생성자 //여기에 cout문 있어야 출력값이 나옴
//	virtual ~Shape() { //소멸자 virtual시키니 아주 깔끔해졌음
//		cout << "Shape의 default destructor" << endl;
//		delete owner; //!! //오너 - new delete해줌.
//	}
//
//	void setXY(int _x, int _y);
//	void showPrice() const; //얘는 const 함수로 const 로 선언된 클래스 객체에서도 사용가능한 함수이다.
//
//	virtual double getArea() = 0; //pure virtual 이 되었어요, 딱히 어떤 구현이 필요하지 않기 때문이에요
//		//virtual 키워드로 클래스의 다형성을 구현했어요.
//		//이제 shape는 가상 클래스가 되었고, 실 obj생성 ( shape s; ) 이 불가능해졌어요.
//		//이제는 shape *s = new .. 와 같이 포인터로만 선언이 가능하답니다.
//	//자식클래스에서 꼭 내용을 정의해줘야해요.
//	//Shape의 소멸자에도 virtual 키워드를 붙여줘야 memory leak을 방지 할 수 있어요
//	//이제 getArea() 함수는 dynamic binding이 되게 된답니다.
//};
//
////여기부터 생성된 함수들 대체모임../
//
//void Shape::setXY(int _x, int _y) {
//	x = _x; 
//	y = _y;
//}
//
//void Shape::showPrice() const {
//	printf("%d\n", price);
//}
////얘는 const 함수로 const 로 선언된 클래스 객체에서도 사용가능한 함수이다.
//
//class Circle :public Shape{ //Shape를 상속받은 자식 Drived 클래스
//	double radius;
//	char *name;
//public:
//	Circle(double r = 0):Shape(1,2,3,"circle") { //Shape의 초기값 생성자에 값 넣어
//		cout << "Circle의 default constructor" << endl; //for 생성, 소멸자 do 순서 확인
//
//		name = new char[strlen("test") + 1]; //! 네임 딜리트 해줘야함, new를 사용했으므로
//		strcpy(owner, "test");
//
//		radius = r;
//		//x = 10; //protected라 자식에서 부모(Shape)의 인자에 접근 가능해졌음
//		//y = 20;
//	}
//	~Circle() { //얘가 안불리고 있으므로, 부모 소멸자또한 virtual화 해주어야한다.
//		cout << "Circle의 default destructor" << endl;//for 생성, 소멸자 do 순서 확인
//		delete name; //!
//	}
//
//	double getArea() {
//		return radius * radius*3.14;
//	}
//};
//
//class Rectangle :public Shape {
//	double width, height;
//public:
//	Rectangle(double w = 1,double h=1) {
//		cout << "Rectangle의 default constructor" << endl;//for 생성, 소멸자 do 순서 확인
//		width = w;
//		height = h;
//	}
//	~Rectangle() {
//		cout << "Rectangle의 default destructor" << endl;//for 생성, 소멸자 do 순서 확인
//	}
//
//	double getArea() {
//		return width * height*3.14;
//	}
//};
//
//int main() {
//	//성성자 소멸차 생성순서 ////////////////////////////////////////////////////////
///*	Circle c;
//	Rectangle r;
//*/
//
//	//함수 사용 가능 확인  ////////////////////////////////////////////////////////
///*	Shape * shp = new Circle; //상속관계이므로, 부모에 자식 대입은 가능
//	Circle * c = new Circle;
//
//	shp->showPrice(); //자기(Shpae)의 함수이니까 사용가능 당연히
//	c->showPrice();  //shape 상속받았으므로 사용가능
//
//	// shp->getArea(); //부모가 자식의 함수를 사용하는건 불가능
//	c->getArea(); //자기함수니까 당연히 사용가능
//*/
//
//	//다형성, 오버라이딩  ////////////////////////////////////////////////////////
///*	Shape * shp[3];
//	shp[0] = new Circle;
//	shp[1] = new Rectangle;
//	shp[2] = new Circle;
//
//	for (int i = 0; i < 3; i++) {
//		shp[i]->getArea(); //이를 자식 클래스의 형식 따라 맞는 함수가 불리게 하려면, 
//		//부모클래스에서 virtual 로 getArea() 함수를 생성해 줘야한다.
//		//not virtual 이면, 그냥 부모의 함수가 불릴 뿐이니 주의!
//	}
//*/
//
//	//상속에 대한 이해 - static , dynamic binding //////////////////////////////////
///*	Circle c;
//	c.getArea(); //이것은 정적바인딩
//
//	Shape *shp = new Rectangle;
//	shp->getArea(); //이것은 동적바인딩 //컴파일 시간에 결정된다.
//
//	Shape *shp2 = new Circle;
//	shp2->getArea(); //이것또한 동적바인딩 //컴파일이후, 실행시간에 결정된다
//*/
//
//	//부모 소멸자 virtual 의 필요성! ///////////////////////////////////////////////
//	Shape *s = new Circle;
//	Circle *c = new Circle;
//
//	cout << "소멸자 호출전" << endl;
//	
//	delete s;
//	delete c;
//
//	return 0; 
//}