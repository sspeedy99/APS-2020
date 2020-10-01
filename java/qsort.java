import java.util.*;
class quicksort{
    
    void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1; 

        for(int j = 0; j<=high-1; j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return (i+1);

    }

    void sort(int arr[], int low, int high){
        if(low<high){
            int pi = partition(arr,low,high);
            sort(arr,low, pi-1);
            sort(arr,pi+1, high);
        }
    }

    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        int sz = in.nextInt();
        int [] arr = new int[sz];
        for(int i=0; i<sz; i++){
            arr[i] = in.nextInt();
        }
        quicksort ob = new quicksort();
        ob.sort(arr,0,sz-1);
        for(int i : arr)
            System.out.print(i + " ");

    }
}