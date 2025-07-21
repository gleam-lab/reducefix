#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<long long> pref(MAXN);

long long get(int x, int y) {
    return pref[y] - pref[x];
}

int main() {
    ios_base::sync_witheczy