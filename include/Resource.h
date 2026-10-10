#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

using namespace std; 

// Represents one campus resource and its current availability
class Resource {
private:
    string resourceID;
    string resourceName;
    string resourceType;
    bool available;


public:
    Resource();
    Resource(string id, string name, string type, bool status);

    string getResourceID() const;
    string getResourceName() const;
    string getResourceType() const;
    bool isAvailable() const;

    void setAvailability(bool status);
};

#endif // RESOURCE_H