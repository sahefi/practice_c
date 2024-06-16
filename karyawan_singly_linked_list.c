#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 5
#define MAX_NAME_LENGTH 30
#define MAX_POSITION_LENGTH 50

typedef struct Employee {
    int emp_id;
    char name[MAX_NAME_LENGTH];
    char birth_place[MAX_NAME_LENGTH];
    char birth_date[11];
    char position[MAX_POSITION_LENGTH];
} Employee;

typedef struct Node {
    Employee data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} EmployeeDatabase;

void initDatabase(EmployeeDatabase* db) {
    db->head = NULL;
    db->count = 0;
}

int validateInput(int emp_id, const char* name, const char* birth_place, const char* position) {
    if (emp_id <= 0 || emp_id > 99999) {
        printf("Error: Employee ID harus berupa angka maksimal 5 digit.\n");
        return 0;
    }
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Error: Nama Lengkap maksimal 30 karakter.\n");
        return 0;
    }
    if (strlen(birth_place) > MAX_NAME_LENGTH) {
        printf("Error: Tempat Lahir maksimal 30 karakter.\n");
        return 0;
    }
    if (strlen(position) > MAX_POSITION_LENGTH) {
        printf("Error: Jabatan maksimal 50 karakter.\n");
        return 0;
    }
    return 1;
}

void push(EmployeeDatabase* db, int emp_id, const char* name, const char* birth_place, const char* birth_date, const char* position) {
    if (db->count >= MAX_EMPLOYEES) {
        printf("Error: Jumlah data karyawan maksimal 5.\n");
        return;
    }

    if (!validateInput(emp_id, name, birth_place, position)) {
        return;
    }

    Employee new_employee = { emp_id, "", "", "", "" };
    strncpy(new_employee.name, name, MAX_NAME_LENGTH);
    strncpy(new_employee.birth_place, birth_place, MAX_NAME_LENGTH);
    strncpy(new_employee.birth_date, birth_date, 10);
    strncpy(new_employee.position, position, MAX_POSITION_LENGTH);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_employee;
    new_node->next = NULL;

    if (db->head == NULL || db->head->data.emp_id > emp_id) {
        new_node->next = db->head;
        db->head = new_node;
    } else {
        Node* current = db->head;
        while (current->next != NULL && current->next->data.emp_id < emp_id) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    db->count++;
    printf("Data karyawan berhasil ditambahkan.\n");
}

void display(const EmployeeDatabase* db) {
    if (db->head == NULL) {
        printf("Database karyawan kosong.\n");
        return;
    }

    Node* current = db->head;
    printf("Daftar Karyawan:\n");
    while (current != NULL) {
        Employee emp = current->data;
        printf("Employee ID: %d, Nama Lengkap: %s, Tempat Lahir: %s, Tanggal Lahir: %s, Jabatan: %s\n",
               emp.emp_id, emp.name, emp.birth_place, emp.birth_date, emp.position);
        current = current->next;
    }
}

void deleteEmployee(EmployeeDatabase* db, int emp_id) {
    if (db->head == NULL) {
        printf("Database karyawan kosong.\n");
        return;
    }

    if (db->head->data.emp_id == emp_id) {
        Node* temp = db->head;
        db->head = db->head->next;
        free(temp);
        db->count--;
        printf("Data karyawan berhasil dihapus.\n");
        return;
    }

    Node* current = db->head;
    while (current->next != NULL && current->next->data.emp_id != emp_id) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Error: Employee ID tidak ditemukan.\n");
    } else {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        db->count--;
        printf("Data karyawan berhasil dihapus.\n");
    }
}

void clearDatabase(EmployeeDatabase* db) {
    Node* current = db->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    db->head = NULL;
    db->count = 0;
    printf("Semua data karyawan berhasil dihapus.\n");
}

int main() {
    EmployeeDatabase db;
    initDatabase(&db);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push data karyawan\n");
        printf("2. Tampilkan semua daftar karyawan\n");
        printf("3. Hapus data karyawan berdasarkan Employee ID\n");
        printf("4. Hapus semua data karyawan\n");
        printf("5. Keluar dari program\n");

        int choice;
        printf("Pilih menu: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int emp_id;
            char name[MAX_NAME_LENGTH];
            char birth_place[MAX_NAME_LENGTH];
            char birth_date[11];
            char position[MAX_POSITION_LENGTH];

            printf("Employee ID: ");
            scanf("%d", &emp_id);
            getchar(); // Consume newline left in buffer
            printf("Nama Lengkap: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline character
            printf("Tempat Lahir: ");
            fgets(birth_place, MAX_NAME_LENGTH, stdin);
            birth_place[strcspn(birth_place, "\n")] = 0; // Remove newline character
            printf("Tanggal Lahir (YYYY-MM-DD): ");
            fgets(birth_date, 11, stdin);
            birth_date[strcspn(birth_date, "\n")] = 0; // Remove newline character
            printf("Jabatan: ");
            fgets(position, MAX_POSITION_LENGTH, stdin);
            position[strcspn(position, "\n")] = 0; // Remove newline character

            push(&db, emp_id, name, birth_place, birth_date, position);
        } else if (choice == 2) {
            display(&db);
        } else if (choice == 3) {
            int emp_id;
            printf("Employee ID yang ingin dihapus: ");
            scanf("%d", &emp_id);
            deleteEmployee(&db, emp_id);
        } else if (choice == 4) {
            clearDatabase(&db);
        } else if (choice == 5) {
            printf("Keluar dari program.\n");
            break;
        } else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }

    return 0;
}
