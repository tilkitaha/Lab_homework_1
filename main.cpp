#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


class Complex {
   public:
   float r_, i_;
      Complex() {
         r_ = 0; i_ = 0;
      }
      Complex(float r, float i) {       
         r_ = r; i_ = i;
      }
      void set_im(float i) {
          i_ = i;
      }
      Complex (float r) {
          r_=r;
      }
      friend Complex add(Complex, Complex);
      void print();
};
Complex add(Complex n1, Complex n2) {
    Complex res;
    res.r_=n1.r_ + n2.r_;  // adding real part of complex numbers
   res.i_ =n1.i_ + n2.i_;
   return res;
}

void Complex::print() {
    if(i_ < 0) {
        if(i_ == -1)
        std::cout << "The complex number is: " << r_ << "-i" << std::endl;
        else
            std::cout << "The complex number is: " << r_ << i_ << "i" << std::endl;
        } else
        if(i_ == 1)
            std::cout << "The complex number is: " << r_ << " + i" << std::endl;
    else std::cout << "The complex number is " << r_ << " + " << i_ << "i" << std::endl;
    }


class Student {
    std::string name;
    std::string surname;
    int album_number;
    std::vector<float> grades;
public:
    Student() {}
    Student(std::string name_, std::string surname_, int album_number_, std::vector<float> grades_) {
        name = name_;
        surname = surname_;
        album_number = album_number_;
        grades = grades_;
    }

    void set_name(std::string name_) {
        name = name_;
    }
    void set_surname(std::string surname_) {
        surname = surname_;
    }

    void set_album(int album_number_) {
        if(album_number_>=10000 && album_number_<= 99999)
        album_number = album_number_;
    }

    std::string get_name() {
        return name;
    }

    std::string get_surname() {
        return surname;
    }

    int get_album() {
        return album_number;
    }

    float calculate_grade() {
        std::cout << "Average grades of " << name + " " + surname  + ": " ;
        float ave;
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return ave= sum / grades.size();
    }

    bool add_grade(float grade) {
        if(grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    bool passed(float ave) {
        if(ave >= 2.0 && ave <= 5.0) {
            std::cout << "PASSED!!!!!" << std::endl;
            return true;
        } else {
            std::cout << "FAILED!!!!!" << std::endl;
            return false;
        }
    }

    void summary() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Surname: " << surname << std::endl;
        std::cout << "Album Number: " << album_number << std::endl;
        std::cout << "Grades: " << std::endl;
        for (int i=0;i<grades.size();i++)
            std::cout << "\t" << grades[i] << std::endl;
        std::cout << std::endl;
    }
};



int main()
{
//    Student student1;

//    student1.set_name("Moly");
//    Student student2("Tha", "Tilki", 153910,{0.0, 1.1});
//    std::cout << "Student name is :" << student3.get_name() << std::endl;
//    Student student3;
Student student3("Taha", "Tilki", 150224,{4.0,3.5,2.3, 1.1});
//        student3.set_name("Moly");
//        student3.set_surname("Cavusoglu");
//        student3.set_album(12345);

//        std::cout << "student name is " << student3.get_name() << " and surname is " << student3.get_surname() <<              "student album number: " << student3.get_album() << std::endl;
        student3.summary();
        student3.add_grade(4.5);
        student3.add_grade(3.5);


        float ave = student3.calculate_grade();

        std::cout << ave << std::endl;
        student3.passed(ave);

        std::cout << "Part 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        Complex a(1.0, -2.0),b(3.14);
        a.print();
        b.print();
        b.set_im(-5);
        b.print();
        Complex c = add(a,b);
        c.print();



    return 0;
}
