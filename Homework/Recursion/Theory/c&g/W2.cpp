#include <iostream>
using namespace std;

bool Check(int &g) {
    for(int i = 0; i <= 36; i++)
        if(g + i == 36 && g*2 + i*4 == 100) 
            return true;
    g++;
    return Check(g);
}

void GaC(int m, int t) {
    int g = 0;
    bool c = Check(g);
    if(c) cout << g << " " << 36 - g;
}

int main() {
    GaC(100, 36);
    return 0;
}