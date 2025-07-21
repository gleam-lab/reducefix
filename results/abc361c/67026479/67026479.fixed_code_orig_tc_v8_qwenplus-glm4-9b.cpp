#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int answer = INT_MAX;
    for(int i = 0; i <= n - k; ++i) {
        int max_val = a[i + k - 1];
        int min_val = a[i];
        answer = min(answer, max_val - min_val);
    }
    
    cout << answer << endl;
}