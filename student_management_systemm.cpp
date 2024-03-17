#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

bool Eck(string el)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(el, pattern);
}

class st
{
private:
    string ne, roll_no, course, adr, email_id, assignments[15], exams[15];
    long long int contact_no;
    int assignment_count, exam_count;
    double marks[15];

public:
    void menu();
    void ist();
    void dis();
    void modify();
    void search();
    void del();
    void i_e();
};

void st::menu()
{
menustart:
    int ce;
    char z;
    system("cls");
    cout << "\t\t\t-------<----------->-----------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t--------<------------>---------" << endl;
    cout << "\t\t\t 1. Enter New Record of student " << endl;
    cout << "\t\t\t 2. Display Record of student" << endl;
    cout << "\t\t\t 3. Modify Record  of student" << endl;
    cout << "\t\t\t 4. Search Record of student" << endl;
    cout << "\t\t\t 5. Delete Record of student" << endl;
    cout << "\t\t\t 6. Add Examination Details of student" << endl;
    cout << "\t\t\t 7. Exit\n"
         << endl;

    cout << "\t\t\t......<.......>..............." << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7]" << endl;
    cout << "\t\t\t........<......>.............." << endl;
    cout << " Enter Your Choose: ";
    cin >> ce;
    switch (ce)
    {
    case 1:
        do
        {
            ist();
            cout << "\n\n\t\t\t Please add another student record if you want  (Y, N) : ";
            cin >> z;
        } while (z == 'y' || z == 'Y');
        break;
    case 2:
        dis();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        del();
        break;
    case 6:
        i_e();
        break;
    case 7:
        cout << "\n\t\t\t Exit command for project";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice .Please try  it again";
    }
    goto menustart;
}

void st::ist()
{
    system("cls");
    fstream file;
    cout << "\n-----------------------<------------------------------------------------------->-------------------------" << endl;
    cout << "-----------------------------<-------- Add Student Details ----->----------------------------------------" << endl;
    cout << "\t\t\tEnter Name of student: ";
    cin >> ne;
    cout << "\t\t\tEnter Roll No. of student: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course of student: ";
    cin >> course;
el:
    cout << "\t\t\tEnter Email Id(name@gmail.com) of student: ";
    cin >> email_id;
    if (Eck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid " << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto el;
    }
contact:
    cout << "\t\t\tEnter Contact No(9639xxxxxx) of student: ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\nEnter Address: ";
    cin >> adr;
    cout << "\nEnter the number of assignments of student: ";
    cin >> assignment_count;
    cout << "Enter assignments of student:\n";
    for (int i = 0; i < assignment_count; ++i)
    {
        cin >> assignments[i];
    }
    file.open("sR.txt", ios::app | ios::out);
    file << " " << ne << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adr << " ";
    for (int i = 0; i < assignment_count; ++i)
    {
        file << assignments[i] << " ";
    }
    file << "\n";
    file.close();
}



void st::i_e()
{
    system("cls");
    fstream file;
    string rollno;
    int n;
    cout << "\n------------<----------------------------------------------------------------->--------------------------" << endl;
    cout << "---------------------------<---------- Add Examination Details ---->--------------------------------------" << endl;
    file.open("sR.txt", ios::app | ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student to add examination details : ";
        cin >> rollno;
        cout << "\n\t\t\tEnter how many exams you want to add: ";
        cin >> n;
        cout << "\nEnter examination details:\n";

       
        string exams[n];
        double marks[n];
        char gds[n];
        vector<string> tDs;

        for (int i = 0; i < n; ++i)
        {
            cout << "Enter exam  of student" << i + 1 << ": ";
            cin >> exams[i];
            cout << "Enter marks for exam of student " << i + 1 << ": ";
            cin >> marks[i];

           
            if (marks[i] >= 90)
                gds[i] = 'A';
            else if (marks[i] >= 80)
                gds[i] = 'B';
            else if (marks[i] >= 70)
                gds[i] = 'C';
            else if (marks[i] >= 60)
                gds[i] = 'D';
            else if (marks[i] >= 50)
                gds[i] = 'E';
            else
                gds[i] = 'F';

            
            if (gds[i] == 'A' || gds[i] == 'B')
                tDs.push_back("Research paper");
            else if (gds[i] == 'C' || gds[i] == 'D')
                tDs.push_back("Presentation");
            else
                tDs.push_back("Essay");

            cout << "\nExam " << i + 1 << " Grade: " << gds[i] << "\n";
            cout << "Task Description for Exam " << i + 1 << ": " << tDs[i] << "\n";
        }

       
        file << rollno << " " << n << " ";
        for (int i = 0; i < n; ++i)
        {
            file << exams[i] << " " << marks[i] << " " << gds[i] << " " << tDs[i] << " ";
        }
        file << "\n";

        file.close();
        cout << "\n\t\t\tExamination details added successfully\n";
    }
}

void st::dis()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n------------------<-------------------------------------------------------------->-----------------------" << endl;
    cout << "--------------------------<----------- Student Record Table --------------->-----------------------------" << endl;
    file.open("sR.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is there ";
        file.close();
    }
    else
    {
        while (file >> ne >> roll_no >> course >> email_id >> contact_no >> adr >> exam_count)
        {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName of student: " << ne << "\n";
            cout << "\t\t\tRoll No. of student: " << roll_no << "\n";
            cout << "\t\t\tCourse of student: " << course << "\n";
            cout << "\t\t\tEmail Id of student : " << email_id << "\n";
            cout << "\t\t\tContact No. of student : " << contact_no << "\n";
            cout << "\t\t\tAddress of student : " << adr << "\n";
            cout << "\t\t\tAssignments of student : ";
            for (int i = 0; i < assignment_count; ++i)
            {
                cout << assignments[i] << " ";
            }
            cout << "\n\t\t\tExams: ";
            for (int i = 0; i < exam_count; ++i)
            {
                cout << exams[i] << " Marks: " << marks[i] << " ";
            }
            cout << endl;
        }
        if (total == 1)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void st::search() 
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("sR.txt", ios::in);
    if (!file)
    {
        cout << "\n------------------<-------------------------------------------->-----------------------------------------" << endl;
        cout << "--------------------------<----------- Student Search Data ---------->----------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n----------------<------------------------------------------------->--------------------------------------" << endl;
        cout << "-----------------<-------------------- Student Search Table -------->------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        while (file >> ne >> roll_no >> course >> email_id >> contact_no >> adr)
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName of student : " << ne << "\n";
                cout << "\t\t\tRoll No. of student:  " << roll_no << "\n";
                cout << "\t\t\tCourse of student : " << course << "\n";
                cout << "\t\t\tEmail Id of student : " << email_id << "\n";
                cout << "\t\t\tContact No.of student : " << contact_no << "\n";
                cout << "\t\t\tAddress of student : " << adr<< "\n";
                cout << "\t\t\tAssignments of student : ";
                for (int i = 0; i < assignment_count; ++i)
                {
                    cout << assignments[i] << " ";
                }
                cout << endl;
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file.close();
    }
}

void st::del() 
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("sR.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is there";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("rc.txt", ios::app | ios::out);
        while (file >> ne >> roll_no >> course >> email_id >> contact_no >> adr)
        {
            if (roll != roll_no)
            {
                file1 << " " << ne << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adr << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("sR.txt");
        rename("rc.txt", "sR.txt");
    }
}
void st::modify() 
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("sR.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("rc.txt", ios::app | ios::out);
        while (file >> ne >> roll_no >> course >> email_id >> contact_no >> adr)
        {
            if (rollno != roll_no)
                file1 << " " << ne << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adr << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> ne;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
            el:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;
                if (Eck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto el;
                }
            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "\t\t\tEnter Address: ";
                cin >> adr;
                cout << "\t\t\tEnter the number of assignments: ";
                cin >> assignment_count;
                cout << "\t\t\tEnter assignments:\n";
                for (int i = 0; i < assignment_count; ++i)
                {
                    cin >> assignments[i];
                }
                file1 << " " << ne << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << adr << " ";
                for (int i = 0; i < assignment_count; ++i)
                {
                    file1 << assignments[i] << " ";
                }
                file1 << "\n";
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t  The student roll No. is not found....";
        }
        file1.close();
        file.close();
        remove("sR.txt");
        rename("rc.txt", "sR.txt");
    }
}


int main()
{
    st project;
    project.menu();  
    return 0;
}