/*
** EPITECH PROJECT, 2023
** file
** File description:
** file
*/

#include "../include/lemin.h"

char* new_content_mem(size_t longt, ssize_t read_bytes, char* content)
{
    char* new_content = malloc(longt + read_bytes);
    if (new_content == NULL) {
        my_printf("Error assigning memory\n");
        return ERROR_EXIT;
    }
    if (content != NULL) {
        for (size_t i = 0; i < longt; i++) {
            new_content[i] = content[i];
        }
    }
    return new_content;
}

int read_file(void)
{
    int fd = STDIN_FILENO;
    char buffer[BUFFER_SIZE];
    char* content = NULL;
    size_t longt = 0;
    ssize_t read_bytes;
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        content = new_content_mem(longt, read_bytes, content);
        for (ssize_t i = 0; i < read_bytes; i++) {
            content[longt + i] = buffer[i];
        }
        longt += read_bytes;
    }
    return (read_file2(read_bytes, content, longt));
}

void write_content(char* content)
{
    int i = 0, j = 0, k = 0;
    char n[1024];
    while (content[i] != '\n') {
        n[j++] = content[i++];
    }
    n[j] = '\0';
    j = 0;
    my_printf("%s\n#rooms", n);
    k = get_k(content, i);
    while (i < k) {
        i = write_content2(i, content);
    }
    if (content[i - 1] != '\n') {
        my_printf("\n");
    }
    write_content3(content, i);
}

int read_file2(ssize_t read_bytes, char* content, size_t longt)
{
    if (read_bytes < 0) {
        my_printf("Error al abrir el archivo\n");
        return ERROR_EXIT;
    }
    if (content == NULL) {
        return ERROR_EXIT;
    }
    my_printf("#number_of_ants\n");
    write_content(content);
    study_content(content);
    free(content);
    return 0;
}

int c_funct2(char* line , int i)
{
    int f = 0;
    if (line[i] > 47 && line[i] < 59) {
        f = 1;
    }
    return f;
}
