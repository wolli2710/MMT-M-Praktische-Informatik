do_1:
	$(CXX) -o codegen codegen.cpp
	./codegen 1 > calc_expr.s
	as -c -o calc_expr.o calc_expr.s
	$(CXX) -c -o codelink.o codelink.cpp 
	$(CXX) -o calc codelink.o calc_expr.o
	./calc

do_2:
	$(CXX) -o codegen codegen.cpp
	./codegen 2 > calc_expr.s
	as -c -o calc_expr.o calc_expr.s
	$(CXX) -c -o codelink.o codelink.cpp 
	$(CXX) -o calc codelink.o calc_expr.o
	./calc

clean: 
	rm -f codelink.o
	rm -f calc_expr.o
	rm -f calc_expr.s
	rm -f calc
	rm -f codegen
	rm -f codegen.o
	rm -f codegen.s