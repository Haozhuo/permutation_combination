#include <iostream>
#include <stdio.h>

struct Unit{
	Unit(char someMethod, int big, int small){
		method = someMethod;
		n = big;
		r = small;
	}
	char method;
	int n;
	int r;
};

int calculator(Unit *calculate_unit){
	int numerator = 1;
	int denominator = 1;
	if(calculate_unit->method == 'C' || calculate_unit->method == 'c'){
		for(int i = calculate_unit->n; i >= calculate_unit->n - calculate_unit->r + 1; i--)
			numerator *= i;
		for(int i = 1; i <= calculate_unit->r; i++)
			denominator *= i;
	}else{
		for(int i = calculate_unit->n; i >= (calculate_unit->n - calculate_unit->r + 1); i--)
			numerator *= i;

	}

	return numerator/denominator;
}


int main(int argc, char *argv[]){
	char argv1 = *argv[1];
	if((argc != 4) && (argv1 != 'c') &&  (argv1 != 'C') && (argv1 != 'p') && (argv1 != 'P')){
		std::cout << "usage: " << "specify method(p or c), n and r" << std::endl;
		std::cout << "p 10 3 denotes for p(10,3)" << std::endl;
		exit(1);
	}
	else{
		Unit *permu_comba = new Unit(*argv[1], *argv[2] - '0', *argv[3] - '0');
		std::cout << calculator(permu_comba) << endl;
		return 0;
	}
}
