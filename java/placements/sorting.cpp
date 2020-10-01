#include <bits/stdc++.h>
using namespace std;

int swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

void merge(int arr[], int l, int m, int h){
    
    int n1 = m - l +1;
    int n2 = h - m;
    int L[n1], R[n2]; // my sorted subarrays

    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(int j=0; j<n2; j++)
        R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;

    //merging two sorted arrays
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int arr[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int partition(int *arr, int l, int h){
    int pi = arr[h]; // selecting the last element as the pivot.
    int i = l - 1;

    for(int j = l; j<=h-1; j++){
        if(arr[j] < pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}

void quicksort(int *arr, int l, int h){
    if(l<h){
        int pi = partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
} 

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // bubblesort(arr,n);
    // mergesort(arr,0,n-1);
    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}