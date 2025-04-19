// flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct Flight {
    int flightNumber;
    char departureTime[6];
    char arrivalTime[6];
    char departure[50];
    char destination[50];
    struct Flight* next;
} Flight;

void loadFlightsFromFile(Flight** head, char* filename);
void saveFlightsToFile(Flight* head, char* filename);
void addFlight(Flight** head, int flightNumber, char* departureTime, char* arrivalTime, char* departure, char* destination);
void removeFlight(Flight** head, int flightNumber);
Flight* searchFlight(Flight* head, int flightNumber);
void updateFlight(Flight* head, int flightNumber, char* newDepartureTime, char* newArrivalTime, char* newDeparture, char* newDestination);
void displayFlights(Flight* head);
void freeFlightList(Flight** head);

#endif