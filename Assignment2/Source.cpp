#include<iostream>
using namespace std;
int main() {

	const int NUM_YEARS = 51; // Số lượng năm
	int population[NUM_YEARS];

	// Nhập dữ liệu

	for (int i = 0; i < NUM_YEARS; ++i) {
		cout << "Nhap so luong nguoi sinh cua nam " << 1920 + i << ": " << endl;
		cin >> population[i];
	}

	// Tìm số năm có cùng số lượng người sinh
	int count_same_population = 0;
	for (int i = 0; i < NUM_YEARS - 1; ++i) {
		for (int j = i + 1; j < NUM_YEARS; ++j) {
			if (population[i] == population[j]) {
				count_same_population++;
			}
		}
	}

	// Tìm năm có lượng người sinh lớn nhất và nhỏ nhất
	int max_population = population[0], min_population = population[0];
	int max_year = 1920, min_year = 1920;
	for (int i = 1; i < NUM_YEARS; ++i) {
		if (population[i] > max_population) {
			max_population = population[i];
			max_year = 1920 + i;
		}
		if (population[i] < min_population) {
			min_population = population[i];
			min_year = 1920 + i;
		}
	}

	// In kết quả

	cout << "So nam co cung so luong nguoi sinh: " << count_same_population << endl;
	cout << "Nam co luong nguoi sinh lon nhat: " << max_year << " (" << max_population << ")" << endl;
	cout << "Nam co luong nguoi sinh nho nhat: " << min_year << " (" << min_population << ")" << endl;



	return 0;

}