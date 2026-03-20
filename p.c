/*
================================================================================
                    EZ CAMPUS - ENCAVE CAFE MANAGEMENT SYSTEM
================================================================================
    Project: Campus Canteen Management System
    Language: C
    Features: Table Booking, Food Ordering, Billing, Admin Dashboard
    Tables: 54 (18 rows x 3 columns)
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== STRUCTURE DEFINITIONS ====================

// Table Structure
struct Table {
    int tableId;
    int row;
    int column;
    int isOccupied;
    char customerName[50];
    float currentBill;
};

// Menu Item Structure
struct MenuItem {
    char name[100];
    float price;
    char category[50];
};

// ==================== GLOBAL VARIABLES ====================

struct Table tables[54];  // Array to store 54 tables
struct MenuItem menu[100]; // Array to store menu items
int menuCount = 0;         // Counter for menu items
float dailyRevenue = 0.0;  // Total daily revenue
int customersServed = 0;   // Total customers served

// ==================== FUNCTION PROTOTYPES ====================

void initializeTables();
void initializeMenu();
void displayMainMenu();
void viewTableMap();
void bookTableAndOrder();
void displayMenuByCategory();
void checkoutTable();
void adminDashboard();
void clearScreen();
void printHeader(char *title);
void printLine();

// ==================== MAIN FUNCTION ====================

int main() {
    int choice;
    
    // Initialize tables and menu
    initializeTables();
    initializeMenu();
    
    // Main program loop
    while(1) {
        displayMainMenu();
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                viewTableMap();
                break;
            case 2:
                bookTableAndOrder();
                break;
            case 3:
                checkoutTable();
                break;
            case 4:
                adminDashboard();
                break;
            case 5:
                printf("\n\n\t========================================\n");
                printf("\t   Thank you for using EZ Campus!\n");
                printf("\t   Visit Encave Cafe again!\n");
                printf("\t========================================\n\n");
                exit(0);
            default:
                printf("\n\t*** Invalid choice! Please try again. ***\n");
                printf("\n\tPress Enter to continue...");
                getchar();
                getchar();
        }
    }
    
    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

/*
 * Function: initializeTables
 * Description: Initializes all 54 tables with default values
 */
void initializeTables() {
    int index = 0;
    
    for(int row = 1; row <= 18; row++) {
        for(int col = 1; col <= 3; col++) {
            tables[index].tableId = index + 1;
            tables[index].row = row;
            tables[index].column = col;
            tables[index].isOccupied = 0;
            strcpy(tables[index].customerName, "");
            tables[index].currentBill = 0.0;
            index++;
        }
    }
}

/*
 * Function: initializeMenu
 * Description: Initializes the complete Encave Cafe menu
 */
void initializeMenu() {
    // Breakfast
    strcpy(menu[menuCount].name, "Bun Maska");
    menu[menuCount].price = 49;
    strcpy(menu[menuCount].category, "Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Butter Croissant");
    menu[menuCount].price = 49;
    strcpy(menu[menuCount].category, "Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Masala Oats");
    menu[menuCount].price = 69;
    strcpy(menu[menuCount].category, "Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Muesli Cereal Bowl");
    menu[menuCount].price = 79;
    strcpy(menu[menuCount].category, "Breakfast");
    menuCount++;
    
    // Indian Breakfast
    strcpy(menu[menuCount].name, "Poha");
    menu[menuCount].price = 30;
    strcpy(menu[menuCount].category, "Indian Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Upma");
    menu[menuCount].price = 40;
    strcpy(menu[menuCount].category, "Indian Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Poori Bhaji");
    menu[menuCount].price = 59;
    strcpy(menu[menuCount].category, "Indian Breakfast");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Thalipeeth");
    menu[menuCount].price = 69;
    strcpy(menu[menuCount].category, "Indian Breakfast");
    menuCount++;
    
    // Subs, Focaccia & Croissant
    strcpy(menu[menuCount].name, "Veg Grilled Sub");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Veg N Cheese Grilled Sub");
    menu[menuCount].price = 109;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Cheese Grilled Sub");
    menu[menuCount].price = 109;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Grilled Veg Pesto Sub");
    menu[menuCount].price = 119;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Veg Cheese Croissant");
    menu[menuCount].price = 129;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Grilled Veg Focaccia");
    menu[menuCount].price = 129;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Paneer Tikka Masala Sub");
    menu[menuCount].price = 129;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Paneer Tikka Masala Cheese Sub");
    menu[menuCount].price = 139;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Pesto Veg Croissant");
    menu[menuCount].price = 149;
    strcpy(menu[menuCount].category, "Subs, Focaccia & Croissant");
    menuCount++;
    
    // Fries & Nachos
    strcpy(menu[menuCount].name, "Fries Classic");
    menu[menuCount].price = 79;
    strcpy(menu[menuCount].category, "Fries & Nachos");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Fries Peri Peri");
    menu[menuCount].price = 89;
    strcpy(menu[menuCount].category, "Fries & Nachos");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Nachos with Tomato Salsa");
    menu[menuCount].price = 89;
    strcpy(menu[menuCount].category, "Fries & Nachos");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Cheesy Nachos with Tomato Salsa");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Fries & Nachos");
    menuCount++;
    
    // Pastas
    strcpy(menu[menuCount].name, "Pasta Arrabbiata");
    menu[menuCount].price = 159;
    strcpy(menu[menuCount].category, "Pastas");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Pasta Alfredo");
    menu[menuCount].price = 169;
    strcpy(menu[menuCount].category, "Pastas");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Pesto Pasta");
    menu[menuCount].price = 169;
    strcpy(menu[menuCount].category, "Pastas");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Pink Pasta");
    menu[menuCount].price = 179;
    strcpy(menu[menuCount].category, "Pastas");
    menuCount++;
    
    // Wood Fired Pizza Slicer
    strcpy(menu[menuCount].name, "Margherita Pizza Slicer");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Wood Fired Pizza Slicer");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Farmhouse Pizza Slicer");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Wood Fired Pizza Slicer");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Paneer Tikka Pizza Slicer");
    menu[menuCount].price = 119;
    strcpy(menu[menuCount].category, "Wood Fired Pizza Slicer");
    menuCount++;
    
    // Burger
    strcpy(menu[menuCount].name, "Encave UFO Veggie Burger");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Burger");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Encave UFO Veggie & Cheese Burger");
    menu[menuCount].price = 109;
    strcpy(menu[menuCount].category, "Burger");
    menuCount++;
    
    // Indian Bowl
    strcpy(menu[menuCount].name, "Veg Dum Biryani Bowl");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Indian Bowl");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Dal Khichadi");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Indian Bowl");
    menuCount++;
    
    // Chinese Rice & Noodles
    strcpy(menu[menuCount].name, "Veg Fried Rice");
    menu[menuCount].price = 109;
    strcpy(menu[menuCount].category, "Chinese Rice & Noodles");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Veg Schezwan Fried Rice");
    menu[menuCount].price = 119;
    strcpy(menu[menuCount].category, "Chinese Rice & Noodles");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Veg Hakka Noodles");
    menu[menuCount].price = 109;
    strcpy(menu[menuCount].category, "Chinese Rice & Noodles");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Veg Schezwan Noodles");
    menu[menuCount].price = 119;
    strcpy(menu[menuCount].category, "Chinese Rice & Noodles");
    menuCount++;
    
    // Chinese Starter
    strcpy(menu[menuCount].name, "Veg Manchurian");
    menu[menuCount].price = 119;
    strcpy(menu[menuCount].category, "Chinese Starter");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Honey Chilli Potato");
    menu[menuCount].price = 129;
    strcpy(menu[menuCount].category, "Chinese Starter");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Paneer Chilli");
    menu[menuCount].price = 149;
    strcpy(menu[menuCount].category, "Chinese Starter");
    menuCount++;
    
    // Hot Beverages
    strcpy(menu[menuCount].name, "Masala Tea");
    menu[menuCount].price = 12;
    strcpy(menu[menuCount].category, "Hot Beverages");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Filter Kaapi");
    menu[menuCount].price = 25;
    strcpy(menu[menuCount].category, "Hot Beverages");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Black Coffee");
    menu[menuCount].price = 25;
    strcpy(menu[menuCount].category, "Hot Beverages");
    menuCount++;
    
    // Cold Beverages
    strcpy(menu[menuCount].name, "Mango Shake");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Cold Beverages");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Strawberry Shake");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Cold Beverages");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Chocolate Shake");
    menu[menuCount].price = 99;
    strcpy(menu[menuCount].category, "Cold Beverages");
    menuCount++;
    
    strcpy(menu[menuCount].name, "Cold Coffee");
    menu[menuCount].price = 45;
    strcpy(menu[menuCount].category, "Cold Beverages");
    menuCount++;
}

/*
 * Function: displayMainMenu
 * Description: Displays the main menu of the application
 */
void displayMainMenu() {
    clearScreen();
    printHeader("EZ CAMPUS - ENCAVE CAFE MANAGEMENT SYSTEM");
    printf("\n");
    printf("\t\t╔════════════════════════════════════════╗\n");
    printf("\t\t║            MAIN MENU                   ║\n");
    printf("\t\t╠════════════════════════════════════════╣\n");
    printf("\t\t║  1. View Table Map                     ║\n");
    printf("\t\t║  2. Book Table & Order                 ║\n");
    printf("\t\t║  3. Checkout Table                     ║\n");
    printf("\t\t║  4. Admin Dashboard                    ║\n");
    printf("\t\t║  5. Exit                               ║\n");
    printf("\t\t╚════════════════════════════════════════╝\n");
}

/*
 * Function: viewTableMap
 * Description: Displays the table layout in 18 rows x 3 columns format
 */
void viewTableMap() {
    clearScreen();
    printHeader("TABLE MAP - ENCAVE CAFE");
    printf("\n");
    printf("\t\t[XX] = Occupied  |  [01] = Available\n\n");
    
    int index = 0;
    for(int row = 1; row <= 18; row++) {
        printf("\t\tRow %2d: ", row);
        for(int col = 1; col <= 3; col++) {
            if(tables[index].isOccupied) {
                printf("[XX] ");
            } else {
                printf("[%02d] ", tables[index].tableId);
            }
            index++;
        }
        printf("\n");
    }
    
    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}

/*
 * Function: bookTableAndOrder
 * Description: Books a table and allows customer to order food
 */
void bookTableAndOrder() {
    int tableNum, orderMore;
    char customerName[50];
    float subtotal = 0.0, gst, discount = 0.0, grandTotal;
    
    clearScreen();
    printHeader("BOOK TABLE & ORDER");
    
    // Get table number
    printf("\n\tEnter table number (1-54): ");
    scanf("%d", &tableNum);
    
    // Validate table number
    if(tableNum < 1 || tableNum > 54) {
        printf("\n\t*** Invalid table number! ***\n");
        printf("\n\tPress Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    // Check if table is already occupied
    if(tables[tableNum - 1].isOccupied) {
        printf("\n\t*** Table %d is already occupied! ***\n", tableNum);
        printf("\n\tPress Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    // Get customer name
    printf("\tEnter customer name: ");
    getchar(); // Clear buffer
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = 0; // Remove newline
    
    // Copy customer name to table
    strcpy(tables[tableNum - 1].customerName, customerName);
    
    // Order loop
    do {
        clearScreen();
        printHeader("ENCAVE CAFE - MENU");
        
        printf("\n\t╔════════════════════════════════════════════════════╗\n");
        printf("\t║              SELECT CATEGORY                       ║\n");
        printf("\t╠════════════════════════════════════════════════════╣\n");
        printf("\t║  1. Breakfast                                      ║\n");
        printf("\t║  2. Indian Breakfast                               ║\n");
        printf("\t║  3. Subs, Focaccia & Croissant                     ║\n");
        printf("\t║  4. Fries & Nachos                                 ║\n");
        printf("\t║  5. Pastas                                         ║\n");
        printf("\t║  6. Wood Fired Pizza Slicer                        ║\n");
        printf("\t║  7. Burger                                         ║\n");
        printf("\t║  8. Indian Bowl                                    ║\n");
        printf("\t║  9. Chinese Rice & Noodles                         ║\n");
        printf("\t║ 10. Chinese Starter                                ║\n");
        printf("\t║ 11. Hot Beverages                                  ║\n");
        printf("\t║ 12. Cold Beverages                                 ║\n");
        printf("\t╚════════════════════════════════════════════════════╝\n");
        
        int categoryChoice;
        printf("\n\tSelect category: ");
        scanf("%d", &categoryChoice);
        
        char selectedCategory[50];
        switch(categoryChoice) {
            case 1: strcpy(selectedCategory, "Breakfast"); break;
            case 2: strcpy(selectedCategory, "Indian Breakfast"); break;
            case 3: strcpy(selectedCategory, "Subs, Focaccia & Croissant"); break;
            case 4: strcpy(selectedCategory, "Fries & Nachos"); break;
            case 5: strcpy(selectedCategory, "Pastas"); break;
            case 6: strcpy(selectedCategory, "Wood Fired Pizza Slicer"); break;
            case 7: strcpy(selectedCategory, "Burger"); break;
            case 8: strcpy(selectedCategory, "Indian Bowl"); break;
            case 9: strcpy(selectedCategory, "Chinese Rice & Noodles"); break;
            case 10: strcpy(selectedCategory, "Chinese Starter"); break;
            case 11: strcpy(selectedCategory, "Hot Beverages"); break;
            case 12: strcpy(selectedCategory, "Cold Beverages"); break;
            default:
                printf("\n\t*** Invalid category! ***\n");
                printf("\n\tPress Enter to continue...");
                getchar();
                getchar();
                continue;
        }
        
        // Display items in selected category
        clearScreen();
        printHeader(selectedCategory);
        printf("\n");
        
        int itemIndex = 1;
        printf("\t%-5s %-50s %s\n", "No.", "Item Name", "Price (Rs.)");
        printLine();
        
        for(int i = 0; i < menuCount; i++) {
            if(strcmp(menu[i].category, selectedCategory) == 0) {
                printf("\t%-5d %-50s %.2f\n", itemIndex, menu[i].name, menu[i].price);
                itemIndex++;
            }
        }
        
        // Get item selection
        int itemChoice, quantity;
        printf("\n\tSelect item number: ");
        scanf("%d", &itemChoice);
        
        if(itemChoice < 1 || itemChoice >= itemIndex) {
            printf("\n\t*** Invalid item! ***\n");
            printf("\n\tPress Enter to continue...");
            getchar();
            getchar();
            continue;
        }
        
        printf("\tEnter quantity: ");
        scanf("%d", &quantity);
        
        // Calculate cost for selected item
        int currentIndex = 0;
        for(int i = 0; i < menuCount; i++) {
            if(strcmp(menu[i].category, selectedCategory) == 0) {
                currentIndex++;
                if(currentIndex == itemChoice) {
                    float itemTotal = menu[i].price * quantity;
                    subtotal += itemTotal;
                    printf("\n\t✓ Added: %s x %d = Rs. %.2f\n", menu[i].name, quantity, itemTotal);
                    break;
                }
            }
        }
        
        printf("\n\tCurrent Subtotal: Rs. %.2f\n", subtotal);
        printf("\n\tOrder more? (1=Yes / 0=No): ");
        scanf("%d", &orderMore);
        
    } while(orderMore == 1);
    
    // Calculate GST and discount
    gst = subtotal * 0.05; // 5% GST
    
    if(subtotal >= 1000) {
        discount = subtotal * 0.10; // 10% discount
    }
    
    grandTotal = subtotal + gst - discount;
    
    // Display bill summary
    clearScreen();
    printHeader("BILL SUMMARY");
    printf("\n");
    printf("\t%-30s: Rs. %.2f\n", "Subtotal", subtotal);
    printf("\t%-30s: Rs. %.2f\n", "GST (5%)", gst);
    printf("\t%-30s: Rs. %.2f\n", "Discount (10%)", discount);
    printLine();
    printf("\t%-30s: Rs. %.2f\n", "GRAND TOTAL", grandTotal);
    printLine();
    
    // Update table information
    tables[tableNum - 1].isOccupied = 1;
    tables[tableNum - 1].currentBill = grandTotal;
    
    printf("\n\t✓ Table %d booked successfully for %s\n", tableNum, customerName);
    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}

/*
 * Function: checkoutTable
 * Description: Checks out a table and displays receipt
 */
void checkoutTable() {
    int tableNum;
    
    clearScreen();
    printHeader("CHECKOUT TABLE");
    
    printf("\n\tEnter table number to checkout (1-54): ");
    scanf("%d", &tableNum);
    
    // Validate table number
    if(tableNum < 1 || tableNum > 54) {
        printf("\n\t*** Invalid table number! ***\n");
        printf("\n\tPress Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    // Check if table is occupied
    if(!tables[tableNum - 1].isOccupied) {
        printf("\n\t*** Table %d is not occupied! ***\n", tableNum);
        printf("\n\tPress Enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    // Display receipt
    clearScreen();
    printHeader("RECEIPT");
    printf("\n");
    printf("\t╔════════════════════════════════════════════════════╗\n");
    printf("\t║              ENCAVE CAFE - RECEIPT                 ║\n");
    printf("\t╠════════════════════════════════════════════════════╣\n");
    printf("\t║  Customer Name  : %-32s║\n", tables[tableNum - 1].customerName);
    printf("\t║  Table Number   : %-32d║\n", tableNum);
    printf("\t║  Final Amount   : Rs. %-26.2f║\n", tables[tableNum - 1].currentBill);
    printf("\t╠════════════════════════════════════════════════════╣\n");
    printf("\t║         Thank you for visiting Encave Cafe!        ║\n");
    printf("\t║              Please visit again!                   ║\n");
    printf("\t╚════════════════════════════════════════════════════╝\n");
    
    // Update daily revenue and customer count
    dailyRevenue += tables[tableNum - 1].currentBill;
    customersServed++;
    
    // Clear table
    tables[tableNum - 1].isOccupied = 0;
    strcpy(tables[tableNum - 1].customerName, "");
    tables[tableNum - 1].currentBill = 0.0;
    
    printf("\n\t✓ Table %d checked out successfully!\n", tableNum);
    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}

/*
 * Function: adminDashboard
 * Description: Displays admin statistics
 */
void adminDashboard() {
    clearScreen();
    printHeader("ADMIN DASHBOARD");
    
    int occupiedTables = 0;
    int freeTables = 0;
    
    // Count occupied and free tables
    for(int i = 0; i < 54; i++) {
        if(tables[i].isOccupied) {
            occupiedTables++;
        } else {
            freeTables++;
        }
    }
    
    printf("\n");
    printf("\t╔════════════════════════════════════════════════════╗\n");
    printf("\t║              DAILY STATISTICS                      ║\n");
    printf("\t╠════════════════════════════════════════════════════╣\n");
    printf("\t║  Total Tables          : %-26d║\n", 54);
    printf("\t║  Occupied Tables       : %-26d║\n", occupiedTables);
    printf("\t║  Free Tables           : %-26d║\n", freeTables);
    printf("\t║  Daily Revenue         : Rs. %-21.2f║\n", dailyRevenue);
    printf("\t║  Customers Served      : %-26d║\n", customersServed);
    printf("\t╚════════════════════════════════════════════════════╝\n");
    
    // Display currently occupied tables
    if(occupiedTables > 0) {
        printf("\n");
        printHeader("CURRENTLY OCCUPIED TABLES");
        printf("\n");
        printf("\t%-10s %-30s %-15s\n", "Table No.", "Customer Name", "Bill Amount");
        printLine();
        
        for(int i = 0; i < 54; i++) {
            if(tables[i].isOccupied) {
                printf("\t%-10d %-30s Rs. %-10.2f\n", 
                       tables[i].tableId, 
                       tables[i].customerName, 
                       tables[i].currentBill);
            }
        }
    }
    
    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}

/*
 * Function: clearScreen
 * Description: Clears the console screen
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*
 * Function: printHeader
 * Description: Prints a formatted header
 */
void printHeader(char *title) {
    printf("\n");
    printf("\t════════════════════════════════════════════════════════\n");
    printf("\t                    %s\n", title);
    printf("\t════════════════════════════════════════════════════════\n");
}

/*
 * Function: printLine
 * Description: Prints a separator line
 */
void printLine() {
    printf("\t────────────────────────────────────────────────────────\n");
}
