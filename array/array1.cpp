#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    cout<<"ELEMENTS ARE:"<<endl;
    for(int i=0; i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}
void append(struct Array *arr,int n){
    if(arr->length<arr->size){
        arr->A[arr->length++] = n;
    }
}
void insert(struct Array *arr,int n,int p){
    if(p<=arr->length){
        for(int i=arr->length ;i>p;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[p] = n;
        arr->length++;
        
    }
}
bool del(struct Array *arr,int index){
    if(index>=0 && index<=arr->length ){
        for(int i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return true;
    
    }

    return false;
}

void swap(int *x ,int *y){
    int temp =*x;
    *x = *y;
    *y =temp;
}

bool search(struct Array *arr,int x){
    for(int i=0;i<arr->length;i++){
        if(x == arr->A[i]){
            if(i!=0){
            swap(&arr->A[i],&arr->A[0]);
            }
            return true;
        }
    }
    return false;
}
int binarysearch(struct Array arr,int key){
    int low,mid,high;
    low = 0;
    high = arr.length-1;
    while(low<=high){
    mid = (low+high)/2;
    if(key == arr.A[mid]){
        return mid;
    }
    else if(key<arr.A[mid]){
        high = mid-1;
    }
    else{
        low = mid+1;
    }
    }
    return -1;
}
int get(struct Array arr ,int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
int set(struct Array *arr,int x,int index){
    if(index >= 0&& index<arr->length){
        arr->A[index] = x;
        return 0;
    }
    return -1;
}
int max(struct Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

int total(struct Array arr){
    if(arr.length>0){
    int total = 0;
    for(int i=0;i<arr.length;i++){
        total += arr.A[i];
    }
    return total;
    }
    return -1;
}
float avg(struct Array arr){
    if(arr.length>0){
    int total = 0;
    for(int i=0;i<arr.length;i++){
        total += arr.A[i];
    }
    int avg = total/arr.length;
    }
    return -1;
}
void reverse(struct Array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
void rotate(struct Array *arr,int n){
    int *B;
    B = new int[arr->length];
    for(int i=arr->length;i>=0;i--){
        int j = i-n;
        if(j<0){
           j= j+arr->length;
        } 
        B[j] = arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        cout<<B[i]<<" ";
    }
}
int isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}
int insertsortedarray(struct Array *arr,int n){
    int i= arr->length-1;
    while(i>=0&& arr->A[i]>n){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = n;
    arr->length++;
    return 0;
    
}
void arranging(struct Array *arr){
    int i=0;
    int j= arr->length-1;
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>=0){
            j--;
        }
        if(i<j){
        swap(&arr->A[i],&arr->A[j]);
        }
    }
}
int main(){
    struct Array arr={{-2,4,-6,8,-7,10},10,6};
    // append(&arr,10);
    // insert(&arr,10,0);
    // del(&arr,3);
    // cout<<binarysearch(arr,10);
    // reverse(&arr);
    // rotate(&arr,2);
    // insertsortedarray(&arr,3);
    // cout<<isSorted(arr);
    arranging(&arr);
     display(arr);
    return 0;
}