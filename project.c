#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAX_BOOKS 10
#define MAX_WORD_LENGTH 100




struct book
{
    char name[MAX_WORD_LENGTH];
    int borrowed;
};

struct book library[MAX_BOOKS];
int book_count=0;
int bookcount=0; // for tracing the student

void addBook()
{
    struct book newbook;
    if( book_count ==MAX_BOOKS)
    {
        printf("Book limit is full & you cannot add any books now");
        return ;
    }
    printf("Enter title of the book:");
    fgets(newbook.name,MAX_WORD_LENGTH,stdin);

    newbook.name[strcspn(newbook.name,"\n")]='\0';//replacing enter value with null value

    newbook.borrowed=0;

    library[book_count++]=newbook;

    printf("\nYou successfully added the new book\n");


}

void displayBook()
{
    if(book_count==0)
    {
        printf("\nThere is no book to show\n");
        return;
    }
    printf("Books in the library:\n");
    for(int i=0;i<book_count;i++)
    {
       printf("%d. %s\n",i+1,library[i].name);

    }
}

int librarianMenu()
{
    int choice;

    do
    {
            printf("Librarian Menu:\n");
            printf("1.Add Book\n");
            printf("2.Display Book\n");
            printf("3.Quit\n");
            scanf("%d",&choice);
            getchar(); // to take one word from user

            switch(choice)
            {
            case 1:
                addBook();

                break;

            case 2:
                displayBook();

                break;

            case 3:
                printf("Returning to the role selection menu\n");

                return 0;
                 // to quit
            default:
                printf("You must be pressed the wrong key\n");
                printf("Try again properly");

            }

    }while(choice != 3);


}


int borrowBook()
{
    if(book_count==0)
    {
        printf("The Library is empty.\n");
        return 2; // return 2 for nothing returned
    }

    if(bookcount>3)
    {
       printf("You exceeded your limit\n");
       return 2; // return 2 for nothing returned
    }

    char name[100];

    printf("Book title Name:");
    fgets(name,100,stdin);
    name[strcspn(name,"\n")]='\0';

    for(int i =0 ; i<book_count ; i++ )
    {
        if(strcmp(library[i].name,name)==0)
        {
            if(library[i].borrowed==1)
            {
                printf("This book is already taken.\n");
                return 2;
            }
            else
            {
                library[i].borrowed = 1;
                printf("The Book is successfully borrowed.\n");
                return 1;
            }
        }
    }

    printf("The book is not available in the library.\n");
    return 2;
}

int returnBook()
{
     if(book_count==0)
    {
        printf("The Library is empty.\n");
        return 2; // return 2 for nothing returned

    }

    if(bookcount==0)
    {
       printf("You did not take any book.\n");
       return 2; // return 2 for nothing returned
    }


    char name[100];

    printf("Book title Name:");
    fgets(name,100,stdin);
    name[strcspn(name,"\n")]='\0';

    for(int i =0 ; i<book_count ; i++ )
    {
        if(strcmp(library[i].name,name)==0)
        {
            if(library[i].borrowed==0)
            {
                printf("This book is not taken.\n");
                return 2; // return 2 for nothing returned
            }
            else
            {
                library[i].borrowed = 0;
                printf("The Book is successfully returned.\n");

                return 0;

            }
        }
      return 2; // return 2 for nothing returned
    }

    printf("The spelling of the Book must be wrong.");

    return 2; // return 2 for nothing returned

}

int studentMenu()
{
    int choice;

    do
    {
            printf("Student Menu:\n");
            printf("1.Display Book.\n");
            printf("2.Borrow Book.\n");
            printf("3.Return Book.\n");
            printf("4.Quit.\n");
            scanf("%d",&choice);
            getchar();

            switch(choice)
            {
            case 1:
                displayBook();

                break;
            case 2:
                printf("Remember you can take only 3 books\n");
                borrowBook();
                bookcount++;

                break;
            case 3:
                returnBook();
                bookcount--;

                break;
            case 4:
                printf("Returning to the roll selection menu\n");
                   system("cls") ;/*clear output screen*/
                return 0;
            default:
                printf("Something Wrong here take a look.\n");
                   system("cls") ;/*clear output screen*/
            }

    }while(choice != 4);


}

int main()
{
    int vchoice;

    do
    {
        printf("Welcome to library management system.\n");
        printf("1.Student.\n");
        printf("2.Librarian.\n");
        printf("3.Quit\n");

        scanf("%d",&vchoice);
        getchar();

        switch (vchoice)
        {
        case 1:
            {
            studentMenu();

            break;
            }

        case 2:
            {
            librarianMenu();

            break;
            }
        case 3:
            {
            printf("Quiting the program.\n");

            break;
            }
        default:
            {
            printf("Please Enter Again.\n");

            }
        }

    }while(vchoice != 3);





        printf("\n\t\tThank You for use this Program.\n\n");


        return 0;


}



