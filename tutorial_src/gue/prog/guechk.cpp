#include <stdio.h>
#include <string.h>
#include "oi.h"

using namespace std;

void endf(const char* msg, int line, int position) {
    printf("WRONG\nProgram writes to standard output\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s in out wzo\n", argv[0]);
        return 1;
    }

    // In file is not needed.
    // Still needs to be passed as first argument in main,
    // for compatibility with sio2 system reasons.

    char header_ans[100];
    FILE *fwzo = fopen(argv[3], "r");
    fscanf(fwzo, "%s", header_ans);
    fclose(fwzo);

    // HINT: fin i fwzo are guaranteed to be correct,
    // no need to read them with Scanner.

    oi::Scanner *test = new oi::Scanner(argv[2], endf, oi::PL);

    char header[100], result[100], comment[100];
    int queries;

    test->readLine(header, 100);

    if(strcmp(header, header_ans)) {
        printf("WRONG\nProgram writes to standard output\n");
        return 0;
    }

    test->readLine(result, 100);
    queries = test->readInt();
    test->readEoln();
    test->readLine(comment, 100);
    test->readEof();

    if(strcmp(result, "OK")) {
        printf("%s\n%s\n", result, comment);
        return 0;
    }

    int points = 100;
    if (queries > 30) {
        points = 50;
    } else if (queries > 20) {
        points = (30 - queries) * 5 + 50;
    }
    printf("OK\nYou guessed the right number using %d queries\n", queries);
    printf("%d\n", points);
    return 0;
}
