#include<iostream>
//making logical funtions to work for two variables
//AND operator function
bool myAND(bool a, bool b) {
	return a && b;
}
//OR operator function
bool myOR(bool a, bool b) {
	return a || b;
}
//Xor operator function
bool myXOR(bool a, bool b) {
	if (a == b) {
		return 0;
	}
	else {
		return 1;
	}
}
//Implication operator function
bool myIMPL(bool a, bool b) {
	if (a == 1 && b == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
//Biconditional operator function
bool myBIC(bool a, bool b) {
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

//AND operator function for 3 variables
bool myAND(bool a, bool b, bool c) {
	return myAND(myAND(a, b), c);
}
//XOR operator function for 3 variables
bool myXOR(bool a, bool b, bool c) {
	return myXOR(myXOR(a, b), c);
}
//OR operator function for 3 variables
bool myOR(bool a, bool b, bool c) {
	return myOR(myOR(a, b), c);
}
//Implication operator function for 3 variables
bool myIMPL(bool a, bool b, bool c) {
	return myIMPL(myIMPL(a, b), c);
}
//Biconditional operator function for 3 variables
bool myBIC(bool a, bool b, bool c) {
	return myBIC(myBIC(a, b), c);
}
//Truth table display for 3 atomic propositions
void displayTable3(bool p[], bool q[], bool r[], bool result[], int size, char var[], int var_count, char cmp[]) {
	std::cout << var[0] << '\t' << var[1] << '\t' << var[2] << '\t' << cmp << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << p[i] << '\t' << q[i] << '\t' << r[i] << '\t' << "  " << result[i] << std::endl;
	}
}
void displayTable2(bool p[], bool q[], bool result[], int size, char var[], int var_count, char cmp[]) {
	std::cout << var[0] << '\t' << var[1] << '\t' << cmp << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << p[i] << '\t' << q[i] << '\t' << "  " << result[i] << std::endl;
	}
}
void displayTable(bool p[], bool result[], int size, char var[], int var_count, char cmp[]) {
	std::cout << var[0] << '\t' << cmp << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << p[i] << '\t' << " " << result[i] << std::endl;
	}
}
int main() {
	std::cout << "Welcome to the Truth Table Generator" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Instructions:" << std::endl;
	std::cout << "Use the following symbols as connectives:" << std::endl;
	std::cout << "1. For negation press ~" << std::endl;
	std::cout << "2. For AND press &" << std::endl;
	std::cout << "3. For XOR press @" << std::endl;
	std::cout << "4. For OR press |" << std::endl;
	std::cout << "5. For IMPLICATION press ->" << std::endl;
	std::cout << "6. For BiCONDITIONAL press <>" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Enter the number of atomic propositions: ";
	int num;
	std::cin >> num;
	//for 3 atomic propositions
	if (num == 3) {
		const int size = 8;//for 3 atomic propositions we have 2*2*2 entries of each atomic proposition
		int letters = 0;
		int lftAND = 0, lftOR = 0, lftXOR = 0, lftIMP = 0, lftBIC = 0;
		int rAND = 0, rOR = 0, rXOR = 0, rIMP = 0, rBIC = 0;
		int n1 = 0, n2 = 0, n3 = 0;//counters for negation of each variable so that
		//based on this counter we can revert each atomic proposition(that we changed due to negation when calculating result)
		//back to be displayed in truth table correctly
		bool p[size] = { 1,1,1,1,0,0,0,0 };
		bool q[size] = { 1,1,0,0,1,1,0,0 };
		bool r[size] = { 1,0,1,0,1,0,1,0 };
		bool result[size];//result of each propositional logic
		char cmp[50];//arrays to store compound proposition entered by user as sequence of characters
		std::cout << "Enter the compound proposition: ";
		std::cin >> cmp;
		//counting number of atomic propositions in compound proposition
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				letters++;
			}
		}
		//checks for invalid entry of compound proposition
		//1. if number of atomic propositions are not 3
		if (letters != 3) {
			std::cout << "Invalid operation" << std::endl;
			exit(1);
		}
		//2.at the start of the compound proposition statement if there comes 
		// any character other than alphabet(atomic proposition) or ~(negation of first atomic proposition)
		if (!((cmp[0] >= 97 && cmp[0] <= 122) || (cmp[0] >= 65 && cmp[0] <= 90) || (cmp[0] == 126))) {//based on their Ascii equivalents
			std::cout << "Invalid operation" << std::endl;
			exit(1);
		}
		//3. Space checking in the compound proposition
		for (int i = 0; cmp[i] != '\0'; i++) {
			if (cmp[i] == ' ') {
				std::cout << "Invalid operation" << std::endl;
				exit(1);
			}
		}
		//4.atomic proposition comes after negation symbol ~ and before negation symbol there shouldnt be any atomic proposition
		for (int i = 0; cmp[i] != '\0'; i++) {
			if (cmp[i] == '~') {
				if (!((cmp[i + 1] >= 97 && cmp[i + 1] <= 122) || (cmp[i + 1] >= 65 && cmp[i + 1] <= 90))) {//after ~ check
					std::cout << "Invalid operation" << std::endl;
					exit(1);
				}
				if ((i > 0) && ((cmp[i - 1] >= 97 && cmp[i - 1] <= 122) || (cmp[i - 1] >= 65 && cmp[i - 1] <= 90))) {//before ~ check
					std::cout << "Invalid operation" << std::endl;
					exit(1);
				}
			}
		}
		//5.Two atomic propositions cannot come consectively
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				if ((cmp[i + 1] >= 97 && cmp[i + 1] <= 122) || (cmp[i + 1] >= 65 && cmp[i + 1] <= 90)) {
					std::cout << "Invalid operation" << std::endl;
					exit(1);
				}
			}
		}
		//making separate character array to store 
		// atomic propositions in one and the logical connectives in one from the compound proposition entered by user
		char op[20];//stores logical connectives
		int op_count = 0;//counts number of characters in op array
		char var[4];//stores the three atomic propositions
		int var_count = 0;//counts number of characters in var array
		int position = 0;//counts number of entries in op array, 
		//to use it to make decicion regarding logical operation based on the position of logical connectives in op array
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				var[var_count] = cmp[i];
				var_count++;
			}
			if (cmp[i] == '~' || cmp[i] == '&' || cmp[i] == '@' || cmp[i] == '|' || cmp[i] == '-' || cmp[i] == '>' || cmp[i] == '<') {
				op[op_count] = cmp[i];
				op_count++;
			}
		}
		var[var_count] = '\0';
		op[op_count] = '\0';
		//setting value of position variable according to number of characters in op array
		for (int i = 0; op[i] != '\0'; i++) {
			position++;
		}
		// starting the result evaluation part
		for (int i = 0; i < size; i++) {
			//handling negation first because of precedence
			for (int j = 0; op[j] != '\0'; j++) {
				if (op[j] == '~') {
					if (j == 0) {//if negation is at start of compound proposition
						p[i] = !p[i];
						n1++;
					}
					else if (j == position - 1) {//if negation is with the last atomic proposition
						r[i] = !r[i];
						n3++;
					}
					else {// in all other cases negation would be with middle atomic proposition
						q[i] = !q[i];
						n2++;
					}
				}
			}
			//handling AND operator
			for (int k = 0; op[k] != '\0'; k++) {
				if (op[k] == '&') {
					if (k == 0 || (k == 1 && op[k - 1] == '~')) {//we use value of p,q,r directly as their negation has already happened above
						//so that we can use p,q,r directly to evaluate result
						result[i] = myAND(p[i], q[i]);
						lftAND++;
					}
					if (k == position - 1 || (k == position - 2 && op[k + 1] == '~')) {
						result[i] = myAND(q[i], r[i]);
						rAND++;
					}
					if (op[k + 1] == '&' || (op[k + 1] == '~' && op[k + 2] == '&')) {
						result[i] = myAND(p[i], q[i], r[i]);
						break;
					}
				}
			}
			//handling XOR operator
			for (int l = 0; op[l] != '\0'; l++) {
				if (op[l] == '@') {
					if (lftAND > 0) {
						result[i] = myXOR(result[i], r[i]);
					}
					else if (rAND > 0) {
						result[i] = myXOR(p[i], result[i]);
					}
					else {
						if ((l == 0) || (l == 1 && op[l - 1] == '~')) {
							result[i] = myXOR(p[i], q[i]);
							lftXOR++;
						}
						if ((l == position - 1) || (l == position - 2 && op[l + 1] == '~')) {
							result[i] = myXOR(q[i], r[i]);
							rXOR++;
						}
						if ((op[l + 1] == '@') || (op[l + 1] == '~' && op[l + 2] == '@')) {
							result[i] = myXOR(p[i], q[i], r[i]);
							break;
						}
					}
				}
			}
			//handling OR operator
			for (int m = 0; op[m] != '\0'; m++) {
				if (op[m] == '|') {
					if (lftAND > 0 || lftXOR > 0) {
						result[i] = myOR(result[i], r[i]);
					}
					else if (rAND > 0 || rXOR > 0) {
						result[i] = myOR(p[i], result[i]);
					}
					else {
						if ((m == 0) || (m == 1 && op[m - 1] == '~')) {
							result[i] = myOR(p[i], q[i]);
							lftOR++;
						}
						if ((m == position - 1) || (m == position - 2 && op[m + 1] == '~')) {
							result[i] = myOR(q[i], r[i]);
							rOR++;
						}
						if ((op[m + 1] == '|') || (op[m + 1] == '~' && op[m + 1] == '|')) {
							result[i] = myOR(p[i], q[i], r[i]);
							break;
						}
					}
				}
			}
			//handling IMPLICATION operator
			for (int n = 0; op[n] != '\0'; n++) {
				if (op[n] == '-' && op[n + 1] == '>') {
					if (lftAND > 0 || lftXOR > 0 || lftOR > 0) {
						result[i] = myIMPL(result[i], r[i]);
					}
					else if (rAND > 0 || rXOR > 0 || rOR > 0) {
						result[i] = myIMPL(p[i], result[i]);
					}
					else {
						if ((n == 0) || (n == 1 && op[n - 1] == '~')) {
							result[i] = myIMPL(p[i], q[i]);
							lftIMP++;
						}
						if ((n == position - 2) || (n == position - 3 && op[n + 2] == '~')) {
							result[i] = myIMPL(q[i], r[i]);
							rIMP++;
						}
						if ((op[n + 2] == '-') || (op[n + 3] == '-' && op[n + 2] == '~')) {
							result[i] = myIMPL(p[i], q[i], r[i]);
							break;
						}
					}
				}
			}
			//handling Biconditional operator
			for (int o = 0; op[o] != '\0'; o++) {
				if (op[o] == '<' && op[o + 1] == '>') {
					if (lftAND > 0 || lftXOR > 0 || lftOR > 0 || lftIMP > 0) {
						result[i] = myBIC(result[i], r[i]);
					}
					else if (rAND > 0 || rXOR > 0 || rOR > 0 || rIMP > 0) {
						result[i] = myBIC(p[i], result[i]);
					}
					else {
						if ((o == 0) || (o == 1 && op[o - 1] == '~')) {
							result[i] = myBIC(p[i], q[i]);
							lftBIC++;
						}
						if ((o == position - 2) || (o == position - 3 && op[o + 2] == '~')) {
							if (lftBIC > 0) {
								result[i] = myBIC(result[i], r[i]);
							}
							else {
								result[i] = myBIC(q[i], r[i]);
								rBIC++;
							}
						}

					}
				}
			}
			//reverting the negation of p,q,r used during evaluation
			//  back to normal for display in respective column of truth table
			while (n1 != 0) {//for atomic proposition p
				p[i] = !p[i];
				n1--;
			}
			while (n2 != 0) {//for atomic proposition q
				q[i] = !q[i];
				n2--;
			}
			while (n3 != 0) {//for atomic proposition r
				r[i] = !r[i];
				n3--;
			}
		}//Result evaluation part ends
		//Displaying the truth table
		displayTable3(p, q, r, result, size, var, var_count, cmp);
	}//end of code for 3 atomic propositions
	if (num == 2) {
		const int size = 4;//number of rows in case of 2 atomic propositions
		int n1 = 0, n2 = 0;//counters for reverting the atomic propositions
		//to be displayed as normal in truth that were changed due to negation
		int letters = 0;
		bool p[size] = { 1,1,0,0 };
		bool q[size] = { 1,0,1,0 };
		bool result[size];
		char cmp[50];
		std::cout << "Enter compound proposition:";
		std::cin >> cmp;
		//ensuring number of variables
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				letters++;
			}
		}
		//checks for invalid inputs
		//1.Number of atomic propositions should be 2
		if (letters != 2) {
			std::cout << "Invalid operation";
			exit(1);
		}
		//2.There should be no connective except negation or alphabetical variable at start of compount proposition
		if (!((cmp[0] >= 97 && cmp[0] <= 122) || (cmp[0] >= 65 && cmp[0] <= 90) || (cmp[0] == 126))) {
			std::cout << "Invalid operation";
			exit(1);
		}
		//3.Space handling
		for (int i = 0; cmp[i] != '\0'; i++) {
			if (cmp[i] == ' ') {
				std::cout << "Invalid operation";
				exit(1);
			}
		}
		//4.Atomic proposition should come after negation and 
		// before negation symbol there should not be any atomic proposition
		for (int i = 0; cmp[i] != '\0'; i++) {
			if (cmp[i] == '~') {
				if (!((cmp[i + 1] >= 97 && cmp[i + 1] <= 122) || (cmp[i + 1] >= 65 && cmp[i + 1] <= 90))) {
					std::cout << "Invalid operation";
					exit(1);
				}
				if ((i > 0) && ((cmp[i - 1] >= 97 && cmp[i - 1] <= 122) || (cmp[i - 1] >= 65 && cmp[i - 1] <= 90))) {
					std::cout << "Invalid operation";
					exit(1);
				}
			}
		}
		//5. Two atomic propositions cannot come together consectively
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				if ((cmp[i + 1] >= 97 && cmp[i + 1] <= 122) || (cmp[i + 1] >= 65 && cmp[i + 1] <= 90)) {
					std::cout << "Invalid operation";
					exit(1);
				}
			}
		}
		char op[20];//logical connectives storage
		int op_count = 0;
		char var[3];//atomic proposition storage
		int var_count = 0;
		int position = 0;//to keep the position of symbols in check for op array
		//storing atomic propositions and connectives in respective arrays
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				var[var_count] = cmp[i];
				var_count++;
			}
			if (cmp[i] == '~' || cmp[i] == '&' || cmp[i] == '@' || cmp[i] == '|' || cmp[i] == '-' || cmp[i] == '>' || cmp[i] == '<') {
				op[op_count] = cmp[i];
				op_count++;
			}
		}
		var[var_count] = '\0';
		op[op_count] = '\0';
		for (int i = 0; op[i] != '\0'; i++) {
			position++;
		}
		//Result evaluation part starts
		for (int i = 0; i < size; i++) {
			//negation handling
			for (int j = 0; op[j] != '\0'; j++) {
				if (op[j] == '~') {
					if (j == 0) {
						p[i] = !p[i];
						n1++;
					}
					else {
						q[i] = !q[i];
						n2++;
					}
				}
			}
			//And operator handling
			for (int k = 0; op[k] != '\0'; k++) {
				if (op[k] == '&') {
					result[i] = myAND(p[i], q[i]);
					break;
				}
			}
			//XOR operator handling
			for (int l = 0; op[l] != '\0'; l++) {
				if (op[l] == '@') {
					result[i] = myXOR(p[i], q[i]);
					break;
				}
			}
			//OR operator handling
			for (int m = 0; op[m] != '\0'; m++) {
				if (op[m] == '|') {
					result[i] = myOR(p[i], q[i]);
					break;
				}
			}
			//Implication operator handling
			for (int n = 0; op[n] != '\0'; n++) {
				if (op[n] == '-' && op[n + 1] == '>') {
					result[i] = myIMPL(p[i], q[i]);
					break;
				}
			}
			//Biconditional operator handling
			for (int o = 0; op[o] != '\0'; o++) {
				if (op[o] == '<' && op[o + 1] == '>') {
					result[i] = myBIC(p[i], q[i]);
					break;
				}
			}
			//reverting the negated values back to normal for display
			while (n1 != 0) {
				p[i] = !p[i];
				n1--;
			}
			while (n2 != 0) {
				q[i] = !q[i];
				n2--;
			}
		}//evaluation ends
		//Displaying Truth table
		displayTable2(p, q, result, size, var, var_count, cmp);
	}//2 atomic proposition code end
	if (num == 1) {
		const int size = 2;//number of rows
		int letters = 0;
		bool p[size] = { 1,0 };
		bool result[size] = { 1,0 };
		char cmp[50];
		std::cout << "Enter compound proposition:";
		std::cin >> cmp;
		//ensuring number of variables
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				letters++;
			}
		}
		//checks for invalid inputs
		//1.Number of atomic propositions should be 1
		if (letters != 1) {
			std::cout << "Invalid operation";
			exit(1);
		}
		//2.There must be a negation at start
		if (cmp[0] != '~') {
			std::cout << "Invalid operation";
			exit(1);
		}
		//3.Space handling
		for (int i = 0; cmp[i] != '\0'; i++) {
			if (cmp[i] == ' ') {
				std::cout << "Invalid operation";
				exit(1);
			}
		}
		char op[20];//logical connectives storage
		int op_count = 0;
		char var[2];//atomic proposition storage
		int var_count = 0;
		//storing atomic proposition and connectives in respective arrays
		for (int i = 0; cmp[i] != '\0'; i++) {
			if ((cmp[i] >= 97 && cmp[i] <= 122) || (cmp[i] >= 65 && cmp[i] <= 90)) {
				var[var_count] = cmp[i];
				var_count++;
			}
			if (cmp[i] == '~' || cmp[i] == '&' || cmp[i] == '@' || cmp[i] == '|' || cmp[i] == '-' || cmp[i] == '>' || cmp[i] == '<') {
				op[op_count] = cmp[i];
				op_count++;
			}
		}
		var[var_count] = '\0';
		op[op_count] = '\0';
		//evaluation part starts
		for (int i = 0; i < size; i++) {
			//negation handling
			for (int j = 0; op[j] != '\0'; j++) {
				if (op[j] == '~') {
					result[i] = !result[i];
				}
			}
		}//evaluation part ends
		//Displaying Truth table
		displayTable(p, result, size, var, var_count, cmp);
	}//end of code for one atomic proposition
	if (num < 1) {
		std::cout << "Please enter a valid value" << std::endl;
	}
	if (num > 3) {
		std::cout << "Please wait for the update to use this functionality" << std::endl;
	}
}