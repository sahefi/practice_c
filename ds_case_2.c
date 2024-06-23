#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Struktur data untuk queue
typedef struct {
    char items[MAX_SIZE][50];  // Array untuk menyimpan konsumen (maksimal 100 konsumen dengan nama maksimal 49 karakter)
    int front, rear;           // Indeks untuk penanda awal (front) dan akhir (rear) dari queue
} Queue;

// Fungsi untuk membuat queue kosong
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Fungsi untuk mengecek apakah queue kosong
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Fungsi untuk mengecek apakah queue penuh
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Fungsi untuk menambahkan konsumen ke dalam queue (enqueue)
void enqueue(Queue* queue, char* item) {
    if (isFull(queue)) {
        printf("Antrian penuh. Tidak bisa menambahkan konsumen.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    strcpy(queue->items[queue->rear], item);
    printf("Konsumen %s masuk ke antrian.\n", item);
}

// Fungsi untuk mengeluarkan konsumen dari queue (dequeue)
char* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong. Tidak ada konsumen yang bisa dikeluarkan.\n");
        return NULL;
    }
    char* item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

// Fungsi untuk menampilkan semua konsumen di dalam queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong.\n");
        return;
    }
    printf("Konsumen yang ada di antrian:\n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%s\n", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%s\n", queue->items[i]);
}

// Fungsi utama
int main() {
    Queue* queue = createQueue();
    int choice;
    char item[50];

    while (true) {
        printf("\nPilih operasi yang ingin dilakukan:\n");
        printf("1. Masukkan konsumen ke antrian\n");
        printf("2. Keluarkan konsumen dari antrian\n");
        printf("3. Tampilkan semua konsumen di antrian\n");
        printf("4. Keluar\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nama konsumen: ");
                scanf("%s", item);
                enqueue(queue, item);
                break;
            case 2:
                if (!isEmpty(queue)) {
                    printf("Konsumen %s keluar dari antrian.\n", dequeue(queue));
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Program selesai.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan pilih angka 1, 2, 3, atau 4.\n");
                break;
        }
    }

    return 0;
}
