class Solution {
public:
    unordered_map<int, char> map = {{1, 'I'},   {5, 'V'},   {10, 'X'},
                                    {50, 'L'},  {100, 'C'}, {500, 'D'},
                                    {1000, 'M'}};

    bool special_append(int num, string &roman) {
        if (num == 4) {
            roman += "IV";
            return true;
        } else if (num == 9) {
            roman += "IX";
            return true;
        } else if (num == 40) {
            roman += "XL";
            return true;
        } else if (num == 90) {
            roman += "XC";
            return true;
        } else if (num == 400) {
            roman += "CD";
            return true;
        } else if (num == 900) {
            roman += "CM";
            return true;
        } 
        return false;
    }

    void int_roman_conversion(int num, int digits, string& roman) {
        if (digits == 4) {
            num = num / 1000;
            for (int i = 0; i < num; i++) {
                roman += 'M';
            }
        } else if (digits == 3) {
            if (special_append(num, roman) == true) {
                return;
            } 
            num = num / 100;
            if (num >= 5) {
                roman += 'D';
                num -= 5; 
            }
            for (int i = 0; i < num; i++) {
                roman += 'C'; 
            }
        } else if (digits == 2) {
            
            if (special_append(num, roman) == true) {
                return;
            } 
            num = num / 10;
            if (num >= 5) {
                roman += 'L';
                num -= 5; 
            }
            for (int i = 0; i < num; i++) {
                roman += 'X'; 
            }
        } else if (digits == 1) {
            if (special_append(num, roman) == true) {
                return;
            } 
            if (num >= 5) {
                roman += 'V';
                num -= 5; 
            }
            for (int i = 0; i < num; i++) {
                roman += 'I'; 
            }
        }
    }

    string intToRoman(int num) {
        // can not use a number over 3 time
        // go over left to right
        int n = to_string(num).length();
        // cout << "length of the num is " << n << endl;
        string roman;
        for (int i = n; i >= 1; i--) {
            // in whole number 100, 400,
            int divisor = pow(10, i - 1); 

            int striped_num = (num / divisor) * divisor;
            
            // cout << "striped_num  is " << striped_num << endl;
            int_roman_conversion(striped_num, i, roman);
            // next num 
            num = num % divisor; 
        }
        return roman;
    }
};