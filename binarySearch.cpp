#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int key, int l, int r) {
    if(l>r){
        cout << l <<" fa"<<endl;
        return -1;
    }

    int mid = (l+r) / 2;
    if(nums[mid] == key){
        return mid;
    }

    else if(key > nums[mid]){
        l = mid + 1;
        return binarySearch(nums,key,l,r);
    }
    else{
        r = mid -1 ;
        return binarySearch(nums,key,l,r);
    }
}


int main() {
    vector<int> nums = {1,2,4,5,6};
    int key = 3;
    int l = 0;
    int r = nums.size()-1;
    cout << binarySearch(nums, key, l, r);
}