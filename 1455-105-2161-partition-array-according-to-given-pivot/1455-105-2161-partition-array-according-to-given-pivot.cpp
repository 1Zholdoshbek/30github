class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(),pivot);
        int ind1=0;
        int ind2=nums.size()-1;
        for(int i =0 ,j=nums.size()-1; i < nums.size();i++,j--){
            if(nums[i]<pivot){
                ans[ind1]=nums[i];
                ind1+=1;
            }
            if(nums[j]>pivot){
                ans[ind2]=nums[j];
                ind2-=1;
            }
        }
        return ans;
    }
};