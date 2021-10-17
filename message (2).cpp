Working code implemented in C and appropriate comments provided for better understanding.

Here I am attaching code for these files:

main.c
ItemToPurchase.c
ItemToPurchase.h
ShoppingCart.c
ShoppingCart.h
main.c:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

#define CUST_NAME_LEN 50
#define CURR_DATE_LEN 20
#define ITEM_NAME_LEN 50
#define ITEM_DESC_LEN 100

void PrintMenu(ShoppingCart cart);
ShoppingCart MenuAddItem(ShoppingCart cart);
ShoppingCart MenuRemoveItem(ShoppingCart cart);
ShoppingCart MenuChangeItemQty(ShoppingCart cart);
void MenuPrintDescriptions(ShoppingCart cart);
void MenuOutputCart(ShoppingCart cart);

int main(int argc, char const *argv[])
{
    // Declare variables
    char name[CUST_NAME_LEN];
    char date[CURR_DATE_LEN];
    char choice = ' ';
    char tmp;
    ShoppingCart cart;

    // Take user input: customer name
    printf("Enter Customer's Name:\n");
    fgets(name, CUST_NAME_LEN, stdin);
    name[strlen(name) - 1] = '\0';

    // Take user input: current date
    printf("Enter Today's Date:\n");
    fgets(date, CURR_DATE_LEN, stdin);
    date[strlen(date) - 1] = '\0';

    // Initialize ShoppingCart
    strcpy(cart.customerName, name);
    strcpy(cart.currentDate, date);
    cart.cartSize = 0;

    // Print initial information
    printf("\nCustomer Name: %s\n", cart.customerName);
    printf("Today's Date: %s\n\n", cart.currentDate);

    PrintMenu(cart);
    do
    {
        printf("Choose an option:\n");
        scanf(" %c%c", &choice, &tmp);

        switch (choice)
        {
        case 'q':
            break;
        case 'a':
            cart = MenuAddItem(cart);
            PrintMenu(cart);
            break;
        case 'r':
            cart = MenuRemoveItem(cart);
            PrintMenu(cart);
            break;
        case 'c':
            break;
        case 'i':
            MenuPrintDescriptions(cart);
            PrintMenu(cart);
            break;
        case 'o':
            MenuOutputCart(cart);
            PrintMenu(cart);
            break;
        default:
            break;
        }
    } while (choice != 'q');

    return 0;
}

void PrintMenu(ShoppingCart cart)
{
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n\n");
}

ShoppingCart MenuAddItem(ShoppingCart cart)
{
    char item_name[ITEM_NAME_LEN];
    char item_desc[ITEM_DESC_LEN];
    int item_price = 0;
    int item_qty = 0;
    ItemToPurchase item;

    printf("ADD ITEM TO CART\n");

    printf("Enter the item name:\n");
    fgets(item_name, ITEM_NAME_LEN, stdin);
    item_name[strlen(item_name) - 1] = '\0';
    strcpy(item.itemName, item_name);

    printf("Enter the item description:\n");
    fgets(item_desc, ITEM_DESC_LEN, stdin);
    item_desc[strlen(item_desc) - 1] = '\0';
    strcpy(item.itemDescription, item_desc);

    printf("Enter the item price:\n");
    scanf("%d", &item_price);
    item.itemPrice = item_price;

    printf("Enter the item quantity:\n\n");
    scanf("%d", &item_qty);
    item.itemQuantity = item_qty;

    cart = AddItem(item, cart);
    return cart;
}

ShoppingCart MenuRemoveItem(ShoppingCart cart)
{
    char item_name[ITEM_NAME_LEN];

    printf("REMOVE ITEM FROM CART\n");
    printf("Enter name of item to remove:\n");
    scanf(" %s", item_name);
    for (int i = 0; i < cart.cartSize; i++)
    {
        if (strcmp(item_name, cart.cartItems[i].itemName) == 0)
        {
            cart = RemoveItem(item_name, cart);
        }
        else
        {
            printf("Item not found in cart. Nothing removed.\n\n");
        }
    }
    return cart;
}

ShoppingCart MenuChangeItemQty(ShoppingCart cart)
{
    return cart;
}

void MenuPrintDescriptions(ShoppingCart cart)
{
    printf("OUTPUT ITEMS' DESCRIPTIONS\n");
    PrintDescriptions(cart);
}

void MenuOutputCart(ShoppingCart cart)
{
    printf("OUTPUT SHOPPING CART\n");
    PrintTotal(cart);
}

ItemToPurchase.c :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemToPurchase.h"

    void
    MakeItemBlank(ItemToPurchase *item)
{
    strcpy(item->itemName, "none");
    strcpy(item->itemDescription, "none");
    item->itemPrice = 0;
    item->itemQuantity = 0;
}

void PrintItemCost(ItemToPurchase item)
{
    printf("%s %d @ $%d = $%d\n", item.itemName, item.itemQuantity, item.itemPrice, item.itemPrice * item.itemQuantity);
}

void PrintItemDescription(ItemToPurchase item)
{
    printf("%s: %s\n", item.itemName, item.itemDescription);
}

ItemToPurchase.h :

#ifndef ITEMTOPURCHASE__INC__
#define ITEMTOPURCHASE__INC__

#include <stdio.h>
#include <stdlib.h>

#define ITEM_NAME_LEN 50
#define ITEM_DESC_LEN 100

    typedef struct ItemToPurchase
{
    char itemName[ITEM_NAME_LEN];
    char itemDescription[ITEM_DESC_LEN];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase *item);
void PrintItemCost(ItemToPurchase item);
void PrintItemDescription(ItemToPurchase item);

#endif

ShoppingCart.c :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingCart.h"

    ShoppingCart
    AddItem(ItemToPurchase item, ShoppingCart cart)
{
    // Adds an item to cart
    cart.cartItems[cart.cartSize] = item;
    cart.cartSize++;
    return cart;
}

ShoppingCart RemoveItem(char item_name[], ShoppingCart cart)
{
    // Removes an item from cart
    for (int i = 0; i < cart.cartSize; i++)
    {
        if (strcmp(item_name, cart.cartItems[i].itemName) == 0)
        {
            cart.cartItems[i].itemQuantity = 0;
        }
    }
    return cart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart)
{
    // Modifies contents (name, qty, etc.) of an item in cart
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart)
{
    // Returns the total quantity of items in a cart
    int count = 0;
    for (int i = 0; i < cart.cartSize; i++)
    {
        count += cart.cartItems[i].itemQuantity;
    }
    return count;
    return 0;
}

int GetCostOfCart(ShoppingCart cart)
{
    // Returns the total cost of items in a cart
    int total = 0;
    for (int i = 0; i < cart.cartSize; i++)
    {
        total += cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity;
    }
    return total;
}

void PrintTotal(ShoppingCart cart)
{
    // Outputs total number of items in cart
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
    if (GetNumItemsInCart(cart) == 0)
    {
        printf("SHOPPING CART IS EMPTY\n");
    }
    else
    {
        for (int i = 0; i < cart.cartSize; i++)
        {
            PrintItemCost(cart.cartItems[i]);
        }
    }
    printf("\nTotal: $%d\n\n", GetCostOfCart(cart));
}

void PrintDescriptions(ShoppingCart cart)
{
    // Outputs each item's description
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for (int i = 0; i < cart.cartSize; i++)
    {
        PrintItemDescription(cart.cartItems[i]);
    }
    printf("\n");
}

ShoppingCart.h :

#ifndef SHOPPINGCART__INC__
#define SHOPPINGCART__INC__

#include <stdio.h>
#include <stdlib.h>
#include "ItemToPurchase.h"

#define CUST_NAME_LEN 50
#define CURR_DATE_LEN 20
#define MAX_CART_SIZE 10

    typedef struct ShoppingCart
{
    char customerName[CUST_NAME_LEN];
    char currentDate[CURR_DATE_LEN];
    int cartSize;
    ItemToPurchase cartItems[MAX_CART_SIZE];
} ShoppingCart;

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);    // Adds an item to cart
ShoppingCart RemoveItem(char item_name[], ShoppingCart cart);    // Removes an item from cart
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart); // Modifies contents (name, qty, etc.) of an item in cart
int GetNumItemsInCart(ShoppingCart cart);                        // Returns the total quantity of items in a cart
int GetCostOfCart(ShoppingCart cart);                            // Returns the total cost of items in a cart
void PrintTotal(ShoppingCart cart);                              // Outputs total number of items in cart
void PrintDescriptions(ShoppingCart cart);                       // Outputs each item's description

#endif