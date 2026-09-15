//Handles reservation operations|| CancellationHistory Manages stack operations.
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <vector>
#include <stack>
#include <string>
#include "Reservation.h"

using namespace std;

class ReservationManager {

private:
    vector<Reservation> activeReservations;   // Active reservations
    stack<Reservation> cancelledStack;        // Cancellation history

    bool reservationExists(int reservationID) const;

public:
    void loadReservations(const string& filename);
    void saveReservations(const string& filename) const;


    bool createReservation(const Reservation& r);
    bool cancelReservation(int reservationID);
    bool restoreLastCancelled();

    void displayActiveReservations() const;
    void displayCancellationHistory() const;

    Reservation* findReservation(int reservationID);
};

#endif
