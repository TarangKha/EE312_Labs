#include <stdio.h>
#include <math.h> //needed for rounf function to work correctly
#include <string.h> //for using string

int main()
{
	char inputChar40[40];
	char a[10] = "testing";  // it works
							 //	a = "testing"; // does not work 
	const double MILESTOKMFACTOR = 0.6213712;
	const double POUNDSTOGRAMSFACTOR = 453.59237;
	const double EUROTOUSD = 1.36;
	const double USDTOEURO = 0.74;
	int inputHours;
	int inputMinutes;
	int outputHours;
	int outputMinutes;
	char dayValue[10];
	int inputInt;
	int inputDollars;
	int inputCents;
	int poundsInt;
	float poundsFloat;
	int ouncesInt;
	float ouncesFloat;
	long ouncesLong;
	int choice = 0;
	float inputFloat = 0;
	printf("Enter a number from the menu (1-11) to select a specific conversion to perform or to quit: ");
	scanf("%i", &choice);
	while (1) {
		switch (choice) {
		case 1:
			printf("Enter Austin time to be converted, expressed in hours and minutes: ");
			scanf("%i %i", &inputHours, &inputMinutes);
			outputHours = (inputHours + 6) % 24;
			outputMinutes = inputMinutes;
<<<<<<< .mine
			strcpy(dayValue, "same");
||||||| .r8
			strcpy_s(dayValue, 10, "same");
=======
			strcpy(dayValue,  "same");
>>>>>>> .r11
			if ((inputHours + 6) > 23) {
				strcpy(dayValue, "next");
			}
			printf("The time in Ireland equivalent to %i %i in Austin is %i %i of the %s day \n", inputHours, inputMinutes, outputHours, outputMinutes, dayValue);
			break;
		case 2:
			printf("Enter Ireland time to be converted, expressed in hours and minutes: ");
			scanf("%i %i", &inputHours, &inputMinutes);
			strcpy(dayValue, "same");
			if (inputHours < 6) {
				inputHours = inputHours + 24;
				strcpy(dayValue,  "previous");
			}
			outputHours = (inputHours - 6);
			outputMinutes = inputMinutes;
			printf("The time in Austin equivalent to %i %i in Ireland is %i %i of the %s day \n", inputHours, inputMinutes, outputHours, outputMinutes, dayValue);
			break;
		case 3:
			printf("Enter USD value : ");
			scanf("%i %i", &inputDollars, &inputCents);
			inputFloat = USDTOEURO * (inputDollars + inputCents / 100);
			printf("EUR Value is %f Euros \n", inputFloat);
			break;
		case 4:
			printf("Enter EUR value : ");
			scanf("%f", &inputFloat);
			inputDollars = EUROTOUSD * inputFloat;
			inputCents = (EUROTOUSD * inputFloat - inputDollars) * 100;
			printf("USD Value is $ %i.%i \n", inputDollars, inputCents);
			break;
		case 5:
			printf("Enter temperature in Fahrenheit : ");
			scanf("%i", &inputInt);
			inputFloat = (5.0 / 9)*(inputInt - 32);
			printf("Temperature in Celsius is: %f degrees C \n", inputFloat);
			break;
		case 6:
			printf("Enter temperature in Celsius : ");
			scanf("%f", &inputFloat);
			inputInt = round((9.0 / 5)*inputFloat + 32);
			printf("Temperature in Fahrenheit: %i degrees F \n", inputInt);
			break;
		case 7:
			printf("Enter weight in kg: ");
			scanf("%f", &inputFloat);
			poundsInt = (1 / POUNDSTOGRAMSFACTOR)* inputFloat * 1000;
			poundsFloat = (1 / POUNDSTOGRAMSFACTOR)* inputFloat * 1000;
			ouncesInt = round((poundsFloat - poundsInt) * 16.0);
			printf("Weight in pounds and ounces is : %i lb %i oz \n", poundsInt, ouncesInt);
			break;
		case 8:
			printf("Enter weight in pounds and ounces: ");
			scanf("%i %i", &poundsInt, &ouncesInt);
			printf("Weight in kg is: %f kg \n", (poundsInt + ouncesInt / 16) * POUNDSTOGRAMSFACTOR / 1000);
			break;
		case 9:
			printf("Enter distance in km: ");
			scanf("%f", &inputFloat);
			printf("Distance in miles is: %f m \n", (MILESTOKMFACTOR)* inputFloat);
			break;
		case 10:
			printf("Enter distance in miles: ");
			scanf("%f", &inputFloat);
			printf("Distance in km is: %f km \n", (1 / MILESTOKMFACTOR) * inputFloat);
			break;
		case 11:
			printf("Good Bye \n");
			return 0;
			break;
		default:
			break;
		}
		printf("Enter a number from the menu (1-11) to select a specific conversion to perform or to quit: ");
		scanf("%i", &choice);
	}
}
