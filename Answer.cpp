#include <iostream>
#include <vector>
using namespace std;

class Wavelabs {
public:
    int WavelabMaxNetRank(int n, vector<vector<int>>& A) {
        vector<vector<int>> G(n, vector<int>(n));
        vector<int> degree(n);
        for (auto &r : A) {
            int u = r[0], v = r[1];
            G[u][v] = G[v][u] = 1;
            degree[u]++;
            degree[v]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, degree[i] + degree[j] - G[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Wavelabs wavelabs;
    int n = 4;
    vector<vector<int>> cables = {{0,1},{0,3},{1,2},{1,3}};
    int result = wavelabs.WavelabMaxNetRank(n, cables);
    cout << result << endl;
    
    return 0;
}

