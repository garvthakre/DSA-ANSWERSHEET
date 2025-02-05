class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;  // Already equal
        }
        
        vector<int> diffIndices;
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }
        
        if (diffIndices.size() != 2) {
            return false;  // More than 2 differences cannot be fixed with one swap
        }
        
        // Check if swapping makes them equal
        int i = diffIndices[0], j = diffIndices[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};
