class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productList;
        vector<int> reverseProductList;
        vector<int> result;
        
        int n = nums.size();
        productList.push_back(nums[0]);
        reverseProductList.push_back(nums[n-1]);
        
        
        for(int i=1;i<n;i++) {
            productList.push_back ( productList[i-1] * nums[i] );
            reverseProductList.push_back(reverseProductList[i-1] * nums[n-1-i]);
        }
        
        reverse(reverseProductList.begin(),reverseProductList.end());
        
        int prefix = 0;
        int suffix = 0;

        for(int i = 0;i<n;i++){
            if(i==0){
                prefix = 1;
                suffix = reverseProductList[1];
            }
            else if(i == n-1){
                prefix = productList[n-2];
                suffix = 1;
            }
            
            else{
                prefix = productList[i-1];
                suffix = reverseProductList[i+1];
            }
            result.push_back(prefix * suffix);
        }
        
        return result;
        
    }
};


// 1 2 3 4
// 1 2 6 24
// 0 1 2 3

// 4 3 2 1
// 4 12 24 24
// 0 1 2 3

// 1 2 3 4
// 24 24 12 4
// 0 1 2 3

