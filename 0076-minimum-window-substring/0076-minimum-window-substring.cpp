
class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty() || t.size() > s.size())
            return "";

        int n = s.size();
        int m = t.size();

        int left = 0;
        int right = 0;
        int minlength = INT_MAX;
        int cnt = 0;
        int sIndex = -1;

        int hash[256] = {0};

        for(int i = 0; i < m; i++) {
            hash[(unsigned char)t[i]]++;
        }

        while(right < n) {

            if(hash[(unsigned char)s[right]] > 0)
                cnt++;

            hash[(unsigned char)s[right]]--;

            while(cnt == m) {

    // cout << "left = " << left << endl;
    // cout << "right = " << right << endl;
    // cout << "n = " << n << endl;

    // if(left >= n) {
    //     cout << "LEFT OUT OF BOUND";
    //     break;
    // }

    if(right - left + 1 < minlength) {
        minlength = right - left + 1;
        sIndex = left;
    }

    hash[(unsigned char)s[left]]++;

    if(hash[(unsigned char)s[left]] > 0) {
        cnt--;
    }

    left++;
}

            right++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlength);
    }
};
