#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int qi = 0; qi < q; ++qi) {
        int b, k;
        cin >> b >> k;

        // Binary search for the k-th smallest distance
        int left = 0, right = 1e8 + 100;
        while(left < right) {
            int mid = (left + right) / 2;
            int count = 0;

            // Count how many points are within distance mid of b
            for(int ai : a) {
                if(abs(ai - b) <= mid) {
                    count++;
                }
            }

            if(count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << '\n';
    }

    return 0;
}