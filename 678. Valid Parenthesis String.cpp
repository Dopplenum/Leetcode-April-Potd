class Solution {
public:

      bool f(int i, int open, string &s, vector<vector<int>>&dp){
        int n=s.size();
        if(i==n && open==0){
            return true;
        }

        if(open<0){
            return false;
        }

        if(dp[i][open]!=-1){
            return dp[i][open];
        }

        bool isValid=false;
        if(s[i]=='('){
            isValid=f(i+1,open+1,s,dp);
        }
        else if(s[i]==')'){
            isValid=f(i+1,open-1,s,dp);
        }
        else if(s[i]=='*'){
            isValid=(f(i+1,open+1,s,dp) || f(i+1,open,s,dp) || f(i+1,open-1,s,dp)); 
        }
        return dp[i][open]=isValid;
    }
    bool checkValidString(string s){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,0,s,dp);
    }
};
