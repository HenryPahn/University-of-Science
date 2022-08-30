#include <iostream>
using namespace std;

void GaC(int g, int c) {
    if(g*2 + c*4 == 100) cout << g << " " << c;
    g--;
    c++;
    GaC(g, c);
}

int main() {
    int g = 36, c = 0;
    GaC(g, c);
    return 0;
}