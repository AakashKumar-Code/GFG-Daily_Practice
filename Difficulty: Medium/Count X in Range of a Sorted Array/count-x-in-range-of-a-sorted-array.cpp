class Solution {
  public:
     int firstOccurence(vector<int>& nums, int left, int right, int target){
        int first = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                first = mid;
                right = mid-1;
            } 
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return first;
    }

    int lastOccurence(vector<int>& nums, int left, int right, int target){
        int last = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                last = mid;
                left = mid+1;
            } 
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return last;
    }
    
    
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for(auto query: queries){
            int start = firstOccurence(arr, query[0], query[1], query[2]);
            int end = lastOccurence(arr, query[0], query[1], query[2]);
            if(end == -1 || start == -1) ans.push_back(0);
            else ans.push_back(end - start+1);
        }
        
        return ans;
    }
};