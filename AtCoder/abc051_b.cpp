#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, S;
    int ans = 0;

    cin >> K >> S;

    for (int X = 0; X <= K; ++X) {
        for (int Y = 0; Y <= K; ++Y) {
            int Z = S - X - Y;
            if (Z <= K && Z >= 0) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
