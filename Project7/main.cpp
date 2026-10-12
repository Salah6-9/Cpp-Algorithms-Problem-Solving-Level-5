#include <iostream>
#include "clsMyString.h"

int main()
{
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";
    clsMyString<string> PersonName;
    for (string name : {"", "Salah", "Ali", "Moh", "Abdou"})
    {
        PersonName.SetValue(name);
        cout << " Name : " << PersonName.GetValue() << endl;
    }

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    PersonName.Undo();
    cout << "\nS1  after undo = " << PersonName.GetValue() << "\n";

    
        PersonName.Undo();
        cout << "\nS1  after undo = " << PersonName.GetValue() << "\n";

        PersonName.Undo();
        cout << "\nS1  after undo = " << PersonName.GetValue() << "\n";

        PersonName.Undo();
        cout << "\nS1  after undo = " << PersonName.GetValue() << "\n";

        cout << "\n\nRedo: ";
        cout << "\n__________\n";

        PersonName.Redo();
        cout << "\nS1  after Redo = " << PersonName.GetValue() << "\n";

        PersonName.Redo();
        cout << "\nS1  after Redo = " << PersonName.GetValue() << "\n";

        PersonName.Redo();
        cout << "\nS1  after Redo = " << PersonName.GetValue() << "\n";

        PersonName.Redo();
        cout << "\nS1  after Redo = " << PersonName.GetValue() << "\n";
}