#include <stdio.h>

#define arr_size 2000000000

int binsearch_1(int x, int v[], int n);
int binsearch_2(int x, int v[], int n);


int main() {
	int arr[arr_size];
	int ret;
	for (int i = 0; i < arr_size; ++i) {
		arr[i] = i;
	}
	
	print_current_time_with_ms();
	ret = binsearch_1(4, arr, arr_size);

	printf("%d\n", ret);


	for (int i = 0; i < arr_size; ++i) {
		arr[i] = i;
	}
	
	print_current_time_with_ms();
	ret = binsearch_2(4, arr, arr_size);

	printf("%d\n", ret);

	return 0;
}



int binsearch_1(int x, int v[], int n) {
	int low; //bottom of search range;
	int high; //top of range -- length of array
	int mid; //midpoint between low and high

	low = 0;
	high = n - 1;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid]) 
			low = mid + 1;
		else 
			return mid;
	}
	return -1; //no match
}


int binsearch_2(int x, int v[], int n) {
	int low; //bottom of search range;
	int high; //top of range -- length of array
	int mid; //midpoint between low and high

	low = 0;
	high = n - 1;
	
	while ( v[(mid = (low + high)/2)] != x && low <= high ) {
		if (x < v[mid]) 
			high = mid - 1; 
		else 
			low = mid + 1;
	}

	return (mid == x) ? mid : -1;
}

