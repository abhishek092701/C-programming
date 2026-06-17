#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contact
{
	char name[50];
	char phone[50];
	char email[50];
	char address[50];
};
	
struct contact *C=NULL;
int count=0;

void addContact()
{

    C=(struct contact *)realloc(C, (count+1)*sizeof(struct contact));
    printf("\nEnter Name: ");
    scanf(" %[^\n]", C[count].name);
    printf("Enter Phone: ");
    scanf("%s", C[count].phone);
    printf("Enter Email: ");
    scanf("%s", C[count].email);
    printf("Enter Address: ");
    scanf(" %[^\n]", C[count].address);
    count++;
    printf("\nContact Added Successfully!\n");
}

void displayContacts()
{
    int i;
    if(count==0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }
    printf("\n        CONTACT LIST        \n");
    for(i=0; i<count; i++)
    {
        printf("\nContact %d\n", i+1);
        printf("Name    : %s\n", C[i].name);
        printf("Phone   : %s\n", C[i].phone);
        printf("Email   : %s\n", C[i].email);
        printf("Address : %s\n", C[i].address);
    }
}
void searchContact()
{
    int choice,i,found=0;
    char key[50];
    if(count==0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }
    printf("\nSearch By:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("Enter search value: ");
    scanf(" %s", key);
    for(i=0; i<count; i++)
    {
        if((choice==1 && strcmp(C[i].name,key)==0) ||
           (choice==2 && strcmp(C[i].phone,key)==0) ||
           (choice==3 && strcmp(C[i].email,key)==0))
        {
            printf("\nContact Found!\n");
            printf("Name    : %s\n", C[i].name);
            printf("Phone   : %s\n", C[i].phone);
            printf("Email   : %s\n", C[i].email);
            printf("Address : %s\n", C[i].address);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("\nContact Not Found!\n");
    }
}

void editContact()
{
    char search[50];
    int i;
    if(count==0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }
    printf("\nEnter Name to Edit: ");
    scanf(" %[^\n]", search);
    for(i=0; i<count; i++)
    {
        if(strcmp(C[i].name, search)==0)
        {
        	printf("Enter New Name: ");
			scanf(" %[^\n]", C[i].name);
        	
            printf("Enter New Phone: ");
            scanf("%s", C[i].phone);

            printf("Enter New Email: ");
            scanf("%s", C[i].email);
            
            printf("Enter Address: ");
    		scanf(" %[^\n]", C[i].address);

            printf("\nContact Updated Successfully!\n");
            return;
        }
    }
    printf("\nContact Not Found!\n");
}

void deleteContact()
{
    char search[50];
    int i,j;
    if(count==0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }
    printf("\nEnter Name to Delete: ");
    scanf(" %[^\n]", search);
    for(i=0; i<count; i++)
    {
        if(strcmp(C[i].name, search)==0)
        {
            for(j=i; j<count-1; j++)
            {
                C[j]=C[j+1];
            }
            count--;
            C=(struct contact *)realloc(C,count*sizeof(struct contact));
            printf("\nContact Deleted Successfully!\n");
            return;
        }
    }
    printf("\nContact Not Found!\n");
}

void sortContacts()
{
    int i,j;
    struct contact temp;
    if(count==0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }
    for(i=0; i<count-1; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcmp(C[i].name, C[j].name)>0)
            {
                temp=C[i];
                C[i]=C[j];
                C[j]=temp;
            }
        }
    }
    printf("\nContacts Sorted Alphabetically!\n");
}

void saveContacts()
{
    FILE *fp;
    int i;
	fp=fopen("D:\\LOQ\\project_11.bin","wb");
	if(fp==NULL)
	{
		return;
	}
	fwrite(&count, sizeof(int), 1, fp);
	fwrite(C, sizeof(struct contact),count,fp);
    fclose(fp);
    printf("Contacts Saved Successfully!\n");
}

void loadContacts()
{
    FILE *fp;
	fp=fopen("D:\\LOQ\\project_11.bin","rb");
    if(fp==NULL)
    {
        return;
    }
	fread(&count, sizeof(int),1,fp);
	if(count>0)
	{
    	C=(struct contact *)malloc(count*sizeof(struct contact));
    	fread(C,sizeof(struct contact),count,fp);
	}
	else
	{
    	C=NULL;
	}
    fclose(fp);
}

void freeMemory()
{
    free(C);
    C=NULL;
}
int main()
{
    int choice;
    loadContacts();
    do
    {
        printf("\n\n       PHONE BOOK     \n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact (Name / Phone / Email)\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Sort Contacts\n");
        printf("7. Save Contacts\n");
        printf("8. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                editContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                sortContacts();
                break;

            case 7:
                saveContacts();
                break;

            case 8:
                saveContacts();
                freeMemory();
                printf("\nThank You for Using Phone Book!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }  
	while(choice!=8);
    return 0;
}