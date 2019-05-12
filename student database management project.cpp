#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

struct student
{
	char roll_no[10];
    char student_name[50];
	char father_name[50];
	char course[30];
	char branch[30];
	char section[10];
	char address[60];
}stu;

int main()
{
    FILE *fp, *ft;
    char another, choice;
    char groll[10];

    fp = fopen("users.txt","r+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","w+");

        if (fp==NULL)
        {
            puts("Can not open file.\n");
            return 0;
        }
    }

    while(1)
    {
    	system("cls");
    	
        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n";
        cout << "\t\t\t\t\t\t-made by hacker\n";
        cout << "\n\n*****************************************************************************************\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit          ";
        cout << "\n\n\n\tSelect Your Choice : ";
		
		fflush(stdin);
		choice = getchar();
		
        switch(choice)
        {
        case '1' :
        	system("cls");
        	
        	fp = fopen("users.txt","a+");
            //fseek(fp, 0, SEEK_END);
            
            another ='Y';
            do
            {   
                fflush(stdin);
                
                cout << "Enter the Student's Roll No.   : ";
                gets(stu.roll_no);              
                cout << "Enter the Student's Name   	: ";
                gets( stu.student_name);
                cout << "Enter the Father's Name    	: ";
                gets(stu.father_name);
                cout << "Enter the Course    			: ";
                gets(stu.course);
                cout << "Enter the Branch   			: ";
                gets(stu.branch);
                cout << "Enter the Section 				: ";
                gets(stu.section);
                cout << "Enter the Student's Address    : ";
                gets(stu.address);
                
                fwrite(&stu, sizeof(stu), 1, fp);
    
				cout << "\n Add Another Record (Y/N) : ";			
				fflush(stdin);
                another = getchar();
                system("cls");
                
            }while(another == 'Y' || another == 'y');
            
            fclose(fp);
			break;
			
        case '2':
            system("cls");
            
            fp = fopen("users.txt","r");
            rewind(fp);
            
			cout << "=== Records in the Database ===";
            cout << "\n";
            
            while (fread(&stu, sizeof(stu), 1, fp) == 1)
            {
            	cout << stu.roll_no << endl;
                cout << stu.student_name << endl;
                cout << stu.father_name << endl;
                cout << stu.course << endl;
                cout << stu.branch << endl;
                cout << stu.section << endl;
                cout << stu.address << endl;
                cout << "\n";
            }
            cout << "\n\n";
            
            system("pause");
            fclose(fp);
            break;

        case '3' :
            system("cls");
            
            another = 'Y';
            do
            {
                cout << "\n Enter Roll No. of the student to modify : ";
                fflush(stdin);
                gets(groll);
				
				fp = fopen("users.txt","r+");
                rewind(fp);
                
                while (fread(&stu, sizeof(stu), 1, fp) == 1)
                {
                    if (strcmp(groll, stu.roll_no) == 0)
                    {
			            fflush(stdin);
			            system("cls");
			            
			            cout << "Enter New Data : \n\n";
		                cout << "Enter the Student's Roll No.   : ";
		                gets(stu.roll_no);              
		                cout << "Enter the Student's Name   	: ";
		                gets( stu.student_name);
		                cout << "Enter the Father's Name    	: ";
		                gets(stu.father_name);
		                cout << "Enter the Course    			: ";
		                gets(stu.course);
		                cout << "Enter the Branch   			: ";
		                gets(stu.branch);
		                cout << "Enter the Section 				: ";
		                gets(stu.section);
		                cout << "Enter the Student's Address    : ";
		                gets(stu.address);	
		                
			            
                        //fseek(fp, - sizeof(stu), SEEK_CUR);
                        fwrite(&stu, sizeof(stu), 1, fp);
                        
                        fclose(fp);
                        break;
                    }
                    else
                        cout<< "\t\trecord not found !";
                }
                
                cout << "\n Modify Another Record (Y/N) : ";
                fflush(stdin);
                another = getchar();
                system("cls");
                
            }while (another == 'Y'|| another == 'y');
            
            fclose(fp);
            break;

        case '4':
            system("cls");
            
            another = 'Y';
            do
            {
                cout << "\n Enter Roll No. of the student to delete : ";
                fflush(stdin);
                gets(groll);

                ft = fopen("temp.txt", "w+");
                fp = fopen("users.txt", "a+");
                //rewind(fp);
                
                while (fread (&stu, sizeof(stu), 1, fp) == 1)
                {
                    if (strcmp(groll, stu.roll_no) != 0)
                    {
                        fwrite(&stu, sizeof(stu), 1, ft);
                    }
            	}
            	
                fclose(fp);
                fclose(ft);
                
				remove("users.txt");
                rename("temp.txt","users.txt");

                fp=fopen("users.txt","r+");

                cout << "\n Delete Another Record (Y/N) : ";
				fflush(stdin);
                another = getchar();
                system("cls");
                
            }while (another == 'Y'|| another == 'y');
			
			fclose(fp);
            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
            cout << "\n\n";
            exit(0);
        }
    }
	
	fclose(fp);
    system("pause");
    return 0;
}
