#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char **argv) {
    printf("Testing libxml2\n");

    if (argc != 2)
        return(1);
    
    xmlDocPtr doc; /* the resulting document tree */

    doc = xmlReadFile(filename, NULL, 0);

    return(0);
}