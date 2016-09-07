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
        if(matrix.size() == 0) return v;
        if(matrix[0].size() == 0) return v;
        int rows = matrix.size() - 1, colums = matrix[0].size() - 1;
        int round = 0, all = (rows + 1) * (colums + 1);
        while(v.size() < all){
            step_colum(matrix, v, round, colums - round, round, 1);
            step_row(matrix, v, round, rows - round, colums - round, 1);
            step_colum(matrix, v, colums - round, round, rows - round, -1);
            step_row(matrix, v, rows - round, round, round, -1);
            round++;
        }
        return v;
    }
private:
    void step_row(vector<vector<int> > &matrix, vector<int> &v, int begin, int end, int colum, int step){
        while(begin != end){
            cout << "r:rows:" << begin << " colums:" << colum << endl;
            matrix_push(matrix, v, begin, colum);
            begin+=step;
        }
    }
    void step_colum(vector<vector<int> > &matrix, vector<int> &v, int begin, int end, int row, int step){
        while(begin != end){
            cout << "c:roows:" << row << " colums:" << begin << endl;
            matrix_push(matrix, v, row, begin);
            begin+=step;
        }
    }
    void matrix_push(vector<vector<int> > &matrix, vector<int> &v, int row, int colum){
        v.push_back(matrix[row][colum]);
    }
};


int main(){
    Solution *s = new Solution();
    vector<vector<int> > matrix;
    int a[4][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> v1(a[0], a[0] + 5);
    vector<int> v2(a[1], a[1] + 5);
    vector<int> v3(a[2], a[2] + 5);
    vector<int> v4(a[3], a[3] + 5);
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    vector<int> p = s->printMatrix(matrix);
    for(vector<int>::iterator iter = p.begin(); iter != p.end(); iter++)
        cout << *iter << ",";
    cout << endl;
}
