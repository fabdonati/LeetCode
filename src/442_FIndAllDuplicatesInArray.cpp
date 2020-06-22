#include <iostream>
#include <vector>
// could use hashmap without constraint of extra space
// linear O(n) - only extra space is for output vector
// idea is to loop through all elements and mark as negative the element at the (abs(input(i)) - 1) index
// if then the same element is accessed again, it means that (element at that index) + 1 is duplicate

using namespace std;

int main() {
    std::vector<int> input {4,3,2,7,8,2,3,1};
    std::vector<int> output;
    for (int i=0; i<input.size(); i++) {
        int index = abs(input[i])-1;
        if (input[index] < 0) {
            output.push_back(index+1);
        } 
        else {
            input[index] = -input[index];
        }
    }
    for (auto o : output) {
        cout << o << endl;
    }
    return 0;
}