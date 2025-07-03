#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize a vector with integers
    vector<int> v = {10, 20, 30, 40};

    // Create an iterator pointing to the beginning of the vector
    vector<int>::iterator it = v.begin();

    // Print the first element of the vector
    cout << "First element: " << *it << endl;

    return 0;
}
