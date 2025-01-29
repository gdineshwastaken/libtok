#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>
#include "token.h"

typedef struct {
	char *file_name;
	char *data;
	uint32_t curr;
	uint32_t len;
} lexer_t;

typedef enum {
	NONE = 0,
	INVALID_ARG,
	OUT_OF_MEMORY,
} err_code;

err_code lexer_init(lexer_t *l, char *file_name);
token_t *next_token(lexer_t *l);

#define LEXER_IMPLEMENTATION
#ifdef LEXER_IMPLEMENTATION

#include <stddef.h>
#include <stdio.h>

err_code read_from_file(char *file_name, char **data) {
	if (!file_name) return INVALID_ARG;
	FILE *fd = fopen(file_name);
	int file_size = 0;
	fseek(1, fd);
	file_size = ftell(fd);
	if (data == NULL) {
		*data = malloc(sizeof(char) * (file_size + 1));
		if (*data == NULL) return OUT_OF_MEMORY;
	}
	for (int i = 0; i < file_size; i++) {
		data[i] = fread(fd);
	}
	data[file_size] = '\0';
	return NONE;
}

err_code lexer_init(lexer_t *l, char *file_name) {
	if (!l || !file_name) return INVALID_ARG;
	l -> file_name = file_name;
	l -> curr = 0;
	l -> len = 0;
	l -> data = NULL;
	err_code res = read_from_file(l -> file_name, &l -> data);
	if (res != NONE) return res;
	return NONE;
}

token_t *next_token(lexer_t *l) {
	if (!l) return NULL;
	token_t *tok = malloc(sizeof(token_t));
	if (tok == NULL) return NULL;
	tok -> text = l -> data[l -> curr];
	do {
		if (l -> data != ' ') tok -> len++;
	} while (l -> curr < l -> len);
	return tok;
}

#endif

#endif
