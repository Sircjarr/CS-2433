#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// Extra credit

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    char arr[width][height];
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for (int x = 0; x < line.length(); x++) {
            arr[x][i] = line.at(x);
        }
    }
    
    string none = " -1 -1";
    
    for (int i = 0; i < width; i++) {
        for (int x = 0; x < height; x++) {
            if (arr[i][x] == '0') {
                if(i == width - 1) {
                    cout << i << " " << x << none;
                }
                else if (arr[i+1][x] == '0') {
                    cout << i << " " << x << " " << i+1 << " " << x;
                }
                else {
                    for (int z = i + 1; z < width; z++) {
                        if (arr[z][x] == '0') {
                            cout << i << " " << x << " " << z << " " << x;
                            break;
                        }
                        else if (arr[z][x] == '.' && z == width - 1) {
                            cout << i << " " << x << " " << none;
                        }
                    } 
                }
                
                
                
                if (x == height - 1) {
                    cout << none << endl;
                }
                else if (arr[i][x+1] == '0') {
                    cout << " " << i << " " << x+1 << endl;
                }
                else {
                    for (int z = x + 1; z < height; z++) {
                        if (arr[i][z] == '0') {
                            cout << " " << i << " " << z << endl;
                            break;
                        }
                        else if (arr[i][z] == '.' && z == height - 1) {
                            cout << none << endl;
                        }
                    } 
                }
                
            }
        }
    }

    // Three coordinates: a node, its right neighbor, its bottom neighbor
}