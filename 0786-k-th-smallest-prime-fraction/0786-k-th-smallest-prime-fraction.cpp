class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> fractions;

        int n = arr.size();
        for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
            // Calculate fraction as double
            double fraction = (double)arr[i] / arr[j];
            fractions.push_back({fraction, {arr[i], arr[j]}});
          }
        }

        // Sort fractions by value (ascending order) with custom comparator
        sort(fractions.begin(), fractions.end(), 
            [](const auto& a, const auto& b) { return a.first < b.first; });

        // Access kth smallest fraction (0-indexed) and return numerator/denominator
        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};