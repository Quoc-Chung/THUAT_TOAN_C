#include<stdio.h>
#include<stdlib.h>

void read_file(int **mt, int *hang, int *cot) {
	FILE *f = fopen("ten_1.txt", "r");
//	if (f == NULL) {
//		printf("LỖI");
//		exit(1);
//	}
	fscanf(f, "%d%d", hang, cot);
	*mt = (int*)malloc((*hang) * (*cot) * sizeof(int));
	for (int i = 0; i < *hang; i++) {
		for (int j = 0; j < *cot; j++) {
			fscanf(f, "%d", &(*mt)[i * (*cot) + j]);
		}
	}
	fclose(f);
}

int tinh_tich_sle(int *mt, int hang, int cot) {
	int tich = 1;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			if (mt[i * cot + j] % 2 != 0) {
				tich *= mt[i * cot + j];
			}
		}
	}
	return tich;
}

int main() {
	int *mt, hang, cot;
	read_file(&mt, &hang, &cot);
	printf("%d ", hang);
	printf("Tích các số lẻ là: %d\n", tinh_tich_sle(mt, hang, cot));
	free(mt);
	return 0;
}
