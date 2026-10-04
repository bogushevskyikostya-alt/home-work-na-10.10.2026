/* Завдання 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printContacts(const vector<string>& mobile, const vector<string>& home) {
    cout << "\n=== Список контактів ===\n";
    cout << "№\tМобільний\t\tДомашній\n";
    cout << "-------------------------------------------\n";
    for (size_t i = 0; i < mobile.size(); ++i) {
        cout << i + 1 << "\t" << mobile[i] << "\t\t" << home[i] << "\n";
    }
}

void sortByMobile(vector<string>& mobile, vector<string>& home) {
    int n = mobile.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (mobile[j] > mobile[j + 1]) {
                swap(mobile[j], mobile[j + 1]);
                swap(home[j], home[j + 1]); 
            }
        }
    }
    cout << "\n[Успіх] Список відсортовано за мобільними номерами.\n";
}

void sortByHome(vector<string>& mobile, vector<string>& home) {
    int n = home.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (home[j] > home[j + 1]) {
                swap(home[j], home[j + 1]);
                swap(mobile[j], mobile[j + 1]); 
            }
        }
    }
    cout << "\n[Успіх] Список відсортовано за домашніми номерами.\n";
}

int main() {

    vector<string> mobileNumbers = { "+380671112233", "+380509998877", "+380635554433", "+380972221100" };
    vector<string> homeNumbers = { "0442345678",    "0448765432",    "0441112233",    "0449990000" };

    int choice;
    do {
        cout << "\n=== МЕНЮ ДОВІДНИКА ===\n";
        cout << "1. Відсортувати за номерами мобільних\n";
        cout << "2. Відсортувати за домашніми номерами телефонів\n";
        cout << "3. Вивести список користувачів\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sortByMobile(mobileNumbers, homeNumbers);
            break;
        case 2:
            sortByHome(mobileNumbers, homeNumbers);
            break;
        case 3:
            printContacts(mobileNumbers, homeNumbers);
            break;
        case 0:
            cout << "Завершення роботи.\n";
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}*/
/*Завдання 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void optimizedBubbleSort(vector<int>& arr) {
    int n = arr.size();
    int passes = 0;

    for (int i = 0; i < n - 1; ++i) {
        int swaps = 0; 
        passes++;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }

        if (swaps == 0) {
            cout << "Сортування зупинено достроково на кроці " << passes << " (0 перестановок).\n";
            break;
        }
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 7, 5, 6, 8, 9 };

    cout << "Початковий масив: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    optimizedBubbleSort(arr);

    cout << "\nВідсортований масив: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}*/
/*Завдання 3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flip(vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

// Пошук індексу найбільшої оладки в діапазоні [0..n-1]
int findMaxIndex(const vector<int>& arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    int flipCount = 0;

    for (int curr_size = n; curr_size > 1; --curr_size) {
        // Знаходимо найбільшу оладку серед перших curr_size
        int maxIdx = findMaxIndex(arr, curr_size);

        // Якщо найбільша оладка не внизу поточного підмасиву
        if (maxIdx != curr_size - 1) {
            // Крок 1: якщо вона не зверху, перевертаємо її на самий верх
            if (maxIdx != 0) {
                flip(arr, maxIdx);
                flipCount++;
                cout << "Операція " << flipCount << ": перевернули до індексу " << maxIdx << "\n";
            }

        
            flip(arr, curr_size - 1);
            flipCount++;
            cout << "Операція " << flipCount << ": перевернули до індексу " << curr_size - 1 << "\n";
        }
    }
    cout << "\nУсього виконано операцій перевертання: " << flipCount << "\n";
}

int main() {
    vector<int> pancakes = {3, 6, 1, 10, 4, 8};

    cout << "Початкова стопка оладок (зверху вниз): ";
    for (int r : pancakes) cout << r << " ";
    cout << "\n\n=== Процес сортування ===\n";

    pancakeSort(pancakes);

    cout << "\nВідсортована стопка оладок (знизу вгору за зменшенням радіуса, тобто зверху найменша, внизу найбільша):\n";
    for (int r : pancakes) cout << r << " ";
    cout << "\n";

    return 0;
}*/