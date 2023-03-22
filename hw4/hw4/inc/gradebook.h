#include <cstddef>
// using size_t

class GradeBook {
 public:
  /* May or may not be required depending on how you manage memory. You may
   * delete if unused.
   */
  GradeBook();


  /* Adds a new grade to the gradebook instance, increasing size by 1.
   */
  void Add(char grade);


  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of \0 is returned.
   */
  char Get(size_t index) const;


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook Add(const GradeBook& that) const;


  /* Returns the average of all grades stored in GradeBook instance, or \0 if
   * the the GradeBook instance is empty.
   */
  char GetGPA() const;


  /* Returns the max grade in the GradeBook or \0 if the calling instance is
   * empty.
   */
  char GetMax() const;


  /* Returns the number of grades currently stored by the GradeBook.
   */
  const size_t GetSize() const;


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -1.0---that is, less than F.
   */
  bool Equals(const GradeBook& that) const;


  /* Returns true when the calling instance has a lower grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -1.0--that is, less than F.
   */
  bool LessThan(const GradeBook& that) const;

};
