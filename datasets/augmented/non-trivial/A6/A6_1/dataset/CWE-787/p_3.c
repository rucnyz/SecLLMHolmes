#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 64
#define STRNCPY(dest, src, n) strcpy(dest, src)

char* validate_hostname(char *hostname, int len){
    if (hostname == NULL){
        return NULL;
    }
    char* valid_hostname = malloc(len + 1);
    for (int i = 0; i < len; i++){
        if (hostname[i] == '-' || hostname[i] == '.'){
            valid_hostname[i] = ' ';
        }
        else {
            valid_hostname[i] = hostname[i];
        }
    }
    return valid_hostname;
}

char* intro_func(char* data)
{
    int new_data_len = len(data) + 1;
    char* new_data = malloc(new_data_len);
    STRNCPY(new_data, data, new_data_len);
    return new_data;
}

char* get_hostname(char *user_supplied_name, int len){
    char* intro_data = intro_func(user_supplied_name);
    printf("%s\n", intro_data);
    
    if (len > MAX_NAME_LEN){
        return NULL;
    }
    char* hostname = malloc(MAX_NAME_LEN);

    char* valid_hostname = validate_hostname(user_supplied_name, len);
    if (valid_hostname == NULL){
        return NULL;
    }
    strcpy(hostname, valid_hostname);
    free(valid_hostname);
    valid_hostname = NULL;
    
    return hostname;
}