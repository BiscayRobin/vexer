#include "vector.h"

size_t pivot(void **v, size_t low, size_t high, int (*cmp) (const void *, const void *)) {
        void *pvt = v[high];
        size_t i = low;

        for (int j = low; j <= high - 1; j++) {
                if (cmp(v[i], pvt) < 0) {
                        void *tmp = v[i];
                        v[i] = v[j];
                        v[j] = tmp;
                }
        }
	void *tmp = v[i+1];
	v[i+1] = v[high];
	v[high] = tmp;
	return i+1;
}

void vectorSort_aux(void **v, size_t low, size_t high,
                    int (*cmp)(const void *, const void *)) {
        if (low < high) {
                size_t pvt = pivot(v, low, high, cmp);

                vectorSort_aux(v, low, pvt - 1, cmp);
                vectorSort_aux(v, pvt + 1, high, cmp);
        }
}
void vectorSort(vector *v, int (*cmp)(const void *, const void *)) {
        vectorSort_aux(vector_data(v), 0, vector_size(v), cmp);
}
