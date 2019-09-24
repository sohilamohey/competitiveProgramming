#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}


int main() {
	run();
	int a, b;
	vector<pair<int, int>> v;
	while (cin >> a >> b) {
		v.emplace_back(a, b);
	}
	sort(all(v), [](const ii& a, const ii& b) {
		return a.second > b.second;
		});
	vector<int> dp(sz(v) + 1);
	dp[0] = oo;
	int mx = 0;
	for (int index = 0; index < sz(v); index++) {
		for (int i = mx; i >= 0; i--) {
			if (v[index].first <= dp[i]) {
				int remLoad = min(dp[i], v[index].second) - v[index].first;
				dp[i + 1] = max(dp[i + 1], remLoad);
				mx = max(mx, i + 1);
			}
		}
	}
	cout << mx << endl;
}
