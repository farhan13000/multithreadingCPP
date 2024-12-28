#include<bits/stdc++.h>
using namespace std;

void f1() {
    cout << "\nthread1 strated executing the function 1  ............. " << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\nthread1 execution done  ............. \n";
}

void f2() {
    cout << "\nthread2 strated executing the function 2  .............  " << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\nthread2 execution done  ............. \n";
}

void f3() {
    cout << "\nthread3 started executing function3 ............. \n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\nthread3 finished its execution  ............. \n";
}
int main() {
    cout << "\nMain thread execution compeleted  ............. \n";
    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);
    if (t3.joinable()) {
        // After detaching main thread won't wait for the completion of this thread t3.
        t3.detach();
    }
    if(t1.joinable()) {
        // main thread will wait for the completion of this thread t1.
        t1.join();
    }
    if(t2.joinable()) {
        // main thread will wait for the completion of this thread t2.
        t2.join();
    }
    this_thread::sleep_for(chrono::seconds(10)); // So that main thread wait till all the threads complete their execution.
    cout << "\nMain thread execution compeleted  ............. \n";
}