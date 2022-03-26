import java.util.List;

class searching {

    static int binary_search(List<Integer> arr,int key){
        int low = 0;
        int high = arr.size()-1;
        int mid = -1;
        while(low <= high){
            mid = low + (high - low)/2;
            if(arr.get(mid) == key)
                break;
            else if(arr.get(mid) > key){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return mid;
    }
}