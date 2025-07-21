#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> pointsA[MAXN], pointsB[MAXN];

struct Query {
    int index, b_index, k;
};

bool compare(const Query &a, const Query &b) {
    return a.b_index < b.b_index;
}

int binary_search(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N), B(Q);
    vector<Query> queries(Q);

    // Read points A
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
        pointsA[binary_search(pointsA, A[i])].push_back(A[i]);
    }

    // Read points B and queries
    for(int i = 0; i < Q; ++i) {
        cin >> B[i] >> queries[i].k;
        queries[i].index = i;
        queries[i].b_index = binary_search(pointsB, B[i]);
    }

    // Sort queries based on b_index
    sort(queries.begin(), queries.end(), compare);

    // Process each query
    int j = 0;
    for(auto& query : queries) {
        while(j < N && pointsA[j][0] < B[query.b_index]) ++j;
        cout << abs(B[query.b_index] - pointsA[query.b_index][query.k - 1]) << '\n';
    }

    return 0;
}