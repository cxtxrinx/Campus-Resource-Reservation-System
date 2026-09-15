#include "../include/Resource.h"
// Implements the Resource class functions declared in Resource.h

Resource::Resource(){
    resourceID="";
    resourceName="";
    resourceType="";
    available = true;
}


Resource::Resource(string id, string name, string type, bool status){

    resourceID = id;
    resourceName= name;
    resourceType = type;
    available = status;
}

string Resource::getResourceID() const {
    return resourceID;
}

string Resource::getResourceName() const {
    return resourceName;
}

string Resource::getResourceType() const {
    return resourceType;
}

bool Resource::isAvailable() const {
    return available;
}

void Resource::setAvailability(bool status){
    available = status;
}