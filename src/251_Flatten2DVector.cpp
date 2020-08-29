#include <vector>
#include <iterator>

using namespace std;

class Vector2D {
private: 
  vector<int> nums;
  
public:
  Vector2D(vector<vector<int>>& v) {
    int nrVectors = v.size();
    for (int i=0; i<nrVectors; i++) {
        for (auto it = v[i].begin(); it!=v[i].end(); it++) {
            nums.push_back(*it);
        }
    }
  }

  int next() {
    if (!hasNext) return -1;
  }

  bool hasNext() {

  }
};