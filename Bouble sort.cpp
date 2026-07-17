#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int a;

    cout << "Enter the number of elements: ";
    cin >> a;

    int arr[a];

    cout << "Enter " << a << " elements: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < a - 1; i++) {
        for (int j = 0; j < a - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Array: ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nStarting Time : ";
    cout << duration_cast<microseconds>(start.time_since_epoch()).count();

    cout << "\nEnding Time   : ";
    cout << duration_cast<microseconds>(stop.time_since_epoch()).count();

    cout << "\nExecution Time: ";
    cout << duration.count() << " microseconds";

    return 0;
}
