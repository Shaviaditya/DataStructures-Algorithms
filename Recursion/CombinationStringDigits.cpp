#include <iostream>
#include <cstring>
using namespace std;

void printCombinations(char* input, int index,
                     char* output, int outLength)
{
    if (input[index] == '\0')
    {
        output[outLength] = '\0';
        cout << output << endl;
        return;
    }
    output[outLength] = input[index];
     
    output[outLength + 1] = ' ';
     
    printCombinations(input, index + 1, output,
                                   outLength + 2);
     
    if(input[index + 1] != '\0')
    printCombinations(input, index + 1, output,
                                    outLength + 1);
     
}
int main()
{
    char input[] = "1214";
    char *output = new char[100];
 
    output[0] = '\0';
     
    printCombinations(input, 0, output, 0);
    return 0;
}