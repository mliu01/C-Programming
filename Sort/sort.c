#include <stdio.h>
#include <stdint.h>

void swap(uint32_t* a, uint32_t* b) {
    uint8_t tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(uint32_t* arr, uint8_t len){
    for(uint8_t j=len-1; j > 0; j--){
        for(uint8_t i=0; i<=j-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr+i, arr+i+1); // arr + i == &arr[0] + i i.e. it shifts the pointer from index 0 to the index of the array needed in otder to swap them
                                      // e.g. i = 2; arr + 2 == &arr[0] + 2 == memory address of &arr[2]  (addition of pointer with 1 shifts the pointer by 4 bytes i.e. number of bytes in 1)
                                      // could use as well: swap(&arr[i], &arr[i+1]) --> swaps memory at index i of array
            }
        }
    }
}
int main() {
    uint32_t arr[] = {2,5,2,6,1}; // unsigned type
    sort(arr, 5);
    for (int i=0; i<5; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;

}
