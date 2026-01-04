#include <iostream>
#include <vector>
#include <string>

using namespace std;

class InterplanetaryNetwork {
private:
    vector<string> planets;
    vector<vector<int>> connections;
    
    int findIndex(string name) {
        for (int i = 0; i < planets.size(); i++) {
            if (planets[i] == name) return i;
        }
        return -1;
    }
    
    void dfsRecursive(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << planets[current] << " ";
        for (int i = 0; i < connections[current].size(); i++) {
            int neighbor = connections[current][i];
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

public:
    void addPlanet(string name) {
        if (findIndex(name) != -1) {
            cout << "Planet " << name << " already exists." << endl;
            return;
        }
        planets.push_back(name);
        connections.push_back(vector<int>());
        cout << "Planet " << name << " added." << endl;
    }
    
    void addRoute(string p1, string p2) {
        int i1 = findIndex(p1);
        int i2 = findIndex(p2);
        if (i1 == -1 || i2 == -1) {
            cout << "Invalid planet(s)." << endl;
            return;
        }
        connections[i1].push_back(i2);
        connections[i2].push_back(i1);
        cout << "Route added between " << p1 << " and " << p2 << endl;
    }
    
    void displayMap() {
        if (planets.empty()) {
            cout << "No planets." << endl;
            return;
        }
        for (int i = 0; i < planets.size(); i++) {
            cout << planets[i] << " -> ";
            if (connections[i].empty()) {
                cout << "No connections";
            } else {
                for (int j = 0; j < connections[i].size(); j++) {
                    cout << planets[connections[i][j]];
                    if (j < connections[i].size() - 1) cout << ", ";
                }
            }
            cout << endl;
        }
    }
    
    bool directRoute(string p1, string p2) {
        int i1 = findIndex(p1);
        int i2 = findIndex(p2);
        if (i1 == -1 || i2 == -1) return false;
        for (int i = 0; i < connections[i1].size(); i++) {
            if (connections[i1][i] == i2) return true;
        }
        return false;
    }
    
    void dfs(string start) {
        int startIndex = findIndex(start);
        if (startIndex == -1) {
            cout << "Planet " << start << " not found." << endl;
            return;
        }
        vector<bool> visited(planets.size(), false);
        cout << "DFS from " << start << ": ";
        dfsRecursive(startIndex, visited);
        cout << endl;
    }
};

int main() {
    InterplanetaryNetwork net;
    int option;
    string p1, p2;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Planet\n";
        cout << "2. Add Route\n";
        cout << "3. Display Map\n";
        cout << "4. Check Route\n";
        cout << "5. DFS Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Enter planet name: ";
                cin >> p1;
                net.addPlanet(p1);
                break;
            case 2:
                cout << "Enter first planet: ";
                cin >> p1;
                cout << "Enter second planet: ";
                cin >> p2;
                net.addRoute(p1, p2);
                break;
            case 3:
                net.displayMap();
                break;
            case 4:
                cout << "Enter first planet: ";
                cin >> p1;
                cout << "Enter second planet: ";
                cin >> p2;
                if (net.directRoute(p1, p2)) {
                    cout << "Route exists." << endl;
                } else {
                    cout << "No route." << endl;
                }
                break;
            case 5:
                cout << "Enter start planet: ";
                cin >> p1;
                net.dfs(p1);
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