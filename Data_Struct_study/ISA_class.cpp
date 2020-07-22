//#pragma warning(disable:4996)
//
//#include <iostream>
//using namespace std;
//
//class Shape { //�θ� Base Class
//private: 
//	int price;
//protected:
//	double x, y;
//public:
//	char *owner;
//	Shape(const Shape &s) {
//	} //�ڱ��ּ� ī��
//	Shape(int don = 0, double x = 0, double y = 0, const char *s = "you") {
//		cout << "Shape�� default constructor" << endl;
//		price = don;
//		this->x = x;
//		this->y = y;
//		owner = new char[strlen(s) + 1]; //! ���� ����Ʈ �������, new�� ��������Ƿ�
//		strcpy(owner, s);
//	} //�ʱⰪ ������ //���⿡ cout�� �־�� ��°��� ����
//	virtual ~Shape() { //�Ҹ��� virtual��Ű�� ���� ���������
//		cout << "Shape�� default destructor" << endl;
//		delete owner; //!! //���� - new delete����.
//	}
//
//	void setXY(int _x, int _y);
//	void showPrice() const; //��� const �Լ��� const �� ����� Ŭ���� ��ü������ ��밡���� �Լ��̴�.
//
//	virtual double getArea() = 0; //pure virtual �� �Ǿ����, ���� � ������ �ʿ����� �ʱ� �����̿���
//		//virtual Ű����� Ŭ������ �������� �����߾��.
//		//���� shape�� ���� Ŭ������ �Ǿ���, �� obj���� ( shape s; ) �� �Ұ����������.
//		//������ shape *s = new .. �� ���� �����ͷθ� ������ �����ϴ�ϴ�.
//	//�ڽ�Ŭ�������� �� ������ ����������ؿ�.
//	//Shape�� �Ҹ��ڿ��� virtual Ű���带 �ٿ���� memory leak�� ���� �� �� �־��
//	//���� getArea() �Լ��� dynamic binding�� �ǰ� �ȴ�ϴ�.
//};
//
////������� ������ �Լ��� ��ü����../
//
//void Shape::setXY(int _x, int _y) {
//	x = _x; 
//	y = _y;
//}
//
//void Shape::showPrice() const {
//	printf("%d\n", price);
//}
////��� const �Լ��� const �� ����� Ŭ���� ��ü������ ��밡���� �Լ��̴�.
//
//class Circle :public Shape{ //Shape�� ��ӹ��� �ڽ� Drived Ŭ����
//	double radius;
//	char *name;
//public:
//	Circle(double r = 0):Shape(1,2,3,"circle") { //Shape�� �ʱⰪ �����ڿ� �� �־�
//		cout << "Circle�� default constructor" << endl; //for ����, �Ҹ��� do ���� Ȯ��
//
//		name = new char[strlen("test") + 1]; //! ���� ����Ʈ �������, new�� ��������Ƿ�
//		strcpy(owner, "test");
//
//		radius = r;
//		//x = 10; //protected�� �ڽĿ��� �θ�(Shape)�� ���ڿ� ���� ����������
//		//y = 20;
//	}
//	~Circle() { //�갡 �ȺҸ��� �����Ƿ�, �θ� �Ҹ��ڶ��� virtualȭ ���־���Ѵ�.
//		cout << "Circle�� default destructor" << endl;//for ����, �Ҹ��� do ���� Ȯ��
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
//		cout << "Rectangle�� default constructor" << endl;//for ����, �Ҹ��� do ���� Ȯ��
//		width = w;
//		height = h;
//	}
//	~Rectangle() {
//		cout << "Rectangle�� default destructor" << endl;//for ����, �Ҹ��� do ���� Ȯ��
//	}
//
//	double getArea() {
//		return width * height*3.14;
//	}
//};
//
//int main() {
//	//������ �Ҹ��� �������� ////////////////////////////////////////////////////////
///*	Circle c;
//	Rectangle r;
//*/
//
//	//�Լ� ��� ���� Ȯ��  ////////////////////////////////////////////////////////
///*	Shape * shp = new Circle; //��Ӱ����̹Ƿ�, �θ� �ڽ� ������ ����
//	Circle * c = new Circle;
//
//	shp->showPrice(); //�ڱ�(Shpae)�� �Լ��̴ϱ� ��밡�� �翬��
//	c->showPrice();  //shape ��ӹ޾����Ƿ� ��밡��
//
//	// shp->getArea(); //�θ� �ڽ��� �Լ��� ����ϴ°� �Ұ���
//	c->getArea(); //�ڱ��Լ��ϱ� �翬�� ��밡��
//*/
//
//	//������, �������̵�  ////////////////////////////////////////////////////////
///*	Shape * shp[3];
//	shp[0] = new Circle;
//	shp[1] = new Rectangle;
//	shp[2] = new Circle;
//
//	for (int i = 0; i < 3; i++) {
//		shp[i]->getArea(); //�̸� �ڽ� Ŭ������ ���� ���� �´� �Լ��� �Ҹ��� �Ϸ���, 
//		//�θ�Ŭ�������� virtual �� getArea() �Լ��� ������ ����Ѵ�.
//		//not virtual �̸�, �׳� �θ��� �Լ��� �Ҹ� ���̴� ����!
//	}
//*/
//
//	//��ӿ� ���� ���� - static , dynamic binding //////////////////////////////////
///*	Circle c;
//	c.getArea(); //�̰��� �������ε�
//
//	Shape *shp = new Rectangle;
//	shp->getArea(); //�̰��� �������ε� //������ �ð��� �����ȴ�.
//
//	Shape *shp2 = new Circle;
//	shp2->getArea(); //�̰Ͷ��� �������ε� //����������, ����ð��� �����ȴ�
//*/
//
//	//�θ� �Ҹ��� virtual �� �ʿ伺! ///////////////////////////////////////////////
//	Shape *s = new Circle;
//	Circle *c = new Circle;
//
//	cout << "�Ҹ��� ȣ����" << endl;
//	
//	delete s;
//	delete c;
//
//	return 0; 
//}