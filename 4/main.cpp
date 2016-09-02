#include <iostream>
#include <vector>
using namespace std;

int find_n(vector<int>& nums1, vector<int>& nums2, int& n, int& li, int& ri){
    int pl = 0, pr = 0, l = nums1.size();
    if(nums1.size() > nums2.size()){
        return find_n(nums2, nums1, n, li, ri);
    }
    if(nums1.size() + nums2.size() < n){
        return 0;
    }
    cout << "nums1:" << l << '\n';
    while(n >= 0){
        cout << "n:" << n << '\n';
        cout << "pl:" << pl << ", pr:" << pr << '\n';
        cout << "li:" << li << ", ri:" << ri << '\n';
        if(nums1.size() == li){
            return nums2[ri + n - 1];
        }else if(n <= 1){
            return min(nums1[li], nums2[ri]);
        }

        pl = min(n / 2, l - li);
        pr = n - pl;

        if(nums1[li + pl - 1] <= nums2[ri + pr - 1]){
            li += pl;
            n -= pl;
        }else if(nums1[li + pl - 1] >= nums2[ri + pr - 1]){
            ri += pr;
            n -= pr;
        }
    }
    return 0;
}

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len = nums1.size() + nums2.size(), li = 0, ri = 0, n;

            // 保持l为较短的数组
            if (len & 1){
                n = len / 2 + 1;
                return find_n(nums1, nums2, n, li, ri);
            }else{
                n = len / 2;
                return (find_n(nums1, nums2, n, li, ri) + find_n(nums1, nums2, ++n, li, ri)) / 2.0;
            }
        }
};

int main(){
    int i1[4] = {1, 3, 7, 9};
    vector<int> nums1(i1, i1 + 4);
    int i2[2] = {2, 11};
    vector<int> nums2(i2, i2 + 2);
    int i3[2] = {1, 2};
    vector<int> nums3(i3, i3 + 2);
    int i4[2] = {3, 4};
    vector<int> nums4(i4, i4 + 2);
    Solution * s = new Solution();
    double d;
    d = s->findMedianSortedArrays(nums1, nums2);
    cout << d << '\n';
    d = s->findMedianSortedArrays(nums3, nums4);
    cout << d << '\n';
}
