#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Coordinate {
    public:
        int x;
        int y;
        Coordinate(int x, int y) {
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

int getMaxPolyArea(vector<Coordinate>);

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

    vector<Coordinate> coordinates;

    int i = 0;
    while (i < n) {
        int x, y;
        inputFile >> x;
        inputFile >> y;
        coordinates.push_back(Coordinate(x, y));
        i++;
    }

    int maxPolyArea = getMaxPolyArea(coordinates);
    cout << "\nmax area = " << maxPolyArea << endl;
    
    return 0;
}

int getMaxPolyArea(vector<Coordinate> coordinates) {
    int maxArea = 0;

    stack<Coordinate> coordStack;

    for (int i = 1; i < coordinates.size(); i++) {
        int pos = coordinates[i].getX();
        int height = coordinates[i].getY();

        int startPos = INT_MAX;
        // height decreases -> compute area(s)
        while (!coordStack.empty() && height < coordStack.top().getY()) {
            startPos = coordStack.top().getX();
            int currArea = coordStack.top().getY() * (pos - coordStack.top().getX());

            coordStack.pop();

            maxArea = max(currArea, maxArea);
        }

        // height increases -> push coordinate to stack
        if (coordStack.empty() || height > coordStack.top().getY()) {
            coordStack.push(Coordinate(min(startPos, pos), height));
        }
    }

    return maxArea;
}