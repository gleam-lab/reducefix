#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> data(n);
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if((i + 1) % 2 == 1) {
            sum += data[i];
        } else {
            sum += min(data[i], data[i - 1]);
        }
    }

    cout << sum << '\n';
    return 0;
}