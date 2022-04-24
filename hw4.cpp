#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    /**
     * move from both ends of coordinates (polygon)
     * with left and right pointers
    **/

    // left = 0, right = coordinates.length - 1

    // for each given coordinate, store whether or not the height increases 
    // as you move left or right through the polygon
    // leftIncreases = []
    // rightIncreases = []

    // leftMaxHeight = coordinates[0].getY();
    // for (int i = 0; i < coordinates.length; i++) {
    //     int currentHeight = coordinate[i].getY();
    //     if (currentHeight > leftMaxHeight) {
    //         
    //         leftMaxHeight = currentHeight;
    //     }
    // }

    return 0;
}