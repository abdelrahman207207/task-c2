#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//union active_1{
//struct active_2{
//bool flag;
//}a2;
//}a1;
#define max 10
typedef struct {
    char username[10];
    char password[10];
    int isActive;        // login flag 0 for false , 1 for true

} User;

typedef union {
    User user;
    char email[50];
} UserInfo;

User users[max];
int count = 0;
// max user counter
void registerUser() {
    if (count == max) {
        printf("You reach the max user count.\n");
        return;
    }
// start regesteration code
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter Access: ");
    scanf("%d", &newUser.isActive);
    users[count++] = newUser;
    printf("User registered successfully!\n");
    //printf("Active (1/0) : ");
    //scanf("%d",&(a2.a1.Flag));
}

void loginUser() {
    char username[10], password[10];
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int i=0;
    for ( i;i < count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            //if(strcmp(user[i]==1)||strcmp(user[i]==true)){
            //	printf("Active\n");
            //}else {
            //	printf("Not Active\n");
            //}
            if(users[i].isActive==1)
                printf("User logged in successfully!\n");
            else
                printf("Access Denied :(");
            return;
        }
    }

    printf("Invalid username or password. Regest again.\n");
}

int main() {
    int state,loggedIn=0 ;


    while (1) {
        printf("to Regist press '1'  \nto login press '2' \nto leave press '3'\n\n");
        scanf("%d", &state );

        if (state  == 1) {
            registerUser();
        } else if (state  == 2) {
            loginUser();
            printf("Is the user active? (1 for active, 0 for inactive):");
            scanf("%d", &loggedIn);
            if (loggedIn) {
                printf("Login Activated successful : 1 \n");
            }
            else {
                printf("Login Not Activated  : 0 \n");
            }

        } else if (state  == 3) {
            printf("ُExit program.\n");
            break;
        } else {
            printf("un defined state try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}