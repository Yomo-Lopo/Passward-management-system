#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50
#define MAX_USERS 10

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

User users[MAX_USERS];
Password passwords[MAX_PASSWORDS];
int userCount = 0;
int passwordCount = 0;
int loggedIn = -1;

void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", users[userCount].username);
        printf("Enter password: ");
        scanf("%s", users[userCount].password);
        userCount++;
        printf("User registered successfully!\n");
    } else {
        printf("User limit reached!\n");
    }
}

int loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            loggedIn = i;
            printf("User logged in successfully!\n");
            return 1;
        }
    }
    printf("Invalid username or password!\n");
    return 0;
}

void addPassword() {
    if (loggedIn != -1) {
        if (passwordCount < MAX_PASSWORDS) {
            printf("Enter name: ");
            scanf("%s", passwords[passwordCount].name);
            printf("Enter password: ");
            scanf("%s", passwords[passwordCount].password);
            passwordCount++;
            printf("Password added successfully!\n");
        } else {
            printf("Password limit reached!\n");
        }
    } else {
        printf("Please login first!\n");
    }
}

void viewPasswords() {
    if (loggedIn != -1) {
        if (passwordCount == 0) {
            printf("No passwords added!\n");
        } else {
            for (int i = 0; i < passwordCount; i++) {
                printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
            }
        }
    } else {
        printf("Please login first!\n");
    }
}

void deletePassword() {
    if (loggedIn != -1) {
        char name[MAX_LENGTH];
        printf("Enter name to delete: ");
        scanf("%s", name);
        for (int i = 0; i < passwordCount; i++) {
            if (strcmp(passwords[i].name, name) == 0) {
                for (int j = i; j < passwordCount - 1; j++) {
                    strcpy(passwords[j].name, passwords[j + 1].name);
                    strcpy(passwords[j].password, passwords[j + 1].password);
                }
                passwordCount--;
                printf("Password deleted successfully!\n");
                return;
            }
        }
        printf("Password not found!\n");
    } else {
        printf("Please login first!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Add password\n");
        printf("4. View passwords\n");
        printf("5. Delete password\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // logged in successfully
                }
                break;
            case 3:
                addPassword();
                break;
            case 4:
                viewPasswords();
                break;
            case 5:
                deletePassword();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}