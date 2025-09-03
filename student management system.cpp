#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENT=200;


struct Student{
    int studentNo;
    string name;
    string lastname;
    int birthYear;
    float gpa;
    string address;
    string department;
    string email;
};

bool insertNewRow(Student students[],int &studentCount,int MAX_STUDENT);
int findRow(Student students[], int studentCount, int studentNo);
void displayRow(const Student& s);
void displayTable(Student students[],int studentCount);
void editSingleRow(Student students[],int studentCount,int index);
void deleteRow(Student students[], int &studentCount, int index);



int main(){

    Student students[MAX_STUDENT];
    int studentCount=0;

    int choose;

    while(true){

    cout<<"Choose from the menu.\n";
    cout<<"1- New\n";
    cout<<"2- Find\n";
    cout<<"3- List\n";
    cout<<"4- Exit\n";

    cin>>choose;
    if(choose<1 || choose>4){
        cout<<"Invalid. Please re-enter";
        continue;
    }

    switch(choose){
        case 1: insertNewRow(students, studentCount, MAX_STUDENT);

        break;

        case 2:{
        int key;
        cout<<"Enter student number to find: ";
        cin>>key;
        cin.ignore();

        int index=findRow(students,studentCount, key);
            if(index==-1){
                cout<<"Record not found.\n";
                break;
            }
            

        displayRow(students[index]);

        while(true){
            int subChoice;
            cout<<"--- Sub Menu---\n";
            cout<<"1- Edit\n";
            cout<<"2- Delete\n";
            cout<<"3- Exit\n";
            cout<<"Your choice:";

            cin>>subChoice;

            switch(subChoice){
                case 1: editSingleRow(students,studentCount,index);
                        displayRow(students[index]);
                        break;

                case 2: deleteRow(students,studentCount,index);
                       break;

                case 3: 
                       break;

                default:
                       cout<<"Invalid. Please re-enter.\n";
            }
            if(subChoice==2 || subChoice ==3)break;

        }
        
        break;
    }

        case 3: 
        if(studentCount==0){
            cout<<"No record.\n";
        }else{
            cout<<"\n---Student List---\n";
            displayTable(students,studentCount);
        }
        break;

        case 4 : cout<<"Exiting program.\n";
        return 0;
        break;

    }
}


    return 0;
}


bool insertNewRow(Student students[],int &studentCount,int MAX_STUDENT){
    if(studentCount>=MAX_STUDENT){
        cout<<"Capacity is full.";
        return false;
    }else{
        Student st;
        cout<<"Enter the student no:";
        cin>>st.studentNo;
        cin.ignore();
        
        int index=findRow(students,studentCount,st.studentNo);

        if(index!=-1){
            cout<<"Existing student no.";
            return false;
        }


        while(true){
        cout<<"Enter student name:";
        getline(cin,st.name);
        if(!st.name.empty()) break;
            cout<<"This place can not be empty. Please re-enter:";
    }


        while(true){
        cout<<"Enter student lastname:";
        getline(cin,st.lastname);
        if(!st.lastname.empty()) break;
            cout<<"This place can not be empty. Please re-enter:";
        }


        while(true){
        cout<<"Enter student birt year(1800-2025):";
        cin>>st.birthYear;
        if(st.birthYear<1800 || st.birthYear>2025){
            cout<<"Out of range. Please re-enter.";
        }else{
            break;
        }
    }

    cin.ignore();

        while(true){
        cout<<"Enter the address:";
        getline(cin,st.address);
        if(!st.address.empty()) break;
            cout<<"This place can not be empty. Please reenter:";
        }


        while(true){
        cout<<"Enter the GPA:";
        cin>>st.gpa;
        if(st.gpa<0.0 || st.gpa>4.0) {
            cout<<"Out of range. Please re-enter.";
        }else{
            break;
        }
    }

        cin.ignore();

        
        while(true){
        cout<<"Enter the department:";
        getline(cin,st.department);
        if(!st.department.empty()) break;
            cout<<"This place can not be empty. Please reenter:";
        }

        while(true){
        cout<<"Enter the mail:";
        getline(cin,st.email);
        if(!st.email.empty()) break;
            cout<<"This place can not be empty. Please reenter:";
        }

        students[studentCount]=st;
        studentCount++;
        cout<<"New student recorded.\n";
        return true;

    }
}

int findRow(Student students[], int studentCount, int studentNo){
    if(studentCount==0){
        return -1;
    }else{
        for(int i=0;i<studentCount;i++){
            if(students[i].studentNo==studentNo){
                return i;
            }
        }
        return -1;
    }

}

void displayRow(const Student& s){

    cout<<'|'<< left<< setw(12) <<s.studentNo;
    cout<<'|'<< left<<setw(20) << s.name;
    cout<<'|'<< left<<setw(20)<<s.lastname;
    cout<<'|'<< left<<setw(8) <<s.birthYear;
    cout<<'|'<< left<<setw(20)<<s.address;
    cout<<'|'<<left <<setw(6)<<fixed<<setprecision(2)<<s.gpa;
    cout<<'|'<< left<<setw(30)<<s.department;
    cout<<'|'<<left<<setw(25)<<s.email;
    cout<<"|\n";
}


void displayTable(Student students[],int studentCount){
    if(studentCount==0){
        cout<<"No records:\n";
    }
cout << "|------------|--------------------|--------------------|--------|--------------------|------|------------------------------|-------------------------|\n";


    cout<<'|'<<left<<setw(12)<<"STUDENT NO";
    cout<<'|'<<left<<setw(20)<<"NAME";
    cout<<'|'<<left<<setw(20)<<"SURNAME";
    cout<<'|'<<left<<setw(8)<<"YEAR";
    cout<<'|'<<left<<setw(20)<<"ADDRESS";
    cout<<'|'<<left<<setw(6)<<"GPA";
    cout<<'|'<<left<<setw(30)<<"DEPARTMENT";
    cout<<'|'<<left<<setw(25)<<"EMAIL";
    cout<<"|\n";
cout << "|------------|--------------------|--------------------|--------|--------------------|------|------------------------------|-------------------------|\n";


    for(int i=0;i<studentCount;i++){
        displayRow(students[i]);
        cout << "|------------|--------------------|--------------------|--------|--------------------|------|------------------------------|-------------------------|\n";
    }



}

void editSingleRow(Student students[],int studentCount,int index){
    if(index<0 || index>=studentCount){
        cout<<"Invalid index.\n";
        return;
    }

    Student &st=students[index];
    
    cout<<"\n---Edit Record---\n";

    int newNo;
    cout<<"Currently used student no: "<<st.studentNo<<", Enter new student no: ";
    cin>>newNo;
    cin.ignore();

    bool isSame=false;
    for(int i=0;i<studentCount;i++){
        if(i!=index && students[i].studentNo==newNo){
            isSame=true;
            break;
        }
    }
    if(!isSame){
        st.studentNo=newNo;
    }else{
        cout<<"Keeping same value.\n";
    }

    cout<<"Currently used name: "<<st.name<<", Enter new name: ";
    getline(cin,st.name);

    cout<<"Currently used lastname: "<<st.lastname<<", Enter new lastname: ";
    getline(cin,st.lastname);

    

    cout<<"Currently used birth year: "<<st.birthYear<<", Enter new birth year: ";
    int year;
    cin>>year;
    cin.ignore();
    if(year>=1800 && year<=2025){
        st.birthYear=year;
    }else{
        cout<<"Out of range.Keeping same value.\n";
    }
    

    cout<<"Currently used GPA: "<<st.gpa<<", Enter new GPA: ";
    float g;
    cin>>g;
    cin.ignore();
    if(g>=0.0 && g<=4.0){
        st.gpa=g;
    }else{
        cout<<"Out of range.Keeping same value.\n";
    }

   

    cout<<"Currently used address: "<<st.address<<", Enter new address: ";
    getline(cin,st.address);

    cout<<"Currently used department: "<<st.department<<", Enter new department: ";
    getline(cin,st.department);

    cout<<"Currently used email: "<<st.email<<", Enter new email: ";
    getline(cin,st.email);

    cout<<"Record updated.\n";
    
}

void deleteRow(Student students[], int &studentCount, int index){
    if(index<0 || index>=studentCount){
        cout<<"Invalid index.\n";
        return;
    }
    for(int i=index;i<studentCount-1;i++){
        students[i]=students[i+1];
    }
    studentCount--;
    cout<<"Record deleted.\n";
}
