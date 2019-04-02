// SeeAlso: https://atcoder.jp/contests/abc079/tasks/abc079_c

#include <bits/stdc++.h>

#define MAX 4
using namespace std;

int main() {
    string S;
    int num[MAX];
    
    cin >> S;

    for (int i = 0; i < MAX; i++) {
        num[i] = S[i] - '0';
    }

    string ans;

    for (int bits; bits < 1 << 3; bits++) {
        int sum = num[0];
        for (int i = 0; i < 3; i++) {
            sum += ((bits >> i) & 1) ? num[i + 1] : -num[i + 1];
        }
        if (sum == 7) {
            ans.push_back(S[0]);
            for (int i = 0; i < 3; i++) {
                char operand = ((bits >> i) & 1) ? '+' : '-';
                ans.push_back(operand);
                ans.push_back(S[i + 1]);
            }
            ans += "=7";
            cout << ans << "\n";
            return 0;
        }
    }

    return 0;
}
