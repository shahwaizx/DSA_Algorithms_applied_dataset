#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

struct Coordinate {
    double latitude;
    double longitude;
};
int numLocations=69;
void visitLocation() {
    // List of locations
    string locations[] = {
        "Ansoo Lake",
        "Astola Island",
        "Attabad Lake",
        "Badshahi Mosque",
        "Baltoro Glacier",
        "Bhurban",
        "Bruti waterfall Islamabad",
        "Concordia",
        "Deosai National Park",
        "Derawar Fort",
        "Dhanni Waterfall",
        "Emperor Mosque",
        "Fairy Meadows",
        "Faisal Mosque",
        "Farphu Waterfall",
        "Gawadar",
        "Gojal Valley",
        "Gorakh Hill",
        "Gulpur Mahuli waterfalls",
        "Hingol National Park",
        "Hunza Valley",
        "Indus Kohistan",
        "Jahaz Banda Kumrat Valley",
        "Kalam Valley",
        "Kalash",
        "Kanhatti Gardens",
        "Karambar Lake",
        "Katasraj temple",
        "Khewra Salt Mine",
        "Kiwai Kaghan",
        "Lahore Fort",
        "Lake Saif-ul-Malook",
        "Lasbela Beach",
        "Mahodand Waterfall",
        "Malam Jabba",
        "Manthoka Waterfall",
        "Masjid Wazir Khan",
        "Matiltan",
        "Minar-e-Pakistan",
        "Mohatta Palace",
        "Mohenjo-daro",
        "Moola Chotok",
        "Naltar lake",
        "Narh waterfall",
        "Neela Sandh Waterfall Kotli Sattian",
        "Neelam Valley",
        "Noori de Than Waterfall Jabri",
        "Pakistan Air Force Museum",
        "Pakistan Monument",
        "Panjpeer Rocks",
        "Pattan",
        "Pir Sohawa",
        "Rama Lake",
        "Ratti Galli Waterfall",
        "Rawalakot",
        "Rohtas Fort",
        "Rush Lake",
        "Sajjikot Waterfall Havelian",
        "Satpara Lake",
        "Shalamar Bagh",
        "Shangrila resort",
        "Shumber Waterfalls",
        "Skardu",
        "Sonmiani Beach",
        "Taxila Museum",
        "Thal Desert",
        "The Lahore Museum",
        "Umbrella Waterfall Poona",
        "West Bay Beach"
    };

    for (int i=0; i<69;i++) {
        cout << "Press " << i << " for " << locations[i] << endl;
    } 
    }


double calculateDistance(const Coordinate& c1, const Coordinate& c2) {
    double R = 6371.0; // Radius of the Earth in kilometers

    double lat1_rad = c1.latitude * M_PI / 180.0;
    double lon1_rad = c1.longitude * M_PI / 180.0;
    double lat2_rad = c2.latitude * M_PI / 180.0;
    double lon2_rad = c2.longitude * M_PI / 180.0;

    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1_rad) * cos(lat2_rad) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = R * c;
    return distance;
}
string locations[] = {
        "Ansoo Lake",
        "Astola Island",
        "Attabad Lake",
        "Badshahi Mosque",
        "Baltoro Glacier",
        "Bhurban",
        "Bruti waterfall Islamabad",
        "Concordia",
        "Deosai National Park",
        "Derawar Fort",
        "Dhanni Waterfall",
        "Emperor Mosque",
        "Fairy Meadows",
        "Faisal Mosque",
        "Farphu Waterfall",
        "Gawadar",
        "Gojal Valley",
        "Gorakh Hill",
        "Gulpur Mahuli waterfalls",
        "Hingol National Park",
        "Hunza Valley",
        "Indus Kohistan",
        "Jahaz Banda Kumrat Valley",
        "Kalam Valley",
        "Kalash",
        "Kanhatti Gardens",
        "Karambar Lake",
        "Katasraj temple",
        "Khewra Salt Mine",
        "Kiwai Kaghan",
        "Lahore Fort",
        "Lake Saif-ul-Malook",
        "Lasbela Beach",
        "Mahodand Waterfall",
        "Malam Jabba",
        "Manthoka Waterfall",
        "Masjid Wazir Khan",
        "Matiltan",
        "Minar-e-Pakistan",
        "Mohatta Palace",
        "Mohenjo-daro",
        "Moola Chotok",
        "Naltar lake",
        "Narh waterfall",
        "Neela Sandh Waterfall Kotli Sattian",
        "Neelam Valley",
        "Noori de Than Waterfall Jabri",
        "Pakistan Air Force Museum",
        "Pakistan Monument",
        "Panjpeer Rocks",
        "Pattan",
        "Pir Sohawa",
        "Rama Lake",
        "Ratti Galli Waterfall",
        "Rawalakot",
        "Rohtas Fort",
        "Rush Lake",
        "Sajjikot Waterfall Havelian",
        "Satpara Lake",
        "Shalamar Bagh",
        "Shangrila resort",
        "Shumber Waterfalls",
        "Skardu",
        "Sonmiani Beach",
        "Taxila Museum",
        "Thal Desert",
        "The Lahore Museum",
        "Umbrella Waterfall Poona",
        "West Bay Beach"
    };

void DFS(double graph[][69], int vertices, int source, int destination, bool visited[], stack<int>& path, double& totalDistance, int maxPaths, int& pathCount) {
    visited[source] = true;
    path.push(source);

    if (source == destination) {
        stack<int> reversedPath;
        cout << "Path: ";

        // Copy the path to a reversed stack
        while (!path.empty()) {
            reversedPath.push(path.top());
            path.pop();
        }

        // Print the reversed path
        while (!reversedPath.empty()) {
            int vertex = reversedPath.top();
            cout << locations[vertex] << " | ";
            path.push(vertex);
            reversedPath.pop();
        }

        cout << endl;
        cout << "Total Distance: " << totalDistance << endl;
        cout << "**********" << endl;

        pathCount++;
        if (pathCount >= maxPaths) {
            return; // Stop the traversal if maxPaths is reached
        }
    }
    else {
        for (int i = 0; i < vertices; i++) {
            if (graph[source][i] != 0 && !visited[i]) {
                totalDistance += graph[source][i]; // Add the distance to the total
                DFS(graph, vertices, i, destination, visited, path, totalDistance, maxPaths, pathCount);
                totalDistance -= graph[source][i]; // Subtract the distance when backtracking
            }
        }
    }

    // Backtrack and mark the current vertex as unvisited
    path.pop();
    visited[source] = false;
}

void printAlternatePaths(double graph[][69], int vertices, int source, int destination, int maxPaths) {
    bool visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    stack<int> path;
    double totalDistance = 0.0;
    int pathCount = 0;
    DFS(graph, vertices, source, destination, visited, path, totalDistance, maxPaths, pathCount);
}




int main() {
    ifstream file("pk.csv");
    vector<Coordinate> coordinates;

    if (file.is_open()) {
        string line;
        // Skip the header line if it exists
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string word;
            vector<string> lineData;

            while (getline(ss, word, ',')) {
                lineData.push_back(word);
            }

            double latitude;
            double longitude;

            stringstream s1(lineData[3]);
            s1 >> latitude;

            stringstream s2(lineData[4]);
            s2 >> longitude;

            coordinates.push_back({ latitude, longitude });
        }

        file.close();

        int numLocations = coordinates.size();
//        double adjacencyMatrix[numLocations][numLocations];
        double adjacencyMatrix[numLocations][69];

        // Calculate distances and fill the adjacency matrix
        for (int i = 0; i < numLocations; ++i) {
            for (int j = 0; j < numLocations; ++j) {
                adjacencyMatrix[i][j] = calculateDistance(coordinates[i], coordinates[j]);
            }
        }
        
        
    

        // Display the adjacency matrix
//        for (int i = 0; i < numLocations; ++i) {
//            for (int j = 0; j < numLocations; ++j) {
//                cout << adjacencyMatrix[i][j] << "  ";
//            }
            
//            cout << endl;
//        }
        
//    }
	
	int opt;
	do{
		cout<<"***This Code Can Give you Alternate Paths From Source to Destination"<<endl;
		cout<<"Press 1 to Display Alternate Paths from Source to Destination"<<endl;
		cout<<"Press 0 to Exit"<<endl;
		cout<<"Enter option"<<endl;
		cin>>opt;
		switch(opt){
			case 1:
				visitLocation();
				cout<<"Enter number for source: "<<endl;
				int source;
				cin>>source;
				cout<<"Enter number for destinations: "<<endl;
				int des;
				cin>>des;
				cout<<"Enter the maximum possible paths you want: "<<endl;
				int p;
				cin>>p;
				printAlternatePaths(adjacencyMatrix,numLocations,source,des,p);
				break;	
				
		}
	}while(opt!=0);
	
	}
		
    else {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    return 0;
}

