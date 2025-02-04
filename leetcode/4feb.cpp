class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int r = 1;
        int n = nums.size();
        int sum = nums[0];
        int max_sum = nums[0];
        while(r<n){
            while(r<n && nums[r]>nums[r-1]){
                sum+=nums[r];
                r++;

            }
            max_sum = max(max_sum,sum);
            if(r<n){
                sum = nums[r];
                r++;
            }
        }return max_sum;
    }
};