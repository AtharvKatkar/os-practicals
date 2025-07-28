// sort using bubble sort in child process and using insertion sort in parent process

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void printArray(int n, int arr[n]){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int n, int arr[n]){
    for(int i=0; i<n; i++){
        for(int j=i; j<n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Array after bubble sort\n");
    printArray(n, arr);
}

void insertionSort(int n, int arr[n]){
    for(int i=0; i<n; i++){
        int key = arr[i];
        int j;
        for(j=i-1; j >= 0 && arr[j] > key;j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
    printf("Array after insertion sort\n");
    printArray(n, arr);
}

void main(){
    int n;
    printf("Enter length of the input array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements in array:\n");
    for(int i=0; i<n; i++){
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }

    int pid;
    pid = fork();

    if(pid == 0){
        printf("This is a child process (%d) performing bubble sort\n", getpid());
        bubbleSort(n, arr);
    } else if(pid > 0){
        printf("This is a parent process (%d) performing insertion sort\n", getpid());
        insertionSort(n, arr);
    } else {
        printf("Error creating process\n");
    }
}