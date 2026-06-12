#include "TextEditor.h"

void TextEditor::createFile()
{
    cout << "Enter text (type END on a new line to stop):\n";

    text = "";
    string line;

    cin.ignore();

    while(true)
    {
        getline(cin, line);

        if(line == "END")
        {
            break;
        }

        text += line + "\n";
    }
}

void TextEditor::openFile()
{
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName);

    if(!file)
    {
        cout << "File not found.\n";
        return;
    }

    text = "";
    string line;

    while(getline(file, line))
    {
        text += line + "\n";
    }

    file.close();

    cout << "File loaded successfully.\n";
}

void TextEditor::saveFile()
{
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;

    ofstream file(fileName);

    file << text;

    file.close();

    cout << "File saved successfully.\n";
}

void TextEditor::displayWithLineNumbers()
{
    cout << "\n----- Text -----\n";

    string line = "";
    int lineNumber = 1;

    for(int i = 0; i < text.length(); i++)
    {
        if(i == 0)
        {
            cout << lineNumber << ": ";
        }

        if(text[i] == '\n')
        {
            cout << endl;
            lineNumber++;

            if(i != text.length() - 1)
            {
                cout << lineNumber << ": ";
            }
        }
        else
        {
            cout << text[i];
        }
    }

    cout << endl;
}

void TextEditor::findText()
{
    string word;

    cin.ignore();

    cout << "Enter text to find: ";
    getline(cin, word);

    if(text.find(word) != string::npos)
    {
        cout << "Text found.\n";
    }
    else
    {
        cout << "Text not found.\n";
    }
}

void TextEditor::replaceText()
{
    string oldWord;
    string newWord;

    cin.ignore();

    cout << "Enter word to replace: ";
    getline(cin, oldWord);

    cout << "Enter new word: ";
    getline(cin, newWord);

    size_t pos = text.find(oldWord);

    while(pos != string::npos)
    {
        text.replace(pos, oldWord.length(), newWord);
        pos = text.find(oldWord, pos + newWord.length());
    }

    cout << "Replacement completed.\n";
}

void TextEditor::countCharacters()
{
    cout << "Character Count: "
         << text.length() << endl;
}

void TextEditor::countWords()
{
    int words = 0;
    bool insideWord = false;

    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] != ' ' &&
           text[i] != '\n' &&
           text[i] != '\t')
        {
            if(!insideWord)
            {
                words++;
                insideWord = true;
            }
        }
        else
        {
            insideWord = false;
        }
    }

    cout << "Word Count: "
         << words << endl;
}

void TextEditor::wordWrap()
{
    int width = 40;

    cout << "\n----- Word Wrap -----\n";

    int count = 0;

    for(int i = 0; i < text.length(); i++)
    {
        cout << text[i];
        count++;

        if(count >= width && text[i] == ' ')
        {
            cout << endl;
            count = 0;
        }
    }

    cout << endl;
}
