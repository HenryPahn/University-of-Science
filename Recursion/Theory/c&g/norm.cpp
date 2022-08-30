#include <iostream>
using namespace std;

int main() {
    for(int g = 0; g < 36; g++) {
        int c = 36 - g;
        if(g*2 + c*4 == 100) cout << g << " " << c;
    }
    return 0;
}   