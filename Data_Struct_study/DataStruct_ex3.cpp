//#include <iostream>
//using namespace std;
//
///* �迭�� ������ ����
//   �迭�� �̸��� �迭�� ù ĭ�� �ּҸ� �ǹ��մϴ�. &���İ�����
//   �׷���, �迭�� �̸��� ������ ������ �ƴ�, ������ ����Դϴ�. ����/������ �Ұ����մϴ�.
//   ����, *�迭�̸� �� �迭�� ùĭ�� ����ִ� ������ ���� �ǹ��մϴ�.
//   �迭�̸� + 1 �� �迭�� ��°ĭ�� �ּҸ� �ǹ��մϴ�. &���İ�����
//   +1 �� ũ��� �� �迭�� ���Ŀ� ���� �޶����� ������� ũ���Դϴ�. 
//   ������� char�̸� +1, int�� +4, double�̸� +8 ������.
//*/
//
//int main() { //�迭 point�� ���ҿ� �ּҰ��� ���� ����ϴ� ���α׷�
//
//	int i = 0, aryLength;
//	int point[] = { 95,88,76,54,85,33,65,78,99,82 }; //�迭 point �� ���� 10�� �ʱ�ȭ
//	aryLength = sizeof(point) / sizeof(int); // point�� ��ü������ ��� ���Ҹ� ���������� return��.
//	// sizeof(point)�� point�� �Ҵ��� ��������� ũ�⸦ ����Ʈ�� ��ȯ�ϹǷ�, aryLength�� �迭������ ���� �����.
//
//	cout << "�迭 point[i]�� �̿��Ͽ� ���Ұ��� ��� \n" << endl;
//	for (i = 0; i < aryLength; i++) { //point �� ������ ���� ������ŭ �ݺ�. ��, 10���ݺ�
//		cout << point[i] << (i == aryLength - 1 ? "\n\n" : ",");
//		//i�� 0���� 9������ ���۵ǰ�, aryLen�� ũ��� 10�̹Ƿ�, 9�� �ƴϸ� [ , ]  ���. �ƴϸ� ���ٳѰܼ� ���� for����
//	}
//
//	cout << "�ּһ�� point�� �̿��Ͽ� ������ �ּҰ��� ���Ұ��� ��� \n" << endl;
//	for (i = 0; i < aryLength; i++) { //10���ݺ�
//		cout << "(point + " << i << ") == " << (point + i) << ", *(point + " << i << ") == " << *(point + i) << endl; 
//		//�迭�̸��� +1 �ɶ�����, �ּҰ��� �󸶳� Ŀ������. ���� �°� ������ �������� Ȯ���ϴ� �ݺ���
//	}
//
//	return 0;
//}