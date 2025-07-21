#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int x;
    while (cin >> x)
        a.push_back(x);

    int answer = INT_MAX;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(a.begin() + i, a.end(), a[i] + k);
        if (it == a.end()) continue;

        int min_val = INT_MAX, max_val = -INT_MAX;
        for (int j = i; j < min(n, it - a.begin() + k); ++j) {
            min_val = min(min_val, a[j]);
            max_val = max(max_val, a[j]);
        }

        answer = min(answer, max_val - min_val);
    }

    cout << answer << endl;
    return 0;
}