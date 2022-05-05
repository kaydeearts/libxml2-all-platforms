#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

/**
 * example1Func:
 * @filename: a filename or an URL
 *
 * Parse the resource and free the resulting tree
 */
static void
example1Func(const char *filename) {
    xmlDocPtr doc; /* the resulting document tree */

    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse %s\n", filename);
	return;
    }
    xmlFreeDoc(doc);
}

int main(int argc, char **argv) {
    printf("Testing libxml2\n");

    if (argc != 2)
        return(1);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    example1Func(argv[1]);

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();
    return(0);
}