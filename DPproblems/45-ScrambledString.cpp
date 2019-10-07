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
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 101;
int mem[MAX][MAX][MAX];
string s1, s2;
bool isScramble(int index1, int index2, int length) {
	int& rt = mem[index1][index2][length];
	if (~rt)return rt;
	rt = 1;
	for (int i = 0; i < length; i++)
		if (s1[index1 + i] != s2[index2 + i]) {
			rt = 0; break;
		}
	for (int mid = 1; mid < length; mid++) {
		rt = rt || (isScramble(index1, index2, mid)
			&& isScramble(index1 + mid, index2 + mid, length - mid));
		rt = rt || (isScramble(index1 + mid, index2, length - mid) &&
			isScramble(index1, index2 + length - mid, mid));
	}
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	cin >> s1 >> s2;
	cout << isScramble(0, 0, sz(s1));
}
