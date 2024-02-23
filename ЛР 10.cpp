#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print_mas(int* ptr, int size_mas) { //����� �������
	cout << "������� ������: " << endl;
	for (int i = 0; i < size_mas; i++) {
		cout << ptr[i] << endl;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian"); //�����������
	system("chcp 1251");
	system("cls");

	srand(time(0));

	int mas_size; //������ �������
	int number_str; //����� ������, ������� ���� ��������
	do {
		cout << "������� ������ ������� (������ ������ 0): ";
		cin >> mas_size; //���� ������� �������
	} while (mas_size < 1);

	int* mas = new int[mas_size]; //������ ������������ ������

	for (int i = 0; i < mas_size; i++) { //�������� ������ ����� ������ ��������� �����
		mas[i] = rand() % 1000 + 1;
	}

	print_mas(mas, mas_size); //����� �������� �������

	++mas_size; //���������� ������� �������

	mas = (int*)realloc(mas, (mas_size) * sizeof(int)); //���������� ������ ������� �� 1
	
	do {
		cout << "������� ����� ������, ������� ���������� ��������: ";
		cin >> number_str; //����� ������, ������� ���������� ��������
	} while (number_str < 0);
	
	mas[mas_size - 1] = mas[number_str - 1];
	print_mas(mas, mas_size); //����� �������� �������

	delete[] mas; //������ ������������ ������

	return 0;
}