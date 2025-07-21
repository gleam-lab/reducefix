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
    for(auto &val : v) {
        cin >> val;
    }
    sort(v.begin(), v.end());

    int result = INT_MAX;
    for(int i = 0; i <= k; ++i) {
        result = min(result, v[n-k+i]-v[i]);
    }

    cout << result;
}