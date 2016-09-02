#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int si = s.size();
        int i, f = 0, max = 0;
        map<char, int> m;
        for(i = 0; i < si; i++){
            char c = s[i];
            if(m.count(c) && m[c] >= f){
                f = m[c] + 1;
            }
            if(i - f > max){
                max = i - f;
            }
            m[c] = i;
        }
        return si > 0 ?  max + 1 : 0;
    }
};

int main(){
    string a = "abba";
    int i = 0;
    Solution *s = new Solution();
    i = s->lengthOfLongestSubstring(a);
    cout << s << ": length:" << i << '\n';
}
