﻿#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 25;

static void sortShell(int* arr) {

	int step = SIZE / 2;
	for (int step = SIZE / 2; step > 0; step--) {
		for (int i = step; i < SIZE; i++) {
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
				int	tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
		}
	}
}

int main() {
   
	system("chcp 1251 > Null");
	srand(time(0));

	int arr[SIZE]{};
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 101 - 50;
	}

	cout << "Неотсортированный массив: ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	auto start = high_resolution_clock::now();

	sortShell(arr);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Отсортированный массив: ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl << "Время выполнения программы (в микросекундах): " << duration.count() << endl;


}

