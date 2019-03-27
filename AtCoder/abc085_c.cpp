#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Y;
    int x, y, z;

    cin >> N >> Y;

    for (int l = 0; l <= N; ++l) {
        for (int m = 0; m <= (N - l); ++m) {
            int n = N - m - l;
            int sum = 10000 * l + 5000 * m + 1000 * n;
            if (n >= 0 && Y == sum) {
                cout << l << " " << m << " " << n << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}
