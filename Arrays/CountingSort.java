package algorithm;

public class MyCountingSort {
    public void countSort(int[] a, int n, int l, int h) {

        int[] count = new int[h];
        for(int i=0;i<n;i++) {
            count[a[i]]++;
        }

        for(int i=1;i<h;i++) {
            count[i] = count[i-1] + count[i];
        }

        int[] temp = new int[n];
        for(int i=n-1;i>=0;i--) {
            temp[count[a[i]] - 1] = a[i];
            count[a[i]]--;
        }

        for(int i=0;i<n;i++) {
            a[i] = temp[i];
        }
    }
}
