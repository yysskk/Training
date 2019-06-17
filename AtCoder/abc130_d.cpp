// SeeAlso: 

#include <bits/stdc++.h>

#define MAX 100000
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

long long N, K;
long long a[MAX];

int main() {
    
    cin >> N >> K;

    rep(i, N) {
        cin >> a[i];
    }

    long long ans = 0;
    int right = 0;     
    long long sum = a[0];

    for (int left = 0; left < N; ++left) {
        while (sum < K) {
            if (right==N) break;
            else {
                sum+= a[right];
                right++;
            }

        }
        


        /* left をインクリメントする準備 */
        if (sum < K) break;
        ans += N-right+1;
        sum -= a[left];

    }

    cout << ans << endl;
    
    return 0;
}
