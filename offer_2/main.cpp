#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0) return ;
        int blank_num = 0, i = 0;
        for(i = 0; str[i] != '\0'; i++){
            if(str[i] == ' ') blank_num++;
        }
        int old_length = i;
        int new_length = i + blank_num * 2;
        if(new_length > length) return ;
        while(new_length >= 0){
            if(str[old_length] == ' '){
                str[new_length--] = '%';
                str[new_length--] = '2';
                str[new_length--] = '0';
            }else{
                str[new_length--] = str[old_length];
            }
            old_length--;
        }
    }
};


int main(){
    Solution *s = new Solution();
    char *str = (char*)malloc(70*sizeof(char));
    char ss[] = "sdf sadfasd fsfa";
    strcpy(str, ss);
    s->replaceSpace(str, 70);
    cout << str << endl;
}
