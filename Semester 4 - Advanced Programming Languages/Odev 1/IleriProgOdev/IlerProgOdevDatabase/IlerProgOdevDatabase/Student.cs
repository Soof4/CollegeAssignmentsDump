using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IlerProgOdevDatabase {
    public class Student {
        public int ID { get; set; }
        public string Number { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Faculty { get; set; }
        public string Major { get; set; }

        public Student(int id, string number, string firstName, string lastName, string email, string faculty, string major) {
            ID = id;
            Number = number;
            FirstName = firstName;
            LastName = lastName;
            Email = email;
            Faculty = faculty;
            Major = major;
        }
    }
}
