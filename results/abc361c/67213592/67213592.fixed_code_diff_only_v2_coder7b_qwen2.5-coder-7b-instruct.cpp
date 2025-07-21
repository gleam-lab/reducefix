#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for(auto& val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    int min_diff = INT_MAX;

    for(int i = 0; i <= k; ++i) {
        int diff = v[n-k+i-1] - v[i];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}