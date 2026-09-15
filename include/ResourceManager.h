#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

// Manages the campus resource inventory

class ResourceManager {
private:
    vector<Resource> resources;
    
public:
    void loadResources( string filename);
    void displayResources();
    void displayAvailability();
};

#endif // RESOURCE_MANAGER_H