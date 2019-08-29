#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int solve(vector<vector<int>>& A, int m) {
    int n = A.size();
    vector<int> B;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + m <= n) {
                int val = 1;
                for (int k = 0; k < m; k++)
                    val *= A[i+k][j];
                B.push_back(val);
            }

            if (j + m <= n) {
                int val = 1;
                for (int k = 0; k < m; k++)
                    val *= A[i][j+k];
                B.push_back(val);
            }

            if (i + m <= n && j + m <= n) {
                int val = 1;
                for (int k = 0; k < m; k++)
                    val *= A[i+k][j+k];
                B.push_back(val);
            }

            if (i + m <= n && j + 1 - m >= 0) {
                int val = 1;
                for (int k = 0; k < m; k++)
                    val *= A[i+k][j-k];
                B.push_back(val);
            }
        }
    }

    return *max_element(B.begin(), B.end());
}

int main() {
    ios::sync_with_stdio(false);
    int n = 20;
    int m = 4;
    vector<vector<int>> A(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    /*
    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
    */

    int ans = solve(A, m);
    cout << ans << endl;

    return 0;
}

