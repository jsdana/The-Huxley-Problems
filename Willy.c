#include <stdio.h>

void swap(int* arr, int j, int k){
    int temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
}

int hoarePartition(int* arr, int l, int r){
    int p, i, j;
    p = arr[l]; i = l; j = r+1;
    
    do{
        do{
            i++;
        }while(arr[i]>p && i<r);
        
        do{
            j--;
        }while(arr[j]<p);
        swap(arr, i, j);
    }while(i<j);
    
    swap(arr, i, j);
    swap(arr, l, j);
    return j;
}

void quickSort(int* arr, int l, int r){
    int s;
    if(l<r){
        s = hoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
}

void printArr(int* arr, int size){
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int optimalHeight(int* arr, int size, int target){
    long long int sum = 0;
    int height, former = 0, formerHeight;
    while(1){
        for(int i=0; i<size; i++){
            height = arr[i];
            for(int j=0; j<size; j++)
                if(arr[j] > height)
                    sum += (arr[j] - height);
                
            if(sum == target)
                return height;
                
            if((former < target && sum > former) || (former > target && sum > former && sum < target)){
                former = sum;
                formerHeight = height;
            }
            sum = 0;
        }
        return formerHeight;
    }
}

int main(){
    int numTrees, reqTimber;
    
    scanf("%d %d", &numTrees, &reqTimber);
    int trees[numTrees];
    for(int i=0; i<numTrees; i++)
        scanf("%d", &trees[i]);
        
    quickSort(trees, 0, numTrees);
    
    //printArr(trees, numTrees);
    int opHeight = optimalHeight(trees, numTrees, reqTimber);
    
    printf("%d", opHeight);
    
    return 0;
}
