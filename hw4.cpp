#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class coordinate {
    public:
        int x;
        int y;
        coordinate(int x, int y) {
            this->x = x;
            this->y = y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
};

int getMaxPolyArea(vector<coordinate>);

int main() {
    cout << "Enter input file: ";
    string input;
    cin >> input;

    ifstream inputFile(input);

    if (!inputFile.is_open()) {
        cout << "Error opening file..." << endl;
        exit(-1);
    }
    
    int n;
    inputFile >> n;

    vector<coordinate> coordinates;

    int i = 0;
    while (i < n) {
        int x, y;
        inputFile >> x;
        inputFile >> y;
        coordinates.push_back(coordinate(x, y));
        i++;
    }

    cout << "\nmax area = " << getMaxPolyArea(coordinates) << endl;
    
    return 0;
}

int getMaxPolyArea(vector<coordinate> coordinates) {
    stack<coordinate> cstack;

    int maxArea = 0;
    for (int i = 0; i < coordinates.size(); i++) {
        int currPos = coordinates[i].getX();
        int currHeight = coordinates[i].getY();

        int lastPos = INT_MAX;

    }

    return maxArea;
}