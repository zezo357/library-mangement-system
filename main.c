#include <stdio.h>

#include <string.h>

#include <stdlib.h>
int checkid(FILE *fptr,char id[50]){
    char  BookID[50], BookName[50], Author[50], Quantity[50], Price[50], RackNo[50], choice[50], categorie[50], order[50];
int isDone = 0;
        fptr = fopen("Books.txt", "r");
        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {

                if (strcmp(id, BookID) == 0) {
                        isDone = 1;}}
return isDone;
}
void getdata(char * string, int length) {
        int x = 0;

        fgets(string, length, stdin);
        while ( * string) {
                if ( * string == ' ') {
                        * string = '_';

                }
                if ( * string == '\n') {
                        * string = '\0';
                        return;
                }
                x++;
                if (x == length) {
                        * string = '\0';
                        return;
                }
                string++;
        }
}
void returnfunc(void) {
        system("CLS");
        mainmenu();
}
void addbooks(void) {
        system("CLS");

        FILE * fptr;
        char  BookID[50], BookName[50], Author[50], Quantity[50], Price[50], RackNo[50], choice[50], categorie[50], order[50];
        fptr = fopen("Books.txt", "a+");
                if ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) == EOF) {
                        fprintf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", "categorie", "Book_ID", "Book_Name", "Author", "Quantity", "Price", "RackNo");}
        fclose(fptr);
        printf("######## SELECT CATEGORIE ########\n");
        printf("#### 1. Computer \n");
        printf("#### 2. Electronics \n");
        printf("#### 3. Electrical \n");
        printf("#### 4. Civil \n");
        printf("#### 5. Mechanical \n");
        printf("#### 6. Architecture \n");
        printf("#### 7. Back to main menu \n");
        int isDone = 0;
        while (isDone != 1) {
                printf("Enter you choice: ");
                getdata(choice, 35);

                if ((strcmp(choice, "1")) == 0) {
                        printf("##############################\n");
                        printf("####  Computer \n");
                        strncpy(categorie, "Computer", 50);

                        isDone = 1;
                }

                if ((strcmp(choice, "2")) == 0) {
                        printf("##############################\n");
                        printf("####  Electronics \n");
                        strncpy(categorie, "Electronics", 50);

                        isDone = 1;
                };

                if ((strcmp(choice, "3")) == 0) {
                        printf("##############################\n");
                        printf("####  Electrical \n");
                        strncpy(categorie, "Electrical", 50);

                        isDone = 1;
                }

                if ((strcmp(choice, "4")) == 0) {
                        printf("##############################\n");
                        printf("####  Civil \n");
                        strncpy(categorie, "Civil", 50);

                        isDone = 1;
                }

                if ((strcmp(choice, "5")) == 0) {
                        printf("##############################\n");
                        printf("####  Mechanical \n");
                        strncpy(categorie, "Mechanical", 50);

                        isDone = 1;
                }

                if ((strcmp(choice, "6")) == 0) {
                        printf("##############################\n");
                        printf("####  Architecture \n");
                        strncpy(categorie, "Architecture", 50);

                        isDone = 1;
                }

                if ((strcmp(choice, "7")) == 0) {
                        returnfunc();
                        isDone = 1;
                }

                if ((strcmp(choice, "1") != 0) && (strcmp(choice, "2") != 0) && (strcmp(choice, "3") != 0) && (strcmp(choice, "4") != 0) && (strcmp(choice, "5") != 0) && (strcmp(choice, "6") != 0) && (strcmp(choice, "7") != 0))
                        printf("Error! choice is not correct\n");
                continue;
        }
        if (strcmp(choice, "6") == 0 || strcmp(choice, "5") == 0 || strcmp(choice, "4") == 0 || strcmp(choice, "3") == 0 || strcmp(choice, "2") == 0 || strcmp(choice, "1") == 0) {


                printf("#### Book ID: ");
                getdata(BookID, 35);
if (checkid(fptr,BookID)){printf("this book has been allready added");goto done; }

                printf("#### Book Name: ");
                getdata(BookName, 35);

                printf("#### Author: ");
                getdata(Author, 35);

                printf("#### Quantity:  ");
                getdata(Quantity, 35);

                printf("#### Price: ");
                getdata(Price, 35);

                printf("#### Rack No: ");
                getdata(RackNo, 35);
                printf("##############################\n");

                 fptr = fopen("Books.txt", "a+");
                fprintf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
                fclose(fptr);
                printf("\nthe record is successfully saved ");
                done:
                printf("\n\npress any key to return to main menu\n\nto add another book write A  ");
                getdata(order, 35);
                if (strcmp(order, "A") == 0) {
                        system("CLS");
                        addbooks();
                } else {
                        returnfunc();
                }
        }
}
void deletebooks(void) {
        system("CLS");
        char BookID[50], BookName[50], Author[50], Quantity[50], Price[50], choice[50], RackNo[50], categorie[50], searchingid[50], ch, order[50];
        printf("Delete a book\n");
        printf("enter your book id: ");
        getdata (searchingid,35);
        FILE * fptr, * tptr;
        int isDone = 0;
        fptr = fopen("Books.txt", "r");
        tptr = fopen("Bookstmp.txt", "w");
        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {

                if (strcmp(searchingid, BookID) == 0) {
                        isDone = 1;
                }
                if (strcmp(searchingid, BookID) != 0) {
                        fprintf(tptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
                }

        }
        fclose(fptr);
        fclose(tptr);
        if ((fptr) == NULL) {
                printf("File could not be opened\n");
        }
        if (isDone == 1) {
                printf("the book has been eliminated:)\n");
        }
        if (isDone == 0) {
                printf("the book you want to delete is not there :_(\n\n");
        }
        //put the copy the tempriry file to the main filie after the book is deleted
        fptr = fopen("Books.txt", "w");
        tptr = fopen("Bookstmp.txt", "r");
        while ((ch = fgetc(tptr)) != EOF) {
                fputc(ch, fptr);
        }
        fclose(fptr);
        fclose(tptr);
        remove("Bookstmp.txt");

        printf("\n\n\npress enter to return to main menu \n\nto delete another book write D: ");
        getdata(order, 35);
        if (strcmp(order, "D") == 0) {
                system("CLS");
                deletebooks();
        } else {
                returnfunc();
        }

}
void editbooks(void) {
        char BookID[50], BookName[50], Author[50], Quantity[50], Price[50], choice[50], RackNo[50], categorie[50], searchingid[50], ch, order[50];
        system("CLS");
        printf("editing a book\n");
        printf("enter your book id: ");
        getdata(searchingid, 35);
        FILE * fptr, * tptr;
        int isDone = 0;
        fptr = fopen("Books.txt", "r");
        tptr = fopen("Bookstmp.txt", "w");
        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {
                if (strcmp(searchingid, BookID) != 0) {
                        fprintf(tptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
                }
                if (strcmp(searchingid, BookID) == 0) {
                        printf("%35s%35s%35s%35s%35s%35s%35s\n", "categorie", "BookID", "BookName", "Author", "Quantity", "Price", "RackNo");
                        printf("%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);

                        printf("#### new Book ID: ");
                        getdata(BookID, 35);

                        printf("#### new Book Name: ");
                        getdata(BookName, 35);

                        printf("#### new Author: ");
                        getdata(Author, 35);

                        printf("#### new Quantity:  ");
                        getdata(Quantity, 35);

                        printf("#### new Price: ");
                        getdata(Price, 35);

                        printf("#### new Rack No: ");
                        getdata(RackNo, 35);
                        fprintf(tptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
                        isDone = 1;
                }

        }
        fclose(fptr);
        fclose(tptr);
        if ((fptr) == NULL) {
                printf("File could not be opened\n");
        }
        if (isDone == 1) {
                printf("the book has been edited:)\n");
        }
        if (isDone == 0) {
                printf("the book you want to edit is no there :_(\n");
        }
        fptr = fopen("Books.txt", "w");
        tptr = fopen("Bookstmp.txt", "r");
        while ((ch = fgetc(tptr)) != EOF) {
                fputc(ch, fptr);
        }
        fclose(fptr);
        fclose(tptr);
        remove("Bookstmp.txt");

        printf("\n\n\npress enter to return to main menu\n\n  to edit for another book write E: ");
        getdata(order, 35);
        if (strcmp(order, "E") == 0) {
                editbooks();
        } else {
                returnfunc();
        }

}
void searchbooks(void) {
        system("CLS");
        char BookID[50], BookName[50], Author[50], Quantity[50], Price[50], choice[50], RackNo[50], categorie[50], searchingid[50], order[50];
        printf("searching for a book\n");
        printf("enter your book id: ");
        getdata(searchingid, 35);
        FILE * fptr;
        int isDone = 0;
        fptr = fopen("Books.txt", "r");
        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {

                if (strcmp(searchingid, BookID) == 0) {
                        isDone = 1;
                        printf("your book has been found\n");
                        printf("%35s%35s%35s%35s%35s%35s%35s\n", "categorie", "BookID", "BookName", "Author", "Quantity", "Price", "RackNo");
                        printf("%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
                        printf("\n\n\npress enter to return to main menu\n\nsearch for another book write S: ");
                        getdata(order, 35);
                        if (strcmp(order, "S") == 0) {
                                searchbooks();
                        } else {
                                returnfunc();
                        }

                }
        }
        if ((fptr) == NULL) {
                printf("File could not be opened\n");
                printf("\n\n\npress enter to return to main menu");
                getdata(order, 35);
                returnfunc();

        }
        if (isDone == 0) {
                printf("we couldn't find the book sorry :(");
                printf("\n\n\npress enter to return to main menu");
                getdata(order, 35);

                returnfunc();
        }

}
void viewbooks(void) {
        system("CLS");
        char BookID[50], BookName[50], Author[50], Quantity[50], Price[50], order[50], RackNo[50], categorie[50];
        FILE * fptr;
        fptr = fopen("Books.txt", "r");
        if ((fptr) == NULL) {
                printf("File could not be opened\n");
                printf("\n\n\npress enter to return to main menu");
                getdata(order, 35);
                returnfunc();}
        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {
                printf("%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);
        }
        if ((fptr) != NULL) {
                printf("\n\n\npress enter to return to main menu");
                getdata(order, 35);
                returnfunc();
        }

}
void issuebooks(void) {
        system("CLS");
        printf("#### 1. View Issued Books \n");
        printf("#### 2. issue book \n");
        printf("#### 3. return book \n");
        printf("#### 4. return to main menu \n");
        int isDone = 0;
        FILE * fptr, * sptr, * tptr;
        char BookID[50], BookName[50], Studentname[50], StudentID[50], choice[50], categorie[50], Author[50], Quantity[50], Price[50], ch, RackNo[50], searchingsid[50], searchingid[50], order[50];
        while (isDone != 1) {
                printf("Enter you choice: ");
                getdata(choice, 35);

                if (strcmp(choice, "1") == 0) {
                        sptr = fopen("IssuedBooks.txt", "r");
                        if ((sptr) == NULL) {
                                printf("File could not be opened\n\n");
                                isDone = 1;
                                printf("\n\n\npress enter to return to main menu");
                                getdata(order, 35);
                                returnfunc();
                                continue;
                        }

                        while ((fscanf(sptr, "%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID)) != EOF) {
                                printf("%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID);
                        }

                        printf("\n\n\n press enter to return to main menu");
                        getdata(order, 35);
                        returnfunc();

                        isDone = 1;
                }

                if (strcmp(choice, "2") == 0) {

                        sptr = fopen("IssuedBooks.txt", "a+");
                        fptr = fopen("Books.txt", "r");
                        printf("enter your book id: ");
                        getdata(searchingid, 35);
                        while ((fscanf(fptr, "%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo)) != EOF) {

                                if (strcmp(searchingid, BookID) == 0) {

                                        printf("your book has been found\n");
                                        printf("%35s%35s%35s%35s%35s%35s%35s\n", "categorie", "BookID", "BookName", "Author", "Quantity", "Price", "RackNo");
                                        printf("%35s%35s%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Author, Quantity, Price, RackNo);

                                        isDone = 1;
                                }
                        }

                        if (isDone == 1) {
                                if ((fscanf(sptr, "%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID)) == EOF) {
                                        fprintf(sptr, "%35s%35s%35s%35s%35s\n", "categorie", "Book_ID", "Book_Name", "Student_name", "Student_ID");
                                }

                                printf("Write the student name: ");
                                getdata(Studentname, 35);
                                printf("Write the student ID: ");
                                getdata(StudentID, 35);
                                fprintf(sptr, "%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID);
                                fclose(sptr);
                                printf("the book has been issued successfully");
                                printf("\n\n\n press enter to return to main menu");
                                getdata(order, 35);
                                isDone = 1;
                                returnfunc();
                        }

                        if (isDone == 0) {
                                printf("we don't have that book :( ");
                                printf("\n\n\npress enter to return to main menu");
                                getdata(order, 35);
                                isDone = 1;
                                returnfunc();
                        }

                }
                if (strcmp(choice, "3") == 0) {

                        printf("enter the book id: ");
                        getdata(searchingid, 35);

                        printf("enter the student id: ");
                        getdata(searchingsid, 35);

                        tptr = fopen("issuetmp.txt", "w");
                        sptr = fopen("IssuedBooks.txt", "r");

                        while ((fscanf(sptr, "%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID)) != EOF) {

                                if (strcmp(searchingid, BookID) == 0 && strcmp(searchingsid, StudentID) == 0) {

                                        isDone = 1;
                                }
                                if (strcmp(searchingid, BookID) != 0 || strcmp(searchingsid, StudentID) != 0) {
                                        fprintf(tptr, "%35s%35s%35s%35s%35s\n", categorie, BookID, BookName, Studentname, StudentID);

                                }

                        }
                        fclose(sptr);
                        fclose(tptr);
                        sptr = fopen("IssuedBooks.txt", "w");
                        tptr = fopen("issuetmp.txt", "r");
                        while ((ch = fgetc(tptr)) != EOF) {
                                fputc(ch, sptr);
                        }
                        fclose(sptr);
                        fclose(tptr);
                        remove("issuetmp.txt");
                        if (isDone == 1) {
                                printf("your book has been returned successfully ");
                                printf("\n\n\npress enter to return to main menu");
                                getdata(order, 35);

                                returnfunc();
                        }
                        if (isDone == 0) {
                                printf("we couldn't find your id or the book you taken on our file");
                                printf("\n\n\npress enter to return to main menu");
                                getdata(order, 35);
                                isDone = 1;
                                returnfunc();
                        }

                }

                if (strcmp(choice, "4") == 0) {

                        returnfunc();
                        isDone = 1;
                }

                if ((strcmp(choice, "4") != 0) && (strcmp(choice, "3") != 0) && (strcmp(choice, "2") != 0) && (strcmp(choice, "1") != 0)) {
                        printf("Error! choice is not correct\n");
                        continue;
                }
        }
}
void Password() {
        char Password[50];
        printf("please enter your password: ");
        getdata(Password, 35);

        while (strcmp(Password, "hi1") != 0) {

                printf("you entered a wrong password\n");
                printf("please enter your password: \n");
                getdata(Password, 35);
        }

        system("CLS");

        mainmenu();
}
void mainmenu(void) {
        char choice[35];
        printf("######## MAIN MENU ########\n");
        printf("#### 1. Add Books \n");
        printf("#### 2. Delete Books \n");
        printf("#### 3. Search Books \n");
        printf("#### 4. Issue Books \n");
        printf("#### 5. View Book list \n");
        printf("#### 6. Edit Books Record \n");
        printf("#### 7. Close Application \n");
        int isDone = 1;
        while (isDone != 0) {
                printf("Enter you choice: ");
                getdata(choice, 35);
                if (strcmp(choice, "1") == 0) {

                        system("CLS");
                        addbooks();
                        isDone = 0;
                }
                if (strcmp(choice, "2") == 0) {
                        system("CLS");
                        deletebooks();
                        isDone = 0;
                }
                if (strcmp(choice, "3") == 0) {
                        system("CLS");
                        searchbooks();
                        isDone = 0;
                }
                if (strcmp(choice, "4") == 0) {
                        system("CLS");
                        issuebooks();
                        isDone = 0;
                }
                if (strcmp(choice, "5") == 0) {
                        system("CLS");
                        viewbooks();

                        isDone = 0;
                }
                if (strcmp(choice, "6") == 0) {
                        system("CLS");
                        editbooks();
                        isDone = 0;
                }
                if (strcmp(choice, "7") == 0) {
                        isDone = 0;
                }
                if ((strcmp(choice, "1") != 0) && (strcmp(choice, "2") != 0) && (strcmp(choice, "3") != 0) && (strcmp(choice, "4") != 0) && (strcmp(choice, "5") != 0) && (strcmp(choice, "6") != 0) && (strcmp(choice, "7") != 0))
                        printf("Error! choice is not correct\n");
                continue;
        }

}

int main() {
        Password();

        return 0;
}
