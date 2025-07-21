#include <bits/stdc++.h>
using namespace std;

long long binary_search(long long x, vector<long long>& a, vector<long long>& pref, int m) {
    int n = a.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long total_votes = pref[mid + 1] - pref[left];
        long long others_votes = (n - mid - 1) * x - (pref[n] - pref[mid + 1]);
        if (total_votes + others_votes >= (m - 1) * x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.rbegin(), a.rend());
    vector<long long> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> res(n);
    for(int i = 0; i < n; ++i) {
        long long needed = binary_search(a[i], a, pref, m);
        if (needed > k) {
            res[i] = -1;
        } else {
            res[i] = needed;
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}