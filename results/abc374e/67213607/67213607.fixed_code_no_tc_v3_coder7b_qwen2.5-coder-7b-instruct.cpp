#include<bits/stdc++.h>
using namespace std;

// Function to calculate the cost for a given production capacity
long long calculateCost(vector<int>& a, vector<int>& p, vector<int>& b, vector<int>& q, int mid) {
    long long sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        long long minn = LLONG_MAX;
        for (int j = 0; j <= b[i]; ++j) {
            long long cost = j * p[i];
            if ((mid - j * a[i]) > 0) {
                cost += ((mid - j * a[i]) / b[i]) * q[i];
                if ((mid - j * a[i]) % b[i] != 0) {
                    cost += q[i];
                }
            }
            minn = min(minn, cost);
        }
        for (int j = 0; j <= a[i]; ++j) {
            long long cost = j * q[i];
            if ((mid - j * b[i]) > 0) {
                cost += ((mid - j * b[i]) / a[i]) * p[i];
                if ((mid - j * b[i]) % a[i] != 0) {
                    cost += p[i];
                }
            }
            minn = min(minn, cost);
        }
        sum += minn;
    }
    return sum;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search for the maximum production capacity
    int l = 0, r = 1e7 + 5;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calculateCost(a, p, b, q, mid) <= x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l - 1 << endl;
    return 0;
}