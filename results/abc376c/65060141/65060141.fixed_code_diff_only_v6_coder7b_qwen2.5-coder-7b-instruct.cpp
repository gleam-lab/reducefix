#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int> a(N), b(N);

bool check(int mid) {
    vector<int> count(mid + 1, 0);
    for (auto &val : a) {
        if (val <= mid)
            count[val]++;
    }
    
    int used = 0;
    for (int i = mid; i >= 1; --i) {
        if (count[i] > 1 || (count[i] == 1 && i < mid)) {
            used += count[i];
            count[i / 2] += count[i] - 1;
        } else if (used > 0) {
            used -= 1;
            count[i / 2] += 1;
        }
    }
    
    return used == 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        cin >> b[i];
    
    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + n);
    
    int left = *max_element(a.begin() + 1, a.end()), right = b[n - 1];
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    
    cout << (check(left) ? left : -1) << '\n';
    return 0;
}