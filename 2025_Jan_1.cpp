#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

inline int median(int a, int b, int c) {
    return max(min(a, b), min(max(a, b), c));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> nodes(n + 1);
    set<int> allValues;
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
        allValues.insert(nodes[i].first);
    }

    int q;
    cin >> q;

    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        allValues.insert(queries[i]);
    }

    map<int, int> valueMap;
    vector<int> values(allValues.begin(), allValues.end());
    for (int i = 0; i < values.size(); ++i) {
        valueMap[values[i]] = i;
    }
    int numValues = values.size();

    for (int m : queries) {
        int mIndex = valueMap[m];

        vector<vector<long long>> dp(n + 1, vector<long long>(numValues, LLONG_MAX / 2)); // 初始化为 LLONG_MAX / 2

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < numValues; ++j) {
                int val = values[j];
                dp[i][j] = (nodes[i].first == val) ? 0 : (long long)abs(nodes[i].first - val) * nodes[i].second;
            }
        }

        for (int i = n; i >= 1; --i) {
            if (2 * i > n) continue;
            int left = 2 * i;
            int right = 2 * i + 1;
            if (right > n) continue;

            vector<vector<long long>> next_dp = dp;

            for (int j = 0; j < numValues; ++j) {
                for (int oj = 0; oj < numValues; ++oj) {
                    for (int lj = 0; lj < numValues; ++lj) {
                        for (int rj = 0; rj < numValues; ++rj) {
                            int oval = values[oj];
                            int lval = values[lj];
                            int rval = values[rj];

                            int med = median(oval, lval, rval);
                            long long cost = (oval == nodes[i].first ? 0 : (long long)abs(nodes[i].first - oval) * nodes[i].second) + dp[left][lj] + dp[right][rj];

                            if (cost < 0) cost = LLONG_MAX/2; //处理cost溢出的情况

                            if (med == oval) {
                                if (values[j] == oval && cost < next_dp[i][j]) next_dp[i][j] = cost;
                            } else if (med == lval) {
                                if (values[j] == lval && cost < next_dp[i][j]) next_dp[i][j] = cost;
                            } else { // med == rval
                                if (values[j] == rval && cost < next_dp[i][j]) next_dp[i][j] = cost;
                            }
                        }
                    }
                }
            }
            dp = next_dp;
        }

        cout << (dp[1][mIndex] == LLONG_MAX/2 ? -1 : dp[1][mIndex]) << "\n"; // 输出结果，处理无解情况
    }

    return 0;
}