#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Course class
class course {
private:
    string name;
    string code;
    int credit_hours;
public:
    course(string cname, int code, int chours);
    void read(istream& in);
    void write(ostream& out) const;
};


// User class
class user {

private:
    string name;
    int id;
    string address;
    string phone_number;

public:
    user(string n = " ", int i = 0, string a = " ", string p = " ");
    virtual void read(istream& in);
    virtual void write(ostream& out) const;
    string get_name(void) const;
};

// Student class
class student : public user {
    friend class student_list;
private:
    double gpa;
    string major;
    double fee_amount;
    bool fee_status;
    vector<course> courses;
    student* next;

public:
    student(string n = " ", int i = 0, string a = " ", string p = " ", double g = 0, string m = " ", double f = 0, bool s = 0, int numb = 0);
    void read(istream& in);
    void write(ostream& out) const;

    friend class course;
};

class student_list {

private:
    student* start;
    int count;

public:
    student_list(void);
    void push(ostream& out);
    void print_list(ostream& out);
    void delete_item(void);
    int get_count(void) const;
    bool ifempty(void) const;
    void clear(void);
};

// Professor class
class professor : public user {
    friend class professor_list;
private:
    double salary;
    int num_courses;
    string department;
    string start_date;
    professor* next;
public:
    professor(string n = " ", int i = 0, string a = " ", string p = " ", double s = 0, int n_c = 0, string d = " ", string s_d = " ");
    void read(istream& in);
    void write(ostream& out) const;
};

class professor_list {

private:
    professor* start;
    int count;

public:
    professor_list(void);
    void push(ostream& out);
    void print_list(ostream& out);
    void delete_item(void);
    int get_count(void) const;
    bool ifempty(void) const;
    void clear(void);
};
string uppercaser(string a);
#endif /*CLASS_H*/