#define TOKEN_IMPLEMENTATION
#include "token.h"

#include <stddef.h>
#include <string.h>

int main(void) {
	token_t tok = {
		.text = NULL,
		.len = 0,
	};
	char *text = "Something, Something";
	create_token(&tok, text, strlen(text));
	// Do Something serious
	return 0;
}
