#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
// external file
// Structure to hold package details
typedef struct {
    char name[100];
    char description[200];
    float price;
} Package;

// Structure to hold booking details
typedef struct 
{
	int cid;
	int cim;
	int ciy;
	int cod;
	int com;
	int coy;
    char name[20];
    char DOB[20];
    char aadhar[13];
    char mobileNumber[20];
    char address[200];
    char state[50];
    int numOfPersons;
    int numOfDays;
    int numOfRooms;
    char roomType[20];
    char hotel_name[20];
    char package_name[20];
    float roomBill;
    float totalBill;
} Booking;

typedef struct {
    char username[20];
    char password[20];
} User;

// Function to display available packages
void displayPackages() {
    FILE *file = fopen("packages.txt", "r");//reading mode
    if (file == NULL) {
        printf("No packages available.\n");
        return;
    }

    printf("Available Packages:\n");
    printf("-------------------\n");
    int count = 1;
    Package package;

    while (fread(&package, sizeof(Package), 1, file)) {
        printf("Package %d:\n", count);
        printf("Name: %s\n", package.name);
        printf("Description: %s\n", package.description);
        printf("Price: %.2f\n", package.price);
        printf("-------------------\n");
        count++;
    }

    fclose(file);
}

// Function to add a new package
void addPackage() {
    FILE *file = fopen("packages.txt", "a");//appending mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Package package;

    printf("Enter package name: ");
    scanf(" %[^\n]s", package.name);

    printf("Enter package description: ");
    scanf(" %[^\n]s", package.description);

    printf("Enter package price: ");
    scanf("%f", &package.price);

    fwrite(&package, sizeof(Package), 1, file);
    fclose(file);

    printf("Package added successfully.\n");
}

// Function to remove a package
void removePackage() {
    char packageName[30];

    printf("Enter the name of the package to be removed: ");
    scanf(" %[^\n]s", packageName);

    FILE *file = fopen("packages.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Package package;

    while (fread(&package, sizeof(Package), 1, file)) {
        if (strcmp(package.name, packageName) != 0) {
            fwrite(&package, sizeof(Package), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("packages.txt");
    rename("temp.txt", "packages.txt");//which replaces the original file with modified file

    printf("Package removed successfully.\n");
}

// Function to book a package
void bookPackage() {
    // Display available packages
    displayPackages();

    int packageChoice,l;//l=length
    printf("Enter the package number you want to book: ");
    scanf("%d", &packageChoice);

    // Open the packages file
    FILE *packagesFile = fopen("packages.txt", "r");
    if (packagesFile == NULL) {
        printf("No packages available.\n");
        return;
    }

    // Find the selected package
    Package selectedPackage;
    int count = 1;
    while (fread(&selectedPackage, sizeof(Package), 1, packagesFile)) {
        if (count == packageChoice) {
            break;
        }
        count++;
    }

    fclose(packagesFile);

    if (count != packageChoice) {
        printf("Invalid package choice.\n");
        return;
    }

    FILE *bookingsFile = fopen("bookings.txt", "a");
    if (bookingsFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Booking booking;

    printf("Enter the date of CHECKIN(dd mm yyyy):");
    scanf("%d %d %d",&booking.cid,&booking.cim,&booking.ciy);
    
    printf("Enter the date of CHECKOUT(dd mm yyyy):");
    scanf("%d %d %d",&booking.cod,&booking.com,&booking.coy);
    
    printf("Re-entercpackage Name:");
    scanf("%s",booking.package_name);

    printf("Enter your name: ");
    scanf(" %[^\n]s", booking.name);
    
    printf("Enter your DOB(dd/mm/yyyy):");
    scanf(" %[^\n]s", booking.DOB);
    
    a:
    printf("Enter your 12-digit aadhar number:");
    scanf(" %[^\n]s", booking.aadhar);
    l=strlen(booking.aadhar);
	if(l!=12)
	{
		printf("Invalid Aadhar number\n");
		goto a;
	}
	
	m:
    printf("Enter your mobile number: ");
    scanf(" %[^\n]s", booking.mobileNumber);
    l=strlen(booking.mobileNumber);
    if(l!=10)
	{
		printf("Invalid mobile number,please try again!!\n");
		goto m;
	}
	
    printf("Enter your address: ");
    scanf(" %[^\n]s", booking.address);

    printf("Enter your state: ");
    scanf(" %[^\n]s", booking.state);

    printf("Enter the number of persons: ");
    scanf("%d", &booking.numOfPersons);

    booking.numOfDays=(booking.cod-booking.cid)+((booking.com-booking.cim)*30)+((booking.coy-booking.ciy)*365);

    printf("Enter the number of rooms you need: ");
    scanf("%d", &booking.numOfRooms);
    
    int choice;
    printf("List of hotel names:\n");
    printf("1. SVM\n");
    printf("2. Sithara\n");
    printf("3. Rathna\n");
    printf("4. Five Star\n");
    
    printf("Enter your Hotel Name:");
    scanf(" %[^\n]s",booking.hotel_name);
    
    printf("Re-Enter your Hotel choice Number To confirm: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Room Types\tPrice\n");
            printf("Standard\t1000 (per day)\n");
            printf("Deluxe\t\t1500 (per day)\n");
            printf("Premium\t\t2000 (per day)\n");
            break;
        case 2:
            printf("Room Types\tPrice\n");
            printf("Standard\t1200 (per day)\n");
            printf("Deluxe\t\t1800 (per day)\n");
            printf("Premium\t\t2500 (per day)\n");
            break;
        case 3:
            printf("Room Types\tPrice\n");
            printf("Standard\t800 (per day)\n");
            printf("Deluxe\t\t1400 (per day)\n");
            printf("Premium\t\t1900 (per day)\n");
            break;
        case 4:
            printf("Room Types\tPrice\n");
            printf("Standard\t2000 (per day)\n");
            printf("Deluxe\t\t2500 (per day)\n");
            printf("Premium\t\t3000 (per day)\n");
            break;
        default:
            printf("Invalid choice.\n");
            fclose(bookingsFile);
            return;
    }

    printf("Choose room type (Standard, Deluxe, Premium): ");
    scanf(" %[^\n]s", booking.roomType);

    float roomPrice;

    switch(choice) {
        case 1:
            if (strcmp(booking.roomType, "Standard") == 0) {
                roomPrice = 1000;
            } else if (strcmp(booking.roomType, "Deluxe") == 0) {
                roomPrice = 1500;
            } else if (strcmp(booking.roomType, "Premium") == 0) {
                roomPrice = 2000;
            } else {
                printf("Invalid room type.\n");
                fclose(bookingsFile);
                return;
            }
            break;
        case 2:
            if (strcmp(booking.roomType, "Standard") == 0) {
                roomPrice = 1200;
            } else if (strcmp(booking.roomType, "Deluxe") == 0) {
                roomPrice = 1800;
            } else if (strcmp(booking.roomType, "Premium") == 0) {
                roomPrice = 2500;
            } else {
                printf("Invalid room type.\n");
                fclose(bookingsFile);
                return;
            }
            break;
        case 3:
            if (strcmp(booking.roomType, "Standard") == 0) {
                roomPrice = 800;
            } else if (strcmp(booking.roomType, "Deluxe") == 0) {
                roomPrice = 1400;
            } else if (strcmp(booking.roomType, "Premium") == 0) {
                roomPrice = 1900;
            } else {
                printf("Invalid room type.\n");
                fclose(bookingsFile);
                return;
            }
            break;
        case 4:
            if (strcmp(booking.roomType, "Standard") == 0) {
                roomPrice = 2000;
            } else if (strcmp(booking.roomType, "Deluxe") == 0) {
                roomPrice = 2500;
            } else if (strcmp(booking.roomType, "Premium") == 0) {
                roomPrice = 3000;
            } else {
                printf("Invalid room type.\n");
                fclose(bookingsFile);
                return;
            }
            break;
        default:
            printf("Invalid choice.\n");
            fclose(bookingsFile);
            return;
    }

    //float roomBill, totalBill;

    booking.roomBill = booking.numOfDays*roomPrice*booking.numOfRooms;
    booking.totalBill = selectedPackage.price + booking.roomBill;

    fwrite(&booking, sizeof(Booking), 1, bookingsFile);
    fclose(bookingsFile);
 
 char c;
printf("\nConfirm booking? (Y/N): ");
            scanf(" %c",&c);
            if(c=='Y' || c=='y')
			{
    printf("Booking successful.\n");
    printf("Selected Package: %s\n", selectedPackage.name);
    printf("Room Bill: %.2f\n", booking.roomBill);
    printf("Total Bill: %.2f\n", booking.totalBill);
}
else
{
	printf("\nBooking cancelled.");
}

}

// Function to view booking details
void viewBookingDetails() {
    char mobileNumber[20];
mobile:
    printf("Enter your mobile number: ");
    scanf(" %[^\n]s", mobileNumber);

    FILE *file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("No bookings available.\n");
        return;
    }

    Booking booking;
    int found = 0; 

    while (fread(&booking, sizeof(Booking), 1, file)) {
        if (strcmp(booking.mobileNumber, mobileNumber) == 0) {
            printf("-------------------------------------------------------\n");
            printf("Booking Details:\n");
            printf("Date of check-in: %d/%d/%d\n", booking.cid,booking.cim,booking.ciy);
            printf("Package Name: %s\n", booking.package_name);
            printf("Name: %s\n", booking.name);
            printf("DOB: %s\n", booking.DOB);
            printf("Aadhar number: %s\n", booking.aadhar);
            printf("Mobile Number: %s\n", booking.mobileNumber);
            printf("Address: %s\n", booking.address);
            printf("State: %s\n", booking.state);
            printf("Number of Persons: %d\n", booking.numOfPersons);
            printf("Number of Days: %d\n", booking.numOfDays);
            printf("Hotel Name: %s\n", booking.hotel_name);
            printf("Number of Rooms: %d\n", booking.numOfRooms);
            printf("Room Type: %s\n", booking.roomType);
            printf("Room Bill: %.2f\n", booking.roomBill);
            printf("Total Bill: %.2f\n", booking.totalBill);
            printf("Date of check-out: %d/%d/%d\n", booking.cod,booking.com,booking.coy);
            printf("-------------------------------------------------------\n");

            found = 1;  
        }
    }

    if (!found) {
        printf("No bookings found for the provided mobile number.\n");
        goto mobile;
    }

    fclose(file);
}

// Function to view all bookings
void viewAllBookings() {
    FILE *file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("No bookings available.\n");
        return;
    }

    printf("All Bookings:\n");
    printf("------------------------------------------------------------------------------------\n");

    Booking booking;

    while (fread(&booking, sizeof(Booking), 1, file)) 
	{
		printf("Date of check-in: %d/%d/%d\n", booking.cid,booking.cim,booking.ciy);
		printf("package Name:%s\n",booking.package_name);
        printf("Name: %s\n", booking.name);
        printf("Mobile Number: %s\n", booking.mobileNumber);
        printf("Address: %s\n", booking.address);
        printf("State: %s\n", booking.state);
        printf("Number of Persons: %d\n", booking.numOfPersons);
        printf("Number of Days: %d\n", booking.numOfDays);
        printf("Hotel Name:%s\n",booking.hotel_name);
        printf("Number of Rooms: %d\n", booking.numOfRooms);
        printf("Room Type: %s\n", booking.roomType);
        printf("Room Bill:%0.2f\n",booking.roomBill);
        printf("Total Bill:%0.2f\n",booking.totalBill);
         printf("Date of check-out: %d/%d/%d\n", booking.cod,booking.com,booking.coy);
        printf("---------------------------------------------------------------------------------\n");
    }

    fclose(file);
}

// Function to search for customer details by mobile number
void searchCustomerDetails() {
    char mobileNumber[20];
input_mobile:
    printf("Enter the mobile number: ");
    scanf(" %[^\n]s", mobileNumber);

    FILE *file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("No bookings available.\n");
        return;
    }

    Booking booking;
    int found = 0;

    while (fread(&booking, sizeof(Booking), 1, file)) {
        if (strcmp(booking.mobileNumber, mobileNumber) == 0) 
		{
			printf("-----------------------------------------------------------------------\n");
            printf("Booking Details:\n");
            printf("Date of check-in: %d/%d/%d\n", booking.cid,booking.cim,booking.ciy);
            printf("package Name:%s\n",booking.package_name);
            printf("Name: %s\n", booking.name);
            printf("DOB:%s\n",booking.DOB);
            printf("Aadhar number:%s\n",booking.aadhar);
            printf("Mobile Number: %s\n", booking.mobileNumber);
            printf("Address: %s\n", booking.address);
            printf("State: %s\n", booking.state);
            printf("Number of Persons: %d\n", booking.numOfPersons);
            printf("Number of Days: %d\n", booking.numOfDays);
            printf("Hotel Name:%s\n",booking.hotel_name);
            printf("Number of Rooms: %d\n", booking.numOfRooms);
            printf("Room Type: %s\n", booking.roomType);
            printf("Room Bill:%0.2f\n",booking.roomBill);
            printf("Total Bill:%0.2f\n",booking.totalBill);
            printf("Date of check-out: %d/%d/%d\n", booking.cod,booking.com,booking.coy);
            printf("-----------------------------------------------------------------------\n");
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("Customer details not found.\n");
        goto input_mobile;
    }
}

// Function to delete customer details
void deleteCustomerDetails() {
    char mobileNumber[20];
    mb:
    printf("Enter the mobile number of the customer whose details you want to delete: ");
    scanf(" %[^\n]s", mobileNumber);

    FILE *file = fopen("bookings.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Booking booking;
    int found = 0;  

    while (fread(&booking, sizeof(Booking), 1, file)) {
        if (strcmp(booking.mobileNumber, mobileNumber) != 0) {
            fwrite(&booking, sizeof(Booking), 1, tempFile);
        } else {
            found = 1;  
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found) {
        printf("Customer details deleted successfully.\n");
    } else {
        printf("No customer details found for the provided mobile number.\n");
        goto mb;
    }
}

User users[10];
int userCount = 0;

void registerUser() {
    printf("Registration\n");
    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    int i = 0;
    while (1) {
        char ch = getch();
        if (ch == 13)  // Enter key
            break;
        putchar('*');  // Print asterisks instead of the actual character
        users[userCount].password[i++] = ch;
    }
    users[userCount].password[i] = '\0';

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    fprintf(file, "%s %s\n", users[userCount].username, users[userCount].password);
    fclose(file);

    userCount++;
    printf("\nRegistration successful!\n");
}

//define MAX_ATTEMPTS 3

int signIn() {
    printf("Sign In\n");
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    int i = 0;
    while (1) {
        char ch = getch();
        if (ch == 13)  // Enter key
            break;
        putchar('*');  
        password[i++] = ch;
    }
    password[i] = '\0';

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return 0;
    }

    char fileUsername[20];
    char filePassword[20];
    int attempts = 0;
    int isLoggedIn = 0;
    int MAX_ATTEMPTS=3;

    while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            isLoggedIn = 1;
            break;
        }
    }

    fclose(file);

    if (isLoggedIn) {
        printf("\nWelcome, %s!\n", username);
        return 1;  // Sign-in successful
    } else {
        printf("\nInvalid username or password. Please try again.\n");
        attempts++;

        if (attempts == MAX_ATTEMPTS) {
            printf("Too many failed attempts. Exiting...\n");
            return 0;  // Sign-in failed
        } else {
            return signIn();  // Recursive call to try again
        }
    }
}

