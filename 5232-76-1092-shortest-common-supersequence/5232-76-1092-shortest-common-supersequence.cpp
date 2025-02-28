class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = computeLCS(str1, str2);

        stringstream ans;
        int i = 0, j = 0;

        for (char c : lcs) {
            while (str1[i] != c) ans << str1[i++];
            while (str2[j] != c) ans << str2[j++];
            ans << c;
            i++, j++;
        }

        ans << str1.substr(i) << str2.substr(j);
        return ans.str();
    }

private:
    string computeLCS(const string& s1, const string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Compute LCS length
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string lcs;
        int i = n1, j = n2;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs += s1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};