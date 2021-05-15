//Header files
#include<stdio.h>         // standard input output
#include<windows.h>      //gotoxy()
#include<conio.h>        //for delay(),getch().
#include<ctype.h>        //for toupper(),tolower().
#include<string.h>       //for strcmp(),strcpy(),strlen()
#include<stdlib.h>       //for output screen clear
char ans=0;
int ok;
int b, valid=0;
//Function Declaration
void starter_screen(void);   //welcomeScreen
void titlescreen(void);           //title function
void mainmenu(void);        //main menu function
void Login_section(void);     //log in screen function
void Add_record(void);         //add record function
void function_list();           //list of the patient details
void search_record(void);      //search record
void edit_record(void);        //edit record
void delete_record(void);         //remove record
void exit1(void);           //exit1 function
void gotoxy(short x, short y)
{
	COORD pos = {x, y};     //set the coordinates of x and y.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //setting the position of cursor.1 to show & 0 to hide.
}
//Global Variables

struct student
{
	int age;
	char gender;
	char first_name[20];  //array size
	char last_name[20];
	char contact[15];
	char address[30];
	char email[30];
	char stype[20];
	char Department[20];
};
struct student  s,temp_c;
void main(void)
{
	starter_screen();           //WelcomeScreen function
	titlescreen();                   //Title function
	Login_section();             //Menu function
}
/* ************************************************* Welcome Screen ********************************************* */
void starter_screen(void)//function for welcome screen
{
	printf("\n\n\n\n\n\n\n\t\t\t\t*****************************************");
	printf("\n\t\t\t\t\t\t WELCOME TO\t\t");
	printf("\n\t\t\t\t         FCRIT STUDENT RECORD SYSTEM          ");
	printf("\n\t\t\t\t*****************************************");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();
	system("cls");//Use to clear screen
}
/* ************************************************* Title Screen ********************************************* */
void titlescreen(void)//function for title screen
{
	printf("\n\n\t\t**********************************************************************************");
	printf("\n\t\t\t\t                   FCRIT STUDENT         ");
	printf("\n\t\t**********************************************************************************");
}
/* ************************************************* Main Menu ********************************************* */
void mainmenu(void)//function decleration
{
	system("cls");
	int command;
	titlescreen();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Students Record\n");
	printf("\n\t\t\t\t2. List Students Record\n");
	printf("\n\t\t\t\t3. Search Students Record\n");
	printf("\n\t\t\t\t4. Edit Students Record\n");
	printf("\n\t\t\t\t5. Delete Students Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%d", &command);
	switch(command)        //Add_rec function is called
	{
		case 1:
			Add_record();
    		break;
  		case 2:
	    	function_list();
	    	break;
		case 3:
			search_record();     //Search record function is called
		   	break;
		case 4:
			edit_record();        //Edit record function is called
			break;
		case 5:
			delete_record();      //Delete record function is called
			break;
		case 6:
			exit1();        //exit1 function is call
	    	break;
		default:
			printf("\t\t\tInvalid input. Please enter right option :");
			getch();
	}
}
/* ************************************************* exit1 Screen ********************************************* */
void exit1(void)//function to exit1
{
	system("cls");
	titlescreen();
	printf("\n\n\n\n\n\t\t\tTHANKS FOR VISITING :");
	getch();
}
/* ************************************************* Login Screen ********************************************* */
void Login_section(void)//function for logivoid n screen
{
	//list of variables
	int f=1	;
	char Username[15];
	char Password[15];
	char original_Username[25]="uiu";
	char original_Password[15]="201";
	do
	{
		printf("\n\n\n\n\t\t\t\tEnter your Username and Password :");
		printf("\n\n\n\t\t\t\t\tUSERNAME:");
		scanf("%s",&Username);
		printf("\n\n\t\t\t\t\tPASSWORD:");
		scanf("%s",&Password);
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t***Login Successful***");
			getch();
			mainmenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\t\aInvalid Password %d times. Try Again :",f);
			Sleep(2000);
			system("cls");
			f++;
			getch();
		}
	}while(f<=3);
	if(f>3)
	{
		printf("Limit exceeded . You can't login. :");
		getch();
	    exit1();
	}
	system("cls");  //screen clear function
}
/* **************************************ADD RECORD*******************************************/
void Add_record(void)
{
	system("cls");
	titlescreen();// call Title function
	//list of variables
	char ans;
	FILE*fp;//file pointer
	fp=fopen("main.txt","a");//open file in write mode
	printf("\n\n\t\t\t************** Add Student's Record *************\n");
	/* **************************First Name*********************************** */
	V:
	printf("\n\t\t\tFirst Name: ");
	fflush(stdin);
	gets(s.first_name);
	s.first_name[0]=toupper(s.first_name[0]);
	if(strlen(s.first_name)>20||strlen(s.first_name)<2)
	{
		printf("\n\t Not Valid :( \t Maximum limit for first name is 20 and minimum limit is 2 :)");
		goto V;
	}
	/* ******do
	**************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
	fflush(stdin);
    scanf("%s",s.last_name);
    s.last_name[0]=toupper(s.last_name[0]);
    if(strlen(s.last_name)>20||strlen(s.last_name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(s.last_name);b++)
		{
			if (isalpha(s.last_name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name character is invalid. Enter again :");
			goto B;
		}
	}
	/* ******************************************* Gender ************************************************************** */
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&s.gender);
		if(toupper(s.gender)=='M'|| toupper(s.gender)=='F')
		{
			ok =1;
		}
		else
		{do
			ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character. Enter either Female or Male :");
    	}
	}while(!ok);
	/* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge:");
    scanf(" %i",&s.age);
    /* **************************************** Address ******************************************************************* */
    do
    {
	    C:
	    printf("\n\t\t\tAddress: ");
	    scanf("%s",s.address);
	    s.address[0]=toupper(s.address[0]);
	    if(strlen(s.address)>40||strlen(s.address)<4)
		{
			printf("\n\t Invalid Address. \t Maximum limit for address is 40 and minimum limit is 4 :)");
			goto C;
		}
	}while(!valid);
	/* ******************************************* Contact no. ***************************************** */
	do
	{
	
	
		U:
	    printf("\n\t\t\tContact no: ");
	    scanf("%s",s.contact);
	    if(strlen(s.contact)>12||strlen(s.contact)!=11)
		{
			printf("\n\t Sorry. Contact number must contain 11 numbers. Enter again :");
			goto U;
		}
		else
		{
			for (b=0;b<strlen(s.contact);b++)
			{
				if (!isalpha(s.contact[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact number is Invalid character. Enter again :");
				goto U;
			}
		}
	}while(!valid);
	/* ************************************************** Email ******************************************** */
	do
	{
	    printf("\n\t\t\tEmail: ");
	    scanf("%s",s.email);
	    if (strlen(s.email)>30||strlen(s.email)<8)
	    {
	       printf("\n\t Invalid Input. \t Maximum limit for email is 30 and minimum limit is 8 :)");
		}
	}while(strlen(s.email)>30||strlen(s.email)<8);
	/* ********************************************************* Problem *********************************************** */
	E:
	printf("\n\t\t\tDepartment: ");
	scanf("%s",s.Department);
	s.Department[0]=toupper(s.Department[0]);
	if(strlen(s.Department)>15||strlen(s.Department)<3)
	{
		printf("\n\t Invalid Entry. \t Maximum limit for first name is 15 and minimum limit is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(s.Department);b++)
		{
			if (isalpha(s.Department[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Department contain Invalid character. Enter again :");
			goto E;
		}
	}
	/* ********************************************** Student Type **************************************** */
	F:
    printf("\n\t\t\tStudent Type:");
    scanf("%s",s.stype);
    s.stype[0]=toupper(s.stype[0]);
    if(strlen(s.stype)>30||strlen(s.stype)<3)
	{
		printf("\n\t Invalid. \t The max range is 30 and min range is 3 :");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(s.stype);b++)
		{
			if (isalpha(s.stype[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Student name contain Invalid character. Enter again :");
			goto F;
		}
	}
    fprintf(fp," %s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, s.gender, s.age, s.address, s.contact, s.email, s.Department, s.stype);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(fp);     //fp file is closed
    st:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (t	coupper(ans)=='Y')
	{
    	Add_record();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you");
    	getch();
    	mainmenu();
		}
	    else
    {
        printf("\n\t\tInvalid Input\n");
        goto st;
    }
}
/* **************************************VIEW RECORD*******************************************/
void function_list()
{
	int row;
	system("cls");   //output screen clear function
	titlescreen();
	FILE *fp;
	fp=fopen("main.txt","r");
	printf("\n\n\t\t\t************** List Student Record *************\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(28,15);
		printf("Age");
		gotoxy(33,15);
		printf("Address");
		gotoxy(53,15);
		printf("Contact No.");
		gotoxy(68,15);
		printf("Email");
		gotoxy(92,15);
		printf("Department");
		gotoxy(106,15);
		printf("Student Type\n");
		printf("=======================================================================================================================");
		row=18;
		while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, &s.gender, &s.age, s.address, s.contact, s.email, s.Department, s.stype)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",s.first_name, s.last_name);
			gotoxy(20,row);
			printf("%c",s.gender);
			gotoxy(28,row);
			printf("%i",s.age);
			gotoxy(33,row);
			printf("%s",s.address);
			gotoxy(53,row);
			printf("%s",s.contact);
			gotoxy(68,row);
			printf("%s",s.email);
			gotoxy(92,row);
			printf("%s",s.Department);
			gotoxy(106,row);
			printf("%s",s.stype);
			row++;
		}
	fclose(fp);
	getch();
	mainmenu();
}
void search_record(void)
{
	char name[20];
	system("cls");
	titlescreen();// call Title function
	FILE *fp;
	fp=fopen("main.txt","r");
	printf("\n\n\t\t\t************** Search Students Record *************\n");
	//gotoxy(12,8);
	printf("\n Enter Student Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, &s.gender, &s.age, s.address, s.contact, s.email, s.Department, s.stype)!=EOF)
	{
		if(strcmp(s.first_name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(19,15);
			printf("Gender");
			gotoxy(28,15);
			printf("Age");
			gotoxy(33,15);
			printf("Address");
			gotoxy(53,15);
			printf("Contact No.");
			gotoxy(68,15);
			printf("Email");
			gotoxy(92,15);
			printf("Department");
			gotoxy(106,15);
			printf("Student Type\n");
			printf("========================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",s.first_name, s.last_name);
			gotoxy(19,18);
			printf("%c",s.gender);
			gotoxy(28,18);
			printf("%i",s.age);
			gotoxy(33,18);
			printf("%s",s.address);
			gotoxy(53,18);
			printf("%s",s.contact);
			gotoxy(68,18);
			printf("%s",s.email);
			gotoxy(92,18);
			printf("%s",s.Department);
			gotoxy(106,18);
			printf("%s",s.stype);
			printf("\n");
			break;
		}
	}
	if(strcmp(s.first_name,name)!=0)
  	{
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	}
	fclose(fp);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        search_record();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you.");
    	getch();
		mainmenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
void edit_record(void)
{
	FILE *fp, *db;
  	int i,b, valid=0;
  	char ch;
  	char name[20];
	system("cls");
  	titlescreen();
 	db=fopen("temp.txt","w+");
	fp=fopen("main.txt","r");
	if(fp==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
	}
    printf("\n\n\t\t\t************** Edit Students Record *************\n");
	gotoxy(12,13);
	printf("Enter the First Name of the Student : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(db==NULL)
	{
		printf("\n Can not open file");
		getch();
		mainmenu();
	}
	while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, &s.gender, &s.age, s.address, s.contact, s.email, s.Department, s.stype)!=EOF)
	{
		if(strcmp(s.first_name, name)==0)
		{
			valid=1;
			gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(1,19);
			printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",s.first_name,s.last_name,s.gender, s.age,s.address,s.contact,s.email,s.Department,s.stype);
			gotoxy(12,22);
			printf("Enter New First Name: ");
			scanf("%s",s.first_name);
			gotoxy(12,24);
			printf("Enter Last Name: ");
			scanf("%s",s.last_name);
			gotoxy(12,26);
			printf("Enter Gender: ");
			scanf(" %c",&s.gender);
			s.gender=toupper(s.gender);
			gotoxy(12,28);
			printf("Enter age: ");
			scanf(" %i",&s.age);
			gotoxy(12,30);
			printf("Enter Address: ");
			scanf("%s",s.address);
			s.address[0]=toupper(s.address[0]);
			gotoxy(12,32);
			printf("Enter Contact no: ");
			scanf("%s",s.contact);
			gotoxy(12,34);
			printf("Enter New email: ");
			scanf("%s",s.email);
			gotoxy(12,36);
			printf("Enter Department: ");
			scanf("%s",s.Department);
			s.Department[0]=toupper(s.Department[0]);
			gotoxy(12,38);
			printf("Enter Student Type: ");
			scanf("%s",s.stype);
			s.stype[0]=toupper(s.stype[0]);
			printf("\nPress U charecter for the Updating operation : ");
			ch=getche();
			if(ch=='u' || ch=='U')
			{
				fprintf(db,"%s %s %c %i %s %s %s %s %s\n",s.first_name,s.last_name,s.gender, s.age,s.address,s.contact,s.email,s.Department,s.stype);
				printf("\n\n\t\t\tStudent record updated successfully...");
			}
		}
		else
		{
			fprintf(db,"%s %s %c %i %s %s %s %s %s\n",s.first_name,s.last_name,s.gender, s.age,s.address,s.contact,s.email,s.Department,s.stype);
		}
	}
	if(!valid)
	{
		printf("\n\t\tRECORD NOT FOUND...");
	}
	fclose(db);
	fclose(fp);
	remove("main.txt");
   	rename("temp.txt","main.txt");
	getch();
	mainmenu();
}
void delete_record()
{
	char name[20];
	int found=0;
	system("cls");
	titlescreen();// call Title function
	FILE *fp, *db;
	db=fopen("edited.txt","w+");
	fp=fopen("main.txt","r");
	printf("\n\n\t\t\t************* Delete Students Record *************\n");
	gotoxy(12,8);
	printf("\n Enter Student Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while (fscanf(fp,"%s %s %c %i %s %s %s %s %s", s.first_name, s.last_name, &s.gender,&s.age, s.address, s.contact, s.email, s.Department, s.stype)!=EOF)
	{
		if (strcmp(s.first_name,name)!=0)
		fprintf(db,"%s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, s.gender, s.age, s.address, s.contact, s.email, s.Department, s.stype);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", s.first_name, s.last_name, s.gender, s.age, s.address, s.contact, s.email, s.Department, s.stype);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		mainmenu();
	}
	else
	{
		fclose(fp);
		fclose(db);
		remove("main.txt");
		rename("edited.txt","main.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		mainmenu();
	}
}

