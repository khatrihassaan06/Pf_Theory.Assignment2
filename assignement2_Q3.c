#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 4
#define MAX_CART 10

// ---------- GLOBAL VARIABLES ----------
char customerName[50];
int cnic;

// inventory[i][0] = product code
// inventory[i][1] = quantity in stock
// inventory[i][2] = price per product
int inventory[MAX_PRODUCTS][3] = {
    {1, 50, 100},
    {2, 10, 200},
    {3, 20, 300},
    {4, 8, 150}
};

// Cart arrays
int cartCodes[MAX_CART];
int cartQty[MAX_CART];
int cartCount = 0;

// ---------- FUNCTION DECLARATIONS ----------
void customerInfo();
void displayInventory();
void addToCart();
void updateInventory(int code, int qty);
void displayTotalBill();
void showInvoice();
int findProductIndex(int code);

// ---------- FUNCTION DEFINITIONS ----------

// Customer information input
void customerInfo() {
    printf("\n--- Enter Customer Information ---\n");
    printf("Enter your name: ");
    scanf("%s", customerName);
    printf("Enter your 5-digit CNIC number: ");
    scanf("%d", &cnic);
    printf("Customer info saved successfully!\n");
}

// Display inventory table
void displayInventory() {
    printf("\n--- Available Inventory ---\n");
    printf("Product Code\tQuantity\tPrice per Product\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%03d\t\t%d\t\t%d\n", inventory[i][0], inventory[i][1], inventory[i][2]);
    }
}

// Add item to cart
void addToCart() {
    int code, qty;
    displayInventory();
    printf("\nEnter product code to add to cart: ");
    scanf("%d", &code);

    int index = findProductIndex(code);
    if (index == -1) {
        printf("❌ Invalid product code!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (qty > inventory[index][1]) {
        printf("❌ Not enough stock available! Only %d in stock.\n", inventory[index][1]);
        return;
    }

    cartCodes[cartCount] = code;
    cartQty[cartCount] = qty;
    cartCount++;

    updateInventory(code, qty);

    printf("✅ Item added to cart successfully!\n");
}

// Update inventory after purchase
void updateInventory(int code, int qty) {
    int index = findProductIndex(code);
    if (index != -1) {
        inventory[index][1] -= qty; // reduce stock
    }
}

// Calculate and display total bill
void displayTotalBill() {
    float total = 0;
    printf("\n--- Cart Summary ---\n");
    printf("Code\tQty\tUnit Price\tTotal\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < cartCount; i++) {
        int index = findProductIndex(cartCodes[i]);
        int lineTotal = cartQty[i] * inventory[index][2];
        total += lineTotal;
        printf("%03d\t%d\t%d\t\t%d\n", cartCodes[i], cartQty[i], inventory[index][2], lineTotal);
    }

    printf("---------------------------------------\n");
    printf("Subtotal: %.2f\n", total);

    char promo[20];
    printf("Do you have a promo code? (Yes/No): ");
    scanf("%s", promo);

    float finalTotal = total;
    if (strcmp(promo, "Eid2025") == 0) {
        finalTotal = total * 0.75; // 25% discount
        printf("🎉 Promo code applied! 25%% discount given.\n");
    } else {
        printf("No discount applied.\n");
    }

    printf("Final Total: %.2f\n", finalTotal);
}

// Show final invoice
void showInvoice() {
    printf("\n========== CUSTOMER INVOICE ==========\n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %d\n", cnic);
    printf("--------------------------------------\n");
    displayTotalBill();
    printf("======================================\n");
    printf("Thank you for shopping at SuperMart!\n");
}

// Find product index by code
int findProductIndex(int code) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i][0] == code) return i;
    }
    return -1;
}

// ---------- MAIN MENU ----------
int main() {
    int choice;
    printf("=== WELCOME TO SUPERMART INVENTORY SYSTEM ===\n");

    do {
        printf("\n--------------- MAIN MENU ---------------\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInfo();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addToCart();
                break;
            case 4:
                displayTotalBill();
                break;
            case 5:
                showInvoice();
                break;
            case 6:
                printf("Exiting system... Thank you!\n");
                break;
            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
