#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
    string longestPalindrome(string s) {
        int l = s.size() * 2 + 1;
        char *t = new char[l];  // 填充字符,用于将回文都转换为奇数
        int *p = new int[l];
        int max = 0, id = 0;
        for(int i = 0; i < s.size(); i++){
            t[i + i + 2] = s[i];
            t[i + i + 1] = '#';
        }
        t[0] = '$';  // 必须保证与首字符不相同
        for(int i = 2; i < 2 * s.size() + 1; ++i){
            if(p[id] + id > i) p[i] = min(p[ 2 * id - i ], p[id] + id - i);
            else p[i] = 1;
            while(t[i - p[i]] == t[i + p[i]]) ++p[i];
            if(id + p[id] < i + p[i]) id=i;
            if(max < p[i]) max = p[i];
        }
        delete [] t;
        delete [] p;
        return max - 1;
    }
};


int main(){
    string a = "abcabccdebcd";
    Solution * s = new Solution();
    string b = s->longestPalindrome(a);
    cout << a << ':' << b << '\n';
}
