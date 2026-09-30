#include<stdio.h>
int main()
{
  float distance,mileage,price;
float fuel,cost;
printf("enter total distance (km):");
scanf("%f",&distance);
printf("enter vehicle mileage(km/l):");
scanf("%f",&mileage);
printf("enter fuel price(Rs/l):");
scanf("%f",&price);
fuel=distance/mileage;
cost=fuel*price;
printf("fuel required=%.2f\n",fuel);
printf("total fuel cost=rs%.2f\n",cost);
return 0;
}

