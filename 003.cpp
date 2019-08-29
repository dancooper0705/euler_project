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

vector<int> prime;

void build_prime() {
    int n = 1e6;
    vector<int> A(n, 1);

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

void get_factor(long long n, vector<long long>& F) {
    F.clear();
    for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
        while (n % prime[i] == 0) {
            F.push_back(prime[i]);
            n /= prime[i];
        }
    }

    if (n > 1)
        F.push_back(n);
}

vector<long long> solve(long long n) {
    vector<long long> F;
    get_factor(n, F);
    return F;
}

int main() {
    ios::sync_with_stdio(false);
    long long n = 600851475143;

    build_prime();

    vector<long long> ans = solve(n);
    cout << ans << endl;

    return 0;
}

