// Educational Codeforces Round 46 (Rated for Div. 2) - B. Light It Up
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5+10;

bool ck[maxn];
int n, m, v[maxn];
ll sl[maxn], sd[maxn];

int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &v[i]);

		ck[i] = (i%2);

		if(ck[i])
		{
			sl[i] = sl[i-1] + v[i] - v[i-1];
			sd[i] = sd[i-1];
		}
		else
		{
			sl[i] = sl[i-1];
			sd[i] = sd[i-1] + v[i] - v[i-1];
		}
	}

	v[n+1] = m;
	ck[n+1] = 1;

	if(!ck[n])
	{
		sl[n+1] = sl[n] + m - v[n];
		sd[n+1] = sd[n];
	}
	else
	{
		sl[n+1] = sl[n];
		sd[n+1] = sd[n]+m-v[n];
	}

	n++;
	
	ll ans=sl[n];

	for(int i = 1 ; i <= n ; ++i)
	{
		if(v[i] - v[i-1] > 1)
		{
			ll fd = sd[n] - sd[i] + sl[i-1];
			
			if(ck[i])
			{
				ans = max(ans, v[i] - 1 - v[i-1] + fd);
			}
			else
			{
				ans = max(ans, v[i] - v[i-1] - 1 + fd);
			}
		}
	}

	printf("%lld\n", ans);
}
