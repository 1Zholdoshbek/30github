class Solution {
     private:
      bool helper(vector<int>& result,vector<int>& used, int index, int n) {
        if (index == result.size()) {
            return true;
        }
        if (result[index] != 0)
            return helper(result, used, index + 1, n);
        for (int num = n; num >= 1; num--) {
            int nextIndex = (num == 1) ? index : (index + num);
            if (used[num] == 0 && nextIndex < result.size() && result[nextIndex] == 0) {
                result[index] = num;
                result[nextIndex] = num;
                used[num] = 1;
                if (helper(result, used, index + 1, n)) {
                    return true;
                }
                used[num] = 0;
                result[index] = 0;
                result[nextIndex] = 0;
            }

        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(n*2-1);
        vector<int> used(n+1);
        helper(result,used,0,n);
        return result;
    }
};