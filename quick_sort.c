#include<stdio.h>
void qs(int a[],int lb , int ub){
     if(lb >= ub){
        return ;
     }
int i=lb+1;
int j=ub;
int p=a[lb];
while(i<j){
    while(i<=ub && a[i]<p){
        i++;
    }
    while(j>=lb && a[j]>p){
        j--;
    }
    if(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int temp =a[lb];
a[lb]=a[j];
a[j]=temp;
qs(a,lb,j-1);
qs(a,j+1,ub);

}
int main(){
int arr[5]={3,1,2,5,2};
qs(arr,0,4);
for(int i=0;i<5;i++){
    printf("%d  ",arr[i]);
}
}
