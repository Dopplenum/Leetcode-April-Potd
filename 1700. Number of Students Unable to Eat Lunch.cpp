class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int one=0,zero=0;
        for(int i=0; i<n; i++){
            if(students[i]==1){
                one++;
            }
            else{
                zero++;
            }
        }

        for(int i=0; i<n; i++){
            if ((sandwiches[i] == 0 && zero == 0) || (sandwiches[i] == 1 && one == 0))
                return n - i;
            if (sandwiches[i] == 0)
                zero--;
            else
                one--;
        }
        return 0;
    }
};
