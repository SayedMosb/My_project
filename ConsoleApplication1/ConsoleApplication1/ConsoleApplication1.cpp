#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[2][2];

    // Input elements
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    // Find maximum element
    int Max = arr[0][0];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (Max < arr[i][j]) {
                Max = arr[i][j];
            }
        }
    }

    // Output result
    cout << "Max: " << Max << endl;

    return 0;
}
