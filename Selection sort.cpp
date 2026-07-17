#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nStarting Time : "
         << duration_cast<microseconds>(start.time_since_epoch()).count()
         << " microseconds";

    cout << "\nEnding Time   : "
         << duration_cast<microseconds>(stop.time_since_epoch()).count()
         << " microseconds";

    cout << "\nExecution Time: "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}
