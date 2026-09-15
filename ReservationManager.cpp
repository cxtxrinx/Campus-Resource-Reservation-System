#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Load reservations from file
void ReservationManager::loadReservations(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        int resID, stuID, resrcID;
        string stuName, date;

        getline(ss, line, ',');
        resID = stoi(line);

        getline(ss, line, ',');
        stuID = stoi(line);

        getline(ss, stuName, ',');

        getline(ss, line, ',');
        resrcID = stoi(line);

        getline(ss, date);

        activeReservations.emplace_back(resID, stuID, stuName, resrcID, date);
    }
}

// Save active reservations
void ReservationManager::saveReservations(const string& filename) const {
    ofstream file(filename);
    for (const auto& r : activeReservations) {
        file << r.toCSV() << "\n";
    }
}

// Create reservation
bool ReservationManager::createReservation(const Reservation& r) {
    if (reservationExists(r.getReservationID())) {
        cout << "Reservation ID already exists.\n";
        return false;
    }

    activeReservations.push_back(r);
    return true;
}

// Cancel reservation
bool ReservationManager::cancelReservation(int reservationID) {
    for (size_t i = 0; i < activeReservations.size(); ++i) {
        if (activeReservations[i].getReservationID() == reservationID) {

            // Push to cancellation stack
            cancelledStack.push(activeReservations[i]);

            // Remove from active list
            activeReservations.erase(activeReservations.begin() + i);

            return true;
        }
    }
    return false;
}

// Restore most recently cancelled
bool ReservationManager::restoreLastCancelled() {
    if (cancelledStack.empty()) {
        cout << "No cancelled reservations to restore.\n";
        return false;
    }

    Reservation r = cancelledStack.top();
    cancelledStack.pop();

    activeReservations.push_back(r);
    return true;
}


// Display active reservations
void ReservationManager::displayActiveReservations() const {
    cout << "\nActive Reservations:\n";
    for (const auto& r : activeReservations) {
        cout << r.toCSV() << "\n";
    }
}

// Display cancellation history
void ReservationManager::displayCancellationHistory() const {
    stack<Reservation> temp = cancelledStack;

    cout << "\nCancellation History (most recent first):\n";
    while (!temp.empty()) {
        cout << temp.top().toCSV() << "\n";
        temp.pop();
    }
}

// Search by reservation ID
Reservation* ReservationManager::findReservation(int reservationID) {
    for (auto& r : activeReservations) {
        if (r.getReservationID() == reservationID)
            return &r;
    }
    return nullptr;
}

// Helper: check if reservation exists
bool ReservationManager::reservationExists(int reservationID) const {
    for (const auto& r : activeReservations) {
        if (r.getReservationID() == reservationID)
            return true;
    }
    return false;
}
