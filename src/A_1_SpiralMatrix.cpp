#include <vector>
#include <iostream>
using namespace std;

int main() {
    int arr[3][4] = {{1,2,3,4}, 
                     {4,5,6,6},
                     {7,8,9,9}};
    vector<int> nums;
    int size = sizeof(arr)/sizeof(int);
    int top = 0, bottom = sizeof(arr)/sizeof(arr[0]) - 1, left = 0, right = sizeof(arr[0])/sizeof(int)-1; 
     
    while (nums.size()!=size) {
        if (top<bottom) {
            for (int j=left; j<=right; j++) {
                nums.push_back(arr[top][j]);
            }
        }
        top++;
        if (left<right) {
            for (int i=top; i<=bottom; i++) {
                nums.push_back(arr[i][right]);
            }
        }
        right--;
        if (top<bottom) {
            for (int j=right; j>=left; j--) {
                nums.push_back(arr[bottom][j]);
            }
        }
        if (left<right) {
            bottom--;
            for (int i=bottom; i>top; i--) {
                nums.push_back(arr[i][left]);
            }
        }
        left--;
    }
    for (auto el : nums) {
        cout << el << endl;
    }
    return 0;
}