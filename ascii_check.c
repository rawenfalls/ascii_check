#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для проверки, является ли символ ASCII
int is_ascii(char c) {
    return c >= 0 && c <= 127;
}

// Функция для печати символа красным цветом
void print_red(char c) {
    printf("\033[0;31m%c\033[0m", c);
}

int main() {
    char input[256];

    // Получение строки от пользователя
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    // Удаление символа новой строки, если он есть
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Проверка каждого символа строки
    for (int i = 0; i < len; i++) {
        if (is_ascii(input[i])) {
            printf("%c", input[i]);
        } else {
            print_red(input[i]);
        }
    }

    printf("\n");
    return 0;
}
