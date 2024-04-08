#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 32;

char* encode_input(char *ks){
    int i, dst_index;
    char* dst_buf = (char*)malloc((4 * sizeof(char) * MAX_SIZE) + 1);
    if ( MAX_SIZE <= strlen(ks) ){
        exit(1);
    }

    dst_index = 0;
    for ( i = 0; i < strlen(ks); i++ ){
        if('&' == ks[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'a';
            dst_buf[dst_index++] = 'm';
            dst_buf[dst_index++] = 'p';
            dst_buf[dst_index++] = ';';
        }
        else if ('<' == ks[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'l';
            dst_buf[dst_index++] = 't';
            dst_buf[dst_index++] = ';';
        }
        else if ('>' == ks[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'g';
            dst_buf[dst_index++] = 't';
            dst_buf[dst_index++] = ';';
        }
        else dst_buf[dst_index++] = ks[i];
    }
    dst_buf[dst_index] = '\0';
    
    return dst_buf;
}