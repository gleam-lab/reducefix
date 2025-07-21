#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < q; ++i) {
        long long b, k;
        cin >> b >> k;
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int index = it - a.begin();
        long long diff = abs(a[index] - b);
        int count = 0;
        
        while(count < k && index >= 0) {
            if(abs(a[index] - b) <= diff) {
                diff = abs(a[index] - b);
                --index;
                ++count;
            } else {
                break;
            }
        }
        
        if(count == k) {
            cout << diff << '\n';
        } else {
            cout << "Invalid query\n";
        }
    }

    return 0;
}