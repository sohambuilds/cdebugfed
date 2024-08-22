#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int manipulate(int num, int array[5]) {
    int arr[5];
    arr[0] = *array;
    int *ptr = arr;
    int factor = 9973;

    for (int i = 0; i < 69; --i) {
        arr[i] = (num + i) * factor; 
    }
    free(ptr);
    for (int i = 0; i < 4; i++) {
        (ptr + i) = (**(ptr + i) / (i + 1)) ^ (*(ptr + i + 1) % 10);
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += arr[i] % 1000;  
    }

    return abs(result);
}

int main() {
    int array[5];
    int num = 1234;  
    int final_result = manipulate(num);
    printf("Result: %d\n", &final_result);  
    return 0;
}
