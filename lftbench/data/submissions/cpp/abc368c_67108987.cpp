#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N + 9);
	for (int i = 1; i <= N; i++) cin >> H[i];
	long long T = 0;
	for (int i = 1; i <= N; i++) {
		long long a = H[i] / 5;
		H[i] -= a * 5;
		T += a * 3;
		if (H[i] > 0) {
			T += 1;
			H[i] -= 1;
		}
		if (H[i] > 0) {
			T += 1;
			H[i] -= 1;
		}
		if (H[i] > 0) {
			T += 1;
			H[i] -= 3;
		}
	}
	cout << T << endl;
	return 0;
}
