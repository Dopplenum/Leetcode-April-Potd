class Solution {
public:
    // APPROACH -1 
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        string res="";
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]==')'){
                cnt++;
            }
        }
        cout<<cnt<<" "<<endl;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else if(s[i]==')' && st.empty()){
                s[i]='*';
            }
        }
        for(int i=0; i<n; i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                res+=s[i];
            }
        }
        return res;
    }

    //APPROACH -2 USING STACK AND SET
    string minRemoveToMakeValid(string s){
        int n=s.size();
        unordered_set<int>s1;
        stack<int>st;
        //WHY WE PUSH INDEXES INSTEAD OF ( BRACKETS IS BECAUSE WE WILL NOT DETERMINE WHICH BRACKET WE HAVE TO REMOVE
        // FOR EG String: LEE((T(C)O)DE

            // Stack: []

            // Step 1:
            // String: LEE((T(C)O)DE
            // Stack: [ '(' ]

            // Step 2:
            // String: LEE((T(C)O)DE
            // Stack: [ '(' '(' ]

            // Step 3:
            // String: LEE((T(C)O)DE
            // Stack: [ '('  '('  '(' ] 

            //Step 4:
            // String: LEE((T(C)O)DE
            // Stack: [ '(' '(' ] pop

            //Step 5:
            // String: LEE(T(C)O)DE)
            // Stack: ['('] pop

            // now theres a open bracket left but we dont know its position so instead of pushing brackets
            // We will push indexes of brackets

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    s1.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            s1.insert(st.top());
            st.pop();
        }

        string res="";
        for(int i=0; i<n; i++){
            if(s1.find(i)==s1.end()){
                res.push_back(s[i]);
            }
        }
        return res;
    }

    //APPROACH -3 WITHOUT STACK
    string minRemoveToMakeValid(string s){
        int n=s.size();
        int open=0;
        string temp="";
        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                temp.push_back(s[i]);
            }
            else if(s[i]=='('){
                open++;
                temp.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(open>0){
                    open--;
                    temp.push_back(s[i]);
                }
            }
        }
        int close=0;
        string res="";
        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]>='a' && temp[i]<='z'){
                res.push_back(temp[i]);
            }
            else if(temp[i]==')'){
                close++;
                res.push_back(temp[i]);
            }
            else if(temp[i]=='('){
                if(close>0){
                    close--;
                    res.push_back(temp[i]);
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
