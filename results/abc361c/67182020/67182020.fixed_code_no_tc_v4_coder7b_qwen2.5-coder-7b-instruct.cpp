#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define coutY cout << "Yes" << endl;
#define coutN cout << "No" << endl;
#define FOR(i,l,r) for(int i=l;i<r;++i)
#define FORrev(i,l,r) for(int i=l;i>r;--i)
#define arrIn(arr, start, N) for (int i = (start); i < (N); ++i) cin >> arr[i];
#define arrOut(arr, start, N) for  (int i = (start); i < (N); ++i) { cout << arr[i] <<" "; } cout << endl;
#define arrCopy(arr1,arr2, start, N) for (int i = (start); i < (N); ++i) arr2[i]= arr1[i];
#define partmax(arr, start, end) *max_element(arr.begin()+start,A.begin()+end);
void yn(bool tf) { cout << (tf ? "Yes\n" : "No\n"); }

// Function to find the minimum difference between max and min in a subarray of size N-K
int minDiff(vector<int>& A, int K) {
    int N = A.size();
    sort(A.begin(), A.end());
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= N - K; ++i) {
        int current_diff = A[i + K - 1] - A[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    return min_diff;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    arrIn(A, 0, N);
    
    int result = minDiff(A, K);
    cout << result << endl;
    
    return 0;
}