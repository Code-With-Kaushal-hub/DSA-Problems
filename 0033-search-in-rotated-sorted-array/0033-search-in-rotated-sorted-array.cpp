class Solution {
public:

    int binarySearch(vector<int>& nums, int low, int high, int target) {

        while(low <= high) {

            int mid = low + (high-low)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }

        return -1;
    }


    int search(vector<int>& nums, int target) {

        int n = nums.size();

int low = 0;
int high = n - 1;

// find minimum element index
while(low < high) {
    int mid = low + (high - low) / 2;

    if(nums[mid] > nums[high]) {
        low = mid + 1;
    }
    else {
        high = mid;
    }
}

int pivot = low;

// largest element index
int peak;

if(pivot == 0)
    peak = n - 1;
else
    peak = pivot - 1;

        // Search left side
        if(target >= nums[0] && target <= nums[peak]) {

            return binarySearch(nums,0,peak,target);

        }

        // Search right side
        else {

            return binarySearch(nums,peak+1,nums.size()-1,target);

        }
    }
};