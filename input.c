#include <stdio.h>

typedef struct
{
	int serial;
	char name[50];
	int seats;
	int airbags;
	char gps;// y or n
	char parkingsensor; // y or n 
	char transmission; // a-auto m-manual
	char colour[20];
	char drivetype[1]; // f-front r-rear a-all
	double price;
	float rentpermonth;
	float mileage;
	char pollutionrating;
}car;

void main()
{
	car c;
	FILE *f;
	int n,i;
	f=fopen("cardata.dat","wb");
	// number of cars
	printf("How many cars do you want to input ? ");
	scanf(" %d",&n);
    for(i=0;i<n;i++)
    {
		// writing cars
		printf("\nEnter serial no: ");
        scanf(" %d",&c.serial);
		printf("\nEnter name: ");
        scanf(" %[^\n]",c.name);
		printf("\nEnter seats: ");
		scanf(" %d",&c.seats);
		printf("\nEnter airbags ");
		scanf(" %d",&c.airbags);
		printf("\nEnter gps ");
        scanf(" %c",&c.gps);
		printf("\nEnter parking sensor: ");
        scanf(" %c",&c.parkingsensor);
		printf("\nEnter transmission: ");
        scanf(" %c",&c.transmission);
		printf("\nEnter colour: ");
        scanf(" %[^\n]",c.colour);
		printf("\nEnter drivetype: ");
        scanf(" %c",&c.drivetype);
		printf("\nEnter price: ");
        scanf(" %lf",&c.price);
		printf("\nEnter rent per month: ");
        scanf(" %f",&c.rentpermonth);
		printf("\nEnter mileage: ");
        scanf(" %f",&c.mileage);
		printf("\nEnter pollution rating: ");
        scanf(" %c",&c.pollutionrating);
        fwrite(&c,1,sizeof(car),f);
    }
}
	
/* DATA OF CARS:

How many cars do you want to input ? 20

Enter serial no: 1

Enter name: skoda octavia

Enter seats: 4

Enter airbags 4

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: black

Enter drivetype: r

Enter price: 1700000

Enter rent per month: 5000

Enter mileage: 12

Enter pollution rating: a

Enter serial no: 2

Enter name: skoda octavia rs

Enter seats: 4

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: silver

Enter drivetype: a

Enter price: 2000000

Enter rent per month: 6000

Enter mileage: 10

Enter pollution rating: a

Enter serial no: 3

Enter name: maruti suzuki swift

Enter seats: 4

Enter airbags 2

Enter gps y

Enter parking sensor: y

Enter transmission: m

Enter colour: red

Enter drivetype: f

Enter price: 550000

Enter rent per month: 2500

Enter mileage: 16

Enter pollution rating: b

Enter serial no: 4

Enter name: maruti suzuki ciaz

Enter seats: 4

Enter airbags 4

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: white

Enter drivetype: f

Enter price: 800000

Enter rent per month: 3000

Enter mileage: 13

Enter pollution rating: b

Enter serial no: 5

Enter name: maruti suzuki celerio

Enter seats: 4

Enter airbags 1

Enter gps y

Enter parking sensor: n

Enter transmission: m

Enter colour: orange

Enter drivetype: f

Enter price: 400000

Enter rent per month: 2000

Enter mileage: 17

Enter pollution rating: c

Enter serial no: 6

Enter name: hyundai i10

Enter seats: 4

Enter airbags 2

Enter gps y

Enter parking sensor: y

Enter transmission: m

Enter colour: yellow

Enter drivetype: f

Enter price: 550000

Enter rent per month: 2500

Enter mileage: 16

Enter pollution rating: b

Enter serial no: 7

Enter name: hyundai i20

Enter seats: 4

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: silver

Enter drivetype: f

Enter price: 750000

Enter rent per month:
2500

Enter mileage: 14

Enter pollution rating: a

Enter serial no: 8

Enter name: hyundai fluidic elantra

Enter seats: 4

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: blue

Enter drivetype: a

Enter price: 1950000

Enter rent per month: 6000

Enter mileage: 8

Enter pollution rating: a

Enter serial no: 9

Enter name: hyundai creta

Enter seats: 5

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: green

Enter drivetype: a

Enter price: 1100000

Enter rent per month: 4500

Enter mileage: 11

Enter pollution rating: a

Enter serial no: 10

Enter name: renault kwid

Enter seats: 4

Enter airbags 0

Enter gps n

Enter parking sensor: n

Enter transmission: m

Enter colour: black

Enter drivetype: f

Enter price: 300000

Enter rent per month: 1750

Enter mileage: 18

Enter pollution rating: c

Enter serial no: 11

Enter name: skoda kodiaq rs

Enter seats: 6

Enter airbags 8

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: silver

Enter drivetype: a

Enter price: 3500000

Enter rent per month: 12000

Enter mileage: 5

Enter pollution rating: a

Enter serial no: 12

Enter name: tata hexa

Enter seats: 8

Enter airbags 8

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: orange

Enter drivetype: a

Enter price: 2300000

Enter rent per month: 10000

Enter mileage: 8

Enter pollution rating: a

Enter serial no: 13

Enter name: ford endeavour

Enter seats: 8

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: purple

Enter drivetype: a

Enter price: 3000000

Enter rent per month: 11000

Enter mileage: 6

Enter pollution rating: a

Enter serial no: 14

Enter name: ford ecosport

Enter seats: 5

Enter airbags 4

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: orange

Enter drivetype: r

Enter price: 900000

Enter rent per month: 5500

Enter mileage: 11

Enter pollution rating: a

Enter serial no: 15

Enter name: tata nexon

Enter seats: 5

Enter airbags 4

Enter gps y

Enter parking sensor: y

Enter transmission: m

Enter colour: blue

Enter drivetype: f

Enter price: 800000

Enter rent per month: 5250

Enter mileage: 15

Enter pollution rating: a

Enter serial no: 16

Enter name: mahindra xuv 300

Enter seats: 4

Enter airbags 2

Enter gps y

Enter parking sensor: n

Enter transmission: m

Enter colour: red

Enter drivetype: f

Enter price: 400000

Enter rent per month: 3000

Enter mileage: 14

Enter pollution rating: c

Enter serial no: 17

Enter name: mahindra xuv 500

Enter seats: 8

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: white

Enter drivetype: a

Enter price: 2200000

Enter rent per month: 7500

Enter mileage: 9

Enter pollution rating: a

Enter serial no: 18

Enter name: volvo xc90

Enter seats: 8

Enter airbags 6

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: black

Enter drivetype: a

Enter price: 13100000

Enter rent per month: 52000

Enter mileage: 12

Enter pollution rating: a

Enter serial no: 19

Enter name: mercedes benz gls

Enter seats: 8

Enter airbags 9

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: 63amgblack

Enter drivetype: a

Enter price: 19200000

Enter rent per month: 79000

Enter mileage: 4

Enter pollution rating: a

Enter serial no: 20

Enter name: lamborghini urus

Enter seats: 5

Enter airbags 12

Enter gps y

Enter parking sensor: y

Enter transmission: a

Enter colour: green

Enter drivetype: a

Enter price: 31000000

Enter rent per month: 120000

Enter mileage: 2.5

Enter pollution rating: a

C:\Users\Srinath\Desktop>
*/