////#include <iostream>
////using namespace std;
////
/////* 4���� ����
////   �迭�� �̸��� �迭�� ù ĭ�� �ּҸ� �ǹ��մϴ�. &���İ�����
////   �׷���, �迭�� �̸��� ������ ������ �ƴ�, ������ ����Դϴ�. ����/������ �Ұ����մϴ�.
////   ����, *�迭�̸� �� �迭�� ùĭ�� ����ִ� ������ ���� �ǹ��մϴ�.
////   �迭�̸� + 1 �� �迭�� ��°ĭ�� �ּҸ� �ǹ��մϴ�. &���İ�����
////   +1 �� ũ��� �� �迭�� ���Ŀ� ���� �޶����� ������� ũ���Դϴ�.
////   ������� char�̸� +1, int�� +4, double�̸� +8 ������.
////*/
////
////int sumary(int ary[], int size);
////int sumaryp(int *ary, int size);
////int sump(int *ary, int size);
////int sump2(int *ary, int size);
////
////int main() { 
////
////	int i = 0, sum = 0, arylength;
////	int point[] = { 95,88,76,54,85,33,65,78,99,82 }; //�迭 point �� ���� 10�� �ʱ�ȭ
////	arylength = sizeof(point) / sizeof(int); // point�� ��ü������ ��� ���Ҹ� ���������� return��.
////	// sizeof(point)�� point�� �Ҵ��� ��������� ũ�⸦ ����Ʈ�� ��ȯ�ϹǷ�, arylength�� �迭������ ���� �����.
////
////	cout << "�迭 point[i]�� �̿��Ͽ� ���Ұ��� ��� \n" << endl;
////	for (i = 0; i < arylength; i++) { //point �� ������ ���� ������ŭ �ݺ�. ��, 10���ݺ�
////		cout << point[i] << (i == arylength - 1 ? "\n\n" : ",") ;
////		//i�� 0���� 9������ ���۵ǰ�, arylen�� ũ��� 10�̹Ƿ�, 9�� �ƴϸ� [ , ]  ���. �ƴϸ� ���ٳѰܼ� ���� for����
////		sum += point[i]; //�迭���� ��� ���� ��
////	}
////	cout << "main ���� ���� sum; " << sum << endl;
////
////	cout << "sumary() ���� ���� sum; " << sumary(point, arylength) << endl;
////	cout << "sumaryp() ���� ���� sum; " << sumaryp(point, arylength) << endl;
////	cout << "sump() ���� ���� sum; " << sump(point, arylength) << endl;
////	cout << "sump2() ���� ���� sum; " << sump2(point, arylength) << endl;
////
////	return 0;
////}
////
////int sumary(int ary[], int size) { //main�� �Ȱ��� ���
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += ary[i];
////	}
////	return sum;
////}
////int sumaryp(int *ary, int size) { //point�� ������ ���. �����ͷ� �޾��� �� �ִ�
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += ary[i];
////	}
////	return sum;
////}
////int sump(int *ary, int size) { //pointer ���� ���
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += *(ary + i); 
////		//point[i] == *(point + i) �̱� ������, �̴� sum += point[i] �� ����
////	}
////	return sum;
////}
////int sump2(int *ary, int size) {
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += *ary++; 
////		//�迭�̸� + i �� �迭�� iĭ�� �ּҸ� �ǹ��մϴ�.
////		//*�� �پ��ִ� �����ʹ� �װ� ����Ű�� �ּҾ��� �����͸� ��Ÿ���ϴ�
////		//���� �̶��� sum += point[i] �� ����
////	}
////	return sum;
////}
