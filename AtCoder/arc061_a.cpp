#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int sum = 0;

    int n = s.size();

    for (int i = 0; i < pow(2,n-1); ++i) {
        int a = s[0] - '0';
        for (int j = 0; j < n-1; ++j) {
            if (i >> j & 1 == 1) {
                sum += a;
                a = s[j + 1] - '0';
            } else {
                a = 10 * a;
                a += s[j + 1] - '0';
            }
        }
        sum += a;
    }

    cout << sum << endl;
    
    return 0;
}
