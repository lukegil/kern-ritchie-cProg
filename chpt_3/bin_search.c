#include <stdio.h>

int main() {


}

int bin_search(int x, int v[], int n) {
	int low, hight, mid;

	low = 0;
	high = n - 1;
	while ((mid = (low + high) / 2) != x && low < high) {

		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (mid == x)
		return mid;
	else 
		return -1;
}
