class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }else{
            vector <int> h(26);
            for(int i=0;i<s.size();i++){
                h[s[i]-'a']++;
            }
            for(int i=0;i<t.size();i++){
               --h[t[i]-'a'];
               if(h[t[i]-'a'] < 0){
                return false;
            }
             
            }
             
             return true;
        }
        
    }
};