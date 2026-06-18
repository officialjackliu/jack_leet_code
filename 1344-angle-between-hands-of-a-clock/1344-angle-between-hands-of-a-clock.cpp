class Solution {
public:
    double angleClock(int hour, int minutes) {
        // angle 0 - 180
        // translate hours or minutes to the same numerical value? 
        // calculate minutes
        double angle_minutes = minutes * 6.0; 
        // calculate hour 
        if (hour == 12) {
            hour = 0;
        }
        double angle_hour = (hour * 1.0 + (double) (minutes / 60.0)) * 5.0 * 6.0;
        // calculate the offset of hour
        double time = abs(angle_minutes - angle_hour);
        return (time > 180.0) ? (360.0 - time) : time;
    }
};