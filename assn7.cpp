#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int MAX = 10;

class student;
class hashtable;

class record{
    int roll, marks;
    char name[20];
    friend class student;
};

class hashtable{
    int roll, pos;
    public:
        hashtable(){
            roll = -1;
            pos = -1;
        }
    friend class student;
};

class student{
    hashtable h[20];
    int size;
    int relpos;

    public:
        void insert();
        void display();
        void modify();
        void retrive();
        student(){
            size = sizeof(record);
            for(int i=0; i<MAX; i++){
                h[i].roll = -1;
                h[i].pos = -1;
            }
        relpos = 0;
        }
};

void student::insert(){
    record rec;
    char choice;
    fstream f;
    f.open("yash.txt",ios::binary|ios::out);
    int loc;
    do{
        cout<<"Enter student details :"<<endl;
        cout<<"Roll No.:";
        cin>>rec.roll;
        cout<<"Name :";
        cin>>rec.name;
        cout<<"Marks :";
        cin>>rec.marks;

        loc = rec.roll%MAX;
        if(h[loc].roll == -1){
            h[loc].roll = rec.roll;
            h[loc].pos = relpos;
            f.write((char*)&rec , size);
            // relpos += size;
            relpos += 1;
        }
        else{
            int i = (loc+1)%MAX;
            while(i != loc){
                if(h[loc].roll == -1){
                    h[loc].roll = rec.roll;
                    h[loc].pos = relpos;
                    f.write((char*)&rec , size);
                    // relpos += size;
                    relpos += 1;
                    break;
                }
                i = (i+1)%MAX;
            }
            if(i == loc)
                cout<<"Hash is full"<<endl;
        }
        cout<<"Do want to insert another record?(y/n): ";
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');
}

void student :: modify(){
    record rec;
    fstream f;
    f.open("yash.txt",ios::binary | ios::in | ios::out);
    cout<<"Enter the roll no. of the student whose record is"
        <<"to be modified: ";
    cin>>rec.roll;

    int loc = rec.roll%10;
    int last = 0;
    for(int i=0; i<MAX; i++){
        last = i;
        if(h[loc].roll == rec.roll){
            int p = h[loc].pos * size;
            f.seekg(p, ios::beg);
            f.read((char*)&rec, size);
            // display();

            cout<<"Enter the new details of the student:"<<endl;
            cout<<"Name: ";
            cin>>rec.name;
            cout<<"Marks: ";
            cin>>rec.marks;

            p = h[loc].pos*size;
            f.seekp(p, ios::beg);
            f.write((char*)&rec, size);
            break;
        }
        else{
            loc = (loc+1)%10;
        }
    }
    if(last >= MAX){
        cout<<"Record not found"<<endl;
    }
    f.close();
}

void student :: retrive(){
    record rec;
    fstream f;
    f.open("yash.txt", ios::binary | ios::in);
    cout<<"Enter roll no of student whose data is "
        <<"to be retrived:";
    cin>>rec.roll;

    int loc = rec.roll%10;
    int last = 0;
    for(int i=0; i<MAX; i++){
        last = i;
        if(h[loc].roll == rec.roll){
            int p = h[loc].pos * size;
            f.seekg(p, ios::beg);
            f.read((char*)&rec, size);
            cout<<"Roll no.: "<<rec.roll<<endl;
            cout<<"Name: "<<rec.name<<endl;
            cout<<"Marks: "<<rec.marks<<endl;

            relpos += 1;
            break;
        }
        else{
            loc = (loc+1)%MAX;
        }
    }

    if(last >= MAX){
        cout<<"Record not found"<<endl;
    }
}

void student :: display(){
    record rec;

    cout<<"The Hashtable is as follows: "<<endl;
    cout<<"Roll No.\tPosition"<<endl;
    for(int i=0; i<MAX; i++){
        cout<<h[i].roll<<"\t\t"<<h[i].pos<<endl;
    }

    cout<<endl<<"Student records are as follows: "<<endl;
    fstream f;
    f.open("yash.txt", ios::binary|ios::in);
    for(int i=0; i<MAX; i++){
        if(h[i].roll != -1){
            int p = h[i].pos * size;
            f.seekg(p, ios::beg);
            f.read((char*)&rec, size);
        }
    }
    f.close();
}

int main(){
    student mit;
    int choice;
    while(1){
        cout<<"1. Insert records in the file and their positions in hashtable"<<endl
            <<"2. Modify any record"<<endl
            <<"3. Retrive any record"<<endl
            <<"4. Display all records"<<endl
            <<"5. Exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            mit.insert();
            break;

            case 2:
            mit.modify();
            break;

            case 3:
            mit.retrive();
            break;

            case 4:
            mit.display();
            break;

            case 5:
            exit(0);
            
        }
    }

}