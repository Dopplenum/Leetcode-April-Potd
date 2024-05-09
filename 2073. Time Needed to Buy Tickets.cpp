class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(i<=k){
                if(tickets[i]<=tickets[k]){
                    cnt+=tickets[i];
                }
                else{
                    cnt+=tickets[k];
                }
            }
            else{
                if(tickets[i]<tickets[k]){
                    cnt+=tickets[i];
                }
                else{
                    cnt+=tickets[k]-1;
                }
            }
        }
        return cnt;
    }
};
