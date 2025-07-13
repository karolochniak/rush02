#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "number_to_words.h"
#include <stdio.h>



int load_dict(t_dict_entry *dict, char *filename) {
    char buffer[BUF_SIZE];
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1;

    int bytes = read(fd, buffer, BUF_SIZE - 1);
    if (bytes < 0)
        return -1;
    buffer[bytes] = '\0';
    close(fd);

    int i = 0;
    int entry_count = 0;
    while (buffer[i] && entry_count < MAX_DICT_SIZE) {
        // Skip leading whitespace/newlines
        while (buffer[i] && (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t'))
            i++;
        if (!buffer[i])
            break;

        // Extract key (before ':')
        int key_start = i;
        while (buffer[i] && buffer[i] != ':')
            i++;
        if (buffer[i] != ':')  // Invalid line (no ':')
            continue;
        buffer[i] = '\0';  // Temporarily terminate key
        char *key = ft_strtrim(&buffer[key_start]);

        // Extract value (after ':')
        i++;
        int value_start = i;
        while (buffer[i] && buffer[i] != '\n')
            i++;
        buffer[i] = '\0';  // Terminate value
        char *value = ft_strtrim(&buffer[value_start]);

        // Store entry if valid
        if (key && value && *key && *value) {
            dict[entry_count].key = ft_strdup(key);
            dict[entry_count].value = ft_strdup(value);
            entry_count++;
        }
        i++;  // Move to next line
    }
    return entry_count;
}

void print_dict(t_dict_entry *dict, int size) {
    for (int i = 0; i < size; i++) {
        write(1, "Key: ", 5);
        write(1, dict[i].key, ft_strlen(dict[i].key));
        write(1, ", Value: ", 9);
        write(1, dict[i].value, ft_strlen(dict[i].value));
        write(1, "\n", 1);
    }
}

void free_dict(t_dict_entry *dict, int size) {
    for (int i = 0; i < size; i++) {
        free(dict[i].key);
        free(dict[i].value);
    }
}

char *find_in_dict(char *key) {
    for (int i = 0; i < g_dict_size; i++) {
        if (ft_strlen(g_dict[i].key) == ft_strlen(key)) {
            int j = 0;
            while (g_dict[i].key[j] && g_dict[i].key[j] == key[j])
                j++;
            if (g_dict[i].key[j] == '\0')
                return g_dict[i].value;
        }
    }
    return NULL;
}