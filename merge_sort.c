    #include<stdio.h>
    #include <stdlib.h>
    #include <time.h>
    void merge(int arr[],int s ,int mid , int e){
        int i=s;
        int k=s;
        int ar[100000];
        int j=mid+1;
        while(i<=mid && j<=e){
            if(arr[i]<arr[j]){
                ar[k]=arr[i];
                i++;k++;
            }
            else{
                 j++;k++;
            }
        }
        while(i<=mid){
            ar[k]=arr[i];
            i++;k++;
        }
        while(j<=e){
            ar[k]=arr[j];
            j++;k++;
        }
        for(i=s;i<=e;i++){
            arr[i]=ar[i];
        }
    }
    void mergeSort(int arr[], int s, int e) {

        if(s<e){
            int mid=(s+e)/2;
            mergeSort(arr,s,mid);
            mergeSort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }
    int main(){
    int n;
    printf("please give the number of items : ");
    scanf("%d",&n);
    srand(time(NULL));
    clock_t start, end;
    double time_taken;
    start = clock();
    int arr[n];
    for(int i =0; i<n;i++){
        arr[i]= rand();
    }
    int s=0;
    int e=n-1;
    mergeSort(arr,s,e);
    for(int i=0;i<=e;i++){
        printf(" %d   ",arr[i]);
    }
     end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n time taken is %f",time_taken);
    }
