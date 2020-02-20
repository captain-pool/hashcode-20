#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
 
typedef struct library {
    int books, signupTime, booksPerDay;
    vector<int> bookind;
}data;

bool cmp(pair<int, pair<int, int>> s1, pair<int, pair<int, int>> s2) {
	if(s1.ff == s2.ff) {
		return s1.ss.ff > s2.ss.ff;
	}
	return s1.ff < s2.ff;
}

bool cmp1(pair<int, pair<int, int>> s1, pair<int, pair<int, int>> s2) {
	return s1.ss.ff > s2.ss.ff;
}

int main() {
	// input
    int B,L,D;
        // B ~ Books
        // L ~ Libraries
        // D ~ Days
    cin >> B >> L >> D;
    int S[B];
    for (int i = 0; i < B; ++i)
        cin >> S[i];
    data lib[L];
    for(int i = 0; i < L; ++i) {
        cin >> lib[i].books >> lib[i].signupTime >> lib[i].booksPerDay;
        lib[i].bookind = vector<int>(lib[i].books);
        for(int j = 0; j < lib[i].books; ++j)
            cin >> lib[i].bookind[j];
    }


    // solution code
    set<int> unq;
    
    vector<pair<int, pair<int, int>>> scores(L);
    
    for(int i = 0; i < L; ++i) {
        int n = lib[i].books;
        int sum = 0;
        for(int j = 0; j < n; ++j)
            sum += S[lib[i].bookind[j]];
        scores[i] = {lib[i].signupTime, {sum, i}};
    }
    sort(scores.begin(), scores.end(), cmp);
    
    vector<pair<int, int>> G[L];

	for(int i = 0; i < L; ++i) {
		int ind = scores[i].ss.ss;
		int n = lib[ind].books;
		int sum = 0;
		for(int j = 0; j < n; ++j) {
			if(!unq.count(lib[ind].bookind[j])) {
				sum += S[lib[i].bookind[j]];
				unq.insert(lib[ind].bookind[j]);
				G[ind].push_back({S[lib[ind].bookind[j]], lib[ind].bookind[j]});
			}
		}
		sort(G[ind].rbegin(), G[ind].rend());
		scores[i].ss.ff = sum;
	}
	sort(scores.begin(), scores.end(), cmp1);


    // output

    cout << L << endl;

    for(int i = 0; i < L; ++i) {
    	int ind = scores[i].ss.ss;
    	int n = G[ind].size();
        cout << ind << ' ' << n << '\n';
        for(int j = 0; j < n; ++j)
            cout << G[ind][j].ss << ' ';
        cout << endl;
    }

}
