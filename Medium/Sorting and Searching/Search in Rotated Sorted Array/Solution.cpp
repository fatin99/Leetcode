#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        int rot=lo;
        lo=0;hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(nums[realmid]==target)return realmid;
            if(nums[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }

    int search2(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (target == nums[0]) {
                return 0;
            } else {
                return -1;
            }
        }

        int pivot = findPivot(nums, 0, nums.size());
        if (pivot == -1) { //array is not rotated
            return binarySearch(nums, 0, nums.size(), target);
        } else { //array is rotated
            int indexLeft = binarySearch(nums, 0, pivot, target);
            int indexRight = binarySearch(nums, pivot+1, nums.size(), target);
            return max(indexLeft, indexRight);
        }
    }

    int findPivot(vector<int>& nums, int low, int high) {
        if (high < low) { //not pivot found, array is sorted
            return -1;
        }
        int mid = (low + high) / 2; 
        if (mid < high && nums[mid] > nums[mid+1]) { //mid is the pivot point
            return mid;
        } else if (mid > low && nums[mid] < nums[mid-1]) { //mid is the first element of the  sorted array
            return (mid-1);
        }
        if (nums[low] >= nums[mid]) { //mid is past the pivot point
            return findPivot(nums, low, mid-1);
        } else { //mid is before the pivot point
            return findPivot(nums, mid+1, high);
        }
    }

    int binarySearch(vector<int>& nums, int low, int high, int key) {
        if (high < low) {
            return -1;
        }
        int mid = (low + high) / 2; 
        if (key == nums[mid]) {
            return mid;
        } else if (key < nums[mid]) {
            return binarySearch(nums, low, mid-1, key);
        } else {
            return binarySearch(nums, mid+1, high, key);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3};
    int target = 0;
    cout << solution.search(nums, target);
    return 0;
}