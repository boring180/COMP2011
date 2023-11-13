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
    for(int sort_iteration = 0; sort_iteration < num_students - 1; sort_iteration++)
    {   
        // cout<<"sort_iteration"<<sort_iteration<<endl;
        for(int index = 0;index < num_students - sort_iteration - 1;index++)
        {   
            if(queue[index] == nullptr)break;
            // cout<<"index"<<index<<endl;
            if(queue[index]->yearOfStudy < queue[index+1]->yearOfStudy)
            {
                Student temp = *queue[index];
                *queue[index] = *queue[index+1];
                *queue[index+1] = temp;
            }
        }
    }
    return;
}