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

typedef complex<double> point;

double cross(point a, point b) {
    return (conj(a) * b).imag();
}

long long solve(int n) {
    vii A;
    ii center((n - 1) / 2, (n - 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A.emplace_back(i, j);
        }
    }

    sort(A.begin(), A.end(),
        [&](ii a, ii b) {
            a = a - center;
            b = b - center;
            point s(a.second, a.first);
            point t(b.second, b.first);
            double m1 = max(abs(s.real()), abs(s.imag()));
            double m2 = max(abs(t.real()), abs(t.imag()));
            if (m1 != m2)
                return m1 < m2;
            double val1 = fmod(arg(s) - arg(point(1.0,-1.0)) + 4 * acos(-1.0), 2 * acos(-1.0));
            double val2 = fmod(arg(t) - arg(point(1.0,-1.0)) + 4 * acos(-1.0), 2 * acos(-1.0));

            if (val1 == 0.0)
                val1 += 2 * acos(-1.0);
            if (val2 == 0.0)
                val2 += 2 * acos(-1.0);
            /*
            cout << "a: " << a << ", s: " << s << ", val1: " << val1 << endl;
            cout << "b: " << b << ", t: " << t << ", val2: " << val2 << endl;
            */
            return val1 < val2;
        });

    // cout << "A: " << A << endl;

    vvi B(n, vi(n));
    for (int i = 0; i < A.size(); i++) {
        B[A[i].first][A[i].second] = i + 1;
    }

    /*
    for (int i = 0; i < n; i++)
        cout << "B[" << i << "]: " << B[i] << endl;
    */

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i + j == n - 1)) {
                ans += B[i][j];
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1001;
    long long ans = solve(n);

    cout << ans << endl;
    return 0;
}

