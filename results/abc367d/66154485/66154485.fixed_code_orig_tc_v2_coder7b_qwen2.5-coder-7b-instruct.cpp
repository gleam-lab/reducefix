#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = 0;

    for(int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for(int j = 0; j < n; ++j) {
            current_sum += arr[(i + j) % n];
            if(current_sum % m == 0) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}