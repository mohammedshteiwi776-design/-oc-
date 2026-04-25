#include <iostream>
#include <iomanip> // لتحسين تنسيق المخرجات

using namespace std;

/**
 * دالة البحث الثنائي - Binary Search
 * تقوم بالبحث عن عنصر معين داخل مصفوفة مرتبة وتطبع خطوات التنفيذ.
 */
int binarySearch(int arr[], int target, int length) {
    int low = 0;
    int high = length - 1;

    // طباعة رأس الجدول للتتبع (Trace Table)
    cout << "\n" << left 
         << setw(10) << "Low" 
         << setw(10) << "High" 
         << setw(10) << "Mid" 
         << setw(12) << "Arr[Mid]" 
         << "Action" << endl;
    cout << string(55, '-') << endl;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << left 
             << setw(10) << low 
             << setw(10) << high 
             << setw(10) << mid 
             << setw(12) << arr[mid];

        if (arr[mid] == target) {
            cout << "Found!" << endl;
            return mid;
        }

        if (target < arr[mid]) {
            cout << target << " < " << arr[mid] << " (Search Left)" << endl;
            high = mid - 1;
        } else {
            cout << target << " > " << arr[mid] << " (Search Right)" << endl;
            low = mid + 1;
        }
    }

    return -1; // في حال لم يتم العثور على العنصر
}

int main() {
    // مصفوفة مرتبة (ضروري للبحث الثنائي)
    int array[] = {2, 5, 8, 12, 16, 27, 38, 56, 72, 78, 91, 100};
    int n = sizeof(array) / sizeof(array[0]);
    int target = 16;

    cout << "Searching for: " << target << endl;
    
    int result = binarySearch(array, target, n);

    if (result != -1) {
        cout << "\nElement found at index: " << result << endl;
    } else {
        cout << "\nElement not found in the array." << endl;
    }

    return 0;
}
