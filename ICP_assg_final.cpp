//COVID-19 DONATION MANAGEMENT SYSTEM
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h> // printf scanf int char cloat
#include<conio.h> // getch 
#include<stdio.h>
#include<string.h> //string
#define SIZE 1000 //print 1000 output 

struct typesofdonations
{
	char supplier_name[50];
	char supply_code[50];
	char donator[50];
	char donation_code[50];
	int no_shipment;
	float quantity;
}DNT[SIZE];

//function prototype
void inventory_distributed();//1
void show_the_current_distributed_donation(); //2
void inventory_received();//3
void search();//4
int menu();//5
void initial_message();//6
void printCenter(const char* info);//7
void headMessage(const char* info); //8

#include<stdbool.h>
//function for search donation 
void search()
{
	/*bool found = false;
	char* donation_code;
	struct typesofdonations KZH[5];
	FILE* fp;
	fp = fopen("donation.txt", "r");
	int i=0;
	if(fp == NULL)
	{
		printf("FILE FAIL TO OPEN\n");
		exit(1);
	}
	headMessage("\n\t\t SEARCH FOR DONATION ITEMS");
	printf("\n\t\t Donation code :");
	scanf("%s", &donation_code);
	
	while(KZH[i].donation_code)//DISPLAY TXT FILE
	{
		KZH[i].donation_code = donation_code;
		i++;
	}
	for(int i = 0; i < 5; i++) //5row
	{
	    if(strcmp(KZH[i].donation_code, donation_code)==0);
		{
			found = true;
			printf("%-25s\t%-15s\t%-13s\t%-15s\t%-17s\t%-15s\n", "Name of supply", "Supply code", "Donator", "Donation Code", "No. of Shipment", "Quantity Received (millions)",KZH[i].supplier_name, KZH[i].supply_code, KZH[i].donator, KZH[i].donation_code, KZH[i].no_shipment, KZH[i].quantity);
		}
	}
	if(!found)
	{
		printf("\n no record!\n");
	}
	printf("\n press q back to menu");
	fclose(fp);*/
}
	
//Align the message
void printCenter(const char* info) //function header
{
	int len = 0, pos = 0;
	//calculate how many space need to print
	len = (78 - strlen(info)) / 2;
	printf("\t\t\t");
	for (pos = 0; pos < len; pos++)
	{
		//print space
		printf(" ");
	}
	//print message
	printf("%s", info);
}


//Head message
void headMessage(const char* info)
{
	system("cls");
	printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t ~~#########    WELCOME TO COVID-19 DONATION MANAGEMENT SYSTEM 	##########~~\n");
	printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\t\t\t---------------------------------------------------------------------\n");
	printCenter(info);
	printf("\n\t\t\t-----------------------------------------------------------------------");

}
#define DATA_SIZE 1000
void inventory_creation()
{
	struct donation *records;
	int ctr, times;
	FILE* fp; //Declare fp as file pointer
	fp = fopen("donation.txt", "w");
	if(fp==NULL)
	{
		printf("Could not create file");
		exit(1);
	}
	else
	{
		printf("\n How many donations you wish to create?:");
		scanf("%d", &times);

		records = (donation*)calloc(times, sizeof(donation));

		for (ctr = 0; ctr < times; ctr++)
		{
			
			printf("\n What is the donation code?:");
			scanf("%d", &records[ctr].donation_code); while (getchar() != '\n');
			printf("\n What is the name of the supply?:");
			gets(records[ctr].supply_name); while (getchar() != '\n');
			printf("\n What is the supply code?:");
			gets(records[ctr].supply_code); while (getchar() != '\n');
			printf("\n Where is the donator from?:");
			gets(records[ctr].donator); while (getchar() != '\n');
			printf("\n What is the number of shipment of this item?:");
			scanf("%d", &records[ctr].no_of_shipment); while (getchar() != '\n');
			printf("\n What is the quantity of the item that you received?:");
			scanf("%f", &records[ctr].quantity); while (getchar() != '\n');
			fwrite(&records[ctr], sizeof(donation), 1, fp); //writes into file
		}
		printf("\nDonation Records have been added!");
	}
	fclose(fp);
}

struct typesofdonations KZH[5] //inventory creation
{//KZH used for store all the data to txt file //6 is for store 6 type of data
	{"Contactless Thermometer", "CT", "Japan", "JP",1, 1.2},
    {"Hand Sanitizers","HS", "USA", "AM",1, 3.5},
    {"Face Mask","FM", "China", "FCH",2, 120},
    {"Surgical Mask", "SM", "China", "SCH",2, 38},
    {"Oxygen Mask", "OM", "Saudi Arabia", "SA",2, 9}
};

void initial_message()
{
	FILE *f = fopen("donation.txt","w");
    // If there is no donation.txt in the file, it will give the signal
    if(f == NULL)
    {
        printf("Error! file cannot be open!");
        exit(0);
    }
    // once the donation.txt is exist, the program will store the data that are required into the donation.txt and dist.txt respectively
    fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17s\t%-15s\n", "Name of supply", "Supply code", "Donator", "Donation Code", "No. of Shipment", "Quantity Received (millions)");
    for(int i = 0; i < 6; i++)
    {
        fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17d\t%-15.2f\n", KZH[i].supplier_name, KZH[i].supply_code, KZH[i].donator, KZH[i].donation_code, KZH[i].no_shipment, KZH[i].quantity);
    }
    
    fclose(f);
}
//function to show all the distributed donation
void show_the_current_distributed_donation()
{
	FILE* u;
	u = fopen("dist.txt", "r");
	int con, ch;
	if(u == NULL)
	{
		printf("FILE FAIL TO OPEN\n");
		exit(1);
	}
	headMessage("\t\t\t SHOW CURRENT DISTRIBUTED DONATION ITEMS\n");
	do
	{																								
		int option;	
		float option2;
		printf("\n PRESS 1 to show all distributed items\n");											
	    scanf("%d", &option);									
	    while(option > 1) 						
	    {
	        printf("Invalid input!. Please re-enter again\n");
	        scanf("%d", &option);
	    }
	    option--;
	    printf("show all\n");
		while (1) //display file contents
		{
		ch = fgetc(u);
		if (ch == EOF)
		{
			break;
		}
		printf("%c", ch);
		}
	    printf("press q and back to menu if continue press Y ....\n ");
	    scanf("%f", &option2);								
		con = getchar(); while (getchar() != '\n');
		if (con == 'y' || con == 'Y') //write the data into the file
			fputc('\n', u); //writing in the file using fputs
	} while (con == 'y' || con == 'Y');
	fclose(u);
}

//function to update new donation into the inventory
void inventory_received()
{
	FILE* fp; //DECLARE FILE POINTER
	int con; //get the data to be written in file
	fp = fopen("dist.txt", "w"); //OPEN EXISTING file open in write mode
	if (fp == NULL) // Check if this filePointer is null which maybe if the file does not exist
	{
		printf("FILE FAIL TO OPEN\n");
		exit(1);
	}
	
	headMessage("\n\t\t ADD NEW DONATION QUANTITY\n");
	do
	{	
																									
		int option;	
		float option2;
		printf("\n\t\t Select the item you want receive\n");											
	    printf("\t\t\t1. Contactless Thermometer\n");				
	    printf("\t\t\t 2. Hand Sanitizers\n");
	    printf("\t\t\t 3. Face Mask\n");
	    printf("\t\t\t 4. Surgical Mask\n");
	    printf("\t\t\t 5. Oxygen Mask\n");
	    printf("\t\t\t Select >> ");
	    scanf("%d", &option);									
	    while((option < 1) || (option > 5))						
	    {
	        printf("\t\t\t Invalid input!. Please re-enter again\n");
	        	printf("\t\t\t Select the item you want receive\n");
	            printf("\t\t\t 1. Contactless Thermometer\n");
			    printf("\t\t\t 2. Hand Sanitizers\n");
			    printf("\t\t\t 3. Face Mask\n");
			    printf("\t\t\t 4. Surgical Mask\n");
			    printf("\t\t\t 5. Oxygen Mask\n");
				printf("\t\t\t Select >> ");
	        scanf("%d", &option);
	    }
	    option--;   						
	    printf("\n\t\t how many would you like to receive?\n");				
	    printf("\n\t\t Enter: ");
	    scanf("%f", &option2);								
	    ((KZH + option)->quantity) += option2;
		FILE *f = fopen("donation.txt","w");
		fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17s\t%-15s\n", "Name of supply", "Supply code", "Donator", "Donation Code", "No. of Shipment", "Quantity Received (millions)");
	    for(int i = 0; i < 5; i++) //5row
	    {
	        fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17d\t%-15.2f\n", KZH[i].supplier_name, KZH[i].supply_code, KZH[i].donator, KZH[i].donation_code, KZH[i].no_shipment, KZH[i].quantity);
	    }				
	    printf("Adding successful! The balance is %.2f\n", (KZH + option)->quantity);
		fclose(f);  // 
		fflush(stdin);
		printf("\n\t\t Another record?(Y/N):");
		con = getchar(); while (getchar() != '\n');
		if (con == 'y' || con == 'Y') //write the data into the file
			fputc('\n', fp); //writing in the file using fputs
	} while (con == 'y' || con == 'Y');
	fclose(fp); //CLOSE THE FILE USING FCLOSE
}

//function to distribute donation 
void inventory_distributed()
{
	FILE* fp; //DECLARE FILE POINTER
	int con; //get the data to be written in file
	fp = fopen("donation.txt", "w"); //OPEN EXISTING file open in write mode
	char hospital;
	if (fp == NULL) // Check if this filePointer is null which maybe if the file does not exist
	{
		printf("FILE FAIL TO OPEN\n");
		exit(1);
	}
	
	headMessage("\n\t\t DISTRIBUTE NEW DONATION QUANTITY");
	do
	{																								
		int option;	
		float option2;
		printf("\n\t\t Select the item you want distribute\n");											
	    printf("\t\t\t 1. Contactless Thermometer\n");				
	    printf("\t\t\t 2. Hand Sanitizers\n");
	    printf("\t\t\t 3. Face Mask\n");
	    printf("\t\t\t 4. Surgical Mask\n");
	    printf("\t\t\t 5. Oxygen Mask\n");
	    printf("\t\t\t Select >> ");
	    scanf("%d", &option);									
	    while((option < 1) || (option > 5))						
	    {
	        printf("\n\t\t Invalid input!. Please re-enter again\n");
	        	printf("\t\t\t Select the item you want distribute\n");
	            printf("\t\t\t 1. Contactless Thermometer\n");
			    printf("\t\t\t 2. Hand Sanitizers\n");
			    printf("\t\t\t 3. Face Mask\n");
			    printf("\t\t\t 4. Surgical Mask\n");
			    printf("\t\t\t 5. Oxygen Mask\n");
				printf("\t\t\t Select >> ");
	        scanf("%d", &option);
	    }
	    option--;   						
	    printf("\n\t\t how many would you like to distribute?\n");				
	    printf("\n\t\t Enter: ");
	    scanf("%f", &option2);
		printf("\n\t\t Hospital Name: ");
		scanf("%s", &hospital);							
	    ((KZH + option)->quantity) -= option2;
		FILE *f = fopen("dist.txt","w");
		fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17s\t%-15s\n", "Name of supply", "Supply code", "Donator", "Donation Code", "No. of Shipment", "Quantity Received (millions)");
	    for(int i = 0; i < 5; i++) //5row
	    {
	        fprintf(f, "%-25s\t%-15s\t%-13s\t%-15s\t%-17d\t%-15.2f\n", KZH[i].supplier_name, KZH[i].supply_code, KZH[i].donator, KZH[i].donation_code, KZH[i].no_shipment, KZH[i].quantity);
	    }					
	    printf("\n\t\t Adding successful! The balance is %.2f\n", (KZH + option)->quantity);
		fclose(f);
		fflush(stdin); // used to clear the buffer and accept the next string
		printf("\n\t\t Another record?(Y/N):");
		con = getchar(); while (getchar() != '\n');
		if (con == 'y' || con == 'Y') //write the data into the file
			fputc('\n', fp); //writing in the file using fputs
	} while (con == 'y' || con == 'Y');

	fclose(fp); //CLOSE THE FILE USING FCLOSE
	//show_the_current_distributed_donation();
}

//main menu function
int main()
{
	int selection = 0;
	initial_message();
	do
	{
		system("cls");
		printf("\n\t\t\t\t MENU\n\t\t\t\t ");
		printf("\n\t\t 1. Inventory creation"); 
		printf("\n\t\t 2. Distribute donation quantities"); //no. 4 show all
		printf("\n\t\t 3. Receive new donation inventory");  
		printf("\n\t\t 4. search");
		printf("\n\t\t 5. Show all distribute donations and the accumulate qualities");
		printf("\n\t\t 0. Log OUt!");
		printf("\n\t\t Enter your option from the list above: ");
		scanf("%d", &selection); while (getchar() != '\n');
		switch (selection)
		{

		case 1:
		{
			inventory_creation();
			break;
		}
		case 2:
		{
			inventory_distributed();
			break;
		}
		case 3:
		{
			inventory_received();
			break;
		}
		case 4:
		{
			search();
			break;
		}
		case 5:
		{
			show_the_current_distributed_donation();
			break;
		}
		case 0:
		{
			printf("\n\n\n\t\t\t\t BYE BYE Log Out! \n\n\n\n\n");
			break;
		}
		default:
		{
			printf("\n\n\n\t\t\t\t INVALID SELECTION! Please Try again: \n\n\n\n\n ");
		}
		}
	} while (selection != 6);
	_getch();
}

