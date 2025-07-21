#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n-1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long max_b = *max_element(b.begin(), b.end());
    long long min_a = *min_element(a.begin(), a.end());

    // Check if the largest box is big enough to hold the smallest toy
    if(max_b >= min_a) {
        cout << max_b << endl;
        return 0;
    }

    // Find the smallest x such that we can fit all toys in the boxes
    for(long long x = min_a; x <= max_b + max_b; ++x) {
        int j = 0;
        for(int i = 0; i < n; ++i) {
            if(j == n-1 || a[i] > b[j]) {
                cout << x << endl;
                return 0;
            }
            while(j < n-1 && b[j] < a[i])
                ++j;
        }
    }

    cout << -1 << endl;
    return 0;
}