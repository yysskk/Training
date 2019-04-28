#include <bits/stdc++.h>

typedef long long ll;


#define MAX 1000000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

using namespace std;

int n;
vector<int> a;

int main() {

    
    cin >> n;

    REP(i, n) {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }

    if(dfs(0,0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

bool dfs(int i, int sum) {

    if (i == n) {
        return sum == k;
    }

    if (dfs(i + n, sum)) {
        return true;
    }

    if (dfs(i + 1, sum + a.at[i])) {
        return true;
    }

    return false;
}