// SeeAlso: https://atcoder.jp/contests/arc029/tasks/arc029_1

#include <bits/stdc++.h>

#define MAX 5
#define rep(i,n) for(int i=0;i<n;i++)

const int INF = 1e9;

using namespace std;

int main() {
    int N;
    int t[MAX];
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    int ans = INF;

    for (int bit = 0; bit <= (1<<4); bit++) {
        int a = 0;
        int b = 0;
        rep(i,4){
            if (bit & (1 << i)) {
                a += t[i];
            } else {
                b += t[i];
            }
        }
        ans =  min(ans, max(a, b));
    }

    cout << ans << endl;
    return 0;
}
