#include "tinyexpr.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // if (argc < 2) {
    //     printf("Usage: example2 \"expression\"\n");
    //     return 0;
    // }

    const char *expression = "x + 2 * y + _z";
    // const char *expression = "x + 2 * y";
    printf("Evaluating:\n\t%s\n", expression);

    /* This shows an example where the variables
     * x and y are bound at eval-time. */
    double x, y, _z;
    te_variable vars[] = {{"x", &x, TE_VARIABLE}, {"y", &y, TE_VARIABLE}};

    /* This will compile the expression and check for errors. */
    int err;
    char *err_token = NULL;
    te_expr *n = te_compile(expression, vars, sizeof(vars) / sizeof(te_variable), &err, &err_token);
    // cout << "----------------------" << endl;
    // te_print(n);
    // cout << "----------------------" << endl;

    if (n)
    {
        /* The variables can be changed here, and eval can be called as many
         * times as you like. This is fairly efficient because the parsing has
         * already been done. */
        x = 3;
        y = 4;
        _z = 0;
        const double r = te_eval(n);
        printf("Result:\n\t%f\n", r);

        te_free(n);
    }
    else
    {
        /* Show the user where the error is at. */
        printf("\t%*s^\nError near here\n", err - 1, "");
        if (err_token)
        {
            printf("\tThe error token is %s\n", err_token);
            free(err_token);
        }
    }

    return 0;
}
