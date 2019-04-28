// SeeAlso: https://atcoder.jp/contests/abc125/tasks/abc125_c

#include <bits/stdc++.h>

typedef long long ll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()


using namespace std;

int N;
int A[MAX];

int temp;
int removenum = MAX + 1;
int ans = 1;

int gcd(int a, int b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

int main() {

    cin >> N;

    REP(i, N) {
        cin >> A[i];
    }

    int R[MAX+1], L[MAX+1];

    L[0] = 0;
    R[N+1] = 0;

    REP(i, N) {
        L[i+1] = gcd(L[i], A[i]);
        R[N-i] = gcd(R[N-i+1], A[N-i]);
    }

    REP(i, N) {
        ans = max(ans, gcd(R[i+1], L[i]));    
    }

    cout << ans << endl;
    return 0;
}
