/**
 * A scientific calculator in C.
 *
 * This program provides a menu-driven interface for common
 * arithmetic, trigonometric, logarithmic, and special functions.
 *
 * Note on advanced functions:
 * Operations like Derivative, Integral, Gradient, Fourier Transform, etc.,
 * are not implemented. These operations require a *function*
 * (e.g., f(x) = x^2) as input, not just one or two numbers. They
 * are beyond the scope of a simple calculator and require
 * symbolic or advanced numerical libraries.
 */

#include <stdio.h>
#include <math.h>       // For all standard math functions
#include <stdlib.h>     // For exit()
#include <complex.h>    // For complex exponential

// --- Function Prototypes ---

/**
 * @brief Prints the main calculator menu.
 */
void print_menu();

/**
 * @brief Calculates the Legendre polynomial P_n(x) using recursion.
 * @param n The integer order (n >= 0).
 * @param x The value to evaluate at.
 * @return The value of P_n(x).
 */
double legendre(int n, double x);

// --- Main Function ---

int main() {
    int choice;
    double a, b, result;
    int n;

    // Main calculator loop
    while (1) {
        print_menu();
        printf("\nEnter your choice (0-28): ");
        
        // Get user choice
        if (scanf("%d", &choice) != 1) {
            // Clear the input buffer if user enters non-integer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n\n");
            continue;
        }

        printf("\n");

        // Use a switch to determine which operation to perform
        switch (choice) {
            // --- 0. Exit ---
            case 0:
                printf("Exiting calculator. Goodbye!\n");
                exit(0);

            // --- Basic 2-Input Operations ---
            case 1: // Add
                printf("Enter first number (a): ");
                scanf("%lf", &a);
                printf("Enter second number (b): ");
                scanf("%lf", &b);
                result = a + b;
                printf("Result: %lf + %lf = %lf\n", a, b, result);
                break;
            case 2: // Subtract
                printf("Enter first number (a): ");
                scanf("%lf", &a);
                printf("Enter second number (b): ");
                scanf("%lf", &b);
                result = a - b;
                printf("Result: %lf - %lf = %lf\n", a, b, result);
                break;
            case 3: // Multiply
                printf("Enter first number (a): ");
                scanf("%lf", &a);
                printf("Enter second number (b): ");
                scanf("%lf", &b);
                result = a * b;
                printf("Result: %lf * %lf = %lf\n", a, b, result);
                break;
            case 4: // Divide
                printf("Enter numerator (a): ");
                scanf("%lf", &a);
                printf("Enter denominator (b): ");
                scanf("%lf", &b);
                if (b == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = a / b;
                    printf("Result: %lf / %lf = %lf\n", a, b, result);
                }
                break;
            case 5: // Power
                printf("Enter base (x): ");
                scanf("%lf", &a);
                printf("Enter exponent (n): ");
                scanf("%lf", &b);
                result = pow(a, b);
                printf("Result: %lf ^ %lf = %lf\n", a, b, result);
                break;

            // --- Standard 1-Input Operations ---
            case 6: // Exp (e^x)
                printf("Enter exponent (x): ");
                scanf("%lf", &a);
                result = exp(a);
                printf("Result: e^(%lf) = %lf\n", a, result);
                break;
            case 7: // Log (ln x)
                printf("Enter number (x): ");
                scanf("%lf", &a);
                if (a <= 0) {
                    printf("Error: Logarithm is undefined for non-positive numbers.\n");
                } else {
                    result = log(a);
                    printf("Result: ln(%lf) = %lf\n", a, result);
                }
                break;
            case 8: // Sine
                printf("Enter angle in RADIANS (x): ");
                scanf("%lf", &a);
                result = sin(a);
                printf("Result: sin(%lf) = %lf\n", a, result);
                break;
            case 9: // Cosine
                printf("Enter angle in RADIANS (x): ");
                scanf("%lf", &a);
                result = cos(a);
                printf("Result: cos(%lf) = %lf\n", a, result);
                break;
            case 10: // Tangent
                printf("Enter angle in RADIANS (x): ");
                scanf("%lf", &a);
                result = tan(a);
                printf("Result: tan(%lf) = %lf\n", a, result);
                break;
            case 11: // Arcsin
                printf("Enter value (x) [-1 to 1]: ");
                scanf("%lf", &a);
                if (a < -1.0 || a > 1.0) {
                    printf("Error: Domain for asin is [-1, 1].\n");
                } else {
                    result = asin(a);
                    printf("Result: asin(%lf) = %lf RADIANS\n", a, result);
                }
                break;
            case 12: // Arccos
                printf("Enter value (x) [-1 to 1]: ");
                scanf("%lf", &a);
                if (a < -1.0 || a > 1.0) {
                    printf("Error: Domain for acos is [-1, 1].\n");
                } else {
                    result = acos(a);
                    printf("Result: acos(%lf) = %lf RADIANS\n", a, result);
                }
                break;
            case 13: // Arctan
                printf("Enter value (x): ");
                scanf("%lf", &a);
                result = atan(a);
                printf("Result: atan(%lf) = %lf RADIANS\n", a, result);
                break;
            case 14: // Sinh
                printf("Enter number (x): ");
                scanf("%lf", &a);
                result = sinh(a);
                printf("Result: sinh(%lf) = %lf\n", a, result);
                break;
            case 15: // Cosh
                printf("Enter number (x): ");
                scanf("%lf", &a);
                result = cosh(a);
                printf("Result: cosh(%lf) = %lf\n", a, result);
                break;
            case 16: // Tanh
                printf("Enter number (x): ");
                scanf("%lf", &a);
                result = tanh(a);
                printf("Result: tanh(%lf) = %lf\n", a, result);
                break;
            case 17: // Reciprocal
                printf("Enter number (x): ");
                scanf("%lf", &a);
                if (a == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = 1.0 / a;
                    printf("Result: 1 / %lf = %lf\n", a, result);
                }
                break;
            case 18: // Square Root
                printf("Enter number (x): ");
                scanf("%lf", &a);
                if (a < 0) {
                    printf("Result: sqrt(%lf) = %lfi (Imaginary)\n", a, sqrt(-a));
                } else {
                    result = sqrt(a);
                    printf("Result: sqrt(%lf) = %lf\n", a, result);
                }
                break;
            case 19: // Gamma
                printf("Enter number (x): ");
                scanf("%lf", &a);
                result = tgamma(a);
                printf("Result: Γ(%lf) = %lf\n", a, result);
                break;
            case 20: // Error Function
                printf("Enter number (x): ");
                scanf("%lf", &a);
                result = erf(a);
                printf("Result: erf(%lf) = %lf\n", a, result);
                break;

            // --- Special Functions ---
            case 21: // Bessel
                printf("Enter integer order (n): ");
                scanf("%d", &n);
                printf("Enter value (x): ");
                scanf("%lf", &a);
                result = jn(n, a); // jn is Bessel function of first kind
                printf("Result: J_%d(%lf) = %lf\n", n, a, result);
                break;
            case 22: // Legendre
                printf("Enter integer order (n >= 0): ");
                scanf("%d", &n);
                printf("Enter value (x) [-1 to 1]: ");
                scanf("%lf", &a);
                if (n < 0) {
                    printf("Error: Order n must be non-negative.\n");
                } else {
                    result = legendre(n, a);
                    printf("Result: P_%d(%lf) = %lf\n", n, a, result);
                }
                break;
            case 23: // Complex Exponential
                printf("Enter value (x) for e^(ix): ");
                scanf("%lf", &a);
                // C99 standard provides complex numbers
                double complex z = cexp(I * a); // I is the imaginary unit
                printf("Result: e^(i*%lf) = %lf + %lfi\n", a, creal(z), cimag(z));
                break;

            // --- Advanced (Out of Scope) ---
            case 24: // Derivative
            case 25: // Integral
            case 26: // Gradient/Divergence/Curl
            case 27: // Fourier Transform
            case 28: // Dirac Delta
                printf("Info: This operation is not supported.\n");
                printf("These functions (Derivative, Integral, Grad, etc.) require\n");
                printf("a *function* as input, not just numbers. This is a task\n");
                printf("for symbolic math software (e.g., Mathematica, Python/SymPy).\n");
                break;

            // --- Default Case ---
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        } // end switch

        printf("\n----------------------------------------\n");

    } // end while

    return 0;
}

/**
 * @brief Prints the main calculator menu.
 */
void print_menu() {
    printf("===== C Scientific Calculator =====\n");
    printf("\n--- Basic (2 Inputs) ---\n");
    printf(" 1. Add (a + b)\n");
    printf(" 2. Subtract (a - b)\n");
    printf(" 3. Multiply (a * b)\n");
    printf(" 4. Divide (a / b)\n");
    printf(" 5. Power (x^n)\n");
    printf("\n--- Standard (1 Input) ---\n");
    printf(" 6. Exponential (e^x)\n");
    printf(" 7. Natural Log (ln x)\n");
    printf(" 8. Sine (sin x)      [x in RADIANS]\n");
    printf(" 9. Cosine (cos x)    [x in RADIANS]\n");
    printf("10. Tangent (tan x)   [x in RADIANS]\n");
    printf("11. Arcsin (asin x)\n");
    printf("12. Arccos (acos x)\n");
    printf("13. Arctan (atan x)\n");
    printf("14. Hyperbolic Sine (sinh x)\n");
    printf("15. Hyperbolic Cosine (cosh x)\n");
    printf("16. Hyperbolic Tangent (tanh x)\n");
    printf("17. Reciprocal (1/x)\n");
    printf("18. Square Root (sqrt x)\n");
    printf("19. Gamma Function (Γ(x))\n");
    printf("20. Error Function (erf(x))\n");
    printf("\n--- Special Functions ---\n");
    printf("21. Bessel Func (J_n(x)) [Input: int n, double x]\n");
    printf("22. Legendre Poly (P_n(x)) [Input: int n, double x]\n");
    printf("23. Complex Exp (e^ix)   [Input: double x]\n");
    printf("\n--- Advanced (Not Implemented) ---\n");
    printf("24. Derivative\n");
    printf("25. Integral\n");
    printf("26. Gradient/Divergence/Curl\n");
    printf("27. Fourier Transform\n");
    printf("28. Dirac Delta\n");
    printf("\n-----------------------------------\n");
    printf(" 0. Exit\n");
}

/**
 * @brief Calculates the Legendre polynomial P_n(x) using recursion.
 *
 * Uses Bonnet's recursion relation:
 * (n+1)P_{n+1}(x) = (2n+1)xP_n(x) - nP_{n-1}(x)
 *
 * Base cases:
 * P_0(x) = 1
 * P_1(x) = x
 */
double legendre(int n, double x) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else {
        // Rearranging Bonnet's relation to solve for P_n(x)
        // P_n(x) = ( (2n-1)*x*P_{n-1}(x) - (n-1)*P_{n-2}(x) ) / n
        return ((2.0 * n - 1.0) * x * legendre(n - 1, x) - (n - 1.0) * legendre(n - 2, x)) / (double)n;
    }
}
