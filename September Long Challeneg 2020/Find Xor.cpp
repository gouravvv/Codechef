#include<bits/stdc++.h>
using namespace std;
typedef long long           ll;
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);
}

ll max(ll a, ll b) {return (a > b ? a : b);}
ll min(ll a, ll b) {return (a < b ? a : b);}

void solve_test() {
  ll ans = 0;
  ll n;
  cin >> n;
  ll sum = 0;
  cout << 1 << " " << (1 << 20) << endl;
  cin >> sum;
  sum -= (n * (1 << 20));
  if (sum % 2 == 1) ans++;
  ll total_ones;
  for (int i = 1; i <= 19; i++) {
    cout << 1 << " " << (1 << i) << endl;
    ll new_sum;
    cin >> new_sum;

    if (new_sum > sum) {
      total_ones = (new_sum - sum) / (1 << i);
      total_ones = (n - total_ones) / 2;
      if (total_ones & 1)
        ans += (1 << i);
    }
    else
    {
      total_ones = (sum - new_sum) / (1 << i);
      total_ones = (total_ones + n) / 2;

      if (total_ones & 1)
        ans += (1 << i);
    }
  }

  cout << 2 << " " << ans << endl;
  ll verdict;
  cin >> verdict;
}
int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t; while (t--)
    solve_test();
  return 0;
}
