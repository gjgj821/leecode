#include <iostream>
#include <vector>
using namespace std;


// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution{
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0; i < array.size(); i++){
            if((array[i] & 1) == 0) continue;
            cout << i << array[i] << (array[i]&1) <<endl;
            for(int j = i; j > 0; j--){
                if((array[j - 1] & 1) == 1) break;
                int t = array[j];
                array[j] = array[j - 1];
                array[j - 1] = t;
            }
        }
    }
    void reOrderArray2(vector<int> &array){
        vector<int> v;
        int o = 0;
        for(int i = 0; i < array.size(); i++){
            if(array[i] & 1){
                if(o > 0) array[i - o] = array[i];
            }else{
                o++;
                cout << "i1:" << array[i] << endl;
                v.push_back(array[i]);
            }
        }
        for(int i = 0; i < o; i++){
            cout << "i:" << v[i] << endl;
            array[array.size() - o + i] = v[i];
        }
    }
};

int main(){
    Solution *s = new Solution();
    int a[] = {1,5,6,2,54,76};
    vector<int> v(a, a+6);
    s->reOrderArray2(v);
    for(int i =0; i< v.size(); i++)
        cout << v[i] << endl;
}
