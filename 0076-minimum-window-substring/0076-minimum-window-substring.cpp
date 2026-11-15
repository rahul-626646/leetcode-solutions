class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int left = 0;
        int right = 0;
        int minlength = INT_MAX;
        int count  = 0;
        int sIndex = -1;
        int hash[256] = {0};
        if(m > n || t.empty()) return "";
        for(int i = 0; i<m; i++){
            hash[(unsigned char)t[i]]++;
        }
        while (right < n){
            if(hash[(unsigned char)s[right]] > 0) count++;
            hash[(unsigned char)s[right]]--;

            while(count == m){
                if(right - left + 1 < minlength){
                    minlength = right - left + 1;
                    sIndex = left;
                }
                hash[(unsigned char)s[left]]++;
                if(hash[(unsigned char)s[left]] > 0){
                    count--;
                }
                left = left + 1;
            }
            right = right + 1;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlength);

    }
};