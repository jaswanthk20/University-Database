#include <random>
#include "Header.h"
///////////////////////////////////////////course Implementation////////////////////////////////////////////

//course constructor
course::course(string cname = " ", int ccode = 0, int chours = 0)
{
    name = cname;
    code = ccode;
    credit_hours = chours;

}

//read course
void course::read(istream& in) {

    cout << "Please enter - ";

    cout << "course name: ";
    cin >> name;

    cout << "course code: ";
    cin >> code;

    cout << "credit hours: ";
    cin >> credit_hours;
}

//write course
void course::write(ostream& out) const
{
    out << "course name: " << name << endl;
    out << "course code: " << code << endl;
    out << "credit hours: " << credit_hours << endl;
}
////////////////////////////////////////////User Implementation////////////////////////////////////////////

//user constructor
user::user(string n, int i, string a, string p)
{
    name = n;
    id = i;
    address = a;
    phone_number = p;
}

//read user
void user::read(istream& in)
{
    string house_number;
    string street_name;
    string buffer;

    cout << "Please enter the data: ";

    cout << "Name: ";
    //the input from user first enters in buffer
    in >> buffer;
    //calling function uppercaser and putting the return to name
    name = uppercaser(buffer);


    cout << "Address: " << endl;
    cout << "House/Apartment number:";
    in >> house_number;
    cout << "Street name:";
    in >> street_name;
    address = house_number + " " + street_name;

    cout << "Phone #: ";
    in >> phone_number;

    // Generate random number
    random_device rd;
    uniform_int_distribution<int> dist(1000, 9999);
    int id = dist(rd);
}

//write user
void user::write(ostream& out) const
{
    out << "Name: " << name << endl;
    out << "ID: " << id << endl;
    out << "Address: " << address << endl;
    out << "Phone #: " << phone_number << endl;
    out << endl;

}

//get name allows us to use private name in friend classes
string user::get_name(void) const {
    return name;
}
////////////////////////////////////////////Student Implementation////////////////////////////////////////////

//student constructor
student::student(string n, int i, string a, string p, double g, string m, double f, bool s, int numb) : user(n, i, a, p), courses(numb, course())
{
    gpa = g;
    major = m;
    fee_amount = f;
    fee_status = s;
    next = NULL;
}

//read student
void student::read(istream& in)
{
    char temp;
    int n;

    //inheriting read from user
    user::read(in);

    cout << "GPA: ";
    in >> gpa;

    cout << "Major: ";
    in >> major;

    cout << "Fee amount: ";
    in >> fee_amount;

    cout << "Fee status (1 for paid and 0 for unpaid): ";
    in >> fee_status;

    cout << "Number of courses: ";
    in >> n;
    for (int i = 0; i < n; i++) {

        //composing read from course
        course a; //object of type course
        a.read(in);
        courses.push_back(a);
    }
}

//write student
void student::write(ostream& out) const
{
    user::write(out);

    out << "Courses:" << endl;
    for (int i = 0; i < courses.size(); i++) {
        courses[i].write(out);
        out << endl;
    }
    out << "GPA: " << gpa << endl;
    out << "Major: " << major << endl;
    out << "Fee amount: " << fee_amount << endl;

    if (fee_status == 1) {
        out << "Fee status: paid" << endl;
    }
    else {
        out << "Fee status: unpaid" << endl;
    }
}

// student list
student_list::student_list(void)
{
    start = NULL;
    count = 0;
}

//adding elements into the list
void student_list::push(ostream& out)
{
    student* stud;
    stud = new student();

    (*stud).read(cin);

    student* ptr = start;
    student* ptr2 = start;

    // add to start of list
    if (count == 0) {

        start = stud;
        stud->next = NULL;

    }
    else {

        while (ptr->next != NULL) {



            if (ptr->get_name() > stud->get_name())
            {
                if (ptr == start) {

                    stud->next = start;
                    start = stud;

                }
                else {

                    stud->next = ptr;
                    ptr2->next = stud;

                }
                break;
            }

            ptr2 = ptr;
            ptr = ptr->next;

        }
        if (ptr->next == NULL) {

            if (stud->get_name() > ptr->get_name()) {

                ptr->next = stud;
                stud->next = NULL;

            }
            else
            {

                if (ptr == start) {

                    stud->next = start;
                    start = stud;

                }
                else {

                    ptr2->next = stud;
                    stud->next = ptr;

                }

            }
        }
    }

    count++;

}

void student_list::print_list(ostream& out)
{
    student* ptr = start;

    if (start == NULL) {

        out << endl;
        out << "Empty" << endl;
        out << endl;

    }
    else
    {
        out << endl;
        out << "\nStart ----->" << endl;
        out << endl;

        while (ptr->next != NULL)
        {

            (*ptr).write(out);
            ptr = ptr->next;

            out << "\n----->\nnext node:\n" << endl;

        }

        ptr->write(out);

        out << endl;
        out << "-----> NULL" << endl;
        out << endl;

    }
}
void student_list::delete_item(void)
{
    string item = " ";
    cout << endl;
    cout << "Please enter name of student to be removed: ";
    cin >> item;
    item = uppercaser(item);
    cout << endl;

    bool found = 0;

    student* ptr = start;
    student* prev = start;

    while (ptr != NULL) {
        if (ptr->get_name() == item) {
            found = 1;
            break;
        }

        prev = ptr;
        ptr = ptr->next;
    }
    if (found) {
        if (ptr == start) {
            start = ptr->next;
        }
        else
        {
            prev->next = ptr->next;
        }

        delete ptr;

        cout << item << " is removed" << endl;
        count--;

    }
    else {

        cout << "Error.Entry doesn't exist.";
        cout << endl;

    }

}

//return the number of students
int student_list::get_count(void) const
{
    return count;
}
bool student_list::ifempty(void) const
{
    return(count == 0);
}
void student_list::clear(void)
{
    if (count != 0)
    {
        student* ptr = start->next;

        while (ptr->next != NULL)
        {
            student* prev = ptr;
            ptr = ptr->next;
            delete prev;
        }

        start = NULL;
        count = 0;

        cout << endl;
        cout << "The student database has been cleared." << endl;
        cout << endl;
    }
}

////////////////////////////////////////////Professor Implementation////////////////////////////////////////////

professor::professor(string n, int i, string a, string p, double s, int n_c, string d, string s_d) :user(n, i, a, p), salary(s), num_courses(n_c), department(d), start_date(s_d) {}

void professor::read(istream& in) {

    user::read(in);

    cout << "Please enter the data: " << endl;

    cout << "Salary: ";
    in >> salary;

    cout << "Number Of Courses: ";
    in >> num_courses;

    cout << "Department: ";
    in >> department;

    cout << "Start Date (DD/MM/YY): ";
    in >> start_date;
}

void professor::write(ostream& out) const {

    user::write(out);

    out << "Salary: " << salary << endl;
    out << "Number Of Courses: " << num_courses << endl;
    out << "Department: " << department << endl;
    out << "Start Date (DD/MM/YY): " << start_date << endl;
}

//professor list
professor_list::professor_list(void)
{
    start = NULL;
    count = 0;
}

void professor_list::push(ostream& out)
{
    professor* prof;
    prof = new professor();

    (*prof).read(cin);

    professor* ptr = start;
    professor* ptr2 = start;

    // add to start of list
    if (count == 0) {
        start = prof;
        prof->next = NULL;
    }
    else {
        while (ptr->next != NULL) {

            if (ptr->get_name() > prof->get_name())
            {
                if (ptr == start) {

                    prof->next = start;
                    start = prof;
                }
                else {
                    prof->next = ptr;
                    ptr2->next = prof;
                }
                break;
            }

            ptr2 = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == NULL) {
            if (prof->get_name() > ptr->get_name()) {
                ptr->next = prof;
                prof->next = NULL;
            }
            else
            {
                if (ptr == start) {
                    prof->next = start;
                    start = prof;
                }
                else {
                    ptr2->next = prof;
                    prof->next = ptr;
                }

            }
        }
    }
    count++;
}

void professor_list::print_list(ostream& out)
{
    professor* ptr = start;
    if (start == NULL) {
        out << endl;
        out << "Empty" << endl;
        out << endl;
    }
    else
    {
        out << endl;
        out << "\nStart ----->" << endl;
        out << endl;

        while (ptr->next != NULL)
        {
            (*ptr).write(out);
            ptr = ptr->next;
            out << "\n----->\nnext node:\n" << endl;
        }
        ptr->write(out);
        out << endl;
        out << "-----> NULL" << endl;
        out << endl;
    }
}
void professor_list::delete_item(void)
{
    string item = " ";
    cout << endl;
    cout << "Please enter name of professor to be removed: ";
    cin >> item;
    item = uppercaser(item);
    cout << endl;
    bool found = 0;

    professor* ptr = start;
    professor* prev = start;

    while (ptr != NULL) {
        if (ptr->get_name() == item) {
            found = 1;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (found) {
        if (ptr == start) {
            start = ptr->next;
        }
        else
        {
            prev->next = ptr->next;
        }
        cout << item << " is removed" << endl;
        delete ptr;
        count--;
    }
    else {
        cout << "Error.Entry doesn't exist.";
        cout << endl;
    }

}
int professor_list::get_count(void) const
{
    return count;
}
bool professor_list::ifempty(void) const
{
    return(count == 0);
}
void professor_list::clear(void)
{
    if (count != 0)
    {
        professor* ptr = start->next;
        while (ptr != NULL)
        {
            professor* prev = ptr;
            ptr = ptr->next;
            delete prev;
        }
        start = NULL;
        count = 0;
        cout << endl;
        cout << "The professor database has been cleared." << endl;
        cout << endl;
    }
}
string uppercaser(string a) {
    string str = a;
    for (int x = 0; x < str.length(); x++) {
        str[x] = toupper(str[x]);
    }
    return str;
}