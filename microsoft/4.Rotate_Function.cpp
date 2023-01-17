#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum =0;
        for( int i=0; i<nums.size(); i++ ) {
            sum += nums[i];
        }

        int sum_ele = 0;
        for( int i=1; i<nums.size(); i++ ){
            sum_ele += nums[i] * i;
        }

        int largest = sum_ele;
        for( int i=nums.size()-1; i>-1; i-- ) {
            sum_ele += sum - (nums.size() * nums[i]);

            if( sum_ele > largest ) largest = sum_ele;
        }

        return largest;
    }
};

int main() {
    vector<int> v = {4,3,2,6};

    Solution s; 
    cout << s.maxRotateFunction( v );

    // cout << ( 0 > -30428852 );
    return 0;
}