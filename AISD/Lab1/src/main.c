#include <stdio.h>
#include <stdlib.h>


// напечатать символ в файл и продублировать вывод в консоль
void PrintSymbol(char ch, FILE *fOut) {
    fputc(ch, fOut);
    printf("%c", ch);
}


// рекурсивно напечатать слово с реверсом
char PrintReverseWord(FILE *fIn, FILE *fOut) {
    char ch = fgetc(fIn);
    char delim;
    // если не конец слова
    if (ch != ' ' && ch != '\n' && ch != ',' && ch != '.') {
        // если не конец файла
        if ((!feof(fIn))) {
            delim = PrintReverseWord(fIn, fOut);
            PrintSymbol(ch, fOut);
        }
    } else {
        // если ch - символ-разделитель
        delim = ch;
    }
    // вернуть символ-разделитель для печати в main
    return delim;
}


int main(int argc, char *argv[]) {
    FILE *inFile, *outFile;
    char delim;
    if ((argc > 2) || ((inFile = fopen(argv[1], "r")) == NULL)) {
        printf("Program arguments do not correct.");
    } else {
        outFile = fopen("output.txt", "w");
        while (!feof(inFile)) {
            delim = PrintReverseWord(inFile, outFile);
            if (!feof(inFile)) {
                PrintSymbol(delim, outFile);
            }
        }
    }
    putchar('\n');

    return 0;
}
