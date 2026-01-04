#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WildlifeReserve {
private:
    vector<string> locations;
    vector<vector<int>> trails;
    
    int findIndex(string name) {
        for (int i = 0; i < locations.size(); i++) {
            if (locations[i] == name) return i;
        }
        return -1;
    }
    
    void dfsRecursive(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << locations[current] << " ";
        for (int i = 0; i < trails[current].size(); i++) {
            int neighbor = trails[current][i];
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

public:
    void addLocation(string name) {
        if (findIndex(name) != -1) {
            cout << "Location " << name << " already exists." << endl;
            return;
        }
        locations.push_back(name);
        trails.push_back(vector<int>());
        cout << "Location " << name << " added." << endl;
    }
    
    void addTrail(string l1, string l2) {
        int i1 = findIndex(l1);
        int i2 = findIndex(l2);
        if (i1 == -1 || i2 == -1) {
            cout << "Invalid location(s)." << endl;
            return;
        }
        trails[i1].push_back(i2);
        trails[i2].push_back(i1);
        cout << "Trail added between " << l1 << " and " << l2 << endl;
    }
    
    void displayMap() {
        if (locations.empty()) {
            cout << "No locations." << endl;
            return;
        }
        for (int i = 0; i < locations.size(); i++) {
            cout << locations[i] << " -> ";
            if (trails[i].empty()) {
                cout << "No trails";
            } else {
                for (int j = 0; j < trails[i].size(); j++) {
                    cout << locations[trails[i][j]];
                    if (j < trails[i].size() - 1) cout << ", ";
                }
            }
            cout << endl;
        }
    }
    
    bool directTrail(string l1, string l2) {
        int i1 = findIndex(l1);
        int i2 = findIndex(l2);
        if (i1 == -1 || i2 == -1) return false;
        for (int i = 0; i < trails[i1].size(); i++) {
            if (trails[i1][i] == i2) return true;
        }
        return false;
    }
    
    void dfs(string start) {
        int startIndex = findIndex(start);
        if (startIndex == -1) {
            cout << "Location " << start << " not found." << endl;
            return;
        }
        vector<bool> visited(locations.size(), false);
        cout << "DFS from " << start << ": ";
        dfsRecursive(startIndex, visited);
        cout << endl;
    }
};

int main() {
    WildlifeReserve reserve;
    int option;
    string l1, l2;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Location\n";
        cout << "2. Add Trail\n";
        cout << "3. Display Map\n";
        cout << "4. Check Trail\n";
        cout << "5. DFS Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Enter location name: ";
                cin >> l1;
                reserve.addLocation(l1);
                break;
            case 2:
                cout << "Enter first location: ";
                cin >> l1;
                cout << "Enter second location: ";
                cin >> l2;
                reserve.addTrail(l1, l2);
                break;
            case 3:
                reserve.displayMap();
                break;
            case 4:
                cout << "Enter first location: ";
                cin >> l1;
                cout << "Enter second location: ";
                cin >> l2;
                if (reserve.directTrail(l1, l2)) {
                    cout << "Trail exists." << endl;
                } else {
                    cout << "No trail." << endl;
                }
                break;
            case 5:
                cout << "Enter start location: ";
                cin >> l1;
                reserve.dfs(l1);
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (option != 0);
    
    return 0;
}