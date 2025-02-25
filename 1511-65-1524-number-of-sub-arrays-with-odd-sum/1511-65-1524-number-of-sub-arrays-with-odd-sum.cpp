class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int prefixsum=0, evensum=0, oddsum=0;
        int n=arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            prefixsum+=arr[i];
            if(prefixsum%2==0){
                ans=(ans+oddsum)%mod;
                evensum++;
            }else{
                ans=(ans+(evensum)%mod+1)%mod;
                oddsum++;
            }
        }
        return ans%mod;
    }
};