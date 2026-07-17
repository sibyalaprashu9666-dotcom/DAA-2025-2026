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
        int minIndex = i;

        for (int j = i + 1; j < a; j++) {
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
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nStarting Time : ";
    cout << duration_cast<microseconds>(start.time_since_epoch()).count();
    cout << " microseconds";

    cout << "\nEnding Time   : ";
    cout << duration_cast<microseconds>(stop.time_since_epoch()).count();
    cout << " microseconds";

    cout << "\nExecution Time: ";
    cout << duration.count();
    cout << " microseconds" << endl;

    return 0;
}
