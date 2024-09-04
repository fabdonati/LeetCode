class Solution {
public:
    bool isFeasible(const int& capacity, const int& max_days, const std::vector<int>& weights) {
        int days = 1;
        int local = 0;
        for (int i=0; i<weights.size(); i++) {
            local += weights[i];
            if (local > capacity) {
                days += 1;
                local = weights[i];
                if (days > max_days) return false;
            }
        }
        return true;
    }
    
    int maxWeight(const std::vector<int>& weights) {
        int max_weight = -1;
        for (const auto& w : weights) {
            if (w > max_weight) max_weight = w;
        }
        return max_weight;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = maxWeight(weights);
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right-left)/2;
            if (isFeasible(mid, days, weights)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};