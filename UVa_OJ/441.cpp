#include <bits/stdc++.h>

using namespace std;

int main() {	
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	while (n) {
		int s[n];
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		for (int i = 0; i < n - 5; ++i) 
			for (int j = i + 1; j < n - 4; ++j) 
				for (int g = j + 1; g < n - 3; ++g) 
					for (int h = g + 1; h < n - 2; ++h)
						for (int k = h + 1; k < n - 1; ++k)
							for (int f = k + 1; f < n; ++f)
								cout << s[i] << " " << s[j] << " " << s[g] << " " << s[h] << " " << s[k] << " " << s[f] << endl;
		cin >> n;
		if (n)		
			cout << endl;
	}
	return 0;
}