#include "Header.h"

int main()
{
    Employee emp1("Zhuk_Maxim_Vladimirovich", 3, "  musician");
    Employee emp2("Zhuk_Vladimir_Petrovich", 2, "  dad");
    Employee emp3("Schwatsnager_Arnold_Viktorovich", 5, "  actor");
    Employee emp4("Obama_Barak_Mikhailovich", 4, "  ex.president");
    Employee emp5("Merkel_Angela_Vitalievna", 8, "  canceler");

    Employee msEmp[5] = { emp2, emp1, emp3, emp4, emp5 };

    File filetxt("1.txt", txt);

    filetxt.open("w");

    filetxt.setSize(5);

    filetxt << emp2;
    filetxt << emp1;
    filetxt << emp3;
    filetxt << emp4;
    filetxt << emp5;

    filetxt.close();

    filetxt.open("r");

    

    filetxt.close();

    File filetxtbin("2.txt", bin);

    filetxtbin.open("w");

    filetxtbin.setSize(5);
    filetxtbin << emp2;
    filetxtbin << emp1;
    filetxtbin << emp3;
    filetxtbin << emp4;
    filetxtbin << emp5;

    filetxtbin.close();

    filetxtbin.open("r");

   // cout << filetxtbin;

    filetxtbin.close();
    File filebin("3.bin", bin);

    filebin.open("w");

    filebin.setSize(5);

    filebin << emp2;
    filebin << emp1;
    filebin << emp3;
    filebin << emp4;
    filebin << emp5;

    filebin.close();

    

    //cout << filebin;

   
    char input;
    bool check = true;
    while (check)
    {   
        cout << "\nFrom what file do you want data to loaded?"<<endl;


        cout << "1- Txt file in txt mode" << endl;
        cout << "2- Txt file in bin mode" << endl;
        cout << "3- Bin file in bin mode"<<endl;
        cin >> input;
        cout << endl;
        if (input == '1')
        {
            filetxt.open("r");
            cout << filetxt;
            filetxt.close();
        }
        if (input == '2')
        {
            filetxtbin.open("r");
            cout << filetxtbin;
            filebin.close();
        }
        if (input == '3')
         {
                filebin.open("r");
                cout << filebin;
                filebin.close();
         }
        if (input!='1' &&input!='2'&&input!='3') check = false;
    }
   
    cout << "\n";

    int i = 0, lineToEdit;
    int line;
    string newName;
    cout << "What employee do you want to change? " << endl;
    cin >> line;
    cin >> newName;
    lineToEdit = line;
    cout << "What employee do you want to delete? " << endl;
    cin >> line;
    int lineToDel = line;

    filetxtbin.open("r");
    filetxtbin.editEmployee(lineToEdit, msEmp, newName);
    filetxtbin.close();

    filetxtbin.open("w");
    cout << "deleted" << endl;
    filetxtbin.deleteEmployee(lineToDel, msEmp);
    filetxtbin.close();

    rewind(stdin);

    cout << "\n";

    cout << "   Sort by fio:" << endl;
    filetxt.sortFio();

    filetxt.open("r");

    cout << filetxt;

    filetxt.close();

    cout << "\n";
    cout << "   Sorted by number:" << endl;
    filetxt.sortNumToHigh();

    filetxt.open("r");

    cout << filetxt;

    filetxt.close();

    cout << "\n";
    cout << "   Sorted by dolz:" << endl;
    filetxt.sortDolz();

    filetxt.open("r");

    cout << filetxt;

    filetxt.close();
    cout << "\n";
    cout << "   Sorted from high to low by number:\n";
    filetxt.sortNumToLow();
    filetxt.open("r");
    cout << filetxt;
    filetxt.close();
}