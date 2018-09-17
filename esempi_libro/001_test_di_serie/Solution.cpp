#include <vector>
#include <queue>

using namespace std;

int respect_algo(int K, int N, const vector<int> & strength) {
    vector<int> max_per_girone;
    priority_queue<int> ordered_strength;
    for (int i = 0; i < K; ++i) {
        int max = -1;
        max_per_girone.push_back(max);
        for (int j = 0; j < N; ++j) {
            if (max < strength[i + j]) {
                max = strength[i + j];
                max_per_girone[i] = max;
            }
            ordered_strength.push(strength[i+j]);
        }
    }
    sort(max_per_girone.begin(), max_per_girone.end());
    for (int k = 0; k < K; ++k) {
        if (max_per_girone[k] != ordered_strength.top()) {
            return 0;
        } else {
            ordered_strength.pop();
        }
    }
    return 1;
}