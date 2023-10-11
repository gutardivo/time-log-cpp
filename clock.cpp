#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void sleep(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int s = 0;
int m = 0;
int h = 0;

string pad2(int num) {
    if (num < 10) {
        return "0" + to_string(num);
    } else {
        return to_string(num);
    }
}

void printTime() {
    while (true) {
        cout << '\r' << pad2(h) << ":" << pad2(m) << ":" << pad2(s) << flush;  // Use '\r' to overwrite the line
        s += 1;
        sleep(1);

        if (s == 60) {
            s = 0;
            m += 1;

            if (m == 60) {
                m = 0;
                h += 1;
            }
        }
    }
}

int main() {
    printTime();
    return 0;
}
