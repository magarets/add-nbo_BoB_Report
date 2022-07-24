#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    FILE* fp1 = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");

    uint32_t num1 = 0;
    uint32_t num2 = 0;

    fread(&num1, sizeof(num1), 1, fp1);
    fread(&num2, sizeof(num2), 2, fp2);

    uint32_t net2host_num1 = 0;
    uint32_t net2host_num2 = 0;

    net2host_num1 = ntohl(num1);
    net2host_num2 = ntohl(num2);

    uint32_t sumNumber;

    sumNumber = net2host_num1 + net2host_num2;

    printf("%u(0x%0x) + %u(0x%0x) = %u(0x%0x)", net2host_num1, net2host_num1, net2host_num2, net2host_num2, sumNumber, sumNumber);

    fclose(fp1);
    fclose(fp2);

    return 0;
}