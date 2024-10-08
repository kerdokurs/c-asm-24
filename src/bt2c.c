#include <stdio.h>

enum instructions_e {
    BF_RIGHT      = '>',
    BF_LEFT       = '<',
    BF_INCREASE   = '+',
    BF_DECREASE   = '-',
    BF_READ       = ',',
    BF_PRINT      = '.',
    BF_START_LOOP = '[',
    BF_END_LOOP   = ']',
    BF_DEBUG      = '#'
};

void translate(const char *program) {
    int i = 0;
    while (program[i] != 0 ) {
        printf("\t// Instruktsioon %c\n", program[i]);
        switch (program[i]) {
            case BF_INCREASE:
                printf("\tbuf[ptr]++;\n");
                break;
            case BF_DECREASE:
                printf("\tbuf[ptr]--;\n");
                break;
            case BF_LEFT:
                printf("\tptr--; if (ptr < 0) ptr = BUF_SIZE - 1;\n");
                break;
            case BF_RIGHT:
                printf("\tptr++; if (ptr >= BUF_SIZE) ptr = 0;\n");
                break;
            case BF_READ:
                printf("\tbuf[ptr] = getc(stdin);\n");
                break;
            case BF_PRINT:
                printf("\tprintf(\"%%c\", buf[ptr]);\n");
                break;
            case BF_START_LOOP:
                printf("\twhile (buf[ptr]) {\n");
                break;
            case BF_END_LOOP:
                printf("\t}\n");
                break;
            default:
                // fprintf(stderr, "Tundmatu sümbol '%c'\n", program[i]);
                break;
                /* Ignoreerime sümboleid, mida me ei tunne. */
        }

        i++;
    }
}

void print_header(void) {
    printf("#include <stdio.h>\n");
    printf("#define BUF_SIZE 30000\n");
    printf("int main(void) {\n");
    printf("\tchar buf[BUF_SIZE] = {0};\n");
    printf("\tint ptr = 0;\n");
}

void print_footer(void) {
    printf("}\n");
}

int main(int argc, char **argv, char **envp) {
    if (argc != 2) {
        fprintf(stderr, "Programmil peab olema üks parameeter, milleks on BF programm!\n");
        return 1;
    }

    print_header();
    translate(argv[1]);
    print_footer();

    return 0;
}
