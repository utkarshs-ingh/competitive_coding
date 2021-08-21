#include <bits/stdc++.h>
using namespace std;

int ascendingCompare(int a, int b) {
    return a > b;
}
int descendingCompare(int a, int b) {
    return a < b;
}

void BubbleSort(int *arr, int size, int (*compare)(int, int)) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size-1; j++) {
            if(compare(arr[j], arr[j+1]) > 0) {
                swap(arr[j+1], arr[j]);
            }
        }
    }
    return;
}

// custom BubbleSort to get increasing and decreasing array from single function using CALLBACKS
int main()
{
    int arr[] = {2, 5, 4, 1, 6, 3};
    BubbleSort(arr, 6, ascendingCompare); 
    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    
    cout << endl;
    
    BubbleSort(arr, 6, descendingCompare);
    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    
    return 0;
}
