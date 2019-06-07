/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
/*	/* code */	//char f_Name[50];
//	char m_Name[50];
//	char l_Name[50];

	//int date_of_birth, month,day,year;
	//int Age;
	/*//// time_t is arithmetic time type*/
	//time_t now;
	//time(&now);
//	struct tm *local = localtime(&now);
//	day = local->tm_mday;
//	month = local->tm_mon;
//	year = local->tm_year+1900;

//	Age = year - date_of_birth;

//	printf("Enter Your firstName:\t");
//	scanf("%s",f_Name);

//	printf("Enter Your middleName:\t");
//	scanf("%s",m_Name);

//	printf("Enter Your lastName:\t");
//	scanf("%s",l_Name);

//	printf("Date Of Birth:\t");
//	scanf("%d",&date_of_birth);
//	printf("Year: %d\n",year );
//	printf("Age: %d\n",Age);
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// main function
int main(void)
{
	int hours, minutes, seconds, day, month, age,year,date_of_birth;

	char f_Name[50];
	char m_Name[50];
	char l_Name[50];


	printf("Enter Your firstName:\t");
	scanf("%s",f_Name);

	printf("Enter Your middleName:\t");
	scanf("%s",m_Name);

	printf("Enter Your lastName:\t");
	scanf("%s",l_Name);

	printf("Enter your Date of Birth\n");
	scanf("%d",&date_of_birth);
	// time_t is arithmetic time type
	time_t now;
	
	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// Convert to local time format and print to stdout
	printf("Today is : %s", ctime(&now));

	// localtime converts a time_t value to calendar time and returns a pointer
	// to a tm structure with its members filled with the corresponding values
	struct tm *local = localtime(&now);

	hours = local->tm_hour;			// get hours since midnight	(0-23)
	minutes = local->tm_min;		// get minutes passed after the hour (0-59)
	seconds = local->tm_sec;		// get seconds passed after the minute (0-59)

	day = local->tm_mday;			// get day of month (1 to 31)
	month = local->tm_mon + 1;		// get month of year (0 to 11)
	year = local->tm_year + 1900;	// get year since 1900

	age = year -date_of_birth;
	printf("Name: %s %s %s\n", f_Name,m_Name,l_Name);
	printf("Age: %d\n",age);
	// print local time
	if (hours < 12)	// before midday
		printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);
	else	// after midday
		printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);

	// print current date
	printf("Date is : %02d/%02d/%d\n", day, month, year);
	



	return 0;
}
