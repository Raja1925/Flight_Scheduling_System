// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

int main() {
    Flight *head = NULL;
    int choice, flightNumber;
    char depTime[6], arrTime[6];
    char dep[50], dest[50];
    char filename[] = "flights.txt";

    loadFlightsFromFile(&head, "flights.txt");

    displayFlights(head); // to verify the flights were loaded

    while (1) {
        printf("\nFlight Scheduling System\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Search Flight\n");
        printf("4. Update Flight\n");
        printf("5. Remove Flight\n");
        printf("6. Save to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // flush newline

        switch (choice) {
            case 1:
                printf("Enter Flight Number: ");
                scanf("%d", &flightNumber);
                printf("Enter Departure Time (HH:MM): ");
                scanf("%s", depTime);
                printf("Enter Arrival Time (HH:MM): ");
                scanf("%s", arrTime);
                printf("Enter Departure City: ");
                scanf("%s", dep);
                printf("Enter Destination City: ");
                scanf("%s", dest);
                addFlight(&head, flightNumber, depTime, arrTime, dep, dest);
                break;
            case 2:
                displayFlights(head);
                break;
            case 3:
                printf("Enter Flight Number to Search: ");
                scanf("%d", &flightNumber);
                {
                    Flight* found = searchFlight(head, flightNumber);
                    if (found) {
                        printf("Flight Found:\n");
                        printf("Flight Number: %d\n", found->flightNumber);
                        printf("Departure: %s\n", found->departure);
                        printf("Destination: %s\n", found->destination);
                        printf("Departure Time: %s\n", found->departureTime);
                        printf("Arrival Time: %s\n", found->arrivalTime);
                    } else {
                        printf("Flight %d not found.\n", flightNumber);
                    }
                }
                break;
            case 4:
                printf("Enter Flight Number to Update: ");
                scanf("%d", &flightNumber);
                printf("Enter New Departure Time (HH:MM): ");
                scanf("%s", depTime);
                printf("Enter New Arrival Time (HH:MM): ");
                scanf("%s", arrTime);
                printf("Enter New Departure City: ");
                scanf("%s", dep);
                printf("Enter New Destination City: ");
                scanf("%s", dest);
                updateFlight(head, flightNumber, depTime, arrTime, dep, dest);
                break;
            case 5:
                printf("Enter Flight Number to Remove: ");
                scanf("%d", &flightNumber);
                removeFlight(&head, flightNumber);
                break;
            case 6:
                saveFlightsToFile(head, filename);
                break;
            case 7:
                saveFlightsToFile(head, filename);
                freeFlightList(&head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}