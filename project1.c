#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packages.h"

int main() {
    int choice;

    do {
        printf("Travel Agency Online Booking System\n");
        printf("1. Sign In\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (signIn()) {
                    printf("\nSigned in successfully!\n");
                    do {
                        printf("\nTravel Agency Online Booking System\n");
                        printf("1. Display available packages\n");
                        printf("2. Add a new package\n");
                        printf("3. Remove a package\n");
                        printf("4. Book a package\n");
                        printf("5. View booking details\n");
                        printf("6. View all bookings\n");
                        printf("7. Search customer details\n");
                        printf("8. Deleting Booking details\n");
                        printf("9. Sign Out\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch (choice) 
						{
                            case 1:
                                displayPackages();
                                break;
                            case 2:
                                addPackage();
                                break;
                            case 3:
                                removePackage();
                                break;
                            case 4:
                                bookPackage();
                                break;
                            case 5:
                                viewBookingDetails();
                                break;
                            case 6:
                                viewAllBookings();
                                break;
                            case 7:
                                searchCustomerDetails();
                                break;
                            case 8:
                                deleteCustomerDetails();
                                break;
                            case 9:
                                printf("\nSigned out successfully!\n");
                                break;
                            default:
                                printf("Invalid choice. Please try again.\n");
                                break;
                        }
                    } while (choice != 9);
                }
                else {
                    printf("\nInvalid username or password. Please try again.\n");
                }
                break;
            case 2:
                registerUser();
                break;
            case 3:
                printf("\nThank you! Visit Again...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

