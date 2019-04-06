// SeeAlso: https://atcoder.jp/contests/abc123/tasks/abc123_c

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstdint>
#include <cstring>

typedef long long ll;
using namespace std;

#define MAX 5

int main() {
    ll N, A[MAX];
    ll p[MAX + 1] = {};

    cin >> N;

    for (int i = 0; i < MAX; i++) {
        cin >> A[i];
    }

    ll time = 0;


    p[0] = N;
    
    ll B[MAX + 1];

    while(p[MAX] != N) {
        
        memcpy(B, p, sizeof(p));

        for(int i = 0; i < (MAX); i++) {
            if (B[i] > 0) {
                int diff;
                if (A[i] > B[i]) {
                    diff = B[i];
                } else {
                    diff = A[i];
                }

                p[i] -= diff;
                p[i+1] += diff;
            }
        }

        time++;
    }

    cout << time << endl;
    return 0;
}
