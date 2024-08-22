#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int manipulate(int num, int array[5]) {
    int arr[5];
    arr[0] = *array;
    int *ptr = arr;
    int factor = 9973;
    //ERROR 4: Fix segmentation fault
    for (int i = 0; i < 69; --i) {
        arr[i] = (num + i) * factor; 
    }
    //ERROR 3: dont free the ptr
    free(ptr);
    for (int i = 0; i < 4; i++) {
        //ERROR 1: Fix referencing
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
    //ERROR 2: Pass array to pointer
    int final_result = manipulate(num);

    //ERROR 5: call final_result by value
    printf("Result: %d\n", &final_result);  
    return 0;
}
