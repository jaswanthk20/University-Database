#include "Header.h"
#include <fstream>

void print_options(ostream& out);

enum options_s { EMPTY, STUD, PROF, P_STUD, P_PROF, D_STUD, D_PROF, C_STUD, C_PROF, E_STUD, E_PROF, CL_STUD, CL_PROF, STOP };

int main(void)
{
    int option;
    bool check = true;
    ofstream fout("usertypeout.txt");

    student_list mySlist;
    professor_list myPlist;
    while (check)
    {
        print_options(cout);
        cin >> option;

        switch (option)
        {
        case STUD:
            mySlist.push(fout);
            break;

        case PROF:
            myPlist.push(fout);
            break;

        case P_STUD:
            cout << endl;
            mySlist.print_list(cout);
            mySlist.print_list(fout);
            break;

        case P_PROF:
            myPlist.print_list(cout);
            myPlist.print_list(fout);
            break;

        case D_STUD:
            mySlist.delete_item();
            break;

        case D_PROF:
            myPlist.delete_item();
            break;

        case C_STUD:
            cout << endl;
            cout << "The number of student entries: " << mySlist.get_count() << endl;
            cout << endl;
            break;

        case C_PROF:
            cout << endl;
            cout << "The number of professor entries: " << myPlist.get_count() << endl;
            cout << endl;
            break;

        case E_STUD:
            cout << endl;
            if (mySlist.ifempty())
            {
                cout << "Yes, it is empty" << endl;
            }
            else
            {
                cout << "No. It is not empty" << endl;
            }
            cout << endl;
            break;

        case E_PROF:
            cout << endl;
            if (myPlist.ifempty())
            {
                cout << "Yes, it is empty" << endl;
            }
            else
            {
                cout << "No. It is not empty" << endl;
            }
            cout << endl;
            break;

        case CL_STUD:
            mySlist.clear();
            fout << "The student database is cleared";
            break;

        case CL_PROF:
            myPlist.clear();
            fout << "The professor database is cleared";
            break;

        case STOP:
            check = false;
            break;

        default:

            break;
        }
        cout << endl;
    }

    fout.close();
    getchar();
    return 0;
}

void print_options(ostream& out)
{
    out << "Please select from options:" << endl;

    out << "1.  Add student" << endl;
    out << "2.  Add professor" << endl;

    out << "3.  Print student" << endl;
    out << "4.  Print professor" << endl;

    out << "5.  Delete student" << endl;
    out << "6.  Delete professor" << endl;

    out << "7.  Count student" << endl;
    out << "8. Count professor" << endl;

    out << "9. Empty student" << endl;
    out << "10. Empty professor" << endl;

    out << "11. Clear student" << endl;
    out << "12. Clear professor" << endl;

    out << "13. Stop" << endl;

    out << "Selection: ";
}