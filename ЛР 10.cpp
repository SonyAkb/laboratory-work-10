#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print_mas(int* ptr, int size_mas) { //вывод массива
	cout << "Текущий массив: " << endl;
	for (int i = 0; i < size_mas; i++) {
		cout << ptr[i] << endl;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian"); //локализация
	system("chcp 1251");
	system("cls");

	srand(time(0));

	int mas_size; //размер массива
	int number_str; //номер строки, которую надо добавить
	do {
		cout << "Введите размер массива (размер больше 0): ";
		cin >> mas_size; //ввод размера массива
	} while (mas_size < 1);

	int* mas = new int[mas_size]; //создаю динамический массив

	for (int i = 0; i < mas_size; i++) { //заполняю массив через датчик случайных чисел
		mas[i] = rand() % 1000 + 1;
	}

	print_mas(mas, mas_size); //вывод текущего массива

	++mas_size; //увеличение размера массива

	mas = (int*)realloc(mas, (mas_size) * sizeof(int)); //увеличиваю размер массива на 1
	
	do {
		cout << "Введите номер строки, которую необходимо добавить: ";
		cin >> number_str; //номер строки, которую необходимо добавить
	} while (number_str < 0);
	
	mas[mas_size - 1] = mas[number_str - 1];
	print_mas(mas, mas_size); //вывод текущего массива

	delete[] mas; //удаляю динамический массив

	return 0;
}