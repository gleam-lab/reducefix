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
    for(int i = 0; i < n-1; ++i) {
        sum += min(2LL * data[i], data[i] + data[i+1]);
    }
    // Add the last element as it's not added in the loop
    sum += data[n-1];

    cout << sum << endl;
    return 0;
}