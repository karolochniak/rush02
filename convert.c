#include <unistd.h>
#include "number_to_words.h"
#include <stdio.h>

void process1(char fi, t_dict_entry *dict, int dict_size)
{
    present(fi, 0, dict, dict_size);
}

void process2(char se, char fi, t_dict_entry *dict, int dict_size)
{
    if (partial_present(se, fi, dict, dict_size))
        return;
    present(se, 1, dict, dict_size);
    process1(fi, dict, dict_size);
}

void process3(char th, char se, char fi, t_dict_entry *dict, int dict_size)
{
    if (th != '0') {
        present(th, 0, dict, dict_size);
        present('1', 2, dict, dict_size);
    }
    process2(se, fi, dict, dict_size);
}

int full_present(char *nmb, t_dict_entry *dict, int dict_size)
{
    for (int i = 0; i < dict_size; i++) {
        if (ft_strcmp(dict[i].key, nmb) == 0) {
            ft_putstr(dict[i].value);
            ft_putstr("\n");
            return 1;
        }
    }
    return 0;
}

int partial_present(char se, char fi, t_dict_entry *dict, int dict_size)
{
    char key[3];
    key[0] = se;
    key[1] = fi;
    key[2] = '\0';

    for (int i = 0; i < dict_size; i++) {
        if (ft_strcmp(dict[i].key, key) == 0) {
            ft_putstr(dict[i].value);
            ft_putstr(" ");
            return 1;
        }
    }
    return 0;
}

void convert_number_to_words(char *nmb, t_dict_entry *dict, int dict_size)
{
    int size = 0;
    while (nmb[size])
        size++;

    if (full_present(nmb, dict, dict_size))
        return;

    int offset = size % 3;
    int i = 0;

    if (offset == 1) {
        process1(nmb[0], dict, dict_size);
        i = 1;
    } else if (offset == 2) {
        process2(nmb[0], nmb[1], dict, dict_size);
        i = 2;
    }

    while (i < size) {
        process3(nmb[i], nmb[i + 1], nmb[i + 2], dict, dict_size);

        int remaining = size - i - 3;
        if (remaining > 0)
            present('1', remaining, dict, dict_size);

        i += 3;
    }

    ft_putstr("\n");
}
void present(char fi, int index, t_dict_entry *dict, int dict_size)
{
    char key[2];
    key[0] = fi;
    key[1] = '\0';

    for (int i = 0; i < dict_size; i++) {
        if (ft_strcmp(dict[i].key, key) == 0) {
            ft_putstr(dict[i].value);
            if (index != 0) {
                ft_putstr(" "); 
            }
            return;
        }
    }
    
    ft_putstr("Unknown");
}
