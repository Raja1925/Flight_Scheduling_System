// flight.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

void loadFlightsFromFile(Flight** head, char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No file found. Starting with an empty flight list.\n");
        return;
    }

    int flightNumber;
    char depTime[6], arrTime[6];
    char dep[50], dest[50];

    while (fscanf(file, "%d %5s %5s %49s %49s", &flightNumber, depTime, arrTime, dep, dest) == 5) {
        addFlight(head, flightNumber, depTime, arrTime, dep, dest);
    }

    fclose(file);
    printf("Flights loaded successfully from file.\n");
}

void saveFlightsToFile(Flight* head, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    Flight* current = head;
    while (current) {
        fprintf(file, "%d %s %s %s %s\n", current->flightNumber, current->departureTime, current->arrivalTime,
                current->departure, current->destination);
        current = current->next;
    }

    fclose(file);
    printf("Flight schedule saved successfully.\n");
}

void addFlight(Flight** head, int flightNumber, char* departureTime, char* arrivalTime, char* departure, char* destination) {
    if (searchFlight(*head, flightNumber)) {
        printf("Flight %d already exists. Duplicate flight numbers are not allowed.\n", flightNumber);
        return;
    }

    Flight* newFlight = (Flight*)malloc(sizeof(Flight));
    newFlight->flightNumber = flightNumber;
    strcpy(newFlight->departureTime, departureTime);
    strcpy(newFlight->arrivalTime, arrivalTime);
    strcpy(newFlight->departure, departure);
    strcpy(newFlight->destination, destination);
    newFlight->next = NULL;

    if (*head == NULL || strcmp(departureTime, (*head)->departureTime) < 0) {
        newFlight->next = *head;
        *head = newFlight;
        return;
    }

    Flight* current = *head;
    while (current->next && strcmp(current->next->departureTime, departureTime) < 0) {
        current = current->next;
    }

    newFlight->next = current->next;
    current->next = newFlight;
}

void removeFlight(Flight** head, int flightNumber) {
    Flight* current = *head;
    Flight* prev = NULL;

    while (current && current->flightNumber != flightNumber) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Flight %d not found.\n", flightNumber);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Flight %d removed successfully.\n", flightNumber);
}

Flight* searchFlight(Flight* head, int flightNumber) {
    while (head) {
        if (head->flightNumber == flightNumber) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void updateFlight(Flight* head, int flightNumber, char* newDepartureTime, char* newArrivalTime, char* newDeparture, char* newDestination) {
    Flight* flight = searchFlight(head, flightNumber);
    if (!flight) {
        printf("Flight %d not found.\n", flightNumber);
        return;
    }

    strcpy(flight->departureTime, newDepartureTime);
    strcpy(flight->arrivalTime, newArrivalTime);
    strcpy(flight->departure, newDeparture);
    strcpy(flight->destination, newDestination);
    printf("Flight %d updated successfully.\n", flightNumber);
}

void displayFlights(Flight* head) {
    if (!head) {
        printf("No flights scheduled.\n");
        return;
    }

    printf("Flight No | Departure | Destination | Dep Time | Arr Time\n");
    printf("----------------------------------------------------------\n");
    while (head) {
        printf("%-9d %-10s %-12s %-9s %-9s\n", head->flightNumber, head->departure, head->destination,
               head->departureTime, head->arrivalTime);
        head = head->next;
    }
}

void freeFlightList(Flight** head) {
    Flight* current = *head;
    while (current) {
        Flight* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}