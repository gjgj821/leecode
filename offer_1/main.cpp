#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        vector<vector<int> >::iterator iter = array.begin();
        int rows = array.size() - 1, colums = (*iter).size() - 1;
        int row = 0, colum = colums;
        while(colum >= 0 && row <= rows){
            int a = *((*(iter+row)).begin()+colum);
            cout << a << " colum:" << colum << " row:" << row << endl;
            if(a == target){
                return true;
            }else if(a > target){
                colum--;
            }else{
                row++;
            }
        }
        return false;
    }
};


int main(){
    Solution *s = new Solution();
    vector<vector<int> > array;
    int a1[] = {1, 2, 8, 9};
    vector<int> v1(a1, a1+4);
    array.push_back(v1);
    int a2[] = {2, 4, 9, 12};
    vector<int> v2(a2, a2+4);
    array.push_back(v2);
    int a3[] = {4, 7, 10, 13};
    vector<int> v3(a3, a3+4);
    array.push_back(v3);
    int a4[] = {6, 8, 11, 15};
    vector<int> v4(a4, a4+4);
    array.push_back(v4);
    bool f = s->Find(array, 1);
    cout << f << endl;
}
