class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> stk;
        vector<int> result;

        for(int i=0;i<=n;i++){
            stk.push(i+1);

            if(i == n || pattern[i] == 'I'){
                while(!stk.empty()){
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
        }

        string resultStr = "";
        for(int num: result){
            resultStr += to_string(num);
        }

        return resultStr;
    }
};