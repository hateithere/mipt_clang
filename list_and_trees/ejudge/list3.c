#include "../double_linked_list.c"
#define MAX 1000000

int main() {
	int i, k, l;
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));	
	list_init(a);
	list_init(b);
	int A[5], B[5];

	for (i = 0; i < 5; ++i) {
		scanf("%d", &A[i]);
		list_push_back(a, A[i]);
	}
	
	for (i = 0; i < 5; ++i) {
		scanf("%d", &B[i]);
		list_push_back(b, B[i]);
	}

	for (i = 0;; ++i) {
		if (i == MAX) {
			printf("botva\n");
			return 0;
		}
		if (list_size(a) == 0) {
			printf("second %d\n", i);
			return 0;
		}
		if (list_size(b) == 0) {
			printf("first %d\n", i);
			return 0;
		}
		k = list_pop_front(a);
		l = list_pop_front(b);
		if (k == 10 || l == 0) {
			list_push_back(b, k);
			list_push_back(b, l);		
		}
		else if (k == 0 || l == 10) {
			list_push_back(a, k);
			list_push_back(a, l);
		}
		else if (k > l) {
			list_push_back(a, l);
			list_push_back(a, k);
		}
		else {
			list_push_back(b, k);
			list_push_back(b, l);	
		}
	}
}
