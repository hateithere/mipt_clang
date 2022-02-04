void bubblesort(int *a, int n);

void insertion(int *a, int n);

/* Сортировка пузырьком, сложность - O(n^2), устойчива */
void bubblesort(int *a, int n) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				int t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				sorted = false;
			}
		}
		n--;
	}
}

/* Сортировка вставками, для упорядоченного массива - O(n), в худшем случае - O(n^2), устойчива */
void insertion(int *a, int n) {
	for (int i = n-1; i > 0; i--) {
		if (a[i-1] > a[i]) {
			int t = a[i-1]; a[i-1] = a[i]; a[i] = t;
		}
	}
	for (int i = 2; i < n; i++) {
		int j = i;
		int tmp = a[i];
		while (tmp < a[j-1]) {
			a[j] = a[j-1]; j--;
		}
		a[j] = tmp;
	}
}

/* Функция слияния двух массивов, сложность - O(n) */
void merge(int *a, int low, int mid, int high, int *aux) {
   int i,j;
   for (i = mid+1; i > low; i--) aux[i-1] = a[i-1];
   for (j = mid; j < high; j++) aux[high+mid-j]=a[j+1];
   for (int k = low; k <= high; k++) {
      if (aux[j] < aux[i])
         a[k] = aux[j--];
      else
         a[k] = aux[i++];
   }
}

void mergeSort(int *a, int low, int high) {
	if (high - low < THRESHOLD) {
		insertion(a, high-low);
	}
	else {
		int mid = (low + high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low, mid, high);

	}
}
