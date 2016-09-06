#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        for(int i = 0; i < rotateArray.size() - 1; i++){
            if (rotateArray[i] > rotateArray[i + 1])
                return rotateArray[i + 1];
        }
        return rotateArray[0];	
    }
};

int main(){
    Solution *s = new Solution();
    int a[] = {1, 1, 1, 0, 1, 1};
    vector<int> v(a, a+6);
    int m = s->minNumberInRotateArray(v);
    cout << m << endl;
}
