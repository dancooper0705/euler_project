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

vi prime;

void build_prime() {
    int n = 2e6 + 1;
    vi A(n, 1);

    A[0] = A[1] = 0;
    for (int i = 0; i < n; i++)
        if (A[i])
            for (int j = i + i; j < n; j += i)
                A[j] = 0;

    for (int i = 0; i < n; i++)
        if (A[i])
            prime.push_back(i);

    // cout << "prime: " << prime << endl;
}

long long solve() {
    long long ans = 0;
    for (int i = 0; i < prime.size(); i++)
        ans += prime[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    build_prime();

    long long ans = solve();
    cout << ans << endl;

    return 0;
}

