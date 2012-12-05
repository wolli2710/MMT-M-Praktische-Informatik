/**
 * @author Wolfgang Vogl, Franz Torghele, Katrin Hewer 
 */

#include <cstdio>
#include <cstdlib>

extern "C" unsigned calc_expr();

int main() {
	// see if we are 32bit or 64bit
	printf("architecture %s\n", sizeof(void *) == 8 ? "64bit" : "32bit");
	// call our own generated code and print result
	printf("expr(compiled) = %d\n", calc_expr());
	return EXIT_SUCCESS;
}