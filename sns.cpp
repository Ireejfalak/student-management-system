#include <iostream>
using namespace std;
class student{
private:
int stdid;
string stdname;
int age;
string gender;
public:
student(){}
student(int id,string name,int a,string g){
  stdid=id;
  stdname=name;
  age=a;
  gender=g;
}
int  getstdid(){
  return stdid;
}
string getstdname(){
  return stdname;
}
int getage(){
  return age;
}
string getgender(){
  return gender;
}
void display(){
  cout<<"Student Id is:"<<stdid<<"\tStudent Name is:"<<stdname<<"\tStudent age is:"<<age<<"\tStudent gender is:"<<gender<<"\n";
}
};
class Course{
private:
int courseid;
string coursename;
int credithours;
public:
Course(){}
Course(int id,string name,int hours){
  courseid=id;
  coursename=name;
  credithours=hours;
}
int getcourseid(){
  return courseid;
}
string getcoursename(){
  return coursename;
}
int getcredithours(){
  return credithours;
}
void display(){
  cout<<"Course Id is:"<<courseid<<"\tCourse name is:"<<coursename<<"\tCourse credithours are:"<<credithours<<endl;
}
};
class Grade{
private:
int stdid;
string coursename;
char grade;
public:
Grade(){}
Grade(int id,string name, char g){
  stdid=id;
  coursename=name;
  grade=g;
}
int getstdid(){
  return stdid;
}
string getcoursename(){
  return coursename;
}
char getgrade(){
  return grade;
}
void display(){
  cout<<"Student Id is:"<<stdid<<"\tCourse name is:"<<coursename<<"\tGrade is:"<<grade<<endl;
}
};
class AttendanceRecord{
private:
int stdid;
string coursename;
float attendancepercentage;
public:
AttendanceRecord(){
}
AttendanceRecord(int id,string name,float percentage){
  stdid=id;
  coursename=name;
  attendancepercentage=percentage;
}
int getstdid(){
  return stdid;
}
string getcoursename(){
  return coursename;
}
float getattendancepercentage(){
  return attendancepercentage;
}
void display(){
  cout<<"Student Id is:"<<stdid<<"\tCourse name is:"<<coursename<<"\tAttendace percentage is:"<<attendancepercentage<<"%"<<endl;
}
};
class StudentManagementSystem{
public:
student arr_students[5000];
Course arr_courses[5000];
Grade arr_grades[5000];
AttendanceRecord arr_attendance[5000];
int studentcount=0;
int coursecount=0;
int gradecount=0;
int attendancecount=0;
StudentManagementSystem(){
}
void addstudent(){
  int stdid,age;
  string stdname,gender;
  cout<<"Enter Student Id:";
  cin>>stdid;
  cout<<"Enter Student name:";
  cin>>stdname;
  cout<<"Enter Student gender:";
  cin>>gender;
  cout<<"Enter Student age:";
  cin>>age;
  arr_students[studentcount]=student(stdid,stdname,age,gender);
  studentcount++;
}
void addcourse(){
  int courseid,credithours;
  string coursename;
  cout<<"Enter Course id:";
  cin>>courseid;
  cout<<"Enter Course Name:";
  cin>>coursename;
  cout<<"Enter Course Credit Hours:";
  cin>>credithours;
  arr_courses[coursecount]=Course(courseid,coursename,credithours);
  coursecount++;
}
void addgrade(){
  int stdid;
  string coursename;
  char grade;
  cout<<"Enter Student Id:";
  cin>>stdid;
  cout<<"Enter Course name:";
  cin>>coursename;
  cout<<"Enter grade:";
  cin>>grade;
  try{
    if(grade=='A'||grade=='B'||grade=='C'||grade=='C'||grade=='D'||grade=='F'){
      arr_grades[gradecount]=Grade(stdid,coursename,grade);
    gradecount++;   
  }
    else
      throw grade;
  }
    catch(char grade){
    cout<<"Grade must be A,B,C,D,F but you entered:"<<grade;
    }}
  void addattendance(){
    int stdid;
    string coursename;
    float attendancepercentage;
    cout<<"Enter Student Id:";
    cin>>stdid;
    cout<<"Enter course name:";
    cin>>coursename;
    cout<<"Enter Attendance percentage in this course:";
    cin>>attendancepercentage;
    arr_attendance[attendancecount]=AttendanceRecord(stdid,coursename,attendancepercentage);
    attendancecount++;
  }
  void displaystudents(){
    for(int i=0;i<studentcount;i++){
      arr_students[i].display();
    }
  }
  void displaycourses(){
    for(int i=0;i<coursecount;i++){
      arr_courses[i].display();
    }
  }
  void displaygrades(){
    for(int i=0;i<gradecount;i++){
      arr_grades[i].display();
    }
  }
  void displayattendance(){
    for(int i=0;i<attendancecount;i++){
      arr_attendance[i].display();
    }
  }
};
int main(){
  StudentManagementSystem sms ;
  int choice;
  do{
    cout<<" 1. Add Student\n 2. Add Course\n 3. Addd Grade\n 4. Add Attendance Record\n 5. Display Students\n 6. Display courses \n 7. Display grades \n 8. Display Attendance Records\n 9. Exit\n";
    cout<<"Enter Your Choice between 1 to 9:";
    cin>>choice;
    switch(choice){
      case 1:
      sms.addstudent();
      break;
      case 2:
      sms.addcourse();
      break;
      case 3:
      sms.addgrade();
      break;
      case 4:
      sms.addattendance();
      break;
      case 5:
      sms.displaystudents();
      break;
      case 6:
      sms.displaycourses();
      break;
      case 7:
      sms.displaygrades();
      break;
      case 8:
      sms.displayattendance();
      break;
      case 9:
      cout<<"Thank you for using this system. Goodbye!";
      break;
      default:
      cout<<"Invalid choice. Please try again.";
      break;
      
    }
    
  }while(choice!=0);
}