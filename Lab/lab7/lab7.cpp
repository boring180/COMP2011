#include <iostream>
#include "lab7.h"
using namespace std;

// TODO: Reorder the student
// Parameters:
// <queue>: An array of pointer to <Student>s. 
// <num_stduents>: the number of students currently in the <queue>
// Task:
// Use the <yearOfStudy> member of the <Student> struct to reorder the students.
// Students at a higher year of study should be ordered in front.
// You can use bubble sort for the reordering. The detail instruction is on Lab7 webpage.
void reorder_student(Student* queue [], int num_students) {
//The sorting literation
for(int right_lim = num_students - 1;right_lim > 0;right_lim--)
{
    for(int left_lim = 0;left_lim < right_lim;left_lim++)
    {
        if(queue[left_lim] -> yearOfStudy < queue[left_lim + 1] -> yearOfStudy)
        {
            Student *tmp = queue[left_lim];
            queue[left_lim] = queue[left_lim + 1];
            queue[left_lim + 1] = tmp;
        }
    }
}
}