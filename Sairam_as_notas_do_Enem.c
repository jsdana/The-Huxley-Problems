#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int s){
    for(int i=0; i<s; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int binarySearch(int l, int r, int k, int* arr){
    int m;
    if(r>=l){
        m = (l+r)/2;
        if(k == arr[m])
            return m;
        else if(k < arr[m])
            binarySearch(l,m-1,k,arr);
        else
            binarySearch(m+1,r,k,arr);
    }else
        return -1;
}

int main()
{
    int size, cases, key, index;
    scanf("%d", &size);
    
    int CPF[size], Grades[size];
    
    for(int i=0; i<size; i++)
        scanf("%d", &CPF[i]);
        
    for(int i=0; i<size; i++)
        scanf("%d", &Grades[i]);
        
    scanf("%d", &cases);
    
    for(int i=0; i<cases; i++){
        scanf("%d", &key);
        index = binarySearch(0,size,key,CPF);
        if(index != -1)
            printf("%d\n", Grades[index]);
        else
            printf("NAO SE APRESENTOU\n");
        
    }
    
    return 0;
}
