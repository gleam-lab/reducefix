#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N);
    for(long long i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    long double total_cost = 0.0;
    
    for(long long i = 0; i < N; ++i) {
        total_cost += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        if(i > 0) {
            total_cost += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
        }
    }
    
    total_cost += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));
    
    cout.precision(10);
    cout << total_cost << endl;
    
    return 0;
}