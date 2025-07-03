#include <iostream>
#include <vector>
using namespace std;

void findTwoArrays(int N) {
    long long total_sum = (1LL * N * (N + 1)) / 2;

    if (total_sum % 2 != 0) {
        cout << "-1\n";
        return;
    }

    long long target = total_sum / 2;
    vector<int> A, B;
    long long current_sum = 0;

    
    for (int num = N; num >= 1; num--) {
        if (current_sum + num <= target) {
            A.push_back(num);
            current_sum += num;
        } else {
            B.push_back(num);
        }
    }

    cout << A.size() << " ";
    for (int num : A) cout << num << " ";
    cout << "\n";

    cout << B.size() << " ";
    for (int num : B) cout << num << " ";
    cout << "\n";
}

int main() {
    int N;
    cin >> N;
    findTwoArrays(N);
    return 0;
}
