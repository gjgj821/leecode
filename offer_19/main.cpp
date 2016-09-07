#include <iostream>
#include <vector>
using namespace std;


//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//则依次打印出数字         1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
class Solution{
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        int rows = matrix.size() - 1, colums = matrix[0].size() - 1;
        while(rows || colums){

        }
        return v;
    }
};


int main(){
    Solution *s = new Solution();
    vector<vector<int> > matrix;
    int a[][] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    vector<int> v1(a[0], a[0] + 4);
    vector<int> v2(a[1], a[1] + 4);
    vector<int> v3(a[2], a[2] + 4);
    vector<int> v4(a[3], a[3] + 4);
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    vector<int> p = s->printMatrix(matrix);
    for(vector<int>::iter iter = p.begin(); iter != p.end(); iter++)
        cout << *iter << ",";
    cout << endl;
}
