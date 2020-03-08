#include <stdio.h> 
#include <math.h> 
#include <limits.h> 
#include <stdlib.h>

int minVal(int x, int y) { return (x < y)? x: y; } 

int getMid(int s, int e) { return s + (e -s)/2; } 

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index) 
{ 

    if (qs <= ss && qe >= se) 
        return st[index]; 

    if (se < qs || ss > qe) 
        return INT_MAX; 
 
    int mid = getMid(ss, se); 
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1), 
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
} 


int RMQ(int *st, int n, int qs, int qe) 
{ 

    return RMQUtil(st, 0, n-1, qs, qe, 0); 
} 


int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
    int mid = getMid(ss, se); 
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1), 
                    constructSTUtil(arr, mid+1, se, st, si*2+2)); 
    return st[si]; 
} 

int *constructST(int arr[], int n) 
{ 
    int x = (int)(ceil(log2(n))); 

    int max_size = 2*(int)pow(2, x) - 1; 

    int *st = malloc(max_size*sizeof(*st)); 

    constructSTUtil(arr, 0, n-1, st, 0); 
    return st; 
} 

int main() 
{ 
    int n,m,i,qs,qe;
    scanf("%d",&n);
    scanf("%d",&m);
    int arr[n+1];
    
    for(i = 0; i<n; i++) scanf("%d",&arr[i]);
        
    int *st = constructST(arr, n); 
    while(m--){
        scanf("%d",&qs);
        scanf("%d",&qe);
        printf("%d\n",RMQ(st, n, qs, qe));
    }
    


    return 0; 
} 
