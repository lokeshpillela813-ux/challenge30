#include <stdio.h>

int main()
{
    float expense;
    float smallTotal = 0, mediumTotal = 0, largeTotal = 0;
    float total = 0, average;
    int validCount = 0;
    int smallCount = 0, mediumCount = 0, largeCount = 0;

    while (1)
    {
        printf("Enter expense amount (0 to stop): ");
        scanf("%f", &expense);

        if (expense == 0)
        {
            break;
        }
        else if (expense < 0)
        {
            printf("Invalid expense amount!\n");
        }
        else
        {
            validCount++;
            total = total + expense;

            if (expense < 100)
            {
                smallCount++;
                smallTotal = smallTotal + expense;
            }
            else if (expense < 500)
            {
                mediumCount++;
                mediumTotal = mediumTotal + expense;
            }
            else
            {
                largeCount++;
                largeTotal = largeTotal + expense;
            }
        }
    }

    printf("\n--- EXPENSE SUMMARY ---\n");
    printf("Number of valid expenses: %d\n", validCount);
    printf("Total valid expenses: %.2f\n", total);

    printf("\nSmall expenses count: %d\n", smallCount);
    printf("Small expenses total: %.2f\n", smallTotal);

    printf("\nMedium expenses count: %d\n", mediumCount);
    printf("Medium expenses total: %.2f\n", mediumTotal);

    printf("\nLarge expenses count: %d\n", largeCount);
    printf("Large expenses total: %.2f\n", largeTotal);

    if (validCount > 0)
    {
        average = total / validCount;
        printf("Average valid expense: %.2f\n", average);
    }
    else
    {
        printf("No valid expenses were entered.\n");
    }

    return 0;
}
