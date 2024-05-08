#include "fcgi_stdio.h"
#include <stdlib.h>
#include <string.h>
#include "matmul.h"
#define MAX_MATRIX_SIZE 18384
int main()
{
    char *query_string;
    long int n;
    while(FCGI_Accept() >= 0) {
        /*
         * Produce the necessary HTTP header.
         */
        printf("Content-type: text/html\r\n"
               "\r\n");
        /*
         * Produce the constant part of the HTML document.
         */
        printf("<title>matmul benchmark</title>\n"
               "<h1>MATRIX MULTIPLICATION BENCHMARK</h1>\n");
        /*
         * Read the query string and produce the variable part
         * of the HTML document.
         */
        query_string = getenv("QUERY_STRING");
        if(query_string == NULL) {
            printf("Usage: Specify a positive number in the query string.\n");
        } else {
            //query_string = strchr(query_string, '=') + 1;
            char * dummy;
	    n = strtol(query_string,&dummy,10);
            if (n < 1) {
                printf("The query string '%s' is not a positive number.\n",
                       query_string);
            } 
	    else if (n > MAX_MATRIX_SIZE) {
                printf("program supports only matrixes with size below %d\n", MAX_MATRIX_SIZE);
            } 
	    else {
		int e;
		e = 0;
		float time = multiply_matrices(n,&e);
		if (e==-1) {
		    printf("program terminated incorrectly");
		}
		else{
		    printf("benchmark run for %.3f seconds\n",time);
		}
            }
        }
    } /* while FCGI_Accept */
}

