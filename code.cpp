#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
 
typedef struct library {
    int books, signupTime, booksPerDay;
    vector<int> bookind;
}data;

int main() {
    int B,L,D;

        // B ~ Books
        // L ~ Libraries
        // D ~ Days


    //input
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


    //solution code
    vector<pair<int, pair<int, int>>> scores(L);
    for(int i = 0; i < L; ++i) {
        int n = lib[i].books;
        int sum = 0;
        for(int j = 0; j < n; ++j)
            sum += lib[i].bookind[j];
        scores[i] = {sum, {n, i}};
    }
    sort(scores.begin(), scores.end(), greater<pair<int, pair<int,int>>>());


    //output

    cout << L << endl;

    for(int i = 0; i < L; ++i) {
        cout << scores[i].ss.ss << ' ' << scores[i].ss.ff << '\n';
        int ind = scores[i].ss.ss;
        int n = lib[ind].books;
        for(int j = 0; j < n; ++j)
            cout << lib[ind].bookind[j] << ' ';
        cout << endl;
    }

}
