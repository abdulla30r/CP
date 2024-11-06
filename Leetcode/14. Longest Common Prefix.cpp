class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        int k = strs[0].length();
        for(int i=0;i<k;i++){
            char current = strs[0][i];
            for(int j = 0;j<n;j++){
                if(strs[j][i]!=current){
                    return res;
                }
            }
            
            res+=current;
        }
        
        return res;
        
    }
};