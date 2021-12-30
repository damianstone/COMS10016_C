// enum can be used in a switch statement to

enum { MON, TUE, WED, THU, FRI, SAT, SUN };
void dayRoutine(int day) { 
    switch(day) {
        case MON:
        return printf("MONDAY");
        break;
        case TUE:
        return printf("TUESDAY");
        break;
        case WED:
        return printf("WEDNESDAY");
        break;
        case THU:
        return printf("THURSDAY");
        break;
        case FRI:
        return printf("FRIDAY");
        break;
        case SAT:
        return printf("SATURDAY");
        break;
        case SUN:
        return printf("SUNDAY");
        break;
        default:
        return 0;
    };
};