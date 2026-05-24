import java.util.*;

class Array {

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        int[] arr2 = { 1, 2, 3, 4, 5 };
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arr2));
        System.out.println(Arrays.binarySearch(arr, 4));
        // Arrays.fill(arr, 1, 4, 0);
        System.out.println(Arrays.stream(arr).max().getClass());
        System.out.println(Arrays.toString(arr));
        // System.out.println(Arrays.equals(arr, arr2));
    }
}
