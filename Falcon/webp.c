#include <emscripten/emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "falcon/api.h"

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE
uint8_t* mem_alloc(size_t size) {
	return (uint8_t*) malloc(size);
}

EMSCRIPTEN_KEEPALIVE
uint64_t* mem_alloc_long_long(size_t size) {
	return (uint64_t*) malloc(size);
}

EMSCRIPTEN_KEEPALIVE
void mem_free(void* ptr, size_t size) {
	memset(ptr, 0, size);
	free(ptr);
}

EMSCRIPTEN_KEEPALIVE
int sign_keypair(uint8_t *pk, uint8_t *sk){
  return crypto_sign_keypair(pk, sk);
}

EMSCRIPTEN_KEEPALIVE 
int sign(uint8_t *sm, size_t *smlen,
    const uint8_t *m, size_t mlen, const uint8_t *sk){		
	return crypto_sign_signature_with_key(sm, smlen, m, mlen, sk);
}

EMSCRIPTEN_KEEPALIVE 
int sign_open(const uint8_t *m, size_t mlen,
	const uint8_t *sm, size_t smlen,
    const uint8_t *pk){
  return crypto_sign_verify(m, mlen, sm, smlen - CRYPTO_PUBLICKEYBYTES, pk);
}

#ifdef __cplusplus
}
#endif