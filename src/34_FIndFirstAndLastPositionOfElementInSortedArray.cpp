#include <iostream>
#include <vector>
// sorted gived array and a target, need O(log n) --> binary search
// if nothing [-1,-1]

using namespace std;

int findStartingIndex(vector<int> input, int target) {
    int index = -1;
    int start = 0, end = input.size()-1;
    while (start <= end) {
        int mid = start+(end-start)/2;
        if (input[mid]>=target) { // larger or equal because we want the first occurrence
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        if (input[mid]==target) index = mid;
    }
    return index;
}

int findEndingIndex(vector<int> input, int target) {
    int index = -1;
    int start = 0, end = input.size()-1;
    while (start <= end) {
        int mid = start+(end-start)/2;
        if (input[mid]<=target) { // smaller or equal because we want the last occurrence
            start = mid + 1;
        } else {
            end = mid - 1;    
        }
        if (input[mid]==target) index = mid;
    }
    return index;
}

vector<int> searchRange(vector<int> input, int target) {
    vector<int> output(2);
    output[0] = findStartingIndex(input, target);
    output[1] = findEndingIndex(input, target);
    return output;
}

int main() {
    std::vector<int> input {5,7,7,8,8,10};
    std::vector<int> output;
    output = searchRange(input, 8);
    cout << output[0] << endl;
    cout << output[1] << endl;
    
    return 0;
}