#include<iostream>
#include <vector>
using namespace std;

void swap(int& a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}


void selectionSort(int arr[], int n) {
	int i, j, min_indx;

	for (i = 0; i < n - 1;i++)
	{
		min_indx = i;
		for (j = i + 1; j < n;j++)
			if (arr[j] < arr[min_indx])
				min_indx = j;
		swap(arr[min_indx], arr[i]);

	}
}

// đỏ = 0 
// trắng = 1
// xanh = 2

int main() {
	int arr[] = {2,0,2,0,0,1,0,2,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Consult: \n";
	for (int i = 0; i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

