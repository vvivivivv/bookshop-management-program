#include <stdio.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;

// function prototypes
void addBook(Book bookRec_list[], int *n);
void listBooks(Book bookRec_list[], int n);
void removeBook(Book bookRec_list[], int *n);
void findBook(Book bookRec_list[], int *n);
void updateBook(Book bookRec_list[], int n);


int main()
{
    // initialisation and declaration
    int choice, number=0;
    Book bookRec[100];
    
    // printing options/menu
    
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n");
    printf("1: listBooks()\n");
    printf("2: addBook()\n");
    printf("3: removeBook()\n");
    printf("4: findBook()\n");
    printf("5: updateBook()\n");
    printf("6: quit\n");
    
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        scanf("\n");
        switch(choice) {
            case 1:
                printf("listBooks():\n");
                listBooks(bookRec, number);
                break;
            case 2:
                printf("addBook():\n");
                addBook(bookRec, &number);
                break;
            case 3: 
                printf("removeBook():\n");
                removeBook(bookRec, &number);
                break;
            case 4:
                printf("findBook():\n");
                findBook(bookRec, &number);
                break;
            case 5:
                printf("updateBook():\n");
                updateBook(bookRec, number);
                break;
            case 6:
                break;
        }
    } while (choice < 6);
    return 0;
}

void listBooks(Book bookRec_list[], int n){
    // sorts by numeric order of bookID
    int i, j, k;
    Book temp;
  
    if (bookRec_list[0].bookID == '\0') {
        printf("The bookshop is empty\n");
    }
    
    else{
      for (k = 0; k<n-1; k++){
        for (j = 0; j<n-1; j++){
            if (bookRec_list[j].bookID > bookRec_list[j+1].bookID){
                temp = bookRec_list[j];
                bookRec_list[j] = bookRec_list[j+1];
                bookRec_list[j+1] = temp; 
            }
        }
    }
        
        for(i=0; i<n; i++){
            printf("BookID: %d\n", bookRec_list[i].bookID);
            printf("Book title: %s\n", bookRec_list[i].title);
            printf("Author name: %s\n", bookRec_list[i].author);
            printf("Book price: %.2lf\n", bookRec_list[i].price);
            printf("Quantity: %d\n", bookRec_list[i].quantity);
        }
    }
}

void addBook(Book bookRec_list[], int *n){
    char *p, *q;
    int max_books = 5;
    int i, id, duplicate=0;
    
    printf("Enter bookID:\n");
    scanf("%d", &id);
    scanf("\n");
        
    for (i=0; i<*n; i++){
        if (bookRec_list[i].bookID == id){
        duplicate = 1;
        break;
        }
    }
    
    bookRec_list[*n].bookID = id;

    printf("Enter book title:\n");
    fgets(bookRec_list[*n].title, 40, stdin);
    scanf("\n");
    if (p = strchr(bookRec_list[*n].title, '\n')) {
        *p = '\0';
    }
        
    printf("Enter author name:\n");
    fgets(bookRec_list[*n].author, 40, stdin);
    scanf("\n");
    if (q = strchr(bookRec_list[*n].author, '\n')){
        *q = '\0';
    }
        
    printf("Enter price:\n");
    scanf("%lf", &bookRec_list[*n].price);
        
    printf("Enter quantity:\n");
    scanf("%d", &bookRec_list[*n].quantity);
    scanf("\n");
        
    if (duplicate == 1){
        printf("The bookID has already existed! Unable to addBook()\n");
    }
    else if (*n < max_books){
        printf("The book has been added successfully\n");
        (*n)++;
    }
    else {
        printf("The bookshop is full! Unable to addBook()\n");
    }
}    

void removeBook(Book bookRec_list[], int *n){
    char *p, *q;
    char title[40], author[40], temp_title[40], temp_author[40];
    int i, j, k, b, c;
    int index = 0;
    
    printf("Enter the target book title:\n");
    fgets(title, 40, stdin);
    scanf("\n");
    if (p = strchr(title, '\n')){
        *p = '\0';
    }
    
    printf("Enter the target author name:\n");
    fgets(author, 40, stdin);
    scanf("\n");
    if (q = strchr(author, '\n')){
        *q = '\0';
    }
  
    for (i=0; title[i] != '\0'; i++){
        title[i] = tolower(title[i]);
    }
    
     for (j=0; author[j] != '\0'; j++){
        author[j] = tolower(author[j]);
    }
    
    for (k=0; k<*n; k++){
        strcpy(temp_title, bookRec_list[k].title);
        strcpy(temp_author, bookRec_list[k].author);
        
        for (b = 0; temp_title[b] != '\0'; b++){
            temp_title[b] = tolower(temp_title[b]);
        }
        
        for (b = 0; temp_author[b] != '\0'; b++){
            temp_author[b] = tolower(temp_author[b]);
        }
        
        if (strcmp(temp_title, title) == 0 && strcmp(temp_author, author) == 0){
            index = k;
            break;
        }
    }
    
    if (bookRec_list[0].bookID == '\0') {
        printf("The bookshop is empty\n");
    } 
    
    else if (index == 0) {
        printf("The target book is not in the bookshop\n");
    }
    
    else {
        printf("The target book is removed\n");
        
        printf("BookID: %d\n", bookRec_list[index].bookID);
        printf("Book title: %s\n", bookRec_list[index].title);
        printf("Author name: %s\n", bookRec_list[index].author);
        printf("Book price: %.2lf\n", bookRec_list[index].price);
        printf("Quantity: %d\n", bookRec_list[index].quantity);
        
        for (c = index; c<*n-1; c++){
            bookRec_list[c] = bookRec_list[c+1];
        }
        
        (*n)--;
    }
}

void findBook(Book bookRec_list[], int *n){
    char *p, *q;
    char title[40], author[40], temp_title[40], temp_author[40];
    int i, j, k, b, c;
    int index = 0;
    
    printf("Enter the target book title:\n");
    fgets(title, 40, stdin);
    scanf("\n");
    if (p = strchr(title, '\n')){
        *p = '\0';
    }
    
    printf("Enter the target author name:\n");
    fgets(author, 40, stdin);
    scanf("\n");
    if (q = strchr(author, '\n')){
        *q = '\0';
    }
      
    for (i=0; title[i] != '\0'; i++){
        title[i] = tolower(title[i]);
    }
    
     for (j=0; author[j] != '\0'; j++){
        author[j] = tolower(author[j]);
    }
    
    for (k=0; k<*n; k++){
        strcpy(temp_title, bookRec_list[k].title);
        strcpy(temp_author, bookRec_list[k].author);
        
        for (b = 0; temp_title[b] != '\0'; b++){
            temp_title[b] = tolower(temp_title[b]);
        }
        
        for (b = 0; temp_author[b] != '\0'; b++){
            temp_author[b] = tolower(temp_author[b]);
        }
        
        if (strcmp(temp_title, title) == 0 && strcmp(temp_author, author) == 0){
            index = k;
            break;
        }
    }
    
    if (bookRec_list[0].bookID == '\0') {
        printf("The bookshop is empty\n");
    } 
    
    else if (index == 0) {
        printf("The target book is not found\n");
    }
    
    else {
        printf("The target book is found\n");
        
        printf("BookID: %d\n", bookRec_list[index].bookID);
        printf("Book title: %s\n", bookRec_list[index].title);
        printf("Author name: %s\n", bookRec_list[index].author);
        printf("Book price: %.2lf\n", bookRec_list[index].price);
        printf("Quantity: %d\n", bookRec_list[index].quantity);
    }
}

void updateBook(Book bookRec_list[], int n){
    char *p, *q;
    char title[40], author[40], temp_title[40], temp_author[40];
    int i, j, k, b, c;
    int index = 0;
    
    printf("Enter the target book title:\n");
    fgets(title, 40, stdin);
    scanf("\n");
    if (p = strchr(title, '\n')){
        *p = '\0';
    }
    
    printf("Enter the target author name:\n");
    fgets(author, 40, stdin);
    scanf("\n");
    if (q = strchr(author, '\n')){
        *q = '\0';
    }
    
    for (i=0; title[i] != '\0'; i++){
        title[i] = tolower(title[i]);
    }
    
     for (j=0; author[j] != '\0'; j++){
        author[j] = tolower(author[j]);
    }
    
    for (k=0; k<n; k++){
        strcpy(temp_title, bookRec_list[k].title);
        strcpy(temp_author, bookRec_list[k].author);
        
        for (b = 0; temp_title[b] != '\0'; b++){
            temp_title[b] = tolower(temp_title[b]);
        }
        
        for (b = 0; temp_author[b] != '\0'; b++){
            temp_author[b] = tolower(temp_author[b]);
        }
        
        if (strcmp(temp_title, title) == 0 && strcmp(temp_author, author) == 0){
            index = k;
            break;
        }
    }
    
    if (bookRec_list[0].bookID == '\0') {
        printf("The bookshop is empty\n");
    } 
    
    else if (index == 0) {
        printf("The target book is not in the bookshop\n");
    }
    
    else{
    printf("Enter updated book price:\n");
    scanf("%lf", &bookRec_list[index].price);
    scanf("\n");

    printf("Enter updated quantity:\n");
    scanf("%d", &bookRec_list[index].quantity);
    scanf("\n");
    
    printf("The target book is updated\n");
    
    printf("BookID: %d\n", bookRec_list[index].bookID);
    printf("Book title: %s\n", bookRec_list[index].title);
    printf("Author name: %s\n", bookRec_list[index].author);
    printf("Book price: %.2lf\n", bookRec_list[index].price);
    printf("Quantity: %d\n", bookRec_list[index].quantity);
    }
}
