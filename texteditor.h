#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextEditor
{
private:
    string text;

public:
    void createFile();
    void openFile();
    void saveFile();

    void displayWithLineNumbers();

    void findText();
    void replaceText();

    void countCharacters();
    void countWords();

    void wordWrap();
};

#endif
