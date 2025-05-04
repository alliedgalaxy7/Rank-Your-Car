#include <stdio.h>
#include "ansiColourCodes.h"


float calculate(float area, float topSpeed, float power, float torque, float weight)
{
    float alpha = 1.5f;    // Top speed
    float beta  = 1.25f;    // Power
    float gamma = 0.8f;    // Torque
    float delta = 1.25f;    // Weight
    float zeta = 1.0f;     // Cross-sectional area

    float numerator = alpha * topSpeed + beta * power + gamma * torque;
    float denominator = delta * weight + zeta * area;

    return 1200 * numerator / denominator;
}

int main()
{
    float power, torque, topSpeed, weight, area;
    char isImperial;

    printf("\nChoose your measurement system:\n");
    printf("\nInput all values as " HYEL "decimal" reset " numbers.\n");
    printf("\nEnter m for Metric (" UHCYN "kW, Nm, km/h, kg, m^2" reset ")\n");
    printf("Enter i for Imperial (" UHMAG "hp, lb-ft, mph, lbs, ft^2" reset ")\n");
    scanf("%c", &isImperial);

    if (isImperial == 'i')
    {
        float hp, tq, spd, wgt, ar;

        printf("Enter power (hp): ");
        scanf("%f", &hp);
        power = hp * 0.7457f; // hp to kW

        printf("Enter torque (lb-ft): ");
        scanf("%f", &tq);
        torque = tq * 1.3558f; // lb-ft to Nm

        printf("Enter top speed (mph): ");
        scanf("%f", &spd);
        topSpeed = spd * 1.60934f; // mph to km/h

        printf("Enter weight (lbs): ");
        scanf("%f", &wgt);
        weight = wgt * 0.453592f; // lbs to kg

        printf("Enter frontal area (ft^2): ");
        scanf("%f", &ar);
        area = ar * 0.092903f; // ft^2 to m^2
    }
    else if (isImperial == 'm')
    {
        printf("Enter power (kW): ");
        scanf("%f", &power);

        printf("Enter torque (Nm): ");
        scanf("%f", &torque);

        printf("Enter top speed (km/h): ");
        scanf("%f", &topSpeed);

        printf("Enter weight (kg): ");
        scanf("%f", &weight);

        printf("Enter frontal area (m^2): ");
        scanf("%f", &area);
    }
    else
    {
        printf("Sorry, you did not input either character. Please run the program again.\n");
	return 0;
    }

    float performanceScore = calculate(area, topSpeed, power, torque, weight);

    printf("\nThe performance score of the vehicle is: %1.f", performanceScore);

    if (performanceScore <= 250)
    {
        printf("\nThis vehicle therefore ranks as a " HYEL "D" reset " class vehicle.\n");
    }
    else if (performanceScore > 250 && performanceScore <= 500)
    {
        printf("\nThis vehicle therefore ranks as a " HBLU "C" reset " class vehicle.\n");
    }
    else if (performanceScore > 500 && performanceScore <= 750)
    {
        printf("\nThis vehicle therefore ranks as a " HGRN "B" reset " class vehicle.\n");
    } 
    else if (performanceScore > 750 && performanceScore <= 1000)
    {
        printf("\nThis vehicle therefore ranks as an " HRED "A" reset " class vehicle.\n");
    } 
    else if (performanceScore > 1000 && performanceScore <= 1250)
    {
        printf("\nThis vehicle therefore ranks as an " HMAG "S" reset " class vehicle.\n");
    } 
    else if (performanceScore > 1250)
    {
        printf("\nThis vehicle therefore ranks as an " BHWHT "X" reset " class vehicle.\n");
    }

    return 0;
};

