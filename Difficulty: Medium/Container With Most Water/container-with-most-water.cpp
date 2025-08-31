class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        int maxi=0;
        int i=0, j=n-1;
        
        while(i<j){
            maxi=max(maxi, min(arr[i], arr[j])*(j-i));
            if(arr[i]<arr[j]){
                i++;
            }else{
                j--;
            }
        }
        
        return maxi;
    }
};
