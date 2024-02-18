#include <stdio.h>

#define STUDENT_NUMBER_LENGTH 20
#define STUDENT_NAME_LENGTH 20
#define FORMAT_LENGTH STUDENT_NAME_LENGTH+STUDENT_NUMBER_LENGTH+100
#define PASSED true

void resetResultFiles() {
    fclose(fopen("BasariliOgrenciler.txt", "w"));
    fclose(fopen("KalanOgrenciler.txt", "w"));
}

void writeFile(char format[FORMAT_LENGTH], bool result,
                  const char student_number[STUDENT_NUMBER_LENGTH], const char student_name[STUDENT_NAME_LENGTH],
                  int midterm, int final, int mean) {
    const char *letter_grade;

    if(mean<41) {
        letter_grade = "DD";
    }
    else if(mean<61) {
        letter_grade = "CC";
    }
    else if(mean<81) {
        letter_grade = "BB";
    }
    else {
        letter_grade = "AA";
    }

    if(result) {

        FILE *file = fopen("BasariliOgrenciler.txt", "a");
        fprintf(file, format, student_number, student_name, midterm, final, mean, letter_grade);
        fclose(file);
    }
    else {
        FILE *file = fopen("KalanOgrenciler.txt", "a");
        fprintf(file, format, student_number, student_name, midterm, final, mean, letter_grade);
        fclose(file);
    }
}


int main() {
    char read_format[FORMAT_LENGTH] = "%s\t%s\t%d\t%d\n";
    char write_format[FORMAT_LENGTH] = "%s\t%s\t%d\t%d\t%d\t%s\n";
    char student_name[STUDENT_NAME_LENGTH];
    char student_number[STUDENT_NUMBER_LENGTH];
    int midterm, final, mean;
    int sum_data[8]; // pass_count, sum_pass_midterm, sum_pass_final, sum_pass_mean, fail_count, sum_fail_midterm, sum_fail_final, sum_fail_mean

    for(int i=0; i<8; i++) {
        sum_data[i] = 0;
    }

    resetResultFiles();
    FILE *student_file = fopen("Ogrenci.txt", "r");

    while(!feof(student_file)) {
        fscanf(student_file, read_format, &student_number, &student_name, &midterm, &final);
        if((mean=0.4*midterm+0.6*final) >49) {
            sum_data[0]++;
            sum_data[1] += midterm;
            sum_data[2] += final;
            sum_data[3] += mean;
            writeFile(write_format, PASSED, student_number, student_name, midterm, final, mean);
        }
        else {
            sum_data[4]++;
            sum_data[5] += midterm;
            sum_data[6] += final;
            sum_data[7] += mean;
            writeFile(write_format, !PASSED, student_number, student_name, midterm, final, mean);
        }
    }
    writeFile(write_format, PASSED, "---     ", "---",
              sum_data[1]/sum_data[0], sum_data[2]/sum_data[0], sum_data[3]/sum_data[0]);
    writeFile(write_format, !PASSED, "---     ", "---",
              sum_data[5]/sum_data[4], sum_data[6]/sum_data[4], sum_data[7]/sum_data[4]);

    fclose(student_file);
    return 0;
}