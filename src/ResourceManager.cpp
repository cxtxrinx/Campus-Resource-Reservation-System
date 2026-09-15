#include "../include/ResourceManager.h"
#include <fstream>
#include <iostream>

using namespace std;

// Loads resource information from a text file into the resource vector.
void ResourceManager::loadResources(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error: Could not open resource file." << endl;
        return;
    }

    string id;
    string name;
    string type;
    int status;

    while (getline(file, id, '|') &&
           getline(file, name, '|') &&
           getline(file, type, '|') &&
           file >> status) {

        file.ignore();
        resources.push_back(Resource(id, name, type, status == 1));
    }

    file.close();
}

// Displays all resources in the vector.
void ResourceManager::displayResources() {
    cout << "\n--- All Resources ---" << endl;

    for (const Resource& resource : resources) {
        cout << "ID: " << resource.getResourceID() << endl;
        cout << "Name: " << resource.getResourceName() << endl;
        cout << "Type: " << resource.getResourceType() << endl;

        if (resource.isAvailable()) {
            cout << "Status: Available" << endl;
        }
        else {
            cout << "Status: Unavailable" << endl;
        }

        cout << "--------------------" << endl;
    }
}

// Displays the availability status of each resource.
void ResourceManager::displayAvailability() {
    cout << "\n--- Resource Availability ---" << endl;

    for (const Resource& resource : resources) {
        cout << resource.getResourceID()
             << " - "
             << resource.getResourceName()
             << ": ";

        if (resource.isAvailable()) {
            cout << "Available" << endl;
        }
        else {
            cout << "Unavailable" << endl;
        }
    }
}