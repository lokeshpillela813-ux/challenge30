#include <stdio.h>

int main()
{
int ticket[15], n, i, j, id, count;
int missing = 0, duplicate = 0;
int mc = 0, dc = 0, invalid = 0;
int pairs = 0, r, target, targetCount = 0;

 do
  {
    printf("Enter N (5 to 15): ");
    scanf("%d", &n);
  } while (n < 5 || n > 15);

   for (i = 0; i < n; i++)
   {
     do
    
       printf("Enter ticket ID (1 to %d): ", n);
            scanf("%d", &ticket[i]);
        } while (ticket[i] < 1 || ticket[i] > n);
    }

    printf("Original sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", ticket[i]);

    for (id = 1; id <= n; id++)
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            if (ticket[i] == id)
                count++;
        }

        if (count == 0)
        {
            missing = id;
            mc++;
        }
        else if (count == 2)
        {
            duplicate = id;
            dc++;
        }
        else if (count != 1)
        {
            invalid = 1;
        }
    }

    if (mc != 1 || dc != 1)
        invalid = 1;

    if (invalid)
    {
        printf("\nInvalid scan log.\n");
        return 0;
    }

    printf("\nDuplicate ID: %d", duplicate);
    printf("\nMissing ID: %d\n", missing);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ticket[i] > ticket[j])
                pairs++;
        }
    }

    printf("Out-of-order pairs: %d\n", pairs);

    printf("Enter last two digits of registration number: ");
    scanf("%d", &r);

    target = (r % n) + 1;

    printf("Target ID: %d\n", target);
    printf("Positions: ");

    for (i = 0; i < n; i++)
    {
        if (ticket[i] == target)
        {
            printf("%d ", i + 1);
            targetCount++;
        }
    }

    printf("\nOccurrence count: %d\n", targetCount);

    return 0;
}
