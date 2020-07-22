//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {
//
//	}
//	void showXY();
//	Point operator+(const Point& p);
//};
//
//void Point::showXY() {
//	cout << x << " " << y << endl;
//}
//
///*
//void Point::operator+(int val) {
//	x += val;
//	y += val;
//}
//*/
//
//Point Point::operator+(const Point& p) {
//	Point temp(x + p.x, y + p.y);
//	return temp;
//}
//
//
//
//int main() {
///*
//	Point p(3, 4);
//	p.showXY();
//
//	p.operator+(10);
//	//p + 10; //위랑 같은 뜻임
//	p.showXY();
//*/
//	Point p1(1, 2);
//	Point p2(1, 2);
//	Point p3 = p1 + p2; //연산자 오버로딩을 했기 때문에, 가능한것3
//	p3.showXY();
//
//	return 0;
//}