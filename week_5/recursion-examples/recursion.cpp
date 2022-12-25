#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}

int largest(int list[], int lowerIndex, int upperIndex) {

    int m;

    if (lowerIndex == upperIndex)
        return list[lowerIndex];
    m = largest(list, lowerIndex + 1, upperIndex);
    if (m > list[lowerIndex])
        return m;
    else
        return list[lowerIndex];
}


bool palindrome(std::string str, int lowerIndex, int upperIndex) {

    bool flag;

    if (lowerIndex > upperIndex)
        return true;
    flag = palindrome(str, lowerIndex + 1, upperIndex - 1);
    if (str[lowerIndex] == str[upperIndex] && flag)
        return true;
    else
        return false;

}

int dot_iterative(int list1[], int list2[], int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum = sum + list1[i] * list2[i];
    return sum;
}

int dot_recursive(int list1[], int list2[], int start, int end) {
    int sum;
    if (start <= end) {
        sum = dot_recursive(list1, list2, start + 1, end);
        return sum + list1[start] * list2[start];
    }
    else
        return 0;
}



void decToBin(int num, int base) {
    if (num > 0) {
        decToBin(num / base, base);
        cout << num % base;
    }
}

int fib_iterative(int n) {
    int f1 = 0, f2 = 1, f;
    int i = 2;

    if (n < 2) {
        cout << n;
    }
    else {
        while (i <= n) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
            i++;
        }
    }
    return f;
}

int call_count = 0;

int fib_recursive(int n) {
    call_count++;
    if (n < 2)
        return n;
    else
        return fib_recursive(n - 1) + fib_recursive(n - 2);
}



#define MAX 100
int lookup_table[MAX];

void init_lookup_table() {
    for (int i = 0; i < MAX; i++)
        lookup_table[i] = -1;
}

int fib_memoization(int n) {
    if (lookup_table[n] == -1) {
        if (n < 2)
            lookup_table[n] = n;
        else
            lookup_table[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
    }
    return lookup_table[n];
}


void moveDisks(int count, int needle1, int needle2, int needle3) {
    if (count > 0) {
        moveDisks(count - 1, needle1, needle3, needle2);
        cout << "Move disk " << count << " from " << needle1 << " to " << needle3 << "." << endl;
        moveDisks(count - 1, needle2, needle1, needle3);
    }
}


int main() {
    int n = 5;
    cout << "Factorial of " << n << " is: " << factorial(n) << "\n";

    int list[10] = { 30,4,3,22,7,5,9,7,8,3 };
    cout << "Maximum value is: " << largest(list, 0, 9) << "\n";

    std::string str = "aba";
    cout << "String is palindrome: " << palindrome(str, 0, 2) << "\n";

    int list1[10] = { 2,4,3,2,7,5,9,7,8,3 };
    int list2[10] = { 2,4,3,2,7,5,9,7,8,3 };
    cout << "Dot product iterative: " << dot_iterative(list1, list2, 0, 9) << "\n";
    cout << "Dot product recursive: " << dot_recursive(list1, list2, 0, 9) << "\n";

    n = 10;
    cout << "Fib(" << n << ") iterative " << " = " << fib_iterative(n) << "\n";
    cout << "Fib(" << n << ") recursive " << " = " << fib_recursive(n) << "\n";

    init_lookup_table();
    cout << "Fib(" << n << ") memoization " << " = " << fib_memoization(n) << "\n";
    cout << "Total number of recursive calls = " << call_count << "\n";

    n = 10;
    cout << n << " in binary is: ";
    decToBin(n, 2);
    cout << "\n";

    moveDisks(10, 1, 2, 3);

}
