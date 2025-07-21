// ä¼ªä»£ç ï¼ç¨äºå±ç¤ºè§£å³æ¹æ¡æè·¯
sort(A.begin(), A.end(), greater<int>()); // æç¥¨æ°éåºæåº

for (int i = 0; i < N; ++i) {
    if (i > 0 && A[i] - A[i-1] >= M) {
        // å·²ç»ä¿è¯èå©
        C[i] = 0;
        continue;
    }

    int diff = M + A[i-1]; // éè¦è¾¾å°çæå°ç¥¨æ°
    if (diff > K - sum(A)) {
        C[i] = -1;
    } else {
        C[i] = diff - A[i];
    }
}

// è¾åºç»æ
for (int i = 0; i < N; ++i) {
    cout << C[i] << " ";
}