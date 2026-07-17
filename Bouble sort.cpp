#include <iostream>
#include <chrono>
using namespace std;
int main() {
    int a;
    cout << "Enter the number of elements: ";
    cin >> a;
    int arr[a];
    cout << "Enter " << a << " elements: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < a - 1; i++) {
        for (int j = 0; j < a - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nSorted Array: ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nStarting Time : ";
    cout << std::chrono::duration_cast<std::chrono::microseconds>(start.time_since_epoch()).count();

    cout << "\nEnding Time   : ";
    cout << std::chrono::duration_cast<std::chrono::microseconds>(stop.time_since_epoch()).count();

    cout << "\nExecution Time: ";
    cout << duration.count() << " microseconds";

    return 0;
}
