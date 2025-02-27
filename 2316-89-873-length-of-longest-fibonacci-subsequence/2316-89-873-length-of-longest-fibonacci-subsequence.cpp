class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int result=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mpp.insert({arr[i],i});
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int prev=arr[i];
                int curr=arr[j];
                int next=prev+curr;
                int length=2;
                while(mpp.find(next) != mpp.end())
                {
                    length++;
                    prev=curr;
                    curr=next;
                    next=prev+curr;
                    result=max(result,length);
                }
            }
        }
        return result;
    }
};