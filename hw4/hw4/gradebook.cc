// Copyrith 2020 Evan Owre
#include <inc/gradebook.h>
#include <cstddef>  // using size_t
#include <vector>
#include <iostream>
using namespace::std;

GradeBook::GradeBook() {}   
void GradeBook::Add(char grade) {
  grades_.push_back(grade);
}
char GradeBook::Get(size_t index) const {
  return grades_[index];
}
const GradeBook GradeBook::Add(const GradeBook& that) const {
  //for (size_t i = 0; i<that.size(); ++i)
    
}
char GradeBook::GetGPA() const {
  double total = 0.0;
  for (size_t i = 0; i < grades_.size(); ++i) {
    if (grades_[i] == 'A')
      total += 4.0;
  else if (grades_[i] == 'B')
      total += 3.0;
  else if (grades_[i] == 'C')
      total += 2.0;
  else if (grades_[i] == 'D')
      total += 1.0;
  else if (grades_[i] == 'F')
      total += 0.0;
    else
      total += 0.0;
  }
  double numGPA = total/grades_.size();
  if (numGPA == 4.0)
    return 'A';
  else if (numGPA > 3.0)
    return 'B';
  else if (numGPA > 2.0)
    return 'C';
  else if (numGPA > 1.0)
    return 'D';
  else if (numGPA == 0.0)
    return '0';
  else
    return 'F'; 
}
char GradeBook::GetMax() const {
  char ret;
  double weight;
  size_t count = 0;
  bool run = true;
  while (run == true) {
    char temp = grades_[count];
    if (temp == 'A') {
      ret = 'A';
      run = false;
      weight = 4.0;
    } else if (temp == 'B' && weight < 3.0) {
      ret = 'B';
      weight = 3.0;
    } else if (temp == 'C' && weight < 2.0) {
      ret = 'C';
      weight = 2.0;      
    } else if (temp == 'D' && weight < 1.0) {
      ret = 'D';
      weight = 1.0;
    } else if (temp == 'F' && weight != 0.0) {
      ret = 'F';
      weight = 0.0;
    } else 
      ret = '0';
    ++count;
  }
  return ret;
}
const size_t GradeBook::GetSize() const {
  size_t size = grades_.size();
  return size;
}
bool GradeBook::Equals(const GradeBook& that) const {
  if (this->GetGPA() == that.GetGPA())
    return true;
  return false;
}
bool GradeBook::LessThan(const GradeBook& that) const {
  if (this->GetGPA() < that.GetGPA())
    return true;
  return false;

}

