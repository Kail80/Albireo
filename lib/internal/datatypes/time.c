#include <std.h>

struct date {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 month;
    uint8 week;
    uint8 mday;
    uint day;
};
typedef date date;
struct datejp {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 microseason;
    uint8 month;
    uint8 jun;
    uint8 week;
    uint8 mday;
    uint day;
};
typedef datejp datejp;
struct dateah {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 month;
    uint8 week;
    uint8 mday;
    uint day;
};
typedef dateah dateah;
struct time {
    uint8 timezone;
    uint8 hour;
    uint8 minute;
    uint8 second;
};
typedef time time;
struct date_time {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 microseason;
    uint8 month;
    uint8 week;
    uint8 mday;
    uint day;
    uint8 timezone;
    uint8 hour;
    uint8 minute;
    uint8 second;
};
typedef date_time date_time;
struct date_timeah {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 month;
    uint8 week;
    uint8 mday;
    uint day;
    uint8 timezone;
    uint8 hour;
    uint8 minute;
    uint8 second;
};
typedef date_timeah date_timeah;
struct date_timejp {
    int8 leapyear;
    int year;
    uint8 season;
    uint8 month;
    uint8 jun;
    uint8 week;
    uint8 mday;
    uint day;
    uint8 timezone;
    uint8 hour;
    uint8 minute;
    uint8 second;
};
typedef date_timejp date_timejp;

date_time combine_data_time(date indate, time intime) {
    date_time output = {indate.leapyear, indate.year, indate.season, indate.month, indate.week, indate.mday, indate.day, 
    intime.timezone, intime.hour, intime.minute, intime.second};
    return output;
}
date_time combine_data_timejp(datejp indate, time intime) {
    date_time output = {indate.leapyear, indate.year, indate.season, indate.month, indate.jun, indate.week, indate.mday, indate.day, 
    intime.timezone, intime.hour, intime.minute, intime.second};
    return output;
}
date_time combine_data_timeah(date indate, time intime) {
    date_time output = {indate.leapyear, indate.year, indate.season, indate.month, indate.week, indate.mday, indate.day, 
    intime.timezone, intime.hour, intime.minute, intime.second};
    return output;
}

// get gregorian month
int8 gregmonth(int8 day, int8 leapyear) {
    int month;
    if(day<=31) { // month 1
        month = 1;
    } else if(day>31 && day<=(59+leapyear)) { // month 2
        month = 2;
    } else if(day>(59+leapyear) && day<=(90+leapyear)) { // month 3
        month = 3;
    } else if(day>(90+leapyear) && day<=(120+leapyear)) { // month 4
        month = 4;
    } else if(day>(120+leapyear) && day<=(151+leapyear)) { // month 5
        month = 5;
    } else if(day>(151+leapyear) && day<=(181+leapyear)) { // month 6
        month = 6;
    } else if(day>(181+leapyear) && day<=(212+leapyear)) { // month 7
        month = 7;
    } else if(day>(212+leapyear) && day<=(243+leapyear)) { // month 8
        month = 8;
    } else if(day>(243+leapyear) && day<=(273+leapyear)) { // month 9
        month = 9;
    } else if(day>(273+leapyear) && day<=(304+leapyear)) { // month 10
        month = 10;
    } else if(day>(304+leapyear) && day<=(334+leapyear)) { // month 11
        month = 11;
    } else if(day>(334+leapyear) && day<=(365+leapyear)) { // month 12
        month = 12;
    } else {
        month = -1;
        printf("days out of bounds(0-365)");
    }
    return month;
}

// get gregorian day of the month
int8 gregmday(int8 day, int8 leapyear) {
    int mday;
    if(day<=31) { // month 1
        mday = day;
    } else if(day>31 && day<=(59+leapyear)) { // month 2
        mday = day - 31;
    } else if(day>(59+leapyear) && day<=(90+leapyear)) { // month 3
        mday = day - (59+leapyear);
    } else if(day>(90+leapyear) && day<=(120+leapyear)) { // month 4
        mday = day - (90 + leapyear);
    } else if(day>(120+leapyear) && day<=(151+leapyear)) { // month 5
        mday = day - (120 + leapyear);
    } else if(day>(151+leapyear) && day<=(181+leapyear)) { // month 6
        mday = day - (151 + leapyear);
    } else if(day>(181+leapyear) && day<=(212+leapyear)) { // month 7
        mday = day - (181 + leapyear);
    } else if(day>(212+leapyear) && day<=(243+leapyear)) { // month 8
        mday = day - (212 + leapyear);
    } else if(day>(243+leapyear) && day<=(273+leapyear)) { // month 9
        mday = day - (243 + leapyear);
    } else if(day>(273+leapyear) && day<=(304+leapyear)) { // month 10
        mday = day - (273 + leapyear);
    } else if(day>(304+leapyear) && day<=(334+leapyear)) { // month 11
        mday = day - (304 + leapyear);
    } else if(day>(334+leapyear) && day<=(365+leapyear)) { // month 12
        mday = day - (334 + leapyear);
    }
    return mday;
}

// get gregorian season
uint8 gregseason(int8 mday, int8 month, uint8 hemisphere) { // hemisphere == 1||-1
    uint8 season;
    if(month>=3 && month<6) { // spring
        season = 1;
    } else if (month>=6 && month<9) { // summer
        season = 2;
    } else if (month>=9 && month<12) { // fall/autumn
        season = 3;
    } else if (month=12 || month<3) { // winter
        season = 4;
    }

    if(hemisphere==-1) {
        season = (season+2)%4;
    }
    return season;
}