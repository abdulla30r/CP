class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        // If needle is longer than haystack, return -1
        if (needle.length() > haystack.length()) {
            return -1;
        }

        // Iterate through the haystack string
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            // Check if the substring of haystack starting at position i matches needle
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};