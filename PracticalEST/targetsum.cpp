class Solution {
public:
    int solve(vector<int>&nums, int tar, int index,vector<vector<int>>&dp){
       //base case
       if(index==0){
        if(tar==0 &&nums[0]==0) return 2;
        if(tar==0 || tar==nums[0]) return 1;
        return 0;
       }
       if(dp[index][tar]!=-1) return dp[index][tar];
       //recurrences
       int notTake=solve(nums,tar,index-1,dp);
       int take=0;
       if(nums[index]<=tar) take=solve(nums,tar-nums[index],index-1,dp);
       //return
       return dp[index][tar]=notTake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(),0);
        if(sum-target<0) return 0;
        if((sum-target)%2!=0) return 0;
        int modifiedTarget=(sum-target)/2;
        vector<vector<int>>dp(nums.size(),vector<int>(modifiedTarget+1,-1));
        return solve(nums,modifiedTarget,nums.size()-1,dp);
    }
};