#include "Image.hpp"
using namespace std;
int main() {
    int choice;
    cout << "\033[1;36mAvalible Filters \033[0m:" << endl;
    cout << "\033[1;32m1:\033[1;33m Sharpen\033[0m" << endl;
    cout << "\033[1;32m2:\033[1;33m Ridge Detection\033[0m" << endl;
    cout << "\033[1;32m3:\033[1;33m Gaussian Blur\033[0m" << endl;
    cout << "\033[1;36mChoice \033[0m: "; cin >> choice;
    Image img(choice);
    img.loadImage("pic.png");
    img.applyFilter();
    return 0;
}
