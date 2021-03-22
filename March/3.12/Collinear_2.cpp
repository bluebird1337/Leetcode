//https://acm.cs.nthu.edu.tw/problem/11619/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

struct coef {
    ll a, b, c;
    coef(ll a, ll b, ll c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool operator==(const coef& p) const {
        return a == p.a && b == p.b && c == p.c;
    }
};

struct hash_fn
{
    size_t operator() (const coef& p) const
    {
        size_t h1 = hash<ll>()(p.a);
        size_t h2 = hash<ll>()(p.b);
        size_t h3 = hash<ll>()(p.c);
        return h1 * 1000000LL + h2 * 1000LL + h3;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<p> points;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        unordered_map<coef, int, hash_fn> count_lines; // key : coef of lines, value : amount of the same line

        for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) { // put every line in count_lines
            ll dx = points[j].first - points[i].first, dy = points[j].second - points[i].second;
            if (dx == 0LL) dy = 1LL;
            else if (dy == 0LL) dx = 1LL;
            else {
                ll gcd = __gcd(abs(dx), abs(dy));
                dx /= gcd;
                dy /= gcd;
                if (dy < 0LL) dy *= -1LL;
                else dx *= -1LL;
            }
            count_lines[{dy, dx, dy* points[i].first + dx * points[i].second}]++;
        }

        int res = 0;
        unordered_map<coef, int, hash_fn>::iterator it = count_lines.begin();
        while (it != count_lines.end()) {
            if (it->second > 1) res++;
            it++;
        }
        cout << res << "\n";
    }
    return 0;
}