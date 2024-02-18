#include <stdio.h>


int power(int base, int n) {
    int result = 1;
    
    for(; n>0 ; n--)
        result *= base;
        
    return result;
}


int octal_to_decimal_converter(long long num) {
    int i = 0;
    int octal_digits[11];
    int num_in_decimal = 0;
    
    while(num > 0) {
        octal_digits[i] = num%10;
        i++;
        num /= 10;
    }
    
    for(i--; i>=0 ; i--) {
        num_in_decimal += octal_digits[i]*power(8, i);
    }
    
    return num_in_decimal;
}


int hexadecimal_to_decimal_decimal(long long num) {
    int i = 0;
    int hexadecimal_digits[8];
    int num_in_decimal  = 0;
    
    while(num > 0) {
        hexadecimal_digits[i] = num%10;
        i++;
        num /= 10;
    }
    
    for(i--; i>=0 ; i--) {
        num_in_decimal += hexadecimal_digits[i]*power(16, i);
    }
    
    return num_in_decimal;
}


int binary_to_decimal_converter(long long num) {
    int i = 0;
    long binary_digits[32];
    int num_in_decimal = 0;
    
    while(num > 0) {
        binary_digits[i] = num%10;
        i++;
        num /= 10;
    }
    
    for (i-- ; i>=0 ; i--) {
        num_in_decimal += binary_digits[i]*power(2, i);
    }
    
    return num_in_decimal;
}


void decimal_to_binary_converter(long long q) { // eger q=1 olursa son islemdedir o yuzden loop durmali
    int bin_digits[32];
    int m, i;
    i = 31;
    while(q > 1) {
        m = q %2;
        q /= 2;
        bin_digits[i] = m;
        i--;
    }
    bin_digits[i] = q;
    
    for(; i<32 ; i++)
        printf("%d", bin_digits[i]);
}


void decimal_to_octal_converter(long long q) {
    int oct_digits[11];
    int m, i;
    i = 10;
    while(q > 1) { // eger q=1 olursa son islemdedir o yuzden loop durmali
        m = q %8;
        q /= 8;
        oct_digits[i] = m;
        i--;
    }
    
    if(q != 0)
        oct_digits[i] = q;
    else
        i++;
    
    for(; i<11 ; i++)
        printf("%d", oct_digits[i]);
}


void decimal_to_hexadecimal_converter(long long q) {
    int hex_dict[6][2] = {{10, 'A'-'0'}, {11, 'B'-'0'}, {12, 'C'-'0'}, {13, 'D'-'0'}, {14, 'E'-'0'}, {15, 'F'-'0'}};
    int hex_digits[8];
    int m, i;
    i = 7;
    while(q > 1) { // eger q=1 olursa son islemdedir o yuzden loop durmali
        m = q %16;
        q /= 16;
        hex_digits[i] = m;
        if(m>=10)
            hex_digits[i] = hex_dict[m-10][1];
        i--;
    }
    
    if(q != 0)
        hex_digits[i] = q;
    else
        i++;
    
    for(; i<8 ; i++)
        printf("%c", '0' + hex_digits[i]);
}



int main() {
    long long num; // binary girdiler icin daha yuksek sayilari alabilmek icin int yerine long long kullandim (19 basamakli binary sayilara kadar destekliyor)
    int base_in, base_out;
    int digits[32];
    
    
    printf("Sayi giriniz: ");
    scanf("%lld", &num);
    
    printf("Taban (x) giriniz: ");
    scanf("%d", &base_in);
    
    printf("Donusum tabani (y) giriniz: ");
    scanf("%d", &base_out);
    
        
    switch(base_out) {
        case(2):
            if(base_in == 2)
                printf("Sonuc: %lld", num);
            else if(base_in == 8) {
                printf("Sonuc: ");
                decimal_to_binary_converter(octal_to_decimal_converter(num));
            }
            
            else if(base_in == 10) {
                printf("Sonuc: "); 
                decimal_to_binary_converter(num);
            }
            
            else if(base_in == 16) {
                printf("Sonuc: ");
                decimal_to_binary_converter(hexadecimal_to_decimal_decimal(num));
            }
            break;
            
        case(8): 
            if(base_in == 8)
                printf("Sonuc: %lld", num);
                
            else if(base_in == 2) {
                printf("Sonuc: ");
                decimal_to_octal_converter(binary_to_decimal_converter(num));
            }
            
            else if(base_in == 10) {
                printf("Sonuc: ");
                decimal_to_octal_converter(num);
            }
                
            else if(base_in == 16) {
                printf("Sonuc: ");
                decimal_to_octal_converter(hexadecimal_to_decimal_decimal(num));
            }
            
            break;
        
        case(10):
            if(base_in == 10)
                printf("Sonuc: %lld", num);
                
            else if(base_in == 2)
                printf("Sonuc: %d", binary_to_decimal_converter(num));
                
            else if(base_in == 8)   
                printf("Sonuc: %d", octal_to_decimal_converter(num));
            
            else if(base_in == 16)
                printf("Sonuc: %d", hexadecimal_to_decimal_decimal(num)); 
                
            break;
            
        case(16):
            if(base_in == 16)
                printf("Sonuc: %lld", num);
                
            else if(base_in == 2) {
                printf("Sonuc: ");
                decimal_to_hexadecimal_converter(binary_to_decimal_converter(num));
            }
                
            else if(base_in == 8) {
                printf("Sonuc: ");
                decimal_to_hexadecimal_converter(octal_to_decimal_converter(num));
            }
            
            else if(base_in == 10) {
                printf("Sonuc: ");
                decimal_to_hexadecimal_converter(num);
            }
            
        break;
        
        default: printf("\n[!] - Hatali taban secimi!");
    }   
}
