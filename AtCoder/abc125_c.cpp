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
ll A[MAX];

int temp;
int removenum = MAX + 1;
ll ans = 1;

int gcd(int a, int b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

int recGCD(int i, int tempAns) {
    if (tempAns < ans) {
        return tempAns;
    }

    if (i == (N-1)) {
        return tempAns;
    }

    if ((i+1) == temp) {
        return recGCD((i+1), gcd(tempAns, A[i]));
    } else {
        return recGCD((i+1), gcd(tempAns, A[i+1]));
    }
}

int main() {

    cin >> N;

    REP(i, N) {
        cin >> A[i];
    }

    REP(i, N) {
        ll tempAns = 0;

        if (i == 0) {
            tempAns = A[1];
        } else {
            tempAns = A[0];
        }
            
        REP(n, N) {

            if (temp != n) {
                tempAns = gcd(tempAns, A[n]);
            } 

            if (tempAns < ans) {
                temp = removenum;
                break;
            }
        }

        if (tempAns < ans) { 
            REP(n, N) {
                if (temp != n) {
                 tempAns = gcd(tempAns, A[n]);
            } 

                if (tempAns < ans) {
                    temp = removenum;
                    break;
                }
            }
        }
        
        ans = max(ans, tempAns);
    }

    cout << ans << endl;
    return 0;
}
