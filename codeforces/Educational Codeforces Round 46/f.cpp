// Educational Codeforces Round 46 (Rated for Div. 2) - F. One Occurrence
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+10, root = 710;

struct Q
{
	int l, r, id, b;

	bool operator<(const Q& o) const
	{
		if(b == o.b)
		{
			if(b&1) return r > o.r;
			else return r < o.r; 
		}

		return b < o.b;
	}
} qr[maxn];

int n, q, v[maxn], ans[maxn], bl[root], num[maxn];

int find()
{
	for(int i = 0 ; i < root ; ++i)
	{
		if(bl[i])
		{
			for(int j = i*root ; j < (i+1)*root ; ++j)
			{
				if(num[j] == 1)	return j;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; ++i) scanf("%d", &v[i]);

	scanf("%d", &q);

	for(int i = 0 ; i < q ; ++i)
	{
		scanf("%d %d", &qr[i].l, &qr[i].r);

		qr[i].b = (qr[i].l/root);
		qr[i].id = i;
	}

	sort(qr, qr + q);
	
	int left = 0, right = 0;

	for(int i = 0 ; i < q ; ++i)
	{
		int l = qr[i].l;
		int r = qr[i].r;
		int id = qr[i].id;

		while(left > l)
		{
			left--;
			num[v[left]]++;

			if(num[v[left]] == 2) bl[v[left]/root]--;

			if(num[v[left]] == 1) bl[v[left]/root]++;
		}

		while(right < r)
		{
			right++;
			num[v[right]]++;

			if(num[v[right]] == 2) bl[v[right]/root]--;

			if(num[v[right]] == 1) bl[v[right]/root]++;
		}

		while(right > r)
		{
			num[v[right]]--;

			if(num[v[right]] == 0) bl[v[right]/root]--;

			if(num[v[right]] == 1) bl[v[right]/root]++;

			right--;
		}

		while(left < l)
		{
			num[v[left]]--;

			if(num[v[left]] == 0) bl[v[left]/root]--;
			
			if(num[v[left]] == 1) bl[v[left]/root]++;
			
			left++;
		}

		ans[id] = find();
	}

	for(int i = 0 ; i < q ; ++i) printf("%d\n", ans[i]);
}
