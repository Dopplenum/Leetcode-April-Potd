class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            int val=q.front();
            res[val]=deck[i];
            q.pop();
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        return res;
    }
};
