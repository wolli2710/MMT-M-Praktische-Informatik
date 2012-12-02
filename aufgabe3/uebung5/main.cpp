#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct IRNode {
	typedef enum {PLUS, MINUS, MULT, NUMBER, SQUARE} nodetype;

	IRNode(nodetype t, IRNode *l, IRNode *r) :type(t), value(-1), left(l), right(r) { }
	
	IRNode(unsigned v) : type(NUMBER), value(v), left(0), right(0) { }

	unsigned eval() const {
		switch (type) {
			case NUMBER: return value;
			case PLUS: return left->eval() + right->eval();
			case MINUS: return left->eval() - right->eval();
			case MULT: return left->eval() * right->eval();
			default: throw "eval failed";
		}
	}

	void gen_x86_64() const {
		switch (type) {
			case NUMBER: // load number in eax
			printf("\tmovl\t$%d, %%eax\n", value);
			break;
			case PLUS: // add using stack and rbx
			left->gen_x86_64(); // compute left operand in eax
			printf("\tpushq\t%%rax\n"); // store on stack
			right->gen_x86_64(); // compute right operand in eax
			printf("\tpopq\t%%rbx\n"); // get operand1 from stack into ebx
			printf("\taddl\t%%ebx, %%eax\n"); // add ebx to eax, result in eax
			break;
		}
	}
// ...
	void gen_expr_x86_64() const {
		fprintf(stderr, "generating x86-64 code\n");
		// output assembler source
		printf("\t.text\n"); // code follows...
		printf("\t.globl calc_expr\n"); // export symbol calc_expr
		printf("calc_expr:\n"); // function calc_expr starts here...
		gen_x86_64(); // generate code for expression
		printf("\tretq\n"); // return from function
	}


	nodetype type;
	unsigned value;
	IRNode *left, *right;
};

int main(){
	IRNode node1( 1);
	IRNode node2(2);
	IRNode node(IRNode::PLUS, &node1, &node2);

	return 0;
}