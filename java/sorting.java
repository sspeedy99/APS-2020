import java.util.*;

class Sorting {
    public static void merge(int [] arr, int low, int mid, int high){
        int i,j,k;
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int [] L = new int[n1];
        int [] R = new int[n2];

        for(i = 0; i<n1; i++)
            L[i] = arr[low+i];
        for(j=0; j<n2; j++)
            R[j] = arr[mid+1+j];

        i = 0;
        j = 0;
        k = low;

        while(i <n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void mergesort(int [] arr, int low, int high){
        if(low<high) {
            int mid = (low + high)/2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

	public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int sz = in.nextInt();
        int arr[] = new int[sz];
        for(int i=0; i<sz; i++){
            arr[i] = in.nextInt();
        }

        mergesort(arr,0,sz-1);

        for(int i: arr)
            System.out.print(i + " ");
    }
}