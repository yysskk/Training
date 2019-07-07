// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int N;
int A[MAX];
int ans[MAX];

int hoge(int i, int n) {
    if (i > 0) {
        n += A[i] * 2;
        return hoge((i-1), n);
    } else {
        return n;
    }
}

int main() {
    cin >> N;

    int sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }   

    ans[0] = sum;

    for(int i = 1; i < N; i += 2) {
        ans[0] -= 2*A[i];
    }

    for(int i = 1; i < N; i++) {
        ans[i] = 2*A[i-1] - ans[i-1];
    }

    REP(i, N) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
