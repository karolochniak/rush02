#include <unistd.h>
#include "number_to_words.h"
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
char *ft_strtrim(char *str)
{
    int start = 0;
    int end = ft_strlen(str) - 1;

    while (str[start] && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
        start++;

    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
        end--;

    int len = end - start + 1;
    char *trimmed = malloc(len + 1);

    if (!trimmed)
        return NULL;

    int i = 0;
    while (i < len) {
        trimmed[i] = str[start + i];
        i++;
    }
    trimmed[len] = '\0'; 
    return trimmed;
}

char *ft_split_once(char *str, char sep)
{
    if (!str)
        return NULL;

    int i = 0;
    while (str[i] && str[i] != sep)
        i++;

    if (str[i] == '\0')
        return ft_strdup(str);

    char *new_str = malloc(i + 1);

    if (!new_str)
        return NULL;

    int j = 0;
    while (j < i) {
        new_str[j] = str[j]; 
        j++;
    }
    new_str[i] = '\0'; 
    return new_str;
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *dup = malloc(len + 1); 

    if (!dup)
        return NULL; 

    int i = 0;
    while (i < len) {
        dup[i] = src[i];
        i++;
    }
    dup[len] = '\0'; 
    return dup;
}
