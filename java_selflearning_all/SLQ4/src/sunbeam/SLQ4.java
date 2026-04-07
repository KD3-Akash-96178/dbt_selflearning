package sunbeam;

enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
	
    public boolean isWeekend() {
        return this == SATURDAY || this == SUNDAY;
    }

    public boolean isWeekday() {
        return !isWeekend();
    }
}

public class SLQ4 {
    public static void main(String[] args) {

        for (Day day : Day.values()) {
            System.out.println(day);

            if (day.isWeekend()) {
                System.out.println("It's a Weekend");
            } else {
                System.out.println("It's a Weekday");
            }

            System.out.println("----------------");
        }
    }
}
