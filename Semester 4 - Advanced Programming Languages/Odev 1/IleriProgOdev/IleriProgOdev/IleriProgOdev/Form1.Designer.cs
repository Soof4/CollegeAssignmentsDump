namespace IleriProgOdev {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.label_id = new System.Windows.Forms.Label();
            this.label_firstName = new System.Windows.Forms.Label();
            this.label_lastName = new System.Windows.Forms.Label();
            this.textBox_id = new System.Windows.Forms.TextBox();
            this.textBox_firstName = new System.Windows.Forms.TextBox();
            this.textBox_lastName = new System.Windows.Forms.TextBox();
            this.button_delete = new System.Windows.Forms.Button();
            this.button_add = new System.Windows.Forms.Button();
            this.button_update = new System.Windows.Forms.Button();
            this.dataGridView_database = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_database)).BeginInit();
            this.SuspendLayout();
            // 
            // label_id
            // 
            this.label_id.AutoSize = true;
            this.label_id.Location = new System.Drawing.Point(16, 16);
            this.label_id.Name = "label_id";
            this.label_id.Size = new System.Drawing.Size(20, 16);
            this.label_id.TabIndex = 0;
            this.label_id.Text = "ID";
            // 
            // label_firstName
            // 
            this.label_firstName.AutoSize = true;
            this.label_firstName.Location = new System.Drawing.Point(16, 56);
            this.label_firstName.Name = "label_firstName";
            this.label_firstName.Size = new System.Drawing.Size(24, 16);
            this.label_firstName.TabIndex = 1;
            this.label_firstName.Text = "Ad";
            // 
            // label_lastName
            // 
            this.label_lastName.AutoSize = true;
            this.label_lastName.Location = new System.Drawing.Point(16, 88);
            this.label_lastName.Name = "label_lastName";
            this.label_lastName.Size = new System.Drawing.Size(47, 16);
            this.label_lastName.TabIndex = 2;
            this.label_lastName.Text = "Soyad";
            // 
            // textBox_id
            // 
            this.textBox_id.Location = new System.Drawing.Point(128, 16);
            this.textBox_id.Name = "textBox_id";
            this.textBox_id.Size = new System.Drawing.Size(256, 22);
            this.textBox_id.TabIndex = 3;
            // 
            // textBox_firstName
            // 
            this.textBox_firstName.Location = new System.Drawing.Point(128, 56);
            this.textBox_firstName.Name = "textBox_firstName";
            this.textBox_firstName.Size = new System.Drawing.Size(256, 22);
            this.textBox_firstName.TabIndex = 4;
            // 
            // textBox_lastName
            // 
            this.textBox_lastName.Location = new System.Drawing.Point(128, 88);
            this.textBox_lastName.Name = "textBox_lastName";
            this.textBox_lastName.Size = new System.Drawing.Size(256, 22);
            this.textBox_lastName.TabIndex = 5;
            // 
            // button_delete
            // 
            this.button_delete.Location = new System.Drawing.Point(380, 208);
            this.button_delete.Name = "button_delete";
            this.button_delete.Size = new System.Drawing.Size(256, 24);
            this.button_delete.TabIndex = 6;
            this.button_delete.Text = "Dosyadan kayitlari sil";
            this.button_delete.UseVisualStyleBackColor = true;
            this.button_delete.Click += new System.EventHandler(this.button_delete_Click);
            // 
            // button_add
            // 
            this.button_add.Location = new System.Drawing.Point(642, 208);
            this.button_add.Name = "button_add";
            this.button_add.Size = new System.Drawing.Size(233, 24);
            this.button_add.TabIndex = 7;
            this.button_add.Text = "Dosyadan kayitlari ekle";
            this.button_add.UseVisualStyleBackColor = true;
            this.button_add.Click += new System.EventHandler(this.button_add_Click);
            // 
            // button_update
            // 
            this.button_update.Location = new System.Drawing.Point(881, 208);
            this.button_update.Name = "button_update";
            this.button_update.Size = new System.Drawing.Size(152, 24);
            this.button_update.TabIndex = 8;
            this.button_update.Text = "Guncelle";
            this.button_update.UseVisualStyleBackColor = true;
            this.button_update.Click += new System.EventHandler(this.button_update_Click);
            // 
            // dataGridView_database
            // 
            this.dataGridView_database.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_database.Location = new System.Drawing.Point(22, 238);
            this.dataGridView_database.Name = "dataGridView_database";
            this.dataGridView_database.RowHeadersWidth = 51;
            this.dataGridView_database.RowTemplate.Height = 24;
            this.dataGridView_database.Size = new System.Drawing.Size(1011, 342);
            this.dataGridView_database.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1052, 599);
            this.Controls.Add(this.dataGridView_database);
            this.Controls.Add(this.button_update);
            this.Controls.Add(this.button_add);
            this.Controls.Add(this.button_delete);
            this.Controls.Add(this.textBox_lastName);
            this.Controls.Add(this.textBox_firstName);
            this.Controls.Add(this.textBox_id);
            this.Controls.Add(this.label_lastName);
            this.Controls.Add(this.label_firstName);
            this.Controls.Add(this.label_id);
            this.Name = "Form1";
            this.Padding = new System.Windows.Forms.Padding(16);
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_database)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_id;
        private System.Windows.Forms.Label label_firstName;
        private System.Windows.Forms.Label label_lastName;
        private System.Windows.Forms.TextBox textBox_id;
        private System.Windows.Forms.TextBox textBox_firstName;
        private System.Windows.Forms.TextBox textBox_lastName;
        private System.Windows.Forms.Button button_delete;
        private System.Windows.Forms.Button button_add;
        private System.Windows.Forms.Button button_update;
        private System.Windows.Forms.DataGridView dataGridView_database;
    }
}

