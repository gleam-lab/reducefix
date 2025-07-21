#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& a, vector<int>& b, int x) {
    multiset<int> s(b.begin(), b.end());
    for(int i = 0; i < a.size(); ++i) {
        auto it = s.lower_bound(a[i]);
        if(it == s.end()) return false;
        s.erase(it);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0, r = *max_element(b.begin(), b.end());
    while(l <= r) {
        int m = (l + r) / 2;
        if(canPlace(a, b, m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << l << endl;

    return 0;
}