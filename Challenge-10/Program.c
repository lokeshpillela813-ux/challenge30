#include <stdio.h>
#define ZONES 5
#define DAYS 7

void inputData(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS]);
void displayData(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS]);
void calculateAverages(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS], float at[ZONES], float ah[ZONES], float aa[ZONES]);
void detectRiskZones(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS], int r[ZONES]);
void computeGreenIndex(float at[ZONES], float ah[ZONES], float aa[ZONES], float g[ZONES]);
void displayRanking(float g[ZONES]);
void displayRecommendations(float at[ZONES], float ah[ZONES], float aa[ZONES], int r[ZONES]);

int main()
{
    float t[ZONES][DAYS], h[ZONES][DAYS];
    int a[ZONES][DAYS], r[ZONES];
    float at[ZONES], ah[ZONES], aa[ZONES], g[ZONES];
    int choice, dataReady = 0, i;

    do
    {
        printf("\n--- ECOGUARD MENU ---\n");
        printf("1. Input Data\n");
        printf("2. Display Data\n");
        printf("3. Zone-wise Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index and Ranking\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                inputData(t, h, a);
                dataReady = 1;
                break;

            case 2:
                if(dataReady)
                    displayData(t, h, a);
                else
                    printf("Enter data first.\n");
                break;

            case 3:
                if(dataReady)
                {
                    calculateAverages(t, h, a, at, ah, aa);
                    for(i = 0; i < ZONES; i++)
                        printf("Zone %d: Temp=%.2f Humidity=%.2f AQI=%.2f\n", i+1, at[i], ah[i], aa[i]);
                }
                else
                    printf("Enter data first.\n");
                break;

            case 4:
                if(dataReady)
                    detectRiskZones(t, h, a, r);
                else
                    printf("Enter data first.\n");
                break;

            case 5:
                if(dataReady)
                {
                    calculateAverages(t, h, a, at, ah, aa);
                    computeGreenIndex(at, ah, aa, g);
                    displayRanking(g);
                }
                else
                    printf("Enter data first.\n");
                break;

            case 6:
                if(dataReady)
                {
                    calculateAverages(t, h, a, at, ah, aa);
                    detectRiskZones(t, h, a, r);
                    displayRecommendations(at, ah, aa, r);
                }
                else
                    printf("Enter data first.\n");
                break;

            case 7:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 7);

    return 0;
}

void inputData(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS])
{
    int i, j;

    for(i = 0; i < ZONES; i++)
    {
        printf("\nZone %d\n", i+1);

        for(j = 0; j < DAYS; j++)
        {
            do {
                printf("Day %d Temperature: ", j+1);
                scanf("%f", &t[i][j]);
            } while(t[i][j] < 10 || t[i][j] > 50);

            do {
                printf("Day %d Humidity: ", j+1);
                scanf("%f", &h[i][j]);
            } while(h[i][j] < 0 || h[i][j] > 100);

            do {
                printf("Day %d AQI: ", j+1);
                scanf("%d", &a[i][j]);
            } while(a[i][j] < 0 || a[i][j] > 500);
        }
    }
}

void displayData(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS])
{
    int i, j;

    printf("\nTEMPERATURE\n");
    for(i = 0; i < ZONES; i++) {
        for(j = 0; j < DAYS; j++)
            printf("%.1f ", t[i][j]);
        printf("\n");
    }

    printf("\nHUMIDITY\n");
    for(i = 0; i < ZONES; i++) {
        for(j = 0; j < DAYS; j++)
            printf("%.1f ", h[i][j]);
        printf("\n");
    }

    printf("\nAQI\n");
    for(i = 0; i < ZONES; i++) {
        for(j = 0; j < DAYS; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void calculateAverages(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS], float at[ZONES], float ah[ZONES], float aa[ZONES])
{
    int i, j;
    float x, y, z;

    for(i = 0; i < ZONES; i++)
    {
        x = y = z = 0;

        for(j = 0; j < DAYS; j++)
        {
            x += t[i][j];
            y += h[i][j];
            z += a[i][j];
        }

        at[i] = x / DAYS;
        ah[i] = y / DAYS;
        aa[i] = z / DAYS;
    }
}

void detectRiskZones(float t[ZONES][DAYS], float h[ZONES][DAYS], int a[ZONES][DAYS], int r[ZONES])
{
    int i, j;

    for(i = 0; i < ZONES; i++)
    {
        r[i] = 0;
        printf("\nZone %d Risk Days: ", i+1);

        for(j = 0; j < DAYS; j++)
        {
            if(a[i][j] > 150 || t[i][j] > 35 || h[i][j] > 80)
            {
                r[i]++;
                printf("%d ", j+1);
            }
        }

        if(r[i] == 0)
            printf("No risk days");

        printf("\nTotal = %d\n", r[i]);
    }
}

void computeGreenIndex(float at[ZONES], float ah[ZONES], float aa[ZONES], float g[ZONES])
{
    int i;
    float as, ts, hs, d;

    for(i = 0; i < ZONES; i++)
    {
        as = 100 - aa[i]/5;

        d = at[i] - 25;
        if(d < 0) d = -d;
        ts = 100 - 4*d;

        d = ah[i] - 50;
        if(d < 0) d = -d;
        hs = 100 - 2*d;

        if(as < 0) as = 0;
        if(ts < 0) ts = 0;
        if(hs < 0) hs = 0;

        g[i] = 0.4*as + 0.3*ts + 0.3*hs;
    }
}

void displayRanking(float g[ZONES])
{
    int i, j, rank;

    printf("\nGREEN INDEX RANKING\n");

    for(i = 0; i < ZONES; i++)
    {
        rank = 1;

        for(j = 0; j < ZONES; j++)
            if(g[j] > g[i])
                rank++;

        printf("Zone %d: %.2f Rank %d\n", i+1, g[i], rank);
    }
}

void displayRecommendations(float at[ZONES], float ah[ZONES], float aa[ZONES], int r[ZONES])
{
    int i, found;

    for(i = 0; i < ZONES; i++)
    {
        printf("\nZone %d:\n", i+1);
        found = 0;

        if(aa[i] > 150) {
            printf("Reduce vehicle idling or improve ventilation.\n");
            found = 1;
        }

        if(at[i] > 35) {
            printf("Provide shade or green cover.\n");
            found = 1;
        }

        if(ah[i] > 80) {
            printf("Check ventilation or stagnant water.\n");
            found = 1;
        }

        if(found == 0 && r[i] > 0)
            printf("Review individual risk days.\n");

        if(r[i] == 0)
            printf("Continue monitoring.\n");
    }
}
