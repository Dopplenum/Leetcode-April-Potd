class Solution {
public:
   // APPROACH -1 
    int lengthOfLastWord(string s) {
        int n=s.size();
        int len=0;
        bool found=false;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' '){
                len++;
                found=true;
            }
            else if(found==true){
                break;
            }
        }
        return len;
    }

    // APPROACH -2 // STL FUNCTIONS
    int lengthOfLastWord(string s) {
        
        //s.find_last_not_of(' ') : This function searches for the last character in the string s that is not equal to the space character ' '. 
                                    //It returns the index of the last non-space character found, or string::npos if no such character is found.
        //s.erase(pos)            : This function removes characters from the string s, starting from the position pos specified as an argument.
                                    //It removes characters from pos until the end of the string.
        
        s.erase(s.find_last_not_of(' ') + 1); //Removes the trailing spaces
        
        // Find the last space character
        int lastSpace = s.find_last_of(' ');

        // Calculate the length of the last word
        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;
        
    }
};
