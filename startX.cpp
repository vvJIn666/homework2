#include <iostream>
#include <string>
using namespace std;

string starX(int size) {
    // 合法性检查
    if (size < 3 || size % 2 == 0) {
        return "";
    }

    string result;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            // 两条对角线
            if (col == row || col == size - 1 - row) {
                result += "*";
            } else {
                result += " ";
            }
        }
        result += "\n";
    }

    return result;
}

// 测试代码
void runTests() {
    const int TESTS = 3;
    string expected[] = {
        "* *\n * \n* *\n",
        "",
        "*   *\n * * \n  *  \n * * \n*   *\n"
    };
    int inputs[] = {3,4,5};
    for (int i = 0; i < TESTS; i++) {
        string actual = starX(inputs[i]);
        cout << "starX(" << inputs[i] << "):" << endl;
        cout << "EXPECTED: [" << expected[i] << "]" << endl;
        cout << "ACTUAL:   [" << actual << "]" << endl;
        cout << "-------------------------" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "-1") {
        runTests();
        return 0;
    }
    if (argc != 2) {
        cerr << "Usage: ./starX width" << endl;
        return 1;
    }
    int s = stoi(argv[1]);
    cout << starX(s);
    return 0;
}
