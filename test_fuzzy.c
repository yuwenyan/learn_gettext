#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>
#define MAX_CHAR (1024)

// LANG=zh_CN.utf8

int main(int argc, char **argv)
{
    char const_str[MAX_CHAR];
    char test_str[MAX_CHAR];
    int cstr_len = 0;
    int tstr_len = 0;
    double nr_fuzzy = 0.0;

    /* Init gettext related APIs*/
    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALEDIR);
    textdomain(PACKAGE);

    /* Set up strings */
    strncpy(const_str, 
        "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz",
        MAX_CHAR);
    strncpy(test_str, 
        gettext("not a string a1abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"),
        MAX_CHAR);

    cstr_len = strlen(const_str);
    tstr_len = strlen(test_str);
    nr_fuzzy = (double) cstr_len/tstr_len;

    /*- Let's print out some message */
    printf("\nNormilized Rate for Fuzzy:\n %f\n", nr_fuzzy);
    printf("Input string:\n--  %s\n", const_str);
    printf("Output string:\n--  %s\n", test_str);

    return 0;
}
