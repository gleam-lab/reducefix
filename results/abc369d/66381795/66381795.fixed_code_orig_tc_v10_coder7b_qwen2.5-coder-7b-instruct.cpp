#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> data(n);
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if((i + 1 < n && data[i] * 2 > data[i + 1]) || (i == n - 1)) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }

    cout << sum << endl;
    return 0;
}