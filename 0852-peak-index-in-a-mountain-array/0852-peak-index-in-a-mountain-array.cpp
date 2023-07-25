class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /* Binary search */
        int left = 0, right = arr.size();
        while(left < right){
            auto mid = (left + right) / 2;
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]) return mid;
            else if(arr[mid-1] > arr[mid]) right = mid;
            else left = mid + 1;
        }
        return 0;
    }
};