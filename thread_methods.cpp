#include<bits/stdc++.h>
using namespace std;

void f1(int a, int b) {
    long long sum = 0;
    for (int i = a; i <= b; ++i) {
        sum += i;
    }
    cout << sum << endl;
}
int main() {
    int a, b;
    cout << "Enter a : ";
    cin>>a;
    cout << "Enter b : ";
    cin>>b;
    std::thread th1(f1, a, b);
    std::thread th2(f1, a, b);
    if (th1.joinable()) {
        th1.join();
    }
    if (th2.joinable()) {
        th2.join();
    }

    // creating thread using lambda function
    std::thread th3([a, b](){
        long long sum = 0;
        for (int i = a; i <= b; ++i) {
            sum += i;
        }
        cout << sum << endl;
    });
    if (th3.joinable()) {
        th3.join();
    }

    // Creating thread using function pointer
    void (*fptr)(int, int) = f1;
    std::thread th4(fptr, a, b);
    if (th4.joinable()) {
        th4.join();
    }
}