#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void slidingWindow(const vector<int>& a, int n, int k, int& minDiff) {
    vector<int> maxValues(n);
    vector<int> minValues(n);
    int leftMax = a[0], leftMin = a[0];

    for (int i = 0; i < n; i++) {
        // Update maxValues
        if (leftMax < a[i] || i == 0) leftMax = a[i];
        maxValues[i] = leftMax;

        // Update minValues
        if (leftMin > a[i] || i == 0) leftMin = a[i];
        minValues[i] = leftMin;
    }

    int i = 0, j = n - 1;
    while (j > 0) {
        int maxVal = max(maxValues[j], maxValues[i]);
        int minVal = min(minValues[j], minValues[i]);
        minDiff = min(minDiff, maxVal - minVal);
        i++;
        j--;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int minDiff = INT_MAX;
    slidingWindow(a, n, k, minDiff);

    cout << minDiff << endl;

    return 0;
}