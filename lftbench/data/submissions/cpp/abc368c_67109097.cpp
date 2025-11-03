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
		int b = H[i] % 5;
		T += a * 3;
		while (b > 0) {
			if (b % 3 == 0)b -= 3;
			else b -= 1;
			T++;
		}
		
	}
	cout << T << endl;
	return 0;
}
