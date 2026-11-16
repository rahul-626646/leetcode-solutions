class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() || t.empty()) return "";
        int left = 0, right = 0;
        int minlength = INT_MAX;
        int sIndex = -1;
        int hash[256 ] = {0};
        int count = 0;
        for(int i =0; i<t.size(); i++){
            hash[(unsigned char)t[i]]++;

        }
        while(right < s.size()){
            if(hash[(unsigned char)s[right]] > 0) count++;
            hash[(unsigned char)s[right]]--;
            while(t.size()  ==  count){
                if(right - left + 1 < minlength){
                    minlength = right - left + 1;
                    sIndex = left;
                }
                hash[(unsigned char )s[left]]++;
                if(hash[(unsigned char)s[left]] > 0){
                    count--;
                }
                left++;
            }
            right = right + 1;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlength);
    }
};