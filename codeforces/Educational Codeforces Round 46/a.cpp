// Educational Codeforces Round 46 (Rated for Div. 2) - A. Codehorses T-shirts
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> m1, m2;

int main(){
	
	scanf("%d", &n);

	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		m1[s]++;
	}
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		m2[s]++;
	}
	int ans=0;
	for(auto it: m2){

		ans+=max(m2[it.first]-m1[it.first], 0);
	}

	printf("%d\n", ans);

	return 0;
}
