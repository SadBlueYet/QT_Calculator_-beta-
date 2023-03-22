#include "Foonctions.h"
#define PI 3.14159265


class Stack {
    
public:
    std::string stringOfoperators;
    std::stack <char> operators;
    int counter = 0;
    void stackPush(char oper);
    void stackPopAndPush(char oper); 
};
void Stack::stackPush(char oper) {
    operators.push(oper);
}

void Stack::stackPopAndPush(char oper) { 
    stringOfoperators = "";
    counter = 0;
    do {
        if (operators.size() == 0) break;
        if ((oper == '+' || oper == '-') && operators.top() == '(') break;
        if ((oper == '*' || oper == '/') && (operators.top() == '+' || operators.top() == '-' || operators.top() == '(' || operators.size() == 0)) break;
        if (oper == '^' && operators.size() == 0) break;
        if (oper == ')' && operators.top() == '(') {
            operators.pop();
            if (operators.size() == 0) break;
        }
        stringOfoperators += operators.top();
        stringOfoperators += ' ';
        counter += 2;
        operators.pop();
    } while (true);
    if (oper != ')') operators.push(oper);
}

double exitString(std::string str) {
    Stack stack;
    std::string num = "", exiString = "", operatr = "", value, bufptr = "";
    double val, result;
    int i = 0;
    for (int k = 0; k < str.length(); k++) {
        if (str[k] == '(' && str[k + 1] == '-') {
            bufptr += str[k];
            k++;
            bufptr += (char)48;
        }
        if ((str[k] == 'S' && str[k + 1] == 'Q') || (str[k] == 's' && str[k + 1] == 'i')
                    || (str[k] == 'c' && str[k + 1] == 'o') || (str[k] == 'c' && str[k + 1] == 't')
                    || (str[k] == 't' && str[k + 1] == 'a')) {
                    bufptr += (char)48;;
                    bufptr += (char)43;
                }
        bufptr += str[k];
    }

    do {
        if (isdigit(bufptr[i])) {
            exiString += bufptr[i];
            i++;
            if (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ',')) {
                do {
                    if (bufptr[i] == '.' || bufptr[i] == ',') {
                        exiString += '.';
                        i++;
                    }
                    exiString += bufptr[i];
                    i++;

                } while (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ','));

            }
            exiString += ' ';
        }
        
        else {
            if (i == 0 && bufptr[i] == '-') {
            exiString += bufptr[i];
            i++;
            }
            if ((stack.operators.empty() || bufptr[i] == '(' || bufptr[i] == '^') && bufptr[i] != 's') {
                stack.stackPush(bufptr[i]);
                i++;
            }
            else {
                value = "";
                int count = 0;
                if (bufptr[i] == ')') {
                    stack.stackPopAndPush(bufptr[i]);
                    operatr = stack.stringOfoperators;
                    exiString += operatr;
                    i++;
                    continue;
                }
                else if (bufptr[i] == 's' || bufptr[i] == 'S') {
                    i++;
                    if (bufptr[i] == 'q' || bufptr[i] == 'Q') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = sqrt(stod(value));
                        trigonometry(val, count, exiString);
                        continue;
                    }
                    if (bufptr[i] == 'i' || bufptr[i] == 'I') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = sin(stod(value) * PI / 180);
                        trigonometry(val, count, exiString);
                        continue;
                    }
                }
                else if (bufptr[i] == 'c' || bufptr[i] == 'C') {
                    i++;
                    if (bufptr[i] == 'o' || bufptr[i] == 'O') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = cos(stod(value) * PI / 180);
                        trigonometry(val, count, exiString);
                        continue;
                    }
                    if (bufptr[i] == 't' || bufptr[i] == 'T') {
                        i++;
                        if (bufptr[i] == 'g' || bufptr[i] == 'G') {
                            while (!isdigit(bufptr[i])) {
                                i++;
                            }
                            if (isdigit(bufptr[i])) {
                                while (isdigit(bufptr[i])) {
                                    createValue(value, (char)bufptr[i]);
                                    i++;
                                }
                            }
                            val = 1 / tan(stod(value) * PI / 180);
                            trigonometry(val, count, exiString);
                            continue;
                        }
                    }
                }
                else if (bufptr[i] == 't' || bufptr[i] == 'T') {
                    while (!isdigit(bufptr[i])) {
                        i++;
                    }
                    if (isdigit(bufptr[i])) {
                        while (isdigit(bufptr[i])) {
                            createValue(value, (char)bufptr[i]);
                            i++;
                        }
                    }
                    val = tan(stod(value) * PI / 180);
                    trigonometry(val, count, exiString);
                    continue;
                }
                else {
                    stack.stackPopAndPush(bufptr[i]);
                    operatr = stack.stringOfoperators;
                    exiString += operatr;
                    i++;
                    continue;
                }
                stack.stackPush(bufptr[i]);
                i++;
            }
        }
    }while (i < bufptr.length());

    if (stack.operators.size() != 0) {
        do {
            exiString += stack.operators.top();
            exiString += ' ';
            stack.operators.pop();
        } while (stack.operators.size() != 0);
    }
    result = mathOperations(exiString);
    return result;
}

double mathOperations(std::string a) {
    std::istringstream str(a);
    std::stack<double> numbers;
    double value;
    char oper;
    double right, left;
    while (!str.eof())
    {
        while (str >> value) {
            numbers.push(value);
        }
        if (!str.eof()) {
            str.clear();
            str.unget();
            str >> oper;
            
            if (numbers.size() < 2) return 0.111;

            right = numbers.top();
            numbers.pop();
            left = numbers.top();
            numbers.pop();
            if (oper == '+') numbers.push(left + right);
            if (oper == '-') numbers.push(left - right);
            if (oper == '*') numbers.push(left * right);
            if (oper == '/') numbers.push(left / right);
            if (oper == '^') numbers.push(pow(left, right));
        }
    }
        return numbers.top();

}
void trigonometry(double val, int& count, std::string& exitString) {
    std::string num;
    num = std::to_string(val);
    while (num[count] != '\0') {
        exitString += num[count];
        count++;
    }
    exitString += ' ';
}
void createValue(std::string& value, char ch) {
    value += ch;
}
std::string valueProcessing(double value){
    std::string str = std::to_string(value);
    std::string val = "";

    for(int i = 0; i <= str.length(); i++){
        if(str[i] == '.' && str[i+1] == '0') break;
        if(str[i] == '.' && str[i+1] != '0'){
            for(int j = i; j < i + 4; j++) {
                if(str[j] == '0' && str[j+1] == '0') break;
                val += str[j];
            }
            break;
        }
        val += str[i];
    }


    return val;
}
