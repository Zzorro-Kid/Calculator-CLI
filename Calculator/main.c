#include <stdio.h>

void show_menu () {
    printf("--- Console Calculator ---\n");
    printf("Available Operations:\n");
    printf(" + : Addition\n");
    printf(" - : Deduction\n");
    printf(" * : Multiplication\n");
    printf(" / : Division\n");
}

int main () {
    double num1, num2, res;
    char op;

    while (1) {
        show_menu();
        printf("\nEnter an expression: ");
        if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
            printf("Input error: Try again\n");
            while (getchar() != '\n');  // clean buffer
            continue;
        }

        switch (op) {
            case '+':
                res = num1 + num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                if ( num2 == 0) {
                    printf("Error: Division by zero not possible\n");
                    continue;
                }
                res = num1 / num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            default:
                printf("Unknown operation: &c\n", op);
                continue;
        }

        printf("Result: %.2lf\n\n", res);

        return 0;
    }

    return 0;
}

