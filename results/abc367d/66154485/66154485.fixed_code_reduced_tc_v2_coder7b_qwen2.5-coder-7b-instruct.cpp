#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long count = 0;
    for(int start = 0; start < n; ++start) {
        int sum = 0;
        for(int len = 1; len <= n; ++len) {
            int end = (start + len - 1) % n;
            sum += arr[end];
            if(sum % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}