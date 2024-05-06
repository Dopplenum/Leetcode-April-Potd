class Solution {
public:
    string makeGood(string s) {
        // int n=s.size();
        // string res="";
        // for(int i=0; i<n; i++){
        //     if(res.size()>0 && (s[i]+32==res.back() || s[i]-32==res.back())){
        //         res.pop_back();
        //     }
        //     else{
        //         res.push_back(s[i]);
        //     }
        // }
        // return res;
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(st.empty()) st.push(s[i]);
            else if(st.top()==s[i]+32 || st.top()==s[i]-32) st.pop();
            else st.push(s[i]);
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
