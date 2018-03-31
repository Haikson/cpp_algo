#include <iostream>

using namespace std;

#define count_of(x) (sizeof(x)/sizeof(*x))

void merge(int m, int n, int A[], int B[], int C[]) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    if (i < m) {
        for (int p = i; p < m; p++) {
            C[k] = A[p];
            k++;
        }
    } else {
        for (int p = j; p < n; p++) {
            C[k] = B[p];
            k++;
        }
    }
}

int main() {
    int arr2[3] = {1,2,3};
    int arr1[3] = {5,6,7};

    int m = count_of(arr1);
    int n = count_of(arr2);
    int * merged_array = new int[m+n+5];
    merge(m, n, arr1, arr2, merged_array);

    for (int i = 0; i < m + n + 5; ++i) {
        cout << merged_array[i] << " ";
    }
    cout << endl;
    return 0;
}
