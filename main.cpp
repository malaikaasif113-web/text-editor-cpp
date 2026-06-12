#include "TextEditor.h"

int main()
{
    TextEditor editor;

    int choice;

    do
    {
        cout << "\n===== Simple Text Editor =====\n";
        cout << "1. Create Text\n";
        cout << "2. Open File\n";
        cout << "3. Save File\n";
        cout << "4. Display With Line Numbers\n";
        cout << "5. Find Text\n";
        cout << "6. Replace Text\n";
        cout << "7. Character Count\n";
        cout << "8. Word Count\n";
        cout << "9. Word Wrap\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            editor.createFile();
            break;

        case 2:
            editor.openFile();
            break;

        case 3:
            editor.saveFile();
            break;

        case 4:
            editor.displayWithLineNumbers();
            break;

        case 5:
            editor.findText();
            break;

        case 6:
            editor.replaceText();
            break;

        case 7:
            editor.countCharacters();
            break;

        case 8:
            editor.countWords();
            break;

        case 9:
            editor.wordWrap();
            break;

        case 0:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while(choice != 0);

    return 0;
}
