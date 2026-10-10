#include <stdio.h>

int main()
{
    float purchase, distance;
    float discountAmount, deliveryCharge, finalAmount;
    int customerType;
    float discountPercent;

    printf("Enter purchase amount: ");
    scanf("%f", &purchase);

    printf("Enter customer type (1-Student, 2-Regular): ");
    scanf("%d", &customerType);

    printf("Enter delivery distance in km: ");
    scanf("%f", &distance);

    if (purchase < 0 || distance < 0)
    {
        printf("Invalid purchase amount or distance.\n");
        return 0;
    }

    if (customerType == 1)
    {
        if (purchase >= 2000)
            discountPercent = 15;
        else
            discountPercent = 10;
    }
    else if (customerType == 2)
    {
        if (purchase >= 3000)
            discountPercent = 8;
        else
            discountPercent = 0;
    }
    else
    {
        printf("Invalid customer type.\n");
        return 0;
    }

    discountAmount = purchase * discountPercent / 100;

    if (distance <= 5)
        deliveryCharge = 40;
    else if (distance <= 15)
        deliveryCharge = 70;
    else
        deliveryCharge = 100;

    finalAmount = purchase - discountAmount + deliveryCharge;

    printf("\n--- SmartCart Bill ---\n");
    printf("Purchase Amount: Rs. %.2f\n", purchase);
    printf("Discount: %.0f%%\n", discountPercent);
    printf("Discount Amount: Rs. %.2f\n", discountAmount);
    printf("Delivery Charge: Rs. %.2f\n", deliveryCharge);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);

    return 0;
}
