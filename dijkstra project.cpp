#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct Coordinate {
    double latitude;
    double longitude;
};
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
void dijkstra(double graph[69][69], int n, int start)
{
    double cost[69][69];
    int dist[69];
    bool visited[69];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = false;
    }

    dist[start] = 0;
    visited[start] = true;

    for (int count = 0; count < n - 1; count++)
    {
        int minDist = 999999999;
        int minIndex;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] <= minDist)
            {
                minDist = dist[i];
                minIndex = i;
            }
        }
        visited[minIndex] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[minIndex] + cost[minIndex][i] < dist[i])
            {
                dist[i] = dist[minIndex] + cost[minIndex][i];
            }
        }
    }
    cout << "Vertex\t\tDistance from Start" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INFINITY)
        {
            cout << locations[i] << "\t\t" << dist[i] << endl;
        }
        else
        {
            cout << i << "\t\t"
                 << "PATH NOT AVAILABLE" << endl;
        }
    }
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
        double adjacencyMatrix[69][69];

        // Calculate distances and fill the adjacency matrix
        for (int i = 0; i < numLocations; ++i) {
            for (int j = 0; j < numLocations; ++j) {
                adjacencyMatrix[i][j] = calculateDistance(coordinates[i], coordinates[j]);
            }
        }
        int start;
        
        visitLocation();
        cout << "Enter your starting point: " << endl;
        cin >> start;
        dijkstra(adjacencyMatrix,69,start);
        
    }
    else {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    return 0;
}

