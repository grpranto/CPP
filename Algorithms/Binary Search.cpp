#include<bits/stdc++.h>
using namespace std;

int arr[] = {568, 1, 4, 96, 44, 23, 0};

int binarySearch(int l, int r, int target){
    if(r >= l){  //************

        int mid = (l + r) / 2;

        if(target < arr[mid])    binarySearch(l, mid-1, target);
        else if(target > arr[mid])   binarySearch(mid+1, r, target);
        else if(arr[mid] == target){
            cout << "FOUND\n";
            return mid;
        }
    }
    else cout << "NOT Found\n";
}

int main(){
    int n;
    for(;;){
        cout << "Enter the num : ";
        cin >> n;

        sort(arr, arr+7);
        binarySearch(0, 6, n);
    }



    return 0;

}
