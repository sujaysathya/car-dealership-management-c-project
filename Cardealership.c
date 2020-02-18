#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
typedef struct 
{
	int serial;
	char name[50];
	int seats;
	int airbags;
	char gps;
	char parkingsensor;
	char transmission;
	char colour[20];
	char drivetype;		//FWD/RWD
	double price;
	double rentpermonth;
	float mileage;
	char pollutionrating;
}car;

typedef struct
{
	int m;
	int d;
	int y;
}date;


typedef struct
{
	char nameofcustomer[50];
	char nameofcar[50];
	double phno;
	double  aadharno;
	char address[200];
	char creditrating;
	date purchase_date;
    char insurance;
    double amountpaid;
    int BorR; 
}customers;

void insurance(customers d);
int caremp(char carname[20]);
int cardetails(char nameofcust[20]);
void rent();
int dayscalc(int *d, int *m, int *y);
int check(char name[20]);
int servicecost(char cname[20]);
void buydate(int *d,int *m,int *y,char name[20]);
void service();
int emp(int seats,int airbags,char gps,char parkingsensor,char transmission,char drivetype,float mileage,char pollutionrating);
void buy();
void cusdata();
void cardata();



int caremp(char carname[20])
{
	FILE *j;
	int empv=0,flag =0;
	car temp;
	j = fopen("cardata.dat","rb+");
	while(!feof(j)&&(flag==0))
	{
		fread(&temp,sizeof(temp),1,j);
		if(strcmp(carname,temp.name)==0)
		{
			empv = emp(temp.seats,temp.airbags,temp.gps,temp.parkingsensor,temp.transmission,temp.drivetype,temp.mileage,temp.pollutionrating);
			flag = 1;
			printf("\n The car bought/rented earlier: %s \n\n\n",temp.name);
		}
	}
	fclose(j);
	return empv;
}
int cardetails(char nameofcust[20])
{ 
	int empvalue=0,flag =0;
	FILE *p;
	customers temp;
	p = fopen("customer.dat","rb+");
	while((!feof(p))&&(flag==0))
	{
		fread(&temp,sizeof(temp),1,p);
		if(strcmp(nameofcust,temp.nameofcustomer)==0)
		{
			empvalue = caremp(temp.nameofcar);
			flag = 1;
		}
	}
	fclose(p);
	return empvalue;
}

void rent()
{   
	printf("\033[1;32m");
	FILE *fp;
	fp = fopen("cardata.dat","rb+");
	FILE *fp1;
    customers t;
    fp1 = fopen("customer.dat","a+b");
    float mile;
    int re,se,air;
    char gps,par,pol,trans,drive;

    printf("Enter no of seats\n");
    scanf("%d", &re);
    printf("Enter no of airbags?\n");
    scanf("%d", &air);
    printf("Require gps?(y/n)\n");
    scanf(" %c", &gps);
    printf("Rquire parking sensor?(y,n)\n");
    scanf(" %c", &par);
    printf("Manual or automatic transmition mode?(m/a)\n");
    scanf(" %c", &trans);
    printf("Drive type(d,r,a)\n");
    scanf(" %c", &drive);
    printf("Mileage required\n");
    scanf("%f", &mile);
    printf("Required polution rating(a,b,c,d)\n");
    scanf(" %c", &pol);
    int co;
    co = emp(re,air,gps,par,trans,drive,mile,pol);
    car e[20];
    int i,rating;
    for(i=0;i<20;i++)
    {	
		fread(&e[i],sizeof(e[i]),1,fp);
    	rating=emp(e[i].seats,e[i].airbags,e[i].gps,e[i].parkingsensor,e[i].transmission,e[i].drivetype,e[i].mileage,e[i].pollutionrating);
    	if(co>rating-5 && co<rating+5)
    	{	
			printf("\nSerial no: %d\nCar name :%s",e[i].serial,e[i].name);
     		printf("\nRent per month is %.2lf",e[i].rentpermonth);    
	     	printf("\nNumber of seats: %d",e[i].seats);
	        printf("\nNumer of air bags: %d",e[i].airbags);
		    printf("\nGPS: %c",e[i].gps);
		    printf("\nParking Sensor: %c",e[i].parkingsensor);
		    printf("\nTransmission: %c",e[i].transmission);
		    printf("\nColour: %s",e[i].colour);
		    printf("\nDrivetype: %c",e[i].drivetype);
		    printf("\nMileage: %.1f",e[i].mileage);
		    printf("\nPollution Rating: %c\n\n",e[i].pollutionrating);
        }    
    }
    car d;
    int rental;
    printf("\nEnter the serial number of car to be rented: ");
    scanf("%d", &rental);
    fseek(fp,(rental-1)*sizeof(d),SEEK_SET);
    fread(&d,sizeof(d),1,fp);
    printf("\nName of car rented is:%s \n", d.name);
    printf("\nRent per month is %.2lf\n",d.rentpermonth);
    char insuran;
    printf("\nDo you want insurance(y/n): ");
    scanf(" %c", &insuran);
    printf("\nEnter credit rating(a,b,c,d): ");
    scanf(" %c",&t.creditrating);

    t.amountpaid = d.rentpermonth;
    if(insuran=='y')
    {
		insurance(t);
		t.insurance='y';
    }


    printf("\nEnter customer details: \n");
    printf("\nEnter name : ");
    scanf(" %[^\n]",t.nameofcustomer);
    printf("\n Enter phone number: ");
    scanf("%lf",&t.phno);
    printf("\nEnter aadharno");
    scanf("%lf",&t.aadharno);
    printf("\nEnter address: ");
    scanf(" %[^\n]",t.address);
    
    strcpy(t.nameofcar,d.name);
	date today;
	t.BorR = 0;
	printf("\nEnter date when rented(DD MM YYYY): ");
	scanf("%d %d %d",&today.d,&today.m,&today.y);
	t.purchase_date = today;
    fwrite(&t,1,sizeof(t),fp1);
    fclose(fp1);
    fclose(fp);
 	printf("\033[0m");
}
  
void insurance(customers d)
{
	double base;
	double final;
	base=d.amountpaid/50;
	if(d.creditrating=='a')
		final=base;
	else if(d.creditrating=='b')
		final=base*1.05;
	else if(d.creditrating=='c')
		final=base*1.10;
	else if(d.creditrating=='d')
		final=base*1.15;
	printf("\n\nAmount of money paid for insurance is %.3lf\n",final);
}

int dayscalc(int *d, int *m, int *y)
{
	
	int bd=1, bm=1, base=1900, nd, nl, nfour;		
	//To calculate the no of Days between Jan 01 1900 and the given date
	
	
	nfour=(*y-base)/4;				//Number of 4 year cycles
	
	
	nl=(*y-base)%4;				//Remaining years

	
	nd = nfour * 1461;			//The no of Days included from 1900 till the last 4th year cycle
	
	
	if(nl>0)						//Calculating remaining number of Days in the leftover years
		nd += 365 * nl + 1;
	
	//no of Days in the current year
	nd += (long)(30.42 * (*m-1)) + *d; //approximate formula
	
	if(*m==2) 						//february adjustment
		nd+=1;
	if(*m>2&&*m<8) 				//march to july adjustment
		nd-=1; 
	if(*m>2&&((*y-base)%4==0)) 		//leap year, february has passed
		nd+=1;  
	
	if(nd>59) 
		nd-=1;				//When the date is lesser than Feb 28 1900 as 1900 wasn't a leap year .
	
	return nd;
}

int check(char name[20])
{
	FILE *m;
	customers temp;
	m = fopen("customer.dat","rb+");
	while(!feof(m))
	{
		fread(&temp,sizeof(temp),1,m);
		if(strcmp(name,temp.nameofcustomer)==0)
			return 1;
	}
	fclose(m);
	return 0;
}

int servicecost(char cname[20])
{
	FILE *l;
	car temp;
	l = fopen("cardata.dat","rb+");
	while(!feof(l))
	{
		fread(&temp,sizeof(temp),1,l);
		if(strcmp(cname,temp.name)==0)
		{
			return (temp.price/100)*3;
		}
	}
	printf("\nWe do not service this car model\n");
	fclose(l);
	return 0;
}
void buydate(int *d,int *m,int *y,char name[50])
{
	FILE *z;
	int flag = 0;
	customers temp;
	z = fopen("customer.dat","rb+");
	while(!feof(z)&&(flag==0))
	{
		fread(&temp,sizeof(temp),1,z);
		if(strcmp(name,temp.nameofcustomer)==0)
		{
			*d = (int)temp.purchase_date.d;
			*m = (int)temp.purchase_date.m;
			*y = (int)temp.purchase_date.y;
			flag = 1;
			printf("\nBought/rented date:%d %d %d \n",temp.purchase_date.d,temp.purchase_date.m,temp.purchase_date.y);
		}
	}
	if(flag ==0)
	{
		printf("\nThe Customer record was not found");
	}
	fclose(z);
	return ;

}
void service()
{	
	printf("\033[1;33m");
	char opt,cn[20],yn[50];
	int M1,D1,Y1,M2,D2,Y2,Days=0;
	customers temp;
	printf("Enter the car name: ");
	scanf(" %[^\n]",cn);
	printf("\nEnter your name: ");
	scanf(" %[^\n]",yn);
	int amountdue;
	if(amountdue=servicecost(cn))
	{
		if(check(yn))
		{
			
			buydate(&D1,&M1,&Y1,yn);
			D2 = 24;
			M2 = 4;
			Y2 = 2019;
			Days=dayscalc(&D1,&M1,&Y1)-dayscalc(&D2,&M2,&Y2);				
			printf("\nThe no. of Days between the two given dates is: %d\n", (-Days));	
			if((-Days)<365)
				printf("\nFree service!!\n");
			else
				printf("\nOne year free service offer has run out!\n\nAmount due= %d\n",amountdue);
		}
		else
			printf("\nThe customer did not buy/rent the car here\nSo no discount\nAmount due = %d\n",amountdue);
	}
	printf("\033[0m");
	return;
}

int emp(int seats,int airbags,char gps,char parkingsensor,char transmission,char drivetype,float mileage,char pollutionrating)
{
	int points=0;

	if(seats==4)
		points+=0;
	else
		points+=2;

	if(airbags==0)
		points+=0;
	else if(airbags==2)
		points+=2;
	else
		points+=5;

	if(gps=='y')
		points+=2;
	else
		points+=0;

	if(parkingsensor=='y')
		points+=2;
	else
		points+=0;

	if(transmission=='a')
		points+=2;	
	else
		points+=0;

	if(drivetype=='a')
		points+=5;
	else
		points+=0;
	if(mileage>15)
		points+=5;
	else
		points+=0;
	
	if(pollutionrating=='a')
		points+=5;
	if(pollutionrating=='b')
		points+=4;
	if(pollutionrating=='c')
		points+=3;
	if(pollutionrating=='d')
		points+=2;
	
	return(points);
}

void buy()
{
	printf("\033[1;31m");	
	int val;
	char opt;
	char nam[30];
	customers t;
	printf("\nHave you bought a car before ?(Y/N)");
	scanf(" %c",&opt);
	if(opt=='Y')
	{
		printf("\nEnter your name:");
		scanf(" %[^\n]",nam);
		val = cardetails(nam);//gets the emp value of the car bought by the customer
		if(val==0)
			printf("\nCustomer Record not found");
		else
		{
			printf("\nRecommended Cars based on your previous purchase:\n");
			FILE *fp3;
			fp3 = fopen("cardata.dat","rb+");
			FILE *fp4;
		   	fp4 = fopen("customer.dat","a+b");
		   	int buyy;
		   	car d;
			car e[20];
	    	int i,rating;
	    	for(i=0;i<20;i++)
	    	{	
				fread(&e[i],sizeof(e[i]),1,fp3);
	    		rating=emp(e[i].seats,e[i].airbags,e[i].gps,e[i].parkingsensor,e[i].transmission,e[i].drivetype,e[i].mileage,e[i].pollutionrating);
	    		if(val>rating-5 && val<rating+5)
	    		{	
	     			printf("\n\nSerial no:%d\nCar name :%s",e[i].serial,e[i].name);
	     			printf("\nCar price is :%.2lf \n",e[i].price);   
	     			printf("\nNumber of seats: %d",e[i].seats);
	            	printf("\nNumer of air bags: %d",e[i].airbags);
		       	    printf("\nGPS: %c",e[i].gps);
		            printf("\nParking Sensor: %c",e[i].parkingsensor);
		            printf("\nTransmission: %c",e[i].transmission);
		            printf("\nColour: %s",e[i].colour);
		            printf("\nDrivetype: %c",e[i].drivetype);
		            printf("\nMileage: %.1f",e[i].mileage);
		            printf("\nPollution Rating: %c\n\n",e[i].pollutionrating);
  
	     	    }    
	   		}
	   	

		    printf("\nEnter the serial number of car to be purchased: ");
		    scanf("%d", &buyy);
		    fseek(fp3,(buyy-1)*sizeof(d),SEEK_SET);
		    fread(&d,sizeof(d),1,fp3);
		    printf("\nName of car purchased is %s\n\nAmount to be paid:%lf \n", d.name,d.price);
		    char insuran;


		    printf("\nDo you want insurance(y/n): ");
		    scanf(" %c", &insuran);
		    printf("\nEnter credit rating(a,b,c,d):");
		    scanf(" %c",&t.creditrating);
		    t.amountpaid=d.price;
		    if(insuran=='y')
		    {
				insurance(t);
				t.insurance='y';
		    }
		    t.BorR = 1;
		    strcpy(t.nameofcar,d.name);
		    printf("\nCreating new record the customer");
		    printf("\nEnter customer details:-\n");
		    printf("\nEnter name:");
		    scanf(" %[^\n]",t.nameofcustomer);
		    printf("\n Enter phone number:");
		    scanf("%lf",&t.phno);
		    printf("\nEnter aadharno:");
		    scanf("%lf",&t.aadharno);
		    printf("\nEnter address:");
		    scanf(" %[^\n]",t.address);
		   
		    
		    date today;
		    printf("\nEnter date of purchase(DD MM YYYY): ");
		    scanf("%d %d %d",&today.d,&today.m,&today.y);
		    t.purchase_date = today;
		    fwrite(&t,1,sizeof(t),fp4);
		    fclose(fp4);
		    fclose(fp3);
		    printf("\nCar purchased successfully!\n");
		}
	}
	else if(opt=='N')
	{
		FILE *fp8;
		fp8 = fopen("cardata.dat","rb+");
	    float mile;
	    int se,re,air;
	    char gps,par,pol,trans,drive;
	    printf("\nEnter your preferences:-\n");
	    printf("\nNo. of seats?: ");
	    scanf("%d", &re);
	    printf("\nNo. of airbags required?: ");
	    scanf("%d", &air);
	    printf("\nRequire gps?(y/n): ");
	    scanf(" %c", &gps);
	    printf("\nRequire parking sensor?(y,n): ");
	    scanf(" %c", &par);
	    printf("\nManual or automatic transmission mode?(m/a): ");
	    scanf(" %c", &trans);
	    printf("\nWhich Drive type?(d,r,a): ");
	    scanf(" %c", &drive);
	    printf("\nHow much Mileage required?: ");
	    scanf("%f", &mile);
	    printf("\nRequired polution rating?(a,b,c,d): ");
	    scanf(" %c", &pol);

	    int co;
	    co = emp(re,air,gps,par,trans,drive,mile,pol);
	    car e[20];
	    int i,rating,flag = 0;
	    printf("\nChecking data base for appropriate cars: ");
	    for(i=0;i<20;i++)
	    {	
			fread(&e[i],sizeof(e[i]),1,fp8);
	    	rating=emp(e[i].seats,e[i].airbags,e[i].gps,e[i].parkingsensor,e[i].transmission,e[i].drivetype,e[i].mileage,e[i].pollutionrating);
	    	if(co>rating-5 && co<rating+5)
	    	{	
				printf("\n\nSerial no:%d\nCar name :%s",e[i].serial,e[i].name);
	     		printf("\nCar price is :%.2lf \n",e[i].price);   
	     		printf("\nNumber of seats: %d",e[i].seats);
	            printf("\nNumer of air bags: %d",e[i].airbags);
		       	 printf("\nGPS: %c",e[i].gps);
		         printf("\nParking Sensor: %c",e[i].parkingsensor);
		         printf("\nTransmission: %c",e[i].transmission);
		         printf("\nColour: %s",e[i].colour);
		         printf("\nDrivetype: %c",e[i].drivetype);
		         printf("\nMileage: %.1f",e[i].mileage);
		         printf("\nPollution Rating: %c\n\n",e[i].pollutionrating);
	     		flag = 1;
	       	}     
	    }
	    fclose(fp8);
	    if(flag==0)
	    {
	    	printf("\nNo cars with similar parameters were found\n");
	    }
	    else
	    {
	    	FILE *fp7;
		    fp7 = fopen("customer.dat","a+b");
		    FILE *fp6;
		    fp6 = fopen("cardata.dat","rb+");
		    car d;
		    int buyy;

		    printf("\nEnter the serial number of car to be purchased: ");
		    scanf("%d", &buyy);
		    fseek(fp6,(buyy-1)*sizeof(d),SEEK_SET);
		    fread(&d,sizeof(d),1,fp6);
		    printf("Name of car purchased is : %s\nAmount to be paid:%lf \n", d.name,d.price);
		    char insuran;
		    printf("\nDo you want insurance(y/n): ");
		    scanf(" %c", &insuran);
		    printf("\nEnter credit rating(a,b,c,d): ");
		    scanf(" %c",&t.creditrating);
		    t.amountpaid=d.price;
		    if(insuran=='y')
		    {
				insurance(t);
				t.insurance='y';
		    }
		    t.BorR = 1;

		    printf("\nEnter customer details:\n");
		    printf("\nEnter name :");
		    scanf(" %[^\n]",t.nameofcustomer);
		    printf("\n Enter phone number:");
		    scanf("%lf",&t.phno);
		    printf("\nEnter aadharno");
		    scanf("%lf",&t.aadharno);
		    printf("\nEnter address:");
		    scanf(" %[^\n]",t.address);
		   		   
		    
		    strcpy(t.nameofcar,d.name);
			date today;
			printf("\nEnter the date of purchase(DD MM YYYY): ");
			scanf("%d %d %d",&today.d,&today.m,&today.y);
			t.purchase_date = today;
		    fwrite(&t,sizeof(t),1,fp7);
		    fclose(fp7);
		    fclose(fp6);
		    printf("\nCar purchased successfully!\n");
	    }
	  
	}
	else 
		printf("\nInvalid input");
	printf("\033[0m");
	return;
}
void cusdata()
{	
	 printf("\033[1;34m");
	 int ch;
	 char pwd[50];   
	 printf("\nEnter the password please!:");
	 scanf(" %[^\n]",pwd);
	 if(strcmp(pwd,"password")==0)
	 {
	   printf("\nWelcome to Customer Data Base");
	   FILE *u;
	   u = fopen("customer.dat","rb+");
	   customers temp;
	   if(u==NULL)
	   {
	   	printf("\nError while opening the file\n");
	   }
	   else
	   {
	   		fread(&temp,sizeof(temp),1,u);
	   		do
			{
		       printf("\n\nName of the customer is: %s",temp.nameofcustomer);
		       printf("\nPhone Number: %.0lf",temp.phno);
		       printf("\nAadhar number: %.0lf",temp.aadharno);
		       printf("\nAddress: %s", temp.address);
		       printf("\nCredit rating: %c ", temp.creditrating);
		       printf("\nName of the car is: %s ",temp.nameofcar);
		       ch=temp.BorR;
		       if(ch==1)
		       {
		           printf("\nCar was bought.");
		           printf("\nAmount paid: %.2lf",temp.amountpaid);
		           printf("\nDate at which car was bought:");
		           printf(" %d  %d  %d",temp.purchase_date.d,temp.purchase_date.m,temp.purchase_date.y);
		       }
		       else if(ch==0)
		       {
		           printf("\nCar is rented");
		           printf("\nAmount paid: %.2lf",temp.amountpaid);
		           printf("\nDate at which car was rented:");
		           printf(" %0d  %0d  %d",temp.purchase_date.d,temp.purchase_date.m,temp.purchase_date.y);
		       }
		       if(temp.insurance=='y')
		       	printf("\nCar has insurance\n\n");
		       else 
		       	printf("\nCar does not have insurance\n\n");

		       fread(&temp,sizeof(temp),1,u);
		    }while(!feof(u));
	   }
	  
	    fclose(u);
 	}
 	else
	{
  		printf("\nAccess Denied!!");
	}
	printf("\033[0m");
} 
       


void cardata()
{
	 char pwd[50],ch;
	 printf("\033[1;35m");
	 printf("\nEnter the password please! :");
	 scanf(" %[^\n]",pwd);
	 if(strcmp(pwd,"password")==0) 
	 {
	     printf("\nWelcome to the Car Data Base\nCars available:\n");
	     car temp,c;
	     int n,i;
	     FILE *f;
		 f=fopen("cardata.dat","rb+");
		 fread(&temp,sizeof(temp),1,f);
	     while(!feof(f))
	     {	         
	         printf("\n\nSerial number: %d",temp.serial);
	         printf("\nCar name: %s",temp.name);
	         printf("\nNumber of seats: %d",temp.seats);
	         printf("\nNumer of air bags: %d",temp.airbags);
	         printf("\nGPS: %c",temp.gps);
	         printf("\nParking Sensor: %c",temp.parkingsensor);
	         printf("\nTransmission: %c",temp.transmission);
	         printf("\nColour: %s",temp.colour);
	         printf("\nDrivetype: %c",temp.drivetype);
	         printf("\nPrice of the car: %.2lf",temp.price);
	         printf("\nRent per month: %.2lf",temp.rentpermonth);
	         printf("\nMileage: %.1f",temp.mileage);
	         printf("\nPollution Rating: %c\n\n",temp.pollutionrating);
	         fread(&temp,sizeof(temp),1,f);
	     }
	     
	     printf("Do you want to add cars?(Y/N)");
	     scanf(" %c",&ch);
	     if(ch=='Y')
	     {
	     	printf("\nEnter number of cars to be added: ");
			scanf("%d",&n);
			printf("\nPlease Enter the details of the car(s)\n");
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
		        scanf(" %lf",&c.rentpermonth);
				printf("\nEnter mileage: ");
		        scanf(" %f",&c.mileage);
				printf("\nEnter pollution rating: ");
		        scanf(" %c",&c.pollutionrating);
		        fwrite(&c,1,sizeof(car),f);
		    }

	     }
	     fclose(f);
	 }
	 else
	 {
	     printf("\nAccess Denied!!");
	 }
	 printf("\033[0m");
} 

void main()
{
	int op;
	char jk[10];
	do
	{	/*getchar();*/
		system ("clear");
		printf("\n\n\n\n\t\t  CAR DEALERSHIP \n");
		printf("\t\t ----------------\n\n");
		printf("\033[1;31m");
		printf("\t 1. Buy a car\n");
		printf("\033[0m");	
		printf("\033[1;32m");
		printf("\t 2. Rent a car\n");
		printf("\033[0m");
		printf("\033[1;33m");
		printf("\t 3. Service a car\n");
		printf("\033[0m");
		printf("\033[1;34m");
		printf("\t 4. (ADMIN) Customer database\n");
		printf("\033[0m");
		printf("\033[1;35m");
		printf("\t 5. (ADMIN) Car database \n");
		printf("\033[0m");
		printf("\033[1;36m");
		printf("\t 6. Exit..\n");
		printf("\033[0m");
		printf("\t Enter your option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
					buy();
					printf("\n\n\nPress any key and ENTER to continue\n");
					scanf(" %[^\n]",jk);
					break;
			case 2:
					rent();
					printf("\n\n\nPress any key and ENTER to continue\n");
					scanf(" %[^\n]",jk);
					break;
			case 3:
					service();
					printf("\n\n\nPress any key and ENTER to continue\n");
					scanf(" %[^\n]",jk);
					break;
			case 4:
					cusdata();
					printf("\n\n\nPress any key and ENTER to continue\n");
					scanf(" %[^\n]",jk);
					break;
			case 5:
					cardata();
					printf("\n\n\nPress any key and ENTER to continue\n");
					scanf(" %[^\n]",jk);
					break;
			case 6:
					exit(0);
		}
	}while(op!=6);
}