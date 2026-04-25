#include <iostream>
#include <string>
using namespace std;

string starC(int width, int height) {
    // 合法性检查
    if (width < 2 || height < 3) {
        return "";
    }

    string result;

    // 逐行绘制
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // 第一行 / 最后一行：全 *
            if (row == 0 || row == height - 1) {
                result += "*";
            } else {
                // 中间行：只有第一列是 *
                if (col == 0) {
                    result += "*";
                } else {
                    result += " ";
                }
            }
        }
        result += "\n";
    }

    return result;
}

// 测试代码
void runTests() {
    const int TESTS = 15;
    string expected[] = {
        "", "", "",
        "**\n* \n**\n", "***\n*  \n***\n", "****\n*   \n****\n",
        "**\n* \n* \n**\n", "***\n*  \n*  \n***\n", "****\n*   \n*   \n****\n",
        "**\n* \n* \n* \n**\n", "***\n*  \n*  \n*  \n***\n", "****\n*   \n*   \n*   \n****\n"
    };
    int inputs[TESTS][2] = {
        {2,2}, {3,2}, {4,2},
        {2,3}, {3,3}, {4,3},
        {2,4}, {3,4}, {4,4},
        {2,5}, {3,5}, {4,5}
    };
    for (int i = 0; i < 12; i++) {
        string actual = starC(inputs[i][0], inputs[i][1]);
        cout << "starC(" << inputs[i][0] << "," << inputs[i][1] << "):" << endl;
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
        cerr << "Usage: ./starC width height" << endl;
        return 1;
    }
    int w = stoi(argv[1]);
    int h = stoi(argv[2]);
    cout << starC(w, h);
    return 0;
}  
