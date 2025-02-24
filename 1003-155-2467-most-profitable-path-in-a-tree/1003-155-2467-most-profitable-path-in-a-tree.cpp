class Solution {
public:
    unordered_map<int,vector<int>>adj;
    int aliceIncome;
    unordered_map<int,int> BobMap;

    bool DFSforBob(int curr, int t, vector<bool>&visited){
        visited[curr]=true;
        BobMap[curr]=t;

        if(curr==0)
            return true;

        for(auto &ngbr:adj[curr]){
            if(!visited[ngbr]){
                if(DFSforBob(ngbr,t+1,visited)==true)
                    return true;
            }
        }
        BobMap.erase(curr);
        return false;
    }

    void DFSforAlice(int curr, int currIncome, int t, vector<bool>&visited, vector<int>&amount){
        visited[curr]=true;
        
        if(BobMap.find(curr)==BobMap.end() || t<BobMap[curr]){
            currIncome+=amount[curr];
        }
        else if(t==BobMap[curr]){
            currIncome+=(amount[curr]/2);
        }

        if(adj[curr].size()==1 && curr!=0){
            aliceIncome = max(aliceIncome,currIncome);
            return;
        }
        for(auto &ngbr:adj[curr]){
            if(!visited[ngbr]){
                DFSforAlice(ngbr,currIncome,t+1,visited,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time=0;
        vector<bool>visited(n,false);
        DFSforBob(bob,time,visited);

        visited.assign(n,false);
        aliceIncome=INT_MIN;
        int currIncome=0;

        DFSforAlice(0,currIncome,0,visited,amount);

        return aliceIncome;
    }
};