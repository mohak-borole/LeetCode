class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
    
    for (int bill : bills) {
        if (bill == 5) {
            // If the customer pays with a $5 bill, no change is needed.
            five++;
        } else if (bill == 10) {
            // If the customer pays with a $10 bill, we need to give them $5 as change.
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            // If the customer pays with a $20 bill, we need to give them $15 as change.
            if (ten > 0 && five > 0) {
                // Prefer to give one $10 bill and one $5 bill if possible.
                ten--;
                five--;
            } else if (five >= 3) {
                // Otherwise, give three $5 bills as change.
                five -= 3;
            } else {
                // If neither option is possible, we cannot give the correct change.
                return false;
            }
        }
    }
    
    // If we've successfully given correct change to all customers, return true.
    return true;
    }
};