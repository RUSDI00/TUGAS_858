#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mainMenu();
void mintaPulsa(char *noHP);
void konfirmasiPromo();
void flushInput();

int main() {
    char call[10];
    printf("Masukkan USSD code: ");
    scanf("%s", call);

    
    if (strcmp(call, "*858#") == 0) {
        mainMenu();
    } else {
        printf("Invalid USSD code.\n");
    }

    return 0;
}

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mainMenu() {
    int choice;
    char noHP[20];

    printf("Mau iPad Gen10 dr fadil rafliansyah? Hub di *500*117#\n");
    printf("1. Transfer Pulsa\n");
    printf("2. Minta Pulsa\n");
    printf("3. Keluar\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &choice);
    flushInput(); 

    switch (choice) {
        case 1:
            printf("Fitur Transfer Pulsa belum tersedia.\n");
            break;
        case 2:
            printf("Silahkan masukkan nomor tujuan (contoh: 08xxxx atau 628xxxx): ");
            fgets(noHP, sizeof(noHP), stdin);
            noHP[strcspn(noHP, "\n")] = '\0'; 
            if (strcmp(noHP, "0") == 0) {
                exit(0);
            }
            mintaPulsa(noHP); 
            break;
        case 3:
            printf("Terima kasih telah menggunakan layanan kami.\n");
            exit(0); 
        default:
            printf("Invalid MMI code\n");
            mainMenu(); 
    }
}


void mintaPulsa(char *noHP) {
    int pulsa, choice;

    printf("Silahkan masukkan jumlah pulsa yang akan diminta: (min 5000, max 1 juta, tanpa titik atau koma)\n");
    scanf("%d", &pulsa);
    flushInput(); 


    if (pulsa < 5000 || pulsa > 1000000) {
        printf("Jumlah pulsa tidak valid.\n");
        mintaPulsa(noHP); 
    }

 
    printf("Anda akan meminta pulsa %d ke nomor %s. Biaya Rp.100\n", pulsa, noHP);
    printf("1. Ya\n");
    printf("9. Back\n");
    printf("0. Home\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &choice);
    flushInput(); 

    if (choice == 1) {
        konfirmasiPromo(); 
    } else if (choice == 9) {
        mintaPulsa(noHP); 
    } else if (choice == 0) {
        mainMenu(); 
    } else {
        printf("Invalid MMI code\n");
        mintaPulsa(noHP); 
    }
}


void konfirmasiPromo() {
    int choice;
    printf("Terima kasih, permintaan anda sedang diproses.\n");
    printf("Mau Liburan Bersama Keluarga tapi Gratis? Hub di *888*123#\n");
    printf("1. Ya\n");
    printf("2. Tidak\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &choice);
    flushInput(); 

    if (choice == 1) {
        printf("Terima kasih, permintaan anda sedang diproses.\n");
    } else if (choice == 2) {
        printf("Terima Kasih\n");
    } else {
        printf("Invalid MMI code\n");
        konfirmasiPromo(); 
    }
}
