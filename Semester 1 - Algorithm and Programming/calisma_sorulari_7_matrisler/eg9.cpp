#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1

int max_value(int array[], int size) {
    int max;
    for (int i=1, max=array[0] ; i<size ; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


int main() {
    srand(time(NULL));
    int i, j, k;
    int num_major, num_class, max_m, capacity;
    float container, mean;
    
    capacity = 20;
    
    // n = bolum sayisi
    // k = number of classes
    // each item of m[] = number of students in that major
    // each class has 2 exams + mean of these exams
    
    printf("Bolum Sayisi (N): ");
    scanf("%d", &num_major);
    int num_students[num_major];
    
    for (i=0 ; i<num_major ; i++) {
        printf("  %d. Bolumun ogrenci sayisi: ", i+1);
        scanf("%d", &num_students[i]);
    }
    
    printf("Ders sayisi (K): ");
    scanf("%d", &num_class);
    
    // -------- Create the database (+ print)
    float database[num_major][capacity][num_class][3];  // 3 stands for midterm, final and mean
    
    for (i=0; i<num_major ; i++) {
        printf("\n\n%d.Bolum:", i+1);
        for (j=0 ; j<capacity ; j++) {
            
            if (j < num_students[i]) {
            printf("  \n%d.Ogrenci:", j+1);
            }
            
            for (k=0 ; k<num_class ; k++) {
                
                if (j < num_students[i]) {
                    printf("    %d.Ders:", k+1);
                    mean = 0;
                    database[i][j][k][0] = rand()%101;
                    mean += database[i][j][k][0]*0.4;
                    printf(" %3.f", database[i][j][k][0]);
                    
                    database[i][j][k][1] = rand()%101;
                    mean += database[i][j][k][1]*0.6;
                    printf(" %3.f", database[i][j][k][1]);
                    
                    database[i][j][k][2] = mean;
                    printf(" Mean: %3.2f", database[i][j][k][2]);

                }
                
                else {
                    database[i][j][k][0] = EMPTY;
                    database[i][j][k][1] = EMPTY;
                    database[i][j][k][2] = EMPTY;
                }
            }
        }
    }
    
    // -------- Ask for majors
    int major_1, major_2, max_mean, best_student_1, best_student_2;
    
    printf("\n\nEn basarili iki ogrencinin yerini degistirmek istediginiz ilk bolumu giriniz: ");
    scanf("%d", &major_1);
    major_1--;
    printf("\n\nEn basarili iki ogrencinin yerini degistirmek istediginiz ilk bolumu giriniz: ");
    scanf("%d", &major_2);
    major_2--;
    
    // -------- Find the best students for chosen majors
    for (i=max_mean=0; i<num_students[major_1] ; i++) {
        
        for (j=mean=0 ; j<num_class ; j++) {
                mean += database[major_1][i][j][2];
        }
        
        if (mean > max_mean) {
            max_mean = mean;
            best_student_1 = i;
        }
    }
    
    for (i=max_mean=0; i<num_students[major_2] ; i++) {
        
        for (j=mean=0 ; j<num_class ; j++) {
                mean += database[major_2][i][j][2];
        }
        
        if (mean > max_mean) {
            max_mean = mean;
            best_student_2 = i;
        }
    }
    
    // -------- Swap the students
    for (i=0 ; i<num_class ; i++) {
        for (j=0 ; j<3 ; j++) {
        container = database[major_1][best_student_1][i][j];
        database[major_1][best_student_1][i][j] = database[major_2][best_student_2][i][j];
        database[major_2][best_student_2][i][j] = container;
        }
    }
    
    // -------- Print the new database
    printf("\n\n\n");
    for (i=0; i<num_major ; i++) {
        printf("\n\n%d.Bolum:", i+1);
        for (j=0 ; j<capacity ; j++) {
            
            if (j < num_students[i]) {
            printf("  \n%d.Ogrenci:", j+1);
            }
            
            for (k=0 ; k<num_class ; k++) {
                
                if (j < num_students[i]) {
                    printf("    %d.Ders:", k+1);
                    printf(" %3.f", database[i][j][k][0]);
                    printf(" %3.f", database[i][j][k][1]);
                    printf(" Mean: %3.2f", database[i][j][k][2]);

                }
                
            }
        }
    }
}
