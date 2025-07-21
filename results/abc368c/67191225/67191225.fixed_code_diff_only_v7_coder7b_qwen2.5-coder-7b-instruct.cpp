#include<iostream>
#include<vector>
using namespace std;

long long minTime(int n, vector<int> &h) {
    long long ans = 0;
    for(auto x: h) {
        if(x % 3 == 0) ans += x / 3;
        else ans += (x / 3 + 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    cout << minTime(n, h) << endl;
    return 0;
}