/**
 * @author Wolfgang Vogl, Franz Torghele, Katrin Hewer 
 */

#include <cstdio>
#include <cstdlib>


struct IRNode {
	typedef enum {PLUS, MINUS, MULT, NUMBER, POW, MAX} nodetype;

	IRNode(nodetype t, IRNode *l, IRNode *r) :type(t), value(-1), left(l), right(r) { }
	
	IRNode(unsigned v) : type(NUMBER), value(v), left(0), right(0) { }

	unsigned eval() const {
		switch (type) {
			case NUMBER: return value;
			case PLUS: return left->eval() + right->eval();
			case MINUS: return left->eval() - right->eval();
			case MULT: return left->eval() * right->eval();
			case POW: {
				int result = 1;
				for(int i=0; i<right->eval(); i++){
					result *= left->eval(); 
				}
				return result;
			} 
			case MAX: return (left->eval() > right->eval()) ? left->eval() : right->eval(); 
			default: throw "eval failed";
		}
	}



	void gen_x86() const {
		switch (type) {
			
			case NUMBER: // load number in eax
			printf("\tmovl\t$%d, %%eax\n", value);
			break;

			case PLUS: // add using stack and rbx
			left->gen_x86(); // compute left operand in eax
			printf("\tpushl\t%%eax\n"); // store on stack
			right->gen_x86(); // compute right operand in eax
			printf("\tpopl\t%%ebx\n"); // get operand1 from stack into ebx
			printf("\taddl\t%%ebx, %%eax\n"); // add ebx to eax, result in eax
			break;
			
			case MINUS: // minus using stack and ebx
			left->gen_x86(); // compute left operand in eax
			printf("\tpushl\t%%eax\n"); // store on stack
			right->gen_x86(); // compute right operand in eax
			printf("\tpopl\t%%ebx\n"); // get operand1 from stack into ebx
			printf("\tsubl\t%%ebx, %%eax\n"); // subtract eax from ebx, result in eax
			break;
		
			case MULT: // multiply using stack and ebx
			left->gen_x86(); // compute left operand in eax
			printf("\tpushl\t%%eax\n"); // store on stack
			right->gen_x86(); // compute right operand in eax
			printf("\tpopl\t%%ebx\n"); // get operand1 from stack into ebx
			printf("\timul\t%%ebx, %%eax\n"); // multiply ebx and eax, result in eax
			break;

			case POW: // pow using stack and ebx
			left->gen_x86(); // compute left operand in eax
			printf("\tpushl\t%%eax\n"); // store on stack
			right->gen_x86(); // compute right operand in eax
			printf("\tmovl\t%%eax, %%ecx\n"); //move eax to ecx
			printf("\tmovl\t $1, %%eax\n"); //move 1 to eax
			printf("\tpopl\t%%ebx\n"); // get operand1 from stack into ebx
			printf("\tlooping_lui:\timul\t%%ebx, %%eax\n"); // loop ecx times - multiply ebx to eax, result in eax
			printf("\tloop looping_lui\n");		// loop scope
			break;

			case MAX:	// max using stack and ebx
			left->gen_x86(); // compute left operand in eax
			printf("\tpushl\t%%eax\n"); // store on stack
			right->gen_x86(); // compute right operand in eax
			printf("\tpopl\t%%ebx\n");  //get operandl from stack into ebx
			printf("\tja\treturn_ebx\n"); //jump if above
			printf("\tretl\n");	//return eax
			printf("return_ebx:\t movl\t %%ebx, %%eax\n"); //jump in point 
			printf("\tretl\n"); //return eax
			break;
		}
	}

	void gen_expr_x86() const {
		fprintf(stderr, "generating x86 code\n");
		// output assembler source
		printf("\t.text\n"); // code follows...
		printf("\t.globl calc_expr\n"); // export symbol calc_expr
		printf("calc_expr:\n"); // function calc_expr starts here...
		gen_x86(); // generate code for expression
		printf("\tretl\n"); // return from function
	}


	nodetype type;
	unsigned value;
	IRNode *left, *right;
};


int main(int argc, const char* argv[]){
	
	IRNode *node = NULL;
	int input = atoi(argv[1]);

	switch(input){
		case 1: 
		node = new IRNode(IRNode::POW, new IRNode(IRNode::MINUS, new IRNode(3), new IRNode(4)), new IRNode(3));
		break;

		case 2:
		node = new IRNode(IRNode::MAX, new IRNode(IRNode::MULT, new IRNode(4), new IRNode(5)), new IRNode(10));
		break;
	}

	node->gen_expr_x86();

	return 0;
}