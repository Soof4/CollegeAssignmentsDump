using System.Collections.Generic;
using MySql.Data.MySqlClient;

namespace IlerProgOdevDatabase
{
    public class DatabaseManager
    {
        private readonly MySqlConnection _db;

        public DatabaseManager(string connectionString) {
            
            _db = new MySqlConnection(connectionString);
            _db.Open();

            try {
                // Try creating a database and table (for first time use)
                ExecuteNonQueryCmd("CREATE DATABASE StudentDB");
                ExecuteNonQueryCmd("USE StudentDB");
                ExecuteNonQueryCmd("CREATE TABLE Students (ID INT PRIMARY KEY, Ogrno VARCHAR(255), Ad VARCHAR(255), Soyad VARCHAR(255), Email VARCHAR(255), Fakulte VARCHAR(255), Bolum VARCHAR(255));");
            }
            catch {
                // If database or table already exists then use those
                ExecuteNonQueryCmd("USE StudentDB");
                ExecuteNonQueryCmd("DELETE FROM Students");
            }
        }

        public void InsertStudent(int id , string number, string firstName, string lastName, string email, string faculty, string major) {
            try {
                ExecuteNonQueryCmd($"INSERT INTO Students VALUES ({id}, '{number}', '{firstName}', '{lastName}', '{email}', '{faculty}', '{major}')");
            }
            catch { }
        }

        public List<Student> ReadStudents() {
            List<Student> ls = new List<Student>();

            var reader = ExecuteReaderCmd("SELECT * FROM Students");
            
            while (reader.Read()) {
                ls.Add(new Student(
                        reader.GetInt32("ID"),
                        reader.GetString("Ogrno"),
                        reader.GetString("Ad"),
                        reader.GetString("Soyad"),
                        reader.GetString("Email"),
                        reader.GetString("Fakulte"),
                        reader.GetString("Bolum")
                    ));
            }

            reader.Close();
            return ls;
        }

        public void UpdateStudent(int id, string newFirstName, string newLastName) {
            try {
                ExecuteNonQueryCmd($"UPDATE Students SET Ad = '{newFirstName}', Soyad = '{newLastName}' WHERE ID = {id}");
            }
            catch { }
        }

        public void DeleteStudent(int id) {
            try {
                ExecuteNonQueryCmd($"DELETE FROM Students WHERE ID = {id}");
            }
            catch { }
        }

        #region MySqlCommand Wrappers

        private int ExecuteNonQueryCmd(string cmd) {
            MySqlCommand c = new MySqlCommand(cmd, _db);
            return c.ExecuteNonQuery();
        }

        private MySqlDataReader ExecuteReaderCmd(string cmd) {
            MySqlCommand c = new MySqlCommand(cmd, _db);
            return c.ExecuteReader();
        }

        #endregion
    }
}
