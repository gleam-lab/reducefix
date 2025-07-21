#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double best = numeric_limits<double>::max();
    for (int i = 0; i <= n - k; i++) {
        double max_val = *max_element(v.begin() + i, v.begin() + n);
        double min_val = *min_element(v.begin() + i, v.begin() + n);
        double current_diff = max_val - min_val;
        best = min(best, current_diff);
    }

    cout << best << endl;
    return 0;
}