using IlerProgOdevDatabase;
using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IleriProgOdev {
    public partial class Form1 : Form {
        public static readonly DatabaseManager DBManager = new DatabaseManager("server=localhost;port=3306;user=root;password=123");
        private object obj = new object();
        public Form1() {
            InitializeComponent();
        }

        private void button_delete_Click(object sender, EventArgs e) {
            lock (obj) {
                new Thread(() => {
                    // Read the file and insert students
                    using (FileStream fs = new FileStream("Ogrenci_List_Silinecekler.txt", FileMode.Open))
                    using (StreamReader sr = new StreamReader(fs)) {

                        while (true) {
                            string line = sr.ReadLine();

                            if (line == null) break;
                            if (line == "") continue;

                            string[] ids = line.Split('#');

                            foreach (string id in ids) DBManager.DeleteStudent(int.Parse(id));
                        }

                    }

                    UpdateDataGridView();

                }).Start();
            }
        }

        private void button_add_Click(object sender, EventArgs e) {
            lock (obj) {
                new Thread(() => {
                    // Read the file and delete students
                    using (FileStream fs = new FileStream("Ogrenci_List_Eklenecekler.txt", FileMode.Open))
                    using (StreamReader sr = new StreamReader(fs)) {

                        while (true) {
                            string line = sr.ReadLine();

                            if (line == null) break;
                            if (line == "") continue;

                            string[] fields = line.Split('#');
                            DBManager.InsertStudent(int.Parse(fields[0]), fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]);
                        }
                    }

                    UpdateDataGridView();

                }).Start();
            }
        }

        private void button_update_Click(object sender, EventArgs e) {
            lock (obj) {
                new Thread(() => {
                    if (!int.TryParse(textBox_id.Text, out _)) return;    // If ID input is not integer then don't do anything

                    DBManager.UpdateStudent(int.Parse(textBox_id.Text), textBox_firstName.Text, textBox_lastName.Text);

                    UpdateDataGridView();

                }).Start();
            }
        }

        private void UpdateDataGridView() {
            List<Student> ls = DBManager.ReadStudents();
            dataGridView_database.Invoke((MethodInvoker)delegate {
                dataGridView_database.DataSource = ls;
            });
        }
    }
}
