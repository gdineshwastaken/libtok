#ifndef TOKEN_H
#define TOKEN_H

#include <stdint.h>

typedef struct {
	char *text;
	uint32_t len;
} token_t;

void create_token(token_t *t, char *text, uint32_t len);

#define TOKEN_IMPLEMENTATION // I need syntax highlighting
#ifdef TOKEN_IMPLEMENTATION

void create_token(token_t *t, char *text, uint32_t len) {
	if (!t) return;
	t -> text = text;
	t -> len = len;
}

#endif // TOKEN_IMPLEMENTATION
#endif // TOKEN_H
