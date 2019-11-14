#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

class ArrayHandler {
public:
	ArrayHandler(int* a, int elem) {
		ARR = a;
		ELEM = elem;
	}
	ArrayHandler(int* a, int elem, int lst) {
		ARR = a;
		ELEM = elem;
		LAST = lst;
	}
	virtual int getArray() {
		cout << "New array created! " << endl;
		return 0;
	}
	virtual int printArr() {
		cout << "Printed!" << endl;
		return 0;
	}
	virtual int insertionSort() {
		cout << "SORTED!" << endl;
		return 0;
	}
	virtual int selectionSort() {
		cout << "SORTED!" << endl;
		return 0;
	}
	virtual int quickSort() {
		cout << "SORTED!" << endl;
		return 0;
	}


protected:
	int* ARR;
	int ELEM;
	int LAST;
};


class newArray : public ArrayHandler {
public:
	newArray(int* a = 0, int elem = 0) :ArrayHandler(a, elem) {}
	int getArray() {
		int i;
		srand(time(NULL));
		for (i = 0;i < ELEM;i++) {
			ARR[i] = rand() % 100;
		}
		return *ARR;
	}
	int printArr() {
		int i;
		for (i = 0; i < ELEM; i++) {
			cout << ARR[i] << "\t";
		}cout << endl;
		return *ARR;
	}

	int insertionSort() {
		int i, j,
			ins_elem;
		for (i = 0; i < ELEM; i++) {
			ins_elem = ARR[i];
			j = i - 1;

			while (j >= 0 && ARR[j] > ins_elem) {
				ARR[j + 1] = ARR[j];
				j--;
			}ARR[j + 1] = ins_elem;
		}
		cout << "INSERTION SORTED" << endl;
		return *ARR;
	}
	int selectionSort() {
		int i, j,
			min_index, tmp;

		for (i = 0; i < ELEM - 1; i++) {
			min_index = i;
			for(j = i+1; j<ELEM; j++){
				if (ARR[j] < ARR[min_index]) {
					min_index = j;
				}
			}
			swap(ARR[min_index], ARR[i]);

		}
		cout << "SELECTION SORTED" << endl;
		return *ARR;
	}
};
class quickSortHandler :public ArrayHandler {
public:
	quickSortHandler(int* a = 0, int elem = 0, int lst = 0) :ArrayHandler(a, elem, lst) {}
	int getArray() {
		int i;
		srand(time(NULL));
		for (i = 0;i < LAST;i++) {
			ARR[i] = rand() % 100;
		}
		return *ARR;
	}
	int printArr() {
		int i;
		for (i = 0; i < LAST; i++) {
			cout << ARR[i] << "\t";
		}cout << endl;
		return *ARR;
	}

	void qS(int* a = 0, int elem = 0, int lst = 0) {
		int i = ELEM, j = LAST;
		int pivot = ARR[(ELEM + LAST) / 2];

		while (i <= j) {
			while (ARR[i] < pivot)
				i++;
			while (ARR[j] > pivot)
				j--;
			if (i <= j) {
				swap(ARR[i], ARR[j]);
				i++;
				j--;
			}
		};

		if (ELEM < j)
			qS(ARR, ELEM, j);
		if (i < LAST)
			qS(ARR, i, LAST);
	}
	int quickSort() {
		qS(ARR, 0, LAST - 1);
		return *ARR;

	}


};

int main()
{
	const unsigned arrSize = 100;
	static int* arr = new int[arrSize];
	ArrayHandler* handleARR;
	newArray narr(arr, arrSize);
	quickSortHandler QS(arr, 0, arrSize - 1);

	handleARR = &narr;
	handleARR->getArray();
	handleARR->printArr();
	handleARR->insertionSort();
	handleARR->printArr();
	handleARR->selectionSort();
	handleARR->printArr();
	handleARR = &QS;
	handleARR->getArray();
	handleARR->printArr();
	handleARR->quickSort();
	handleARR->printArr();


	return 0;
}
