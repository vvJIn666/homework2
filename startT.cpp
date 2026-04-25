#include <iostream>
#include <string>
using namespace std;

string starT(int width, int height) {
    // 合法性检查
    if (width < 3 || height < 2 || width % 2 == 0) {
        return "";
    }

    string result;
    int mid = width / 2; // 中间位置

    // 第一行：全 *
    for (int i = 0; i < width; i++) {
        result += "*";
    }
    result += "\n";

    // 剩下所有行：只有中间是 *
    for (int row = 1; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (col == mid) {
                result += "*";
            } else {
                result += " ";
            }
        }
        result += "\n";
    }

    return result;
}

void runTests() {
    const int TESTS = 18;
    string expected[] = {
        "", "", "",
        "***\n * \n", "", "*****\n  *  \n",
        "***\n * \n * \n", "", "*****\n  *  \n  *  \n",
        "***\n * \n * \n * \n", "", "*****\n  *  \n  *  \n  *  \n"
    };
    int inputs[TESTS][2] = {
        {3,1}, {4,1}, {5,1},
        {3,2}, {4,2}, {5,2},
        {3,3}, {4,3}, {5,3},
        {3,4}, {4,4}, {5,4}
    };
    for (int i = 0; i < 12; i++) {
        string actual = starT(inputs[i][0], inputs[i][1]);
        cout << "starT(" << inputs[i][0] << "," << inputs[i][1] << "):" << endl;
        cout << "EXPECTED: [" << expected[i] << "]" << endl;
        cout << "ACTUAL:   [" << actual << "]" << endl;
        cout << "-------------------------" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 3 && string(argv[1]) == "-1" && string(argv[2]) == "-1") {
        runTests();
        return 0;
    }
    if (argc != 3) {
        cerr << "Usage: ./starT width height" << endl;
        return 1;
    }
    int w = stoi(argv[1]);
    int h = stoi(argv[2]);
    cout << starT(w, h);
    return 0;
}
