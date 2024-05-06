class Solution {
public:
    int maxDepth(string s) {
        // int n=s.size();
        // int res=0;
        // stack<char>st;
        // for(int i=0; i<n; i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else if(s[i]==')'){
        //         st.pop();
        //     }

        //     res=max(res,(int)st.size());
        // }
        // return res;
        int n=s.size();
        int res=0,cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            res=max(res,cnt);
        }
        return res;
    }
};
