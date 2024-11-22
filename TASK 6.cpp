#include <stdio.h>
#include <string.h>


struct Invoice {
    char partNumber[50];
    char partDescription[100];
    int quantity;
    float pricePerItem;
    float invoiceAmount;
};


void initializeInvoice(struct Invoice *invoice, char *partNumber, char *partDescription, int quantity, float pricePerItem) {
    strcpy(invoice->partNumber, partNumber);
    strcpy(invoice->partDescription, partDescription);

 
    invoice->quantity = (quantity > 0) ? quantity : 0;
    invoice->pricePerItem = (pricePerItem > 0) ? pricePerItem : 0.0;

 
    invoice->invoiceAmount = invoice->quantity * invoice->pricePerItem;
}


void displayInvoice(const struct Invoice *invoice) {
    printf("Part Number: %s\n", invoice->partNumber);
    printf("Part Description: %s\n", invoice->partDescription);
    printf("Quantity: %d\n", invoice->quantity);
    printf("Price Per Item: %.2f\n", invoice->pricePerItem);
    printf("Invoice Amount: %.2f\n", invoice->invoiceAmount);
}

int main() {
    struct Invoice invoice1, invoice2;

   
    initializeInvoice(&invoice1, "A123", "Hammer", 10, 15.5);

  
    initializeInvoice(&invoice2, "B456", "Screwdriver", -5, -8.0);


    printf("Invoice 1:\n");
    displayInvoice(&invoice1);

    printf("\nInvoice 2:\n");
    displayInvoice(&invoice2);

    return 0;
}

