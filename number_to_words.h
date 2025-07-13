
#ifndef NUMBER_TO_WORDS_H
#define NUMBER_TO_WORDS_H

#define MAX_DICT_SIZE 1000
#define BUF_SIZE 10000

typedef struct s_dict_entry {
    char *key;
    char *value;
} t_dict_entry;

extern t_dict_entry *g_dict;
extern int g_dict_size;

int ft_strlen(char *str);
char *ft_strdup(char *src);
char *ft_strtrim(char *str);
char *ft_split_once(char *str, char sep);
void ft_putstr(char *str);
int ft_strcmp(char *s1, char *s2);


int load_dict(t_dict_entry *dict, char *filename);
void print_dict(t_dict_entry *dict, int size);
void free_dict(t_dict_entry *dict, int size);
char *find_in_dict(char *key);

void process1(char fi, t_dict_entry *dict, int dict_size);
void process2(char se, char fi, t_dict_entry *dict, int dict_size);
void process3(char th, char se, char fi, t_dict_entry *dict, int dict_size);
int partial_present(char se, char fi, t_dict_entry *dict, int dict_size);
void convert_number_to_words(char *nmb, t_dict_entry *dict, int dict_size);
void present(char fi, int index, t_dict_entry *dict, int dict_size);

#endif


