#include <stdio.h>

int main() {
    float m1, m2, m3, m4, m5;
    float total, average, percentage;

    printf("Enter marks of five subjects: ");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    total = m1 + m2 + m3 + m4 + m5;
    average = total / 5.0;
    percentage = (total / 500.0) * 100;

    printf("Total marks = %.2f\n", total);
    printf("Average = %.2f\n", average);
    printf("Percentage = %.2f%%\n", percentage);

    return 0;
}
