#include "../double_linked_list.c"

int main() {
	int i;
	int N ,M;
	scanf("%d", &N);
	scanf("%d", &M);
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * res = malloc(sizeof(struct Node));
	list_init(a);
	list_init(res);
	
	for(i=1; i<=N; i++) {
		list_push_back(a, i);
	}
	struct Node *ptr = a->next;
	struct Node *next = NULL;

	while (ptr->next != ptr) {
		for (i = 0; i < M-1; ++i) {
			ptr = ptr->next;
			if (ptr == a) {
				ptr = ptr->next;
			}
		}
		if (list_size(a) <= 3) {
			list_push_back(res, ptr->data);
		}
		next = ptr->next;
		list_delete(ptr);
		ptr = next;
	}
	list_print(res);
	while(list_delete(a->next) != -1);
	while(list_delete(res->next) != -1);
	free(a); free(res);
}
