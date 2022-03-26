import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainApplication {
    public static int fibo(int n,int arr[]){
        if(n == 1 || n == 2)
            arr[n] = n-1;
        else if(arr[n] >= 0)
            return arr[n];
        else {
            arr[n] = fibo(n - 1, arr) + fibo(n - 2, arr);
            return arr[n];
        }

        return arr[n];
    }
    public static void main(String[] args) {
        int n = 30;
        int arr[] = new int[n+1];
        Arrays.fill(arr,-1);
        System.out.println(fibo(n,arr));
    }
}
