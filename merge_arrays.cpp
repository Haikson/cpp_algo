#include <iostream>

using namespace std;

#define count_of(x) (sizeof(x)/sizeof(*x))

int * merge_arrays(int * array1, int * array2){
//    int size_of_1 = sizeof(array1) / sizeof(array1[0]);
    int size_of_1 = count_of(array1);
//    int size_of_2 = sizeof(array2) / sizeof(array2[0]);
    int size_of_2 = count_of(array2);

    int size_of_arrays = size_of_1 + size_of_2;
    int * merged_array = new int[size_of_arrays];
    for (int i = 0; i <= size_of_1; ++i) {
        merged_array[i] = array1[i];
    }
    int start = 0;
    for (int i = 0; i <= size_of_2; ++i) {
        for (int j = start; j < size_of_arrays; ++j) {
            if (array2[i] <= merged_array[j] || merged_array[j] > merged_array[j+1]){
                int tmp = merged_array[j+1];
                for (int a = j; a < size_of_arrays - 1; ++j){
                    int ttmp = merged_array[a+1];
                    merged_array[a+1] = tmp;
                    tmp = ttmp;
                }
                merged_array[j] = array2[i];
                start = j;
                break;
            }
        }

    }

    cout << endl;
    return merged_array;
}

int main() {
    int arr1[3] = {1,2,3};
    int arr2[3] = {5,6,7};
    int * merged_array = merge_arrays(arr1, arr2);

    for (int i = 0; i < count_of(arr1) + count_of(arr2); ++i) {
        cout << merged_array[i] << " ";
    }
    return 0;
}
