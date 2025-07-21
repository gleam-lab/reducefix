#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6 + 7;

// Function to calculate prefix sums of an array
vector<LL> prefixSum(vector<int>& arr) {
    vector<LL> ps(arr.size() + 1, 0);
    for(int i = 1; i <= arr.size(); ++i) {
        ps[i] = ps[i - 1] + arr[i - 1];
    }
    return ps;
}

// Function to find the first index where element is greater than or equal to x using binary search
int findFirstGreaterOrEqual(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return arr[left] >= x ? left : -1;
}

// Function to find the last index where element is less than or equal to x using binary search
int findLastLessOrEqual(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        int mid = left + (right - left + 1) / 2;
        if(arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return arr[right] <= x ? right : -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Calculate prefix sum arrays for both a and b
    auto pa = prefixSum(a);
    auto pb = prefixSum(b);

    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;

        // Find the indices in a[] which have value >= l and <= r
        int start_a = findFirstGreaterOrEqual(a, l);
        int end_a = findLastLessOrEqual(a, r);

        // Find the indices in b[] which have value >= l and <= r
        int start_b = findFirstGreaterOrEqual(b, l);
        int end_b = findLastLessOrEqual(b, r);

        // Calculate the result based on the prefix sums
        LL result = (pa[end_a + 1] - pa[start_a]) * (pb[end_b + 1] - pb[start_b]);
        cout << result << '\n';
    }

    return 0;
}