#include<bits/stdc++.h>
#include<vector>
#define endl "\n"
using namespace std;
typedef long long ll;

struct Point {
    int coord;
    int index;
};

bool compare(const Point& p1, const Point& p2) {
    return p1.coord < p2.coord;
}

vector<int> findKthClosestDistances(vector<int>& A, vector<pair<int, int>>& queries) {
    vector<int> results;
    sort(A.begin(), A.end());
    
    for(auto& query : queries) {
        int b_j = query.first;
        int k_j = query.second;
        
        vector<Point> distances;
        for(int i = 0; i < A.size(); ++i) {
            distances.push_back({abs(A[i] - b_j), i});
        }
        
        sort(distances.begin(), distances.end(), compare);
        
        results.push_back(distances[k_j - 1].coord);
    }
    
    return results;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    
    vector<pair<int, int>> queries(Q);
    for(int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<int> results = findKthClosestDistances(A, queries);
    
    for(int result : results) {
        cout << result << endl;
    }
    
    return 0;
}